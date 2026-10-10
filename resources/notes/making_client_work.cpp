// SPDX-License-Identifier: GPL-3.0-or-later
survarium::network_client {
  boost::array<survarium::player_desc,20> m_net_players;
}

struct survarium::player_desc {                            
    vostok::resources::resource_ptr<
      vostok::resources::unmanaged_resource,
      vostok::resources::unmanaged_intrusive_base
    > player;
    bool is_connected;
};


survarium::network_client::process_player_profile()
{
  match_client->m_match_options.player_profiles[received_players_count]


   if (p_m_match_options->received_players_count 
    == p_m_match_options->players_count)
      survarium::network_client::query_players:
        -> this_->m_net_players.elems[player_id].is_connected = 0;
}


// Reads `player_id` from the packet
survarium::network_client::player_visibility_change()
survarium::network_client::process_player_respawn()




survarium::network_client::get_player(
  survarium::network_client *this,
  unsigned __int8 id
) {
  m_object = this->m_net_players.elems[id].player.m_object
}


//
// Places the client sends packages from
//

enum match_client_message_types_enum_u8 : __int8
{
  connection_request                 = 0x40, // +
  get_startup_info                   = 0x41, // +
  join_match                         = 0x42, // +
  client_player_update               = 0x43, // +
  client_player_commit_suicide       = 0x44, // +
  time_synchronization_request       = 0x45, // +
  time_synchronization_confirmation  = 0x46, // +
  bullets_info_request               = 0x47, // -
  team_bases_initialize_info         = 0x48, // +
  force_finish_match                 = 0x49, // -
  world_synchronization_confirmation = 0x4A, // +
  match_client_invalid_message_type  = 0x7F,
};


survarium::match_client::connect()
 > vostok::network::match_client::new_packet(connection_request);

survarium::network_client::on_connected_to_match()
  > vostok::network::match_client::new_packet(get_startup_info);

survarium::network_client::tick()
  > survarium::network_client::send_player_inputs()
    > vostok::network::match_client::new_packet(client_player_update);

  > survarium::network_client::send_sync_request()
    > vostok::network::match_client::new_packet(time_synchronization_request);

survarium::network_client::on_match_packet_received()
  > survarium::network_client::process_player_profile()
    > survarium::network_client::query_players()
      > survarium::network_client::on_players_ready()
        > vostok::network::match_client::new_packet(team_bases_initialize_info);
        > vostok::network::match_client::new_packet(join_match)

  > survarium::network_client::on_world_sync_request()
    > vostok::network::match_client::new_packet(world_synchronization_confirmation)

  > survarium::network_client::process_sync_response()
    > vostok::network::match_client::new_packet(time_synchronization_confirmation)

> `survarium::network_client::vftable`
  > survarium::network_client::initiate_kill_current_player()
    > vostok::network::match_client::new_packet(client_player_commit_suicide)



//
// What client does with received packages
//

enum vostok::match_server_message_types_enum : __int32
{
  match_server_connection_successful = 0x80, // --//--
  match_options_message_type         = 0x81, // --//--
  server_player_input                = 0x82, // +
  kill_player                        = 0x83, // +
  spawn_player                       = 0x84, // +
  team_base_capture_progress         = 0x85,
  match_time_changed                 = 0x86,
  respawn_time_changed               = 0x87,
  player_kd_stats_changed            = 0x88,
  hit_player                         = 0x89,
  affect_damage_model                = 0x8A,
  sync_response                      = 0x8B,
  match_finished                     = 0x8C,
  server_bullet_added                = 0x8D, // -
  server_bullet_removed              = 0x8E, // -
  server_bullet_moved                = 0x8F, // -
  server_bullet_collided             = 0x90, // -
  player_visibility_changed          = 0x91,
  player_profile_message_type        = 0x92,
  team_bases_message_type            = 0x93,
  initialize_victory_items           = 0x94,
  victory_item_take_or_put           = 0x95,
  trap_placed                        = 0x96,
  trap_removed                       = 0x97,
  trap_fired                         = 0x98,
  trap_disarmed                      = 0x99,
  game_status_changed                = 0x9A,
  match_wait_time_changed            = 0x9B,
  game_world_object_state            = 0x9C,
  world_synchronization_request      = 0x9D,
  damage_model_state                 = 0x9E,
  match_server_invalid_message_type  = 0xC0,
};

survarium::network_client::on_match_packet_received()

server_player_input: survarium::network_client::process_player_action()
  > survarium::network_client::get_player(i)
  > survarium::player::set_character_transform()
  > survarium::player::time_warp()


kill_player: survarium::network_client::process_player_kill()
  > survarium::network_client::get_player(i)
  > survarium::game_world_ui::on_player_killed()
  > survarium::player::kill()


spawn_player: survarium::network_client::process_player_respawn()
  > survarium::network_client::get_player(i)
  > (this->__vftable[1].disconnect)(this, packet); // ???
  > if (v2->m_is_time_synchronized_first_time) { 
      survarium::base_network_client::attach_to_player()
    }
  > 

// Figure out how player is initialized

stack:
  network_client     <- |free_estate| player_id, result_addr
  ret_addr
  ebx
  ebp
  esi
  edi     <- rsp


vostok::resources::resource_ptr<
  vostok::resources::unmanaged_resource,
  vostok::resources::unmanaged_intrusive_base
> player;


struct __cppobj vostok::resources::resource_ptr<
  vostok::resources::unmanaged_resource,
  vostok::resources::unmanaged_intrusive_base
> : vostok::intrusive_ptr<
  vostok::resources::unmanaged_resource,
  vostok::resources::unmanaged_intrusive_base,
  vostok::threading::simple_lock
>
{
};

struct __cppobj vostok::intrusive_ptr<
  vostok::resources::unmanaged_resource,
  vostok::resources::unmanaged_intrusive_base,
  vostok::threading::simple_lock
> {
  vostok::resources::unmanaged_resource *m_object;
};
