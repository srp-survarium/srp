use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::mpsc;
use std::sync::mpsc::TryRecvError;

use survarium::player_input::{
    player_inventory_slot, player_stamina, weapon_core, weapon_core_state, weapon_targets,
};
use survarium::player_profile;
use survarium::player_profile::raw::profile_slot_enum;
use vostok::math::float3;

use crate::message;
use crate::message::server_message::raw::{game_mode_type, game_status};
use crate::message::{ClientGameMessageKind, ServerGameMessageKind};

/// Position updates seen, for rate-limiting the optional position log.
static PLAYER_UPDATES_SEEN: AtomicU64 = AtomicU64::new(0);

pub struct Game {
    client_game_message_rx: mpsc::Receiver<message::ClientGameMessageKind>,
    server_game_message_tx: mpsc::Sender<message::ServerGameMessageKind>,
    map: MapProfile,
}

#[derive(Clone, Copy, Debug)]
struct MapProfile {
    map_name: &'static str,
    local_spawn: [f32; 3],
    remote_spawn: [f32; 3],
    orientation: f32,
}

fn match_player_profile(
    team: player_profile::raw::game_team_id,
    is_local: bool,
    name: &str,
) -> player_profile::raw::player_profile {
    let mut profile = player_profile::raw::player_profile {
        team,
        is_local,
        ..player_profile::raw::player_profile::new_dummy(0, 0, name)
    };

    match std::env::var("SRP_MATCH_LOADOUT_PROFILE").as_deref() {
        Ok("stock-v0100b") => {
            use profile_slot_enum::*;

            // Map-only v0.100b databases intentionally contain no imported
            // equipment. Keep the stock AKS-74U and its ammunition from
            // new_dummy(), but do not advertise imported armor dictionary IDs
            // that do not exist in the target's stock items dictionary.
            for slot in [
                helmet_slot,
                mask_slot,
                torso_slot,
                back_slot,
                pants_slot,
                gloves_slot,
                boots_slot,
            ] {
                profile.slots[slot as usize] = Default::default();
            }
        }
        Ok("configured") | Err(_) => {}
        Ok(other) => panic!(
            "unknown SRP_MATCH_LOADOUT_PROFILE {other:?}; expected configured or stock-v0100b"
        ),
    }

    profile
}

impl MapProfile {
    fn selected() -> Self {
        let name = std::env::var("SRP_MAP_PROFILE")
            .unwrap_or_else(|_| "level03-evening-0100b".to_string());
        match name.as_str() {
            "level03-evening-0100b" => Self {
                map_name: "level_03_evn",
                local_spawn: [-7.76438, 13.95794, -31.85271],
                remote_spawn: [-9.33856, 47.47741, -25.15140],
                orientation: 10.0,
            },
            // Shadow of Chernobyl multiplayer maps, converted by resource-porter.
            // Spawns are the map centre from the converted extent, high enough
            // to drop onto the geometry: the source respawn points live in
            // level.spawn, which the converter does not read yet.
            "soc-mp-pool" => Self {
                map_name: "soc_mp_pool",
                // Derived from the collision mesh, not the bounding box: the
                // centre of mp_pool's box is the bottom of the pool.
                // 769 units of floor at deck level, 5.35m of headroom.
                local_spawn: [25.44, 0.50, -31.18],
                remote_spawn: [30.93, 0.66, -37.48],
                orientation: 0.0,
            },
            // A/B control: identical map, but its client project keeps every
            // template scene object instead of dropping the positional ones.
            "soc-mp-pool-keepobjects" => Self {
                map_name: "soc_mp_pool_k",
                local_spawn: [20.4, 15.0, -37.0],
                remote_spawn: [17.9, 15.0, -34.5],
                orientation: 0.0,
            },
            // A/B control: identical map with no collision archive at all, so the
            // template's own collision stays. Isolates the collision-only model,
            // a shape v0.100b never ships.
            "soc-mp-pool-nocollision" => Self {
                map_name: "soc_mp_pool_n",
                local_spawn: [20.4, 15.0, -37.0],
                remote_spawn: [17.9, 15.0, -34.5],
                orientation: 0.0,
            },
            "soc-darkvalley" => Self {
                map_name: "soc_mp_darkvalley",
                // The map's own MP team bases, from level.spawn.
                local_spawn: [233.06, 2.4, -246.13],
                remote_spawn: [333.43, 2.3, -215.36],
                orientation: 0.0,
            },
            "soc-cordon" => Self {
                map_name: "soc_cordon",
                // Cordon declares no team base, and its widest flat ground is an
                // empty field. This is standable ground 0.4u from the densest
                // cluster of AI graph points -- the inhabited centre.
                local_spawn: [-140.99, -29.19, -362.48],
                remote_spawn: [-141.70, -29.19, -360.17],
                orientation: 0.0,
            },
            // The rest of Shadow of Chernobyl's multiplayer roster. Every spawn
            // below is the map's own `zone_team_base`, read out of level.spawn
            // by `soc-spawn-candidates`: the two teams' bases become the local
            // and remote spawns, which is what they were authored as. Only
            // mp_bath declares none, and falls back to the ranked ground.
            //
            // Each sits 1.5m above the authored height. X-Ray placed a team
            // base *on* the floor and spawned a character standing on it;
            // v0.100b puts the capsule's centre where it is told, so the
            // authored height buries the lower half in the floor and the player
            // falls through the map. Landing from 1.5m costs nothing.
            "soc-rostok" => Self {
                map_name: "soc_mp_rostok",
                local_spawn: [-101.33, -35.16, 15.89],
                remote_spawn: [5.57, -31.26, -112.12],
                orientation: 0.0,
            },
            "soc-factory" => Self {
                map_name: "soc_mp_factory",
                local_spawn: [32.00, 2.71, 43.98],
                remote_spawn: [27.43, 1.83, -73.72],
                orientation: 0.0,
            },
            "soc-atp" => Self {
                map_name: "soc_mp_atp",
                local_spawn: [139.13, -5.22, -69.30],
                remote_spawn: [134.33, -5.66, 25.37],
                orientation: 0.0,
            },
            "soc-railroad" => Self {
                map_name: "soc_mp_railroad",
                local_spawn: [66.39, 2.59, 63.64],
                remote_spawn: [-32.60, 2.75, -108.00],
                orientation: 0.0,
            },
            "soc-lost-village" => Self {
                map_name: "soc_mp_lost_village",
                local_spawn: [83.82, 6.50, -61.79],
                remote_spawn: [-13.05, 12.61, -66.51],
                orientation: 0.0,
            },
            "soc-military-1" => Self {
                map_name: "soc_mp_military_1",
                local_spawn: [-59.54, -9.72, -47.65],
                remote_spawn: [-43.35, -9.45, 52.62],
                orientation: 0.0,
            },
            "soc-military-2" => Self {
                map_name: "soc_mp_military_2",
                local_spawn: [-342.36, -19.71, 254.88],
                remote_spawn: [-288.10, -19.82, 295.73],
                orientation: 0.0,
            },
            "soc-agroprom" => Self {
                map_name: "soc_mp_agroprom",
                local_spawn: [-39.34, 1.77, 38.92],
                remote_spawn: [59.76, 3.27, -35.95],
                orientation: 0.0,
            },
            "soc-workshop" => Self {
                map_name: "soc_mp_workshop",
                local_spawn: [-14.53, 2.48, -56.64],
                remote_spawn: [-30.50, 2.81, 47.73],
                orientation: 0.0,
            },
            "soc-bath" => Self {
                map_name: "soc_mp_bath",
                // No team base declared, and the ranked-ground fallback put the
                // player *under* the map: `convert::spawn` reported
                // [19.43, 1.78, 16.27], but `soc-probe-ground` finds seven
                // collision layers over that column and the lowest upward face
                // is concrete at y=4.43 -- so 1.78 is 2.7m below the building's
                // ground floor, and the player spawned beneath it and fell out
                // of the world. The heuristic's height is not the height of the
                // surface it measured; trust the probe.
                //
                // 4.43 is the floor, 8.62 the ceiling above it, and the three
                // neighbouring columns agree, so this is a room rather than a
                // ledge.
                local_spawn: [19.43, 5.93, 16.27],
                remote_spawn: [16.93, 5.93, 18.77],
                orientation: 0.0,
            },
            // F.E.A.R. multiplayer, from build-lilith-map. Spawns are authored
            // `GameStartPoint`s out of the world's own object list (see the
            // port manifest's `start_points`), at the authored height: F.E.A.R.
            // places a start point about 1.5m above the floor already --
            // Office's floor under the first spawn is at -11.04 and the point
            // at -9.54 -- so unlike the SoC team bases no capsule-centre lift
            // is added on top.
            // Office is an interior map and the engine resolves a spawn onto
            // the topmost collision over its column, so an indoor start point
            // puts the player on the building's roof. Start05 is the one
            // authored point whose column is open to the sky -- the port
            // drops sky-seal geometry, leaving the courtyard floor at -15.04
            // as that column's top surface.
            "fear-office" => Self {
                map_name: "fear_office",
                local_spawn: [86.88, -13.74, -16.57],
                remote_spawn: [86.88, -13.74, -16.07],
                orientation: 0.0,
            },
            "level03-native-0100b" => Self {
                map_name: "level_03",
                local_spawn: [48.593, 0.433, 16.238],
                remote_spawn: [46.093, 0.433, 18.738],
                orientation: 1.447,
            },
            "level04-011e" => Self {
                map_name: "level_04_011e",
                local_spawn: [-78.428, 5.611, 31.116],
                remote_spawn: [-75.928, 5.611, 33.616],
                orientation: -1.474,
            },
            "level04-011e-mono" => Self {
                map_name: "level_04_011e_mono",
                local_spawn: [-78.428, 5.611, 31.116],
                remote_spawn: [-75.928, 5.611, 33.616],
                orientation: -1.474,
            },
            "level01-day-020f" => Self {
                map_name: "level_01_day_020f",
                local_spawn: [90.887, 15.157, 62.428],
                remote_spawn: [88.387, 15.157, 64.928],
                orientation: 0.709,
            },
            "level01-day-020f-native" => Self {
                map_name: "level_01_day_020f_native",
                local_spawn: [90.887, 15.157, 62.428],
                remote_spawn: [88.387, 15.157, 64.928],
                orientation: 0.709,
            },
            "level02-day-020f" => Self {
                map_name: "level_02_day_020f",
                local_spawn: [22.422, 16.156, 191.68],
                remote_spawn: [19.922, 16.156, 194.18],
                orientation: -0.211,
            },
            "level02-day-020f-native" => Self {
                map_name: "level_02_day_020f_native",
                local_spawn: [22.422, 16.156, 191.68],
                remote_spawn: [19.922, 16.156, 194.18],
                orientation: -0.211,
            },
            "level03-day-020f" => Self {
                map_name: "level_03_day_020f",
                local_spawn: [75.552, 0.912, 5.131],
                remote_spawn: [73.052, 0.912, 7.631],
                orientation: 1.37,
            },
            "level03-day-020f-native" => Self {
                map_name: "level_03_day_020f_native",
                local_spawn: [75.552, 0.912, 5.131],
                remote_spawn: [73.052, 0.912, 7.631],
                orientation: 1.37,
            },
            "level03-day-020f-minimal" => Self {
                map_name: "level_03_020f_min",
                local_spawn: [48.593, 0.433, 16.238],
                remote_spawn: [46.093, 0.433, 18.738],
                orientation: 1.447,
            },
            "level03-day-020f-visuals" => Self {
                map_name: "level_03_020f_vis",
                local_spawn: [48.593, 0.433, 16.238],
                remote_spawn: [46.093, 0.433, 18.738],
                orientation: 1.447,
            },
            "level04-day-020f" => Self {
                map_name: "level_04_day_020f",
                local_spawn: [-81.393, 5.611, 27.846],
                remote_spawn: [-78.893, 5.611, 30.346],
                orientation: -1.556,
            },
            "level04-day-020f-native" => Self {
                map_name: "level_04_day_020f_native",
                local_spawn: [-81.393, 5.611, 27.846],
                remote_spawn: [-78.893, 5.611, 30.346],
                orientation: -1.556,
            },
            "level05-day-020f" => Self {
                map_name: "level_05_day_020f",
                local_spawn: [-73.311, 5.91, 10.033],
                remote_spawn: [-70.811, 5.91, 12.533],
                orientation: -1.46,
            },
            "level05-day-020f-native" => Self {
                map_name: "level_05_day_020f_native",
                local_spawn: [-73.311, 5.91, 10.033],
                remote_spawn: [-70.811, 5.91, 12.533],
                orientation: -1.46,
            },
            "level03-day-023h" => Self {
                map_name: "level_03_day_023h",
                local_spawn: [75.552, 0.912, 5.131],
                remote_spawn: [73.052, 0.912, 7.631],
                orientation: 1.37,
            },
            "lobby-playable" => Self {
                map_name: "lobby_playable_0100b",
                local_spawn: [-1.5, 0.25, 0.0],
                remote_spawn: [1.5, 0.25, 0.0],
                orientation: 0.0,
            },
            "stk2-a02-blockpost-slice" => Self {
                map_name: "stk2_a02_blockpost_slice",
                local_spawn: [-1.5, 0.25, 0.0],
                remote_spawn: [1.5, 0.25, 0.0],
                orientation: 0.0,
            },
            "stk2-a02-full" => Self {
                map_name: "stk2_a02_full",
                local_spawn: [0.0, 1.0, 0.0],
                remote_spawn: [2.5, 1.0, 2.5],
                orientation: 0.0,
            },
            "stk2-bar-shooting-gallery-derived" => Self {
                map_name: "stk2_bar_gallery",
                local_spawn: [-2.0, 0.25, 0.0],
                remote_spawn: [2.0, 0.25, 0.0],
                orientation: 0.0,
            },
            other => panic!(
                "unknown SRP_MAP_PROFILE {other:?}; expected level03-evening-0100b, \
                 level03-native-0100b, level04-011e, level04-011e-mono, level01-day-020f, \
                 level01-day-020f-native, \
                 level02-day-020f, level02-day-020f-native, level03-day-020f, \
                 level03-day-020f-native, \
                 level03-day-020f-minimal, \
                 level03-day-020f-visuals, level04-day-020f, \
                 level04-day-020f-native, level05-day-020f, level05-day-020f-native, \
                 level03-day-023h, \
                 lobby-playable, \
                 stk2-a02-blockpost-slice, stk2-a02-full, or \
                 stk2-bar-shooting-gallery-derived"
            ),
        }
    }
}

impl Game {
    pub fn new(
        client_game_message_rx: mpsc::Receiver<message::ClientGameMessageKind>,
        server_game_message_tx: mpsc::Sender<message::ServerGameMessageKind>,
    ) -> Self {
        Self {
            client_game_message_rx,
            server_game_message_tx,
            map: MapProfile::selected(),
        }
    }

    pub fn tick(&mut self) {
        loop {
            match self.client_game_message_rx.try_recv() {
                Ok(message) => {
                    for message in self.handle_message(message) {
                        self.server_game_message_tx.send(message).unwrap()
                    }
                }
                Err(TryRecvError::Empty) => break,
                Err(TryRecvError::Disconnected) => panic!("Channel disconnected"),
            }
        }
    }
}

impl Game {
    pub fn handle_message(&self, message: ClientGameMessageKind) -> Vec<ServerGameMessageKind> {
        match message {
            ClientGameMessageKind::ConnectionRequest { .. } => {
                unreachable!("Should already be handled")
            }
            ClientGameMessageKind::GetStartupInfo => {
                vec![
                    ServerGameMessageKind::MatchOptions {
                        map_id: 0,
                        map_name: self.map.map_name.to_string(),
                        match_mode: game_mode_type::gather_victory_items,
                        player_count: 2,
                        victory_item_count: 10, // batteries
                        respawn_time: 10,
                        match_time: 15 * 60,
                    },
                    ServerGameMessageKind::PlayerProfile {
                        player_profile: Box::new(match_player_profile(
                            player_profile::raw::game_team_id::team_1,
                            true,
                            "sheepy",
                        )),
                    },
                    ServerGameMessageKind::PlayerProfile {
                        player_profile: Box::new(match_player_profile(
                            player_profile::raw::game_team_id::team_2,
                            false,
                            "beauty",
                        )),
                    },
                ]
            }
            ClientGameMessageKind::JoinMatch { .. } => {
                vec![
                    ServerGameMessageKind::GameStatusChanged {
                        game_status: game_status::inprocess,
                    },
                    ServerGameMessageKind::SpawnPlayer {
                        player_id: 0,
                        player: survarium::player_input::player {
                            position: float3 {
                                x: self.map.local_spawn[0],
                                y: self.map.local_spawn[1],
                                z: self.map.local_spawn[2],
                            },
                            orientation: self.map.orientation,
                            look_pitch: 10.,
                            is_alive: true,
                            server_current_active_slot: profile_slot_enum::weapon1_slot,
                            server_target_active_slot: profile_slot_enum::weapon1_slot,
                            player_stamina: player_stamina {
                                value: 100.,
                                last_spending_time_in_ms: 10,
                                last_tick_time_in_ms: 10,
                                lower_threshold_was_reached: false,
                            },
                            player_inventory: vec![
                                player_inventory_slot::weapon_slot(weapon_core {
                                    // Current condition of the AKS-74U in the
                                    // PlayerProfile, not its inventory ID.
                                    inventory_item: 100,
                                    random_seed: 0,
                                    normal_random_seed: 1,
                                    weapon_target: weapon_targets::idle,
                                    old_actions_mask: 0,
                                    ammo_in_magazine: 30,
                                    bullets_in_queue: 0,
                                    fire_queue_type: 0,
                                    ammo_slot: profile_slot_enum::ammo1_weapon1_slot,
                                    is_there_chamber_a_round_state: None, // ???
                                    weapon_core_state: Some(weapon_core_state {
                                        is_shown: true,
                                        active_hands: 1,
                                        start_transition_time_in_ms_lhs: 10,
                                        start_transition_time_in_ms_rhs: 10,
                                        weapon_sound_target_state: (3, None),
                                        logic_sprint_target_state: (0, None),
                                    }),
                                }),
                                player_inventory_slot::item_amount(200),
                            ],
                        },
                    },
                ]
            }
            ClientGameMessageKind::ClientPlayerUpdate { player_state, .. } => {
                // The client tells the server where it is thirty times a
                // second, and the server has nothing to do with it. It is the
                // only way to answer "where was I when that happened", which
                // every report about spawns, holes in the collision and dark
                // patches turns out to need. Off unless asked for, and
                // rate-limited, because the raw stream is unreadable.
                if std::env::var("SRP_LOG_PLAYER_POSITION").is_ok() {
                    let seen = PLAYER_UPDATES_SEEN.fetch_add(1, Ordering::Relaxed);
                    if seen % 30 == 0 {
                        let at = player_state.translation_w;
                        println!(
                            "player at [{:.2}, {:.2}, {:.2}] facing {:.2}",
                            at.x, at.y, at.z, player_state.euler_angle_y
                        );
                    }
                }
                vec![]
            }
            ClientGameMessageKind::TeamBasesInitializeInfo { .. } => {
                vec![
                    ServerGameMessageKind::SpawnPlayer {
                        player_id: 1,
                        player: survarium::player_input::player {
                            position: float3 {
                                x: self.map.remote_spawn[0],
                                y: self.map.remote_spawn[1],
                                z: self.map.remote_spawn[2],
                            },
                            orientation: self.map.orientation,
                            look_pitch: 0.2,
                            is_alive: true,
                            server_current_active_slot: profile_slot_enum::weapon1_slot,
                            server_target_active_slot: profile_slot_enum::weapon1_slot,
                            player_stamina: player_stamina {
                                value: 100.,
                                last_spending_time_in_ms: 10,
                                last_tick_time_in_ms: 10,
                                lower_threshold_was_reached: false,
                            },
                            player_inventory: vec![
                                player_inventory_slot::weapon_slot(weapon_core {
                                    // Current condition of the AKS-74U in the
                                    // PlayerProfile, not its inventory ID.
                                    inventory_item: 100,
                                    random_seed: 0,
                                    normal_random_seed: 1,
                                    weapon_target: weapon_targets::idle,
                                    old_actions_mask: 0,
                                    ammo_in_magazine: 30,
                                    bullets_in_queue: 0,
                                    fire_queue_type: 0,
                                    ammo_slot: profile_slot_enum::ammo1_weapon1_slot,
                                    is_there_chamber_a_round_state: None, // ???
                                    weapon_core_state: Some(weapon_core_state {
                                        is_shown: true,
                                        active_hands: 1,
                                        start_transition_time_in_ms_lhs: 10,
                                        start_transition_time_in_ms_rhs: 10,
                                        weapon_sound_target_state: (3, None),
                                        // weapon_sound_target_state: (0, None), // behind
                                        logic_sprint_target_state: (0, None),
                                    }),
                                }),
                                player_inventory_slot::item_amount(200),
                            ],
                        },
                    },
                    ServerGameMessageKind::SyncResponse {
                        is_connected_bitmask: 0b0011,
                    },
                ]
            }
        }
    }
}
