// SPDX-License-Identifier: GPL-3.0-or-later
//! Shared match state for an initial cohort of v0.21d clients.
//!
//! Scheduling, admission and input arbitration here are experimental SRP
//! policies, not recovered rules of the deployed community server. There is
//! no engine simulation. Recovery trusts one explicit reference client.
use crate::{
    replay::{Event, Journal},
    snapshot::Snapshot,
    transport::MAX_MESSAGE,
};
use std::collections::{BTreeMap, VecDeque};

const BOOTSTRAP_TIMEOUT: u64 = 15_000;
const HISTORY_MS: u32 = 10_000;
const INPUT_LEAD_MS: u32 = 500;
const MAX_HISTORY: usize = 16_384;
const MAX_REVISIONS: usize = 32;

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Delivery {
    pub slot: u8,
    pub opcode: u8,
    pub body: Vec<u8>,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum Stage {
    Loading,
    AwaitClock,
    AwaitPreloadAck,
    AwaitStateAck,
    Playing,
    Finished,
}

struct Player {
    prepared: bool,
    ready: bool,
    initial: Option<Snapshot>,
    stage: Stage,
    reference: u32,
    active_since: Option<u32>,
    transfer: Option<Transfer>,
    last_sync: u32,
    recovery_requested: Option<u32>,
    recovery_after: u64,
    unverified_restores: u8,
    clock_slew: crate::clock::Slew,
}

struct Transfer {
    snapshot: Snapshot,
    started: u64,
    cursor: u64,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Input {
    pub slot: u8,
    pub time: u32,
    pub body: [u8; 16],
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum InputDecision {
    Accepted,
    Revision,
    Duplicate,
    NotPlaying,
    OutsideWindow,
    Capacity,
}

/// A clock anchored by a (wall time, game time) pair. Subtracting a game
/// timestamp from wall time would underflow for an early bootstrap.
struct Clock {
    wall: u64,
    game: u32,
}
impl Clock {
    fn at(&self, now: u64) -> Result<u32, &'static str> {
        u32::try_from(u64::from(self.game) + now.saturating_sub(self.wall))
            .map_err(|_| "match clock exhausted")
    }
}

pub struct Coordinator {
    roster: u8,
    required: usize,
    players: BTreeMap<u8, Player>,
    clock: Option<Clock>,
    baseline: Option<Snapshot>,
    reference: u32,
    bootstrap_started: u64,
    activation: Option<u32>,
    history: VecDeque<Input>,
    match_seconds: u16,
    finished: bool,
    final_snapshot: Option<Snapshot>,
    recovery: crate::recovery::Recovery,
    journal: Journal,
    failures: Vec<(u8, &'static str)>,
    policy_after: u64,
    notices: Vec<(u8, &'static str, u32)>,
}
impl Coordinator {
    pub fn new(roster: u8, required: u8) -> Result<Self, &'static str> {
        Self::with_duration(roster, required, crate::setup::MATCH_SECONDS)
    }

    pub fn with_duration(
        roster: u8,
        required: u8,
        match_seconds: u16,
    ) -> Result<Self, &'static str> {
        if !(1..=20).contains(&roster) || required == 0 || required > roster {
            return Err("invalid roster or starting cohort size");
        }
        if match_seconds == 0 {
            return Err("match duration must be positive");
        }
        Ok(Self {
            roster,
            required: usize::from(required),
            players: BTreeMap::new(),
            clock: None,
            baseline: None,
            reference: 0,
            bootstrap_started: 0,
            activation: None,
            history: VecDeque::new(),
            match_seconds,
            finished: false,
            final_snapshot: None,
            recovery: crate::recovery::Recovery::new(roster),
            journal: Journal::default(),
            failures: vec![],
            policy_after: 0,
            notices: vec![],
        })
    }

    pub fn admit(&mut self, slot: u8) -> Result<(), &'static str> {
        if slot >= self.roster || self.players.contains_key(&slot) {
            return Err("invalid or occupied slot");
        }
        if self.finished
            || (self.activation.is_none()
                && (self.clock.is_some() || self.players.len() == self.required))
        {
            return Err("initial cohort full or match finishing");
        }
        self.players.insert(
            slot,
            Player {
                prepared: false,
                ready: false,
                initial: None,
                stage: Stage::Loading,
                reference: 0,
                active_since: None,
                transfer: None,
                last_sync: 0,
                recovery_requested: None,
                recovery_after: 0,
                unverified_restores: 0,
                clock_slew: crate::clock::Slew::default(),
            },
        );
        Ok(())
    }

    pub fn prepared(&mut self, slot: u8) -> Result<(), &'static str> {
        self.players.get_mut(&slot).ok_or("unknown slot")?.prepared = true;
        Ok(())
    }

    pub fn entered(&self, slot: u8) -> bool {
        self.players
            .get(&slot)
            .is_some_and(|p| p.active_since.is_some())
    }

    pub fn participant_mask(&self) -> u32 {
        self.players.iter().fold(0, |mask, (&slot, player)| {
            mask | if player.active_since.is_some() {
                1 << slot
            } else {
                0
            }
        })
    }

    pub fn ready(&mut self, slot: u8) -> Result<(), &'static str> {
        let player = self.players.get_mut(&slot).ok_or("unknown slot")?;
        if !player.prepared {
            return Err("ready before static setup");
        }
        player.ready = true;
        Ok(())
    }

    pub fn snapshot(&mut self, slot: u8, snapshot: Snapshot) -> Result<(), &'static str> {
        let player = self.players.get_mut(&slot).ok_or("unknown slot")?;
        // Loading clients supply only their locally created empty world.
        if player.stage != Stage::Loading {
            return Ok(());
        }
        if !player.prepared {
            return Err("snapshot before static setup");
        }
        validate_empty(&snapshot)?;
        if let Some(initial) = &player.initial {
            if initial != &snapshot {
                return Err("initial state changed while loading");
            }
        } else {
            player.initial = Some(snapshot);
        }
        Ok(())
    }

    pub fn uploaded(
        &mut self,
        slot: u8,
        snapshot: Snapshot,
        now: u64,
    ) -> Result<Option<crate::recovery::SnapshotDecision>, &'static str> {
        if self
            .players
            .get(&slot)
            .is_some_and(|p| p.stage == Stage::Playing)
        {
            let game = self.game_time(now)?;
            Ok(Some(self.recovery.snapshot(slot, snapshot, game)?))
        } else {
            self.snapshot(slot, snapshot)?;
            Ok(None)
        }
    }

    pub fn hash(
        &mut self,
        slot: u8,
        body: &[u8],
        now: u64,
    ) -> Result<Vec<crate::recovery::Comparison>, &'static str> {
        if body.len() != 8 {
            return Err("invalid CRC report length");
        }
        if self
            .players
            .get(&slot)
            .is_none_or(|p| p.stage != Stage::Playing || read_u32(body, 0) <= p.last_sync)
        {
            return Ok(vec![]);
        }
        let game = self.game_time(now)?;
        self.recovery
            .hash(slot, read_u32(body, 0), read_u32(body, 4), game)
    }

    pub fn reference_state(&self) -> Option<(u8, &Snapshot)> {
        self.recovery.corroborated()
    }

    pub fn final_snapshot(&self) -> Option<&Snapshot> {
        self.finished
            .then_some(self.final_snapshot.as_ref())
            .flatten()
    }

    /// Local lobby routing, not a game-wire message. Count loading and
    /// restoring peers as occupied too; a new transport cannot replace them.
    pub fn routing_status(&self, now: u64) -> Result<(&'static str, u32), &'static str> {
        let occupied = self
            .players
            .keys()
            .fold(0, |mask, slot| mask | (1u32 << slot));
        let past_end = match self.end_time()? {
            Some(end) => self.game_time(now)? >= end,
            None => false,
        };
        let phase = if self.finished || past_end {
            "finished"
        } else if self.activation.is_some() {
            "running"
        } else if self.clock.is_some() {
            "starting"
        } else {
            "waiting"
        };
        Ok((phase, occupied))
    }

    /// Called after processing transport ACKs. Every cohort member must finish
    /// receiving the same baseline before any member gets an activation event.
    pub fn tick(&mut self, now: u64, idle_slots: &[u8]) -> Result<Vec<Delivery>, &'static str> {
        self.tick_with_replay_idle(now, idle_slots, idle_slots)
    }

    /// Replay ACKs must advance independently of fragmented state ACKs. An
    /// incomplete 53 must not hold fresh 54/56/57 events past the engine's
    /// rollback window. `idle_slots` still gates activation/completion.
    pub fn tick_with_replay_idle(
        &mut self,
        now: u64,
        idle_slots: &[u8],
        replay_idle_slots: &[u8],
    ) -> Result<Vec<Delivery>, &'static str> {
        let mut out = Vec::new();
        if self.clock.is_none()
            && self.players.len() == self.required
            && self
                .players
                .values()
                .all(|p| p.ready && p.initial.is_some())
        {
            let baseline = self
                .players
                .values()
                .next()
                .unwrap()
                .initial
                .as_ref()
                .unwrap()
                .clone();
            let target = baseline
                .time
                .checked_add(200)
                .ok_or("invalid baseline time")?;
            self.reference = self
                .reference
                .checked_add(1)
                .ok_or("clock reference exhausted")?;
            self.clock = Some(Clock {
                wall: now,
                game: target,
            });
            self.baseline = Some(baseline);
            self.bootstrap_started = now;
            for (&slot, player) in &mut self.players {
                player.stage = Stage::AwaitClock;
                player.reference = self.reference;
                player.clock_slew.reset(now);
                // Only the selected common baseline remains retained.
                player.initial = None;
                out.push(Delivery {
                    slot,
                    opcode: 0x52,
                    body: [self.reference.to_le_bytes(), target.to_le_bytes()].concat(),
                });
            }
        }
        if self.clock.is_some() && self.activation.is_none() {
            if now.saturating_sub(self.bootstrap_started) > BOOTSTRAP_TIMEOUT {
                return Err("cohort bootstrap timed out");
            }
            if self
                .players
                .values()
                .all(|p| p.stage == Stage::AwaitStateAck)
                && self.players.keys().all(|slot| idle_slots.contains(slot))
            {
                let time = self
                    .game_time(now)?
                    .checked_add(249)
                    .ok_or("match clock exhausted")?
                    / 50
                    * 50;
                self.activation = Some(time);
                for player in self.players.values_mut() {
                    player.stage = Stage::Playing;
                    player.active_since = Some(time);
                }
                for &entering in self.players.keys() {
                    self.recovery.membership(time, entering, true)?;
                    let body = [vec![entering], time.to_le_bytes().to_vec()].concat();
                    self.journal.push(Event {
                        time,
                        opcode: 0x56,
                        body: body.clone(),
                    })?;
                    out.extend(self.broadcast(0x56, &body, None));
                }
            }
        }
        if self.clock.is_some() {
            let current = self.game_time(now)?;
            self.prune(current);
            // Fixed setup has wait_player_percent=0 and a common activation.
            // timelimit_rule_core starts its countdown at that activation;
            // rule_completed becomes true countdown+match_length later.
            if !self.finished {
                if let Some(end) = self.end_time()? {
                    // A checked snapshot can also establish the native
                    // gather-all-batteries objective before the time limit.
                    // This uses the same explicit donor trust as recovery;
                    // the server does not independently simulate deposits.
                    if let Some((_, snapshot)) = self.recovery.corroborated() {
                        if let Ok(stats) = crate::results::Stats::from_world(
                            &snapshot.body,
                            self.roster,
                            crate::setup::VICTORY_ITEMS,
                        ) {
                            let match_start = self.activation.unwrap()
                                + u32::from(crate::setup::COUNTDOWN_SECONDS) * 1000;
                            let objective = snapshot.time >= match_start
                                && stats
                                    .objective_winner(crate::setup::VICTORY_ITEMS)
                                    .is_some();
                            if snapshot.time >= end || objective {
                                self.final_snapshot = Some(snapshot.clone());
                            }
                        }
                    }
                    if current >= end || self.final_snapshot.is_some() {
                        // Bounded failure: do not keep clients in the world
                        // forever if no eligible final donor state arrives.
                        if self.final_snapshot.is_none() && current < end.saturating_add(10_000) {
                            let playing: Vec<_> = self
                                .players
                                .iter()
                                .filter(|(_, p)| p.stage == Stage::Playing)
                                .map(|(&slot, _)| slot)
                                .collect();
                            if let Some(slot) = self.recovery.tick(now, current, &playing) {
                                out.push(Delivery {
                                    slot,
                                    opcode: 0x59,
                                    body: vec![],
                                });
                            }
                            return Ok(out);
                        }
                        self.finished = true;
                        for (&slot, player) in &mut self.players {
                            player.stage = Stage::Finished;
                            // process_player_left_match 0x1a3098 immediately
                            // closes the local match with reason 3. Do NOT send
                            // this early with a future simulation timestamp.
                            out.push(Delivery {
                                slot,
                                opcode: 0x57,
                                // Final snapshot acquisition may take seconds.
                                // The original deadline can already be outside
                                // client history; stamp this departure now.
                                body: [vec![slot], (current / 50 * 50).to_le_bytes().to_vec()]
                                    .concat(),
                            });
                        }
                    }
                }
            }
            if !self.finished {
                if self.activation.is_some() {
                    if now >= self.policy_after {
                        self.policy_after = now.saturating_add(100);
                        let playing: Vec<_> = self
                            .players
                            .iter()
                            .filter(|(_, p)| p.stage == Stage::Playing)
                            .map(|(&s, _)| s)
                            .collect();
                        for &slot in &playing {
                            let p = self.players.get_mut(&slot).unwrap();
                            if p.unverified_restores > 0
                                && self.recovery.agrees(
                                    slot,
                                    p.last_sync.saturating_add(1000),
                                    current,
                                )
                            {
                                p.unverified_restores = 0;
                                self.notices.push((
                                    slot,
                                    "post-restore agreement verified",
                                    current,
                                ));
                            }
                        }
                        for (slot, time) in self.recovery.suspects(current, &playing) {
                            let p = self.players.get_mut(&slot).unwrap();
                            if now >= p.recovery_after && p.recovery_requested.is_none() {
                                p.recovery_requested = Some(time);
                                self.notices.push((slot, "sustained disagreement", time));
                            }
                        }
                    }
                    out.extend(self.advance_joiners(
                        now,
                        current,
                        idle_slots,
                        replay_idle_slots,
                    )?);
                }
                let playing: Vec<_> = self
                    .players
                    .iter()
                    .filter(|(_, p)| p.stage == Stage::Playing)
                    .map(|(&slot, _)| slot)
                    .collect();
                if let Some(slot) = self.recovery.tick(now, current, &playing) {
                    out.push(Delivery {
                        slot,
                        opcode: 0x59,
                        body: vec![],
                    });
                }
            }
        }
        Ok(out)
    }

    pub fn clock_observation(
        &mut self,
        slot: u8,
        body: &[u8],
        now: u64,
        round_trip_ms: Option<u64>,
    ) -> Result<Vec<Delivery>, &'static str> {
        if body.len() != 4 {
            return Err("invalid clock observation");
        }
        if self.players.get(&slot).ok_or("unknown slot")?.stage != Stage::Playing || self.finished {
            return Ok(vec![]);
        }
        let game = self.game_time(now)?;
        let player = self.players.get_mut(&slot).unwrap();
        Ok(player
            .clock_slew
            .observe(read_u32(body, 0), game, now, round_trip_ms)
            .map(|offset| {
                vec![Delivery {
                    slot,
                    opcode: 0x55,
                    body: offset.to_le_bytes().to_vec(),
                }]
            })
            .unwrap_or_default())
    }

    pub fn clock_reply(&mut self, slot: u8, body: &[u8]) -> Result<Vec<Delivery>, &'static str> {
        if body.len() != 8 {
            return Err("invalid clock response");
        }
        let player = self.players.get_mut(&slot).ok_or("unknown slot")?;
        if read_u32(body, 0) != player.reference {
            // Old reliable-unordered replies can survive a newer transfer.
            return Ok(vec![]);
        }
        // Client 43 is reliable unordered; retries are harmless after progress.
        if player.stage != Stage::AwaitClock {
            return Ok(Vec::new());
        }
        if player.transfer.is_some() {
            // 52 clears world-state history, but retains input/event history.
            // Preload and ACK accepted events while the cleared world cannot
            // advance beyond them. Initial empty-cohort bootstrap is unchanged.
            player.stage = Stage::AwaitPreloadAck;
            return Ok(vec![]);
        }
        let snapshot = player
            .transfer
            .as_ref()
            .map(|t| &t.snapshot)
            .or(self.baseline.as_ref())
            .ok_or("missing common baseline")?;
        let body = [snapshot.time.to_le_bytes().as_slice(), &snapshot.body].concat();
        player.last_sync = snapshot.time;
        player.stage = Stage::AwaitStateAck;
        Ok(vec![Delivery {
            slot,
            opcode: 0x53,
            body,
        }])
    }

    pub fn game_time(&self, now: u64) -> Result<u32, &'static str> {
        self.clock
            .as_ref()
            .ok_or("match clock not started")?
            .at(now)
    }

    pub fn end_time(&self) -> Result<Option<u32>, &'static str> {
        self.activation
            .map(|time| {
                time.checked_add(
                    (u32::from(crate::setup::COUNTDOWN_SECONDS) + u32::from(self.match_seconds))
                        * 1000,
                )
                .ok_or("match end time exhausted")
            })
            .transpose()
    }

    /// No sender echo in this initial experiment. Local simulation already has
    /// its inputs. Capture evidence does not establish the deployed echo policy.
    /// Different payloads for a timestamp are accepted in arrival order; exact
    /// previously seen revisions are suppressed, including delayed old retries.
    pub fn input(
        &mut self,
        slot: u8,
        body: &[u8],
        now: u64,
    ) -> Result<(InputDecision, Vec<Delivery>), &'static str> {
        if body.len() != 16 {
            return Err("invalid input length");
        }
        for offset in [0, 4] {
            if !f32::from_le_bytes(body[offset..offset + 4].try_into().unwrap()).is_finite() {
                return Err("nonfinite input rotation");
            }
        }
        if self.players.get(&slot).is_none_or(|p| {
            p.stage != Stage::Playing && !(p.transfer.is_some() && p.active_since.is_some())
        }) {
            return Ok((InputDecision::NotPlaying, vec![]));
        }
        let time = read_u32(body, 12);
        let current = self.game_time(now)?;
        if self
            .end_time()?
            .is_some_and(|end| current >= end || time >= end)
        {
            return Ok((InputDecision::OutsideWindow, vec![]));
        }
        self.prune(current);
        if time < self.players[&slot].active_since.unwrap()
            || time < current.saturating_sub(HISTORY_MS)
            || time > current.saturating_add(INPUT_LEAD_MS)
            || time % 50 != 0
        {
            return Ok((InputDecision::OutsideWindow, vec![]));
        }
        let revisions: Vec<_> = self
            .history
            .iter()
            .filter(|i| i.slot == slot && i.time == time)
            .collect();
        if revisions.iter().any(|i| i.body.as_slice() == body) {
            return Ok((InputDecision::Duplicate, vec![]));
        }
        if revisions.len() >= MAX_REVISIONS || self.history.len() >= MAX_HISTORY {
            return Ok((InputDecision::Capacity, vec![]));
        }
        let decision = if revisions.is_empty() {
            InputDecision::Accepted
        } else {
            InputDecision::Revision
        };
        self.history.push_back(Input {
            slot,
            time,
            body: body.try_into().unwrap(),
        });
        self.recovery.input_changed(time);
        let mut relay = vec![slot];
        relay.extend(body);
        self.journal.push(Event {
            time,
            opcode: 0x54,
            body: relay.clone(),
        })?;
        for (&joining, player) in &mut self.players {
            if player
                .transfer
                .as_ref()
                .is_some_and(|t| time <= t.snapshot.time)
            {
                self.failures
                    .push((joining, "accepted input invalidated joining snapshot"));
            } else if player.stage == Stage::Playing && time <= player.last_sync {
                // This peer cannot roll back across its full-state boundary.
                // A new donor state must include the newly accepted old input.
                player.recovery_requested = Some(player.last_sync);
            }
        }
        Ok((decision, self.broadcast(0x54, &relay, Some(slot))))
    }

    /// If a cohort loses a member during bootstrap, its remaining members must
    /// disconnect too. Starting a subset could leave different membership on
    /// different clients. The adapter handles that explicit failure boundary.
    pub fn remove(&mut self, slot: u8, now: u64) -> Result<Vec<Delivery>, &'static str> {
        let Some(removed) = self.players.remove(&slot) else {
            return Ok(vec![]);
        };
        self.recovery.departed(slot);
        if self.clock.is_some() && self.activation.is_none() && !self.players.is_empty() {
            return Err("member lost during shared bootstrap");
        }
        let out = if removed.active_since.is_some() && !self.finished && !self.players.is_empty() {
            let time = self
                .game_time(now)?
                .checked_add(249)
                .ok_or("match clock exhausted")?
                / 50
                * 50;
            self.recovery.membership(time, slot, false)?;
            let body = [vec![slot], time.to_le_bytes().to_vec()].concat();
            self.journal.push(Event {
                time,
                opcode: 0x57,
                body: body.clone(),
            })?;
            self.broadcast(0x57, &body, None)
        } else {
            vec![]
        };
        if self.players.is_empty() {
            self.clock = None;
            self.baseline = None;
            self.activation = None;
            self.history.clear();
            self.finished = false;
            self.final_snapshot = None;
            self.recovery = crate::recovery::Recovery::new(self.roster);
            self.journal = Journal::default();
            self.policy_after = 0;
        }
        Ok(out)
    }

    fn broadcast(&self, opcode: u8, body: &[u8], except: Option<u8>) -> Vec<Delivery> {
        self.players
            .iter()
            .filter(|(slot, p)| Some(**slot) != except && p.stage == Stage::Playing)
            .map(|(&slot, _)| Delivery {
                slot,
                opcode,
                body: body.to_vec(),
            })
            .collect()
    }

    fn prune(&mut self, time: u32) {
        // Arrival order is not timestamp order: delayed inputs can sit behind
        // newer ones, so popping only the front would retain stale revisions.
        let oldest = time.saturating_sub(HISTORY_MS);
        self.history.retain(|i| i.time >= oldest);
        self.journal.prune(time);
    }

    pub fn take_failures(&mut self) -> Vec<(u8, &'static str)> {
        std::mem::take(&mut self.failures)
    }

    pub fn take_notices(&mut self) -> Vec<(u8, &'static str, u32)> {
        std::mem::take(&mut self.notices)
    }

    /// Local operator request uses exactly the normal restore path and limits.
    pub fn request_recovery(&mut self, slot: u8, now: u64) -> Result<(), &'static str> {
        let game = self.game_time(now)?;
        if self.finished || self.recovery.reference().is_none_or(|r| r == slot) {
            return Err("no distinct reference for active recovery");
        }
        let p = self.players.get_mut(&slot).ok_or("unknown recovery slot")?;
        if p.stage != Stage::Playing || now < p.recovery_after {
            return Err("recovery already active or cooling down");
        }
        p.recovery_requested = Some(game.saturating_sub(1000).max(p.last_sync));
        self.notices
            .push((slot, "operator recovery requested", game));
        Ok(())
    }

    fn advance_joiners(
        &mut self,
        now: u64,
        game: u32,
        idle: &[u8],
        replay_idle: &[u8],
    ) -> Result<Vec<Delivery>, &'static str> {
        let mut out = Vec::new();
        let slots: Vec<_> = self.players.keys().copied().collect();
        for slot in slots {
            if self.failures.iter().any(|(failed, _)| *failed == slot) {
                continue;
            }
            let p = &self.players[&slot];
            if (p.stage == Stage::Loading && p.ready && p.initial.is_some())
                || (p.stage == Stage::Playing
                    && p.recovery_requested.is_some()
                    && now >= p.recovery_after
                    && idle.contains(&slot))
            {
                let Some((donor, snapshot)) = self.recovery.corroborated() else {
                    continue;
                };
                // Use a fresh donor horizon, not a five-second-old periodic
                // sample: the engine's accepted input window is much shorter
                // than the server's retained journal.
                let active = p.active_since.is_some();
                if active && p.unverified_restores >= 3 {
                    self.failures
                        .push((slot, "repeated active recovery did not converge"));
                    continue;
                }
                if game.saturating_sub(snapshot.time) > 1000
                    || donor == slot
                    || (read_u32(&snapshot.body, 0) & (1 << slot) != 0) != active
                    || p.recovery_requested
                        .is_some_and(|time| snapshot.time <= time)
                {
                    continue;
                }
                let snapshot = snapshot.clone();
                self.reference = self
                    .reference
                    .checked_add(1)
                    .ok_or("clock reference exhausted")?;
                let p = self.players.get_mut(&slot).unwrap();
                p.reference = self.reference;
                p.clock_slew.reset(now);
                p.initial = None;
                p.stage = Stage::AwaitClock;
                p.recovery_requested = None;
                if active {
                    p.recovery_after = now.saturating_add(15_000);
                    p.unverified_restores += 1;
                }
                self.notices.push((
                    slot,
                    if active {
                        "active restore started"
                    } else {
                        "late join started"
                    },
                    snapshot.time,
                ));
                p.transfer = Some(Transfer {
                    snapshot,
                    started: now,
                    cursor: 0,
                });
                self.recovery.forget_hashes(slot);
                out.push(Delivery {
                    slot,
                    opcode: 0x52,
                    body: [self.reference.to_le_bytes(), game.to_le_bytes()].concat(),
                });
                continue;
            }
            let Some(transfer) = &p.transfer else {
                continue;
            };
            if now.saturating_sub(transfer.started) > 5000 {
                self.failures
                    .push((slot, "joining snapshot transfer timed out"));
                continue;
            }
            if !matches!(p.stage, Stage::AwaitPreloadAck | Stage::AwaitStateAck)
                || !replay_idle.contains(&slot)
            {
                continue;
            }
            let Some((cursor, events)) =
                self.journal.after(transfer.cursor, transfer.snapshot.time)
            else {
                self.failures.push((
                    slot,
                    "joining snapshot no longer has complete replay history",
                ));
                continue;
            };
            let p = self.players.get_mut(&slot).unwrap();
            p.transfer.as_mut().unwrap().cursor = cursor;
            if !events.is_empty() {
                self.notices.push((
                    slot,
                    "replay batch queued through",
                    events.iter().map(|e| e.time).max().unwrap(),
                ));
                out.extend(events.into_iter().map(|e| Delivery {
                    slot,
                    opcode: e.opcode,
                    body: e.body,
                }));
                continue;
            }
            if p.stage == Stage::AwaitPreloadAck {
                // All replay accepted so far is acknowledged before 53 can
                // restore and advance the world. Inputs arriving during its
                // transfer are sent above without waiting for state ACKs.
                let snapshot = &p.transfer.as_ref().unwrap().snapshot;
                p.last_sync = snapshot.time;
                p.stage = Stage::AwaitStateAck;
                out.push(Delivery {
                    slot,
                    opcode: 0x53,
                    body: [snapshot.time.to_le_bytes().as_slice(), &snapshot.body].concat(),
                });
                continue;
            }
            if !idle.contains(&slot) {
                continue;
            }
            // No unacknowledged replay or unsent accepted events remain.
            // From this point live broadcasts include this peer atomically.
            let time = game.checked_add(249).ok_or("match clock exhausted")? / 50 * 50;
            p.stage = Stage::Playing;
            let active = p.active_since.is_some();
            let baseline = p.transfer.as_ref().unwrap().snapshot.time;
            p.transfer = None;
            self.notices.push((
                slot,
                if active {
                    "active restore replay acknowledged"
                } else {
                    "late join replay acknowledged"
                },
                baseline,
            ));
            if active {
                continue;
            }
            p.active_since = Some(time);
            self.recovery.membership(time, slot, true)?;
            let body = [vec![slot], time.to_le_bytes().to_vec()].concat();
            self.journal.push(Event {
                time,
                opcode: 0x56,
                body: body.clone(),
            })?;
            out.extend(self.broadcast(0x56, &body, None));
        }
        Ok(out)
    }
}

fn read_u32(body: &[u8], offset: usize) -> u32 {
    u32::from_le_bytes(body[offset..offset + 4].try_into().unwrap())
}

/// Empty masks need no compressed-animation parser. Check all four sized
/// blocks (bullets, statistics, objects, rules) and exact end of payload. This
/// is boundary validation, not semantic validation of opaque engine objects.
fn validate_empty(snapshot: &Snapshot) -> Result<(), &'static str> {
    if snapshot.time == 0
        || snapshot.time > 1000
        || snapshot.time % 50 != 0
        || snapshot.body.len() < 12
        || snapshot.body.len() > MAX_MESSAGE - 4
        || read_u32(&snapshot.body, 0) != 0
    {
        return Err("ineligible initial snapshot");
    }
    crate::state::inspect(&snapshot.body, 20)?;
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;
    fn empty(value: u8) -> Snapshot {
        // Structural test fixture only, never sent to a real engine.
        Snapshot {
            time: 50,
            body: [vec![0; 4], vec![1, 0, value], vec![0; 6]].concat(),
        }
    }
    fn loaded(c: &mut Coordinator, slot: u8) {
        c.admit(slot).unwrap();
        c.prepared(slot).unwrap();
        c.ready(slot).unwrap();
        c.snapshot(slot, empty(slot)).unwrap();
    }
    fn running() -> Coordinator {
        let mut c = Coordinator::new(2, 2).unwrap();
        loaded(&mut c, 0);
        loaded(&mut c, 1);
        c.tick(0, &[]).unwrap();
        for slot in 0..2 {
            c.clock_reply(slot, &[1, 0, 0, 0, 250, 0, 0, 0]).unwrap();
        }
        c.tick(50, &[0, 1]).unwrap();
        c
    }

    #[test]
    fn clock_slews_only_the_playing_peer_without_replacing_state() {
        let mut c = Coordinator::new(2, 2).unwrap();
        c.admit(0).unwrap();
        assert!(
            c.clock_observation(0, &1u32.to_le_bytes(), 1000, Some(10))
                .unwrap()
                .is_empty()
        );
        assert!(c.clock_observation(0, &[], 1000, Some(10)).is_err());
        let mut c = running();
        let baseline = c.baseline.as_ref().unwrap().clone();
        let activation = c.activation;
        for now in [5000, 6000] {
            let reported = c.game_time(now).unwrap() - 200;
            assert!(
                c.clock_observation(1, &reported.to_le_bytes(), now, Some(40))
                    .unwrap()
                    .is_empty()
            );
        }
        let reported = c.game_time(7000).unwrap() - 200;
        assert_eq!(
            c.clock_observation(1, &reported.to_le_bytes(), 7000, Some(40))
                .unwrap(),
            vec![Delivery {
                slot: 1,
                opcode: 0x55,
                body: 100i16.to_le_bytes().to_vec()
            }]
        );
        assert_eq!(c.activation, activation);
        assert_eq!(c.baseline.as_ref().unwrap().body, baseline.body);
        assert_eq!(c.players[&1].stage, Stage::Playing);
        c.players.get_mut(&1).unwrap().stage = Stage::AwaitClock;
        assert!(
            c.clock_observation(1, &reported.to_le_bytes(), 8000, Some(40))
                .unwrap()
                .is_empty()
        );
        c.players.get_mut(&1).unwrap().stage = Stage::Playing;
        c.finished = true;
        assert!(
            c.clock_observation(1, &reported.to_le_bytes(), 9000, Some(40))
                .unwrap()
                .is_empty()
        );
    }

    #[test]
    fn all_clients_restore_one_baseline_before_shared_activation() {
        let mut c = Coordinator::new(2, 2).unwrap();
        loaded(&mut c, 1);
        assert!(c.tick(0, &[1]).unwrap().is_empty());
        loaded(&mut c, 0);
        let clocks = c.tick(1, &[]).unwrap();
        assert_eq!(clocks.len(), 2);
        assert_eq!(clocks[0].body, [1, 0, 0, 0, 250, 0, 0, 0]);
        assert_eq!(clocks[0].body, clocks[1].body);
        assert_eq!(c.game_time(11), Ok(260));
        assert!(c.clock_reply(0, &[0; 8]).unwrap().is_empty());
        let a = c.clock_reply(0, &[1, 0, 0, 0, 250, 0, 0, 0]).unwrap();
        assert!(c.tick(40, &[0, 1]).unwrap().is_empty());
        let b = c.clock_reply(1, &[1, 0, 0, 0, 250, 0, 0, 0]).unwrap();
        assert_eq!(a[0].body, b[0].body);
        assert_eq!(&a[0].body[4..], empty(0).body);
        assert!(c.tick(40, &[0]).unwrap().is_empty());
        let events = c.tick(51, &[0, 1]).unwrap();
        assert_eq!(events.len(), 4);
        assert!(
            events
                .iter()
                .all(|e| e.opcode == 0x56 && read_u32(&e.body, 1) == 500)
        );
        assert!(c.tick(100, &[0, 1]).unwrap().is_empty());
        assert!(c.admit(0).is_err());
    }

    #[test]
    fn relay_has_authenticated_slot_and_deduplicates_old_revisions() {
        let mut c = running();
        let mut input = [0; 16];
        input[12..].copy_from_slice(&500u32.to_le_bytes());
        let (decision, deliveries) = c.input(0, &input, 250).unwrap();
        assert_eq!(decision, InputDecision::Accepted);
        assert_eq!(
            deliveries,
            vec![Delivery {
                slot: 1,
                opcode: 0x54,
                body: [vec![0], input.to_vec()].concat()
            }]
        );
        let original = input;
        input[8] = 1;
        assert_eq!(c.input(0, &input, 251).unwrap().0, InputDecision::Revision);
        assert_eq!(
            c.input(0, &original, 252).unwrap(),
            (InputDecision::Duplicate, vec![])
        );
        input[..4].copy_from_slice(&f32::NAN.to_le_bytes());
        assert!(c.input(0, &input, 252).is_err());
        input[..4].fill(0);
        input[12..].copy_from_slice(&5000u32.to_le_bytes());
        assert_eq!(
            c.input(0, &input, 252).unwrap().0,
            InputDecision::OutsideWindow
        );
        assert_eq!(
            c.input(0, &original, 11000).unwrap().0,
            InputDecision::OutsideWindow
        );
        assert!(c.history.is_empty());
    }

    #[test]
    fn initial_state_boundaries_and_bootstrap_failure_are_explicit() {
        let mut bad = empty(0);
        bad.body.push(0);
        assert!(validate_empty(&bad).is_err());
        bad = empty(0);
        bad.body[4] = 255;
        assert!(validate_empty(&bad).is_err());
        bad = empty(0);
        bad.body[0] = 1;
        assert!(validate_empty(&bad).is_err());
        let mut c = Coordinator::new(2, 2).unwrap();
        loaded(&mut c, 0);
        loaded(&mut c, 1);
        c.tick(0, &[]).unwrap();
        assert!(c.tick(BOOTSTRAP_TIMEOUT + 1, &[]).is_err());
        assert!(c.remove(0, 100).is_err());
    }

    #[test]
    fn lobby_status_covers_bootstrap_slot_reuse_and_deadline_before_timer_tick() {
        let mut c = Coordinator::new(2, 2).unwrap();
        assert_eq!(c.routing_status(0), Ok(("waiting", 0)));
        loaded(&mut c, 0);
        assert_eq!(c.routing_status(0), Ok(("waiting", 1)));
        loaded(&mut c, 1);
        c.tick(0, &[]).unwrap();
        assert_eq!(c.routing_status(0), Ok(("starting", 3)));
        for slot in 0..2 {
            c.clock_reply(slot, &[1, 0, 0, 0, 250, 0, 0, 0]).unwrap();
        }
        c.tick(50, &[0, 1]).unwrap();
        assert_eq!(c.routing_status(50), Ok(("running", 3)));
        c.remove(1, 1000).unwrap();
        assert_eq!(c.routing_status(1000), Ok(("running", 1)));
        c.admit(1).unwrap();
        assert_eq!(c.routing_status(1000), Ok(("running", 3)));
        let end_wall = u64::from(c.end_time().unwrap().unwrap() - 250);
        assert_eq!(c.routing_status(end_wall), Ok(("finished", 3)));
        c.tick(end_wall, &[]).unwrap();
        assert_eq!(c.routing_status(end_wall), Ok(("finished", 3)));
    }

    #[test]
    fn departure_is_shared_and_empty_match_can_restart() {
        let mut c = running();
        let leave = c.remove(0, 250).unwrap();
        assert_eq!(
            leave,
            vec![Delivery {
                slot: 1,
                opcode: 0x57,
                body: vec![0, 188, 2, 0, 0]
            }]
        );
        c.admit(0).unwrap(); // Reconnect may load while the other player runs.
        assert!(c.remove(0, 260).unwrap().is_empty()); // Never activated again.
        c.remove(1, 300).unwrap();
        loaded(&mut c, 0);
        loaded(&mut c, 1);
        let clocks = c.tick(500, &[]).unwrap();
        assert_eq!(read_u32(&clocks[0].body, 0), 2);
        assert_eq!(c.game_time(500), Ok(250));
    }

    #[test]
    fn time_limit_closes_each_local_slot_once_and_rejects_late_inputs() {
        let mut c = running();
        let end = c.end_time().unwrap().unwrap();
        assert_eq!(end, 610500); // activation 500 + countdown 10000 + play 600000
        let wall_end = u64::from(end - 250);
        assert!(
            c.tick(wall_end - 1, &[0, 1])
                .unwrap()
                .iter()
                .all(|d| d.opcode == 0x59)
        );
        let mut body = [0; 16];
        body[12..].copy_from_slice(&(end - 50).to_le_bytes());
        assert_eq!(
            c.input(0, &body, wall_end - 1).unwrap().0,
            InputDecision::Accepted
        );
        body[12..].copy_from_slice(&end.to_le_bytes());
        assert_eq!(
            c.input(0, &body, wall_end - 1).unwrap().0,
            InputDecision::OutsideWindow
        );
        // Even if an input is received before this iteration's timer tick,
        // the finished match cannot accept a retroactive action.
        body[12..].copy_from_slice(&(end - 50).to_le_bytes());
        assert_eq!(
            c.input(0, &body, wall_end).unwrap().0,
            InputDecision::OutsideWindow
        );
        assert!(
            c.tick(wall_end, &[])
                .unwrap()
                .iter()
                .all(|d| d.opcode == 0x59)
        );
        // No valid final snapshot in this synthetic test: bounded fallback.
        let wall_end = wall_end + 10_000;
        let finish = c.tick(wall_end, &[]).unwrap();
        assert_eq!(finish.len(), 2);
        for (slot, delivery) in finish.iter().enumerate() {
            assert_eq!(delivery.slot, slot as u8);
            assert_eq!(delivery.opcode, 0x57);
            assert_eq!(delivery.body[0], slot as u8);
            assert_eq!(read_u32(&delivery.body, 1), end + 10_000);
        }
        assert!(c.tick(wall_end + 500, &[0, 1]).unwrap().is_empty());
        assert_eq!(
            c.input(0, &body, wall_end + 1).unwrap().0,
            InputDecision::NotPlaying
        );
        assert!(c.remove(0, wall_end + 1).unwrap().is_empty());
        assert!(c.remove(1, wall_end + 2).unwrap().is_empty());
        assert_eq!(c.end_time().unwrap(), None);
        loaded(&mut c, 0);
        loaded(&mut c, 1);
        assert_eq!(c.tick(wall_end + 3, &[]).unwrap().len(), 2);
        assert!(!c.finished);
        assert!(Coordinator::with_duration(2, 2, 0).is_err());
    }

    fn statistics_snapshot(time: u32, points: [u8; 2]) -> Snapshot {
        // Two inactive-value player stats, curing statuses, five victory items.
        let mut stats = vec![];
        for _ in 0..2 {
            stats.extend([0; 48 + 2 + 4]);
            stats.push(255);
            stats.extend([0; 2 + 4 + 7]);
        }
        stats.extend([0; 14 + 70]);
        stats.extend(points);
        let mut body = vec![3, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0];
        body.extend((stats.len() as u16).to_le_bytes());
        body.extend(stats);
        body.extend([0; 4]);
        Snapshot { time, body }
    }

    #[test]
    fn deadline_waits_for_checked_final_snapshot_before_local_finish() {
        let mut c = running();
        let end = c.end_time().unwrap().unwrap();
        let now = u64::from(end - 250);
        let request = c.tick(now, &[0, 1]).unwrap();
        assert!(request.iter().any(|d| d.opcode == 0x59 && d.slot == 0));
        assert!(request.iter().all(|d| d.opcode != 0x57));
        let snapshot = statistics_snapshot(end, [0, 0]);
        c.uploaded(0, snapshot.clone(), now + 50).unwrap();
        assert!(
            c.tick(now + 50, &[0, 1])
                .unwrap()
                .iter()
                .all(|d| d.opcode != 0x57)
        );
        let hash = [end.to_le_bytes(), snapshot.crc32().to_le_bytes()].concat();
        c.hash(0, &hash, now + 100).unwrap();
        let out = c.tick(now + 100, &[0, 1]).unwrap();
        assert_eq!(out.iter().filter(|d| d.opcode == 0x57).count(), 2);
        assert!(
            out.iter()
                .filter(|d| d.opcode == 0x57)
                .all(|d| read_u32(&d.body, 1) == end + 100)
        );
        assert_eq!(c.final_snapshot(), Some(&snapshot));
    }

    #[test]
    fn all_batteries_finish_early_only_with_checked_post_countdown_state() {
        for (time, points, expected) in [
            (1000, [5, 0], false),    // countdown has not ended
            (12000, [4, 1], false),   // a lead is not the gather-all objective
            (12000, [5, 1], false),   // impossible total
            (12000, [255, 1], false), // cannot overflow into a valid total
            (12000, [0, 5], true),
            (12000, [5, 0], true),
        ] {
            let mut c = running();
            let now = u64::from(time - 250);
            assert!(
                c.tick(now, &[0, 1])
                    .unwrap()
                    .iter()
                    .any(|d| d.opcode == 0x59)
            );
            let snapshot = statistics_snapshot(time, points);
            c.uploaded(0, snapshot.clone(), now + 50).unwrap();
            // Merely uploading a winning score must not finish a match.
            assert!(
                c.tick(now + 50, &[0, 1])
                    .unwrap()
                    .iter()
                    .all(|d| d.opcode != 0x57)
            );
            assert!(c.final_snapshot().is_none());
            let hash = [time.to_le_bytes(), snapshot.crc32().to_le_bytes()].concat();
            c.hash(0, &hash, now + 100).unwrap();
            let out = c.tick(now + 100, &[0, 1]).unwrap();
            assert_eq!(c.finished, expected, "time={time} points={points:?}");
            assert_eq!(
                out.iter().filter(|d| d.opcode == 0x57).count(),
                if expected { 2 } else { 0 }
            );
            if expected {
                assert_eq!(c.final_snapshot(), Some(&snapshot));
                assert_eq!(c.routing_status(now + 100), Ok(("finished", 3)));
                let mut input = [0; 16];
                input[12..].copy_from_slice(&time.to_le_bytes());
                assert_eq!(
                    c.input(0, &input, now + 100).unwrap().0,
                    InputDecision::NotPlaying
                );
                assert!(c.tick(now + 150, &[0, 1]).unwrap().is_empty());
            }
        }
    }

    #[test]
    fn late_input_invalidates_winning_snapshot_before_finish() {
        let mut c = running();
        c.tick(11750, &[0, 1]).unwrap();
        let snapshot = statistics_snapshot(12000, [5, 0]);
        c.uploaded(0, snapshot.clone(), 11800).unwrap();
        c.hash(
            0,
            &[12000u32.to_le_bytes(), snapshot.crc32().to_le_bytes()].concat(),
            11850,
        )
        .unwrap();
        assert!(c.reference_state().is_some());
        let mut input = [0; 16];
        input[12..].copy_from_slice(&11950u32.to_le_bytes());
        assert_eq!(
            c.input(1, &input, 11850).unwrap().0,
            InputDecision::Accepted
        );
        assert!(c.reference_state().is_none());
        assert!(
            c.tick(11850, &[0, 1])
                .unwrap()
                .iter()
                .all(|d| d.opcode != 0x57)
        );
        assert!(!c.finished);
    }

    fn one_running_with_reference() -> Coordinator {
        let mut c = Coordinator::new(2, 1).unwrap();
        loaded(&mut c, 0);
        c.tick(0, &[]).unwrap();
        c.clock_reply(0, &[1, 0, 0, 0, 250, 0, 0, 0]).unwrap();
        c.tick(50, &[0]).unwrap();
        assert!(c.tick(750, &[0]).unwrap().iter().any(|d| d.opcode == 0x59));
        let state = Snapshot {
            time: 750,
            body: [vec![1, 0, 0, 0], vec![1, 0, 42, 0], vec![0; 8]].concat(),
        };
        c.hash(
            0,
            &[state.time.to_le_bytes(), state.crc32().to_le_bytes()].concat(),
            750,
        )
        .unwrap();
        c.uploaded(0, state, 750).unwrap();
        c
    }
    fn input_at(time: u32, actions: u32) -> [u8; 16] {
        let mut b = [0; 16];
        b[8..12].copy_from_slice(&actions.to_le_bytes());
        b[12..].copy_from_slice(&time.to_le_bytes());
        b
    }

    #[test]
    fn late_join_preloads_all_replay_batches_before_snapshot_and_activation() {
        let mut c = one_running_with_reference();
        loaded(&mut c, 1);
        let reset = c.tick(760, &[0, 1]).unwrap();
        assert_eq!(reset.len(), 1);
        assert_eq!((reset[0].slot, reset[0].opcode), (1, 0x52));
        assert_eq!(read_u32(&reset[0].body, 0), 2);
        assert_eq!(c.game_time(760), Ok(1010)); // Shared clock was not reset.
        assert!(c.input(0, &input_at(800, 1), 760).unwrap().1.is_empty());
        assert!(c.clock_reply(1, &reset[0].body).unwrap().is_empty());
        assert!(c.tick(770, &[0]).unwrap().is_empty());
        let first = c.tick(780, &[0, 1]).unwrap();
        assert_eq!(first.len(), 1);
        assert_eq!(first[0].opcode, 0x54);
        assert_eq!(&first[0].body[1..], input_at(800, 1));
        c.input(0, &input_at(800, 2), 790).unwrap(); // Revision during replay.
        c.input(0, &input_at(900, 3), 790).unwrap();
        assert!(c.tick(800, &[0]).unwrap().is_empty());
        let next = c.tick(810, &[0, 1]).unwrap();
        assert_eq!(next.len(), 2);
        assert_eq!(&next[0].body[1..], input_at(800, 2));
        assert_eq!(&next[1].body[1..], input_at(900, 3));
        let restored = c.tick(820, &[0, 1]).unwrap();
        assert_eq!(restored[0].opcode, 0x53);
        assert_eq!(read_u32(&restored[0].body, 0), 750);
        assert!(c.tick(821, &[0]).unwrap().is_empty()); // State not ACKed.
        let enter = c.tick(830, &[0, 1]).unwrap();
        assert_eq!(enter.len(), 2);
        assert!(enter.iter().all(|d| d.opcode == 0x56 && d.body[0] == 1));
        assert_eq!(
            c.input(1, &input_at(1200, 1), 820).unwrap().0,
            InputDecision::OutsideWindow
        );
        let relayed = c.input(0, &input_at(1300, 4), 1050).unwrap().1;
        assert_eq!(relayed.len(), 1);
        assert_eq!(relayed[0].slot, 1);
    }

    #[test]
    fn late_join_replays_departure_and_does_not_activate_invalid_or_stalled_restore() {
        let mut c = one_running_with_reference();
        loaded(&mut c, 1);
        let reset = c.tick(760, &[0, 1]).unwrap();
        c.clock_reply(1, &reset[0].body).unwrap();
        assert!(c.remove(0, 770).unwrap().is_empty());
        let replay = c.tick(780, &[1]).unwrap();
        assert_eq!(replay.len(), 1);
        assert_eq!(replay[0].opcode, 0x57);
        assert_eq!(replay[0].body[0], 0);
        assert!(c.tick(800, &[1]).unwrap().iter().any(|d| d.opcode == 0x53));
        assert!(c.tick(810, &[1]).unwrap().iter().any(|d| d.opcode == 0x56));

        let mut c = one_running_with_reference();
        loaded(&mut c, 1);
        c.tick(760, &[0, 1]).unwrap();
        c.input(0, &input_at(750, 2), 770).unwrap();
        assert!(c.tick(780, &[0, 1]).unwrap().is_empty());
        assert_eq!(
            c.take_failures(),
            vec![(1, "accepted input invalidated joining snapshot")]
        );
        assert!(c.remove(1, 780).unwrap().is_empty());
        assert_eq!(c.players[&0].stage, Stage::Playing);

        loaded(&mut c, 1);
        assert!(c.tick(800, &[0, 1]).unwrap().is_empty()); // Invalidated candidate.
        let mut c = one_running_with_reference();
        loaded(&mut c, 1);
        c.tick(760, &[0, 1]).unwrap();
        c.tick(5761, &[0]).unwrap();
        assert_eq!(
            c.take_failures(),
            vec![(1, "joining snapshot transfer timed out")]
        );
    }

    fn reference_for(c: &mut Coordinator, time: u32, now: u64) {
        let state = Snapshot {
            time,
            body: [vec![3, 0, 0, 0], vec![1, 0, 42, 0, 1, 0, 43, 0], vec![0; 8]].concat(),
        };
        c.hash(
            0,
            &[time.to_le_bytes(), state.crc32().to_le_bytes()].concat(),
            now,
        )
        .unwrap();
        c.uploaded(0, state, now).unwrap();
    }

    #[test]
    fn active_restore_preserves_membership_and_replays_own_inputs_without_reentering() {
        let mut c = running();
        c.tick(750, &[0, 1]).unwrap();
        reference_for(&mut c, 750, 750);
        c.input(0, &input_at(800, 1), 760).unwrap();
        c.request_recovery(1, 760).unwrap();
        assert!(c.request_recovery(0, 760).is_err());
        assert!(c.tick(760, &[0]).unwrap().is_empty()); // Drain old deliveries.
        let reset = c.tick(770, &[0, 1]).unwrap();
        assert_eq!(reset.len(), 1);
        assert_eq!((reset[0].slot, reset[0].opcode), (1, 0x52));
        assert_eq!(c.players[&1].active_since, Some(500));
        let own = c.input(1, &input_at(900, 2), 780).unwrap();
        assert_eq!(own.0, InputDecision::Accepted);
        assert_eq!(own.1[0].slot, 0);
        c.clock_reply(1, &reset[0].body).unwrap();
        let replay = c.tick(800, &[0, 1]).unwrap();
        assert_eq!(replay.len(), 2);
        assert_eq!(
            replay.iter().map(|d| d.body[0]).collect::<Vec<_>>(),
            vec![0, 1]
        );
        let state = c.tick(810, &[0, 1]).unwrap();
        assert_eq!(state.len(), 1);
        assert_eq!(state[0].opcode, 0x53);
        assert!(c.tick(820, &[0, 1]).unwrap().is_empty()); // No 56/57 for restore.
        assert_eq!(c.players[&1].stage, Stage::Playing);
        assert_eq!(c.players[&1].active_since, Some(500));
        assert_eq!(c.players[&1].last_sync, 750);
        assert_eq!(c.players[&1].unverified_restores, 1);
        assert!(c.request_recovery(1, 1000).is_err()); // Cooldown.
        assert!(
            c.take_notices().iter().any(
                |(slot, phase, _)| *slot == 1 && *phase == "active restore replay acknowledged"
            )
        );
        assert!(
            c.hash(
                1,
                &[750u32.to_le_bytes(), 0u32.to_le_bytes()].concat(),
                1000
            )
            .unwrap()
            .is_empty()
        );
    }

    #[test]
    fn pending_state_fragments_do_not_block_replay_but_replay_revisions_wait_for_acks() {
        let mut c = running();
        c.tick(750, &[0, 1]).unwrap();
        reference_for(&mut c, 750, 750);
        c.request_recovery(1, 760).unwrap();
        let reset = c.tick(770, &[0, 1]).unwrap();
        assert!(c.clock_reply(1, &reset[0].body).unwrap().is_empty());
        let state = c.tick(780, &[0, 1]).unwrap();
        assert_eq!(state[0].opcode, 0x53);

        // State fragments remain unacknowledged for 1.2 seconds. Replay must
        // be sent during that interval, not first queued after full restore.
        c.input(0, &input_at(1050, 0x20), 800).unwrap();
        let first = c.tick_with_replay_idle(810, &[0], &[0, 1]).unwrap();
        assert_eq!(first.len(), 1);
        assert_eq!(first[0].opcode, 0x54);
        assert_eq!(&first[0].body[1..], input_at(1050, 0x20));
        c.input(0, &input_at(1050, 0x40), 820).unwrap();
        assert!(c.tick_with_replay_idle(830, &[0], &[0]).unwrap().is_empty());
        let revision = c.tick_with_replay_idle(1000, &[0], &[0, 1]).unwrap();
        assert_eq!(revision.len(), 1);
        assert_eq!(&revision[0].body[1..], input_at(1050, 0x40));
        assert!(
            c.tick_with_replay_idle(1100, &[0], &[0, 1])
                .unwrap()
                .is_empty()
        );
        assert_eq!(c.players[&1].stage, Stage::AwaitStateAck);
        assert!(
            c.tick_with_replay_idle(2000, &[0, 1], &[0, 1])
                .unwrap()
                .is_empty()
        );
        assert_eq!(c.players[&1].stage, Stage::Playing);
        assert_eq!(c.players[&1].active_since, Some(500));
    }

    #[test]
    fn sustained_disagreement_automatically_selects_a_newer_reference_state() {
        let mut c = running();
        c.tick(750, &[0, 1]).unwrap();
        for time in [1000u32, 1250, 1500] {
            for slot in [0, 1] {
                c.hash(
                    slot,
                    &[time.to_le_bytes(), u32::from(slot).to_le_bytes()].concat(),
                    1750,
                )
                .unwrap();
            }
        }
        reference_for(&mut c, 2000, 2000);
        let reset = c.tick(2250, &[0, 1]).unwrap();
        assert_eq!(reset.len(), 1);
        assert_eq!((reset[0].slot, reset[0].opcode), (1, 0x52));
        assert_eq!(c.players[&1].transfer.as_ref().unwrap().snapshot.time, 2000);
    }

    #[test]
    fn repeated_unverified_restores_fail_one_peer_and_positive_agreement_clears_budget() {
        let mut c = running();
        c.tick(750, &[0, 1]).unwrap();
        reference_for(&mut c, 750, 750);
        c.players.get_mut(&1).unwrap().unverified_restores = 3;
        c.request_recovery(1, 760).unwrap();
        assert!(c.tick(770, &[0, 1]).unwrap().is_empty());
        assert_eq!(
            c.take_failures(),
            vec![(1, "repeated active recovery did not converge")]
        );
        assert_eq!(c.players[&0].stage, Stage::Playing);

        let mut c = running();
        c.tick(750, &[0, 1]).unwrap();
        c.players.get_mut(&1).unwrap().unverified_restores = 1;
        c.players.get_mut(&1).unwrap().last_sync = 750;
        for time in [1800u32, 2050, 2300] {
            for slot in [0, 1] {
                c.hash(
                    slot,
                    &[time.to_le_bytes(), 7u32.to_le_bytes()].concat(),
                    3250,
                )
                .unwrap();
            }
        }
        c.tick(3250, &[0, 1]).unwrap();
        assert_eq!(c.players[&1].unverified_restores, 0);
    }
}
