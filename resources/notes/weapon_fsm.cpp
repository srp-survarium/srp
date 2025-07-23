boost::bind -> 72
fsm::add_transition -> 72


fsm::add_transition(inactive_state, show_state,                             boost ::bind(survarium::weapon_core::target_predicate, idle));
fsm::add_transition(inactive_state, show_state,                             boost ::bind(survarium::weapon_core::target_predicate, fire));
fsm::add_transition(inactive_state, show_state,                             boost ::bind(survarium::weapon_core::target_predicate, aim));
fsm::add_transition(inactive_state, show_state,                             boost ::bind(survarium::weapon_core::target_predicate, aim_fire));
fsm::add_transition(inactive_state, show_state,                             boost ::bind(survarium::weapon_core::target_predicate, reload));

fsm::add_transition(show_state, hide_state,                                 boost ::bind(survarium::weapon_core::target_predicate, inactive));

if (chamber_a_round_aimed_state )
{
  fsm::add_transition(show_state, chamber_a_round_aimed_state,              boost ::bind(survarium::weapon_core::must_chamber_a_round_aimed_predicate));
}

if (this->m_is_there_chamber_a_round_state )
{
  fsm::add_transition(show_state, chamber_a_round_state,                    boost ::bind(survarium::weapon_core::must_chamber_a_round_predicate));
}

fsm::add_transition(show_state, reload_state,                               boost ::bind(survarium::weapon_core::can_and_must_reload_predicate));
fsm::add_transition(show_state, idle_state,                                 boost ::bind(survarium::weapon_core::target_predicate, idle));
fsm::add_transition(show_state, fire_state,                                 boost ::bind(survarium::weapon_core::target_predicate, fire));
fsm::add_transition(show_state, aim_state,                                  boost ::bind(survarium::weapon_core::target_predicate, aim));
fsm::add_transition(show_state, aim_fire_state,                             boost ::bind(survarium::weapon_core::target_predicate, aim_fire));
fsm::add_transition(show_state, reload_state,                               boost ::bind(survarium::weapon_core::target_predicate, reload));

fsm::add_transition(hide_state, inactive_state,                             boost ::bind(survarium::weapon_core::target_predicate, inactive));

fsm::add_transition(hide_state, show_state,                                 boost ::bind(survarium::weapon_core::target_predicate, idle));
fsm::add_transition(hide_state, show_state,                                 boost ::bind(survarium::weapon_core::target_predicate, fire));
fsm::add_transition(hide_state, show_state,                                 boost ::bind(survarium::weapon_core::target_predicate, aim));
fsm::add_transition(hide_state, show_state,                                 boost ::bind(survarium::weapon_core::target_predicate, aim_fire));
fsm::add_transition(hide_state, show_state,                                 boost ::bind(survarium::weapon_core::target_predicate, reload));

fsm::add_transition(idle_state, hide_state,                                 boost ::bind(survarium::weapon_core::target_predicate, inactive));

if (chamber_a_round_aimed_state )
{
  fsm::add_transition(idle_state, chamber_a_round_aimed_state,              boost ::bind(survarium::weapon_core::must_chamber_a_round_aimed_predicate));
}

if (this->m_is_there_chamber_a_round_state )
{
  fsm::add_transition(idle_state, chamber_a_round_state,                    boost ::bind(survarium::weapon_core::must_chamber_a_round_predicate));
}

fsm::add_transition(idle_state, reload_state,                               boost ::bind(survarium::weapon_core::target_predicate, reload));
fsm::add_transition(idle_state, fire_state,                                 boost ::bind(survarium::weapon_core::target_predicate, fire));
fsm::add_transition(idle_state, aim_state,                                  boost ::bind(survarium::weapon_core::target_predicate, aim));
fsm::add_transition(idle_state, aim_fire_state,                             boost ::bind(survarium::weapon_core::target_predicate, aim_fire));
fsm::add_transition(reload_state, hide_state,                               boost ::bind(survarium::weapon_core::target_predicate, inactive));

if (this->m_is_there_chamber_a_round_state
  && !this->m_chamber_a_round_on_reload )
{
  fsm::add_transition(reload_state, chamber_a_round_state,                  boost ::bind(survarium::weapon_core::must_chamber_a_round_and_animation_ended_predicate));
}

fsm::add_transition(reload_state, idle_state,                               boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, idle));
fsm::add_transition(reload_state, idle_state,                               boost ::bind(survarium::weapon_core::instant_idle_predicate));
fsm::add_transition(reload_state, fire_state,                               boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, fire));
fsm::add_transition(reload_state, aim_state,                                boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, aim));
fsm::add_transition(reload_state, aim_fire_state,                           boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, aim_fire));
fsm::add_transition(fire_state, hide_state,                                 boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, inactive));

if (chamber_a_round_aimed_state )
{
  fsm::add_transition(fire_state, chamber_a_round_aimed_state,              boost ::bind(survarium::weapon_core::must_chamber_a_round_aimed_and_animation_ended_predicate));
}

if (this->m_is_there_chamber_a_round_state )
{
  fsm::add_transition(fire_state, chamber_a_round_state,                    boost ::bind(survarium::weapon_core::must_chamber_a_round_and_animation_ended_predicate));
}

fsm::add_transition(fire_state, reload_state,                               boost ::bind(survarium::weapon_core::can_and_must_reload_and_animation_ended_predicate));
fsm::add_transition(fire_state, idle_state,                                 boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, idle));
fsm::add_transition(fire_state, aim_state,                                  boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, aim));
fsm::add_transition(fire_state, aim_fire_state,                             boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, aim_fire));
fsm::add_transition(fire_state, reload_state,                               boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, reload));
fsm::add_transition(fire_state, aim_fire_state,                             boost ::bind(survarium::weapon_core::is_trying_to_aim));

fsm::add_transition(aim_state, idle_state,                                  boost ::bind(survarium::weapon_core::target_predicate, idle));
fsm::add_transition(aim_state, hide_state,                                  boost ::bind(survarium::weapon_core::target_predicate, inactive));
fsm::add_transition(aim_state, idle_state,                                  boost ::bind(survarium::weapon_core::instant_idle_predicate));
fsm::add_transition(aim_state, fire_state,                                  boost ::bind(survarium::weapon_core::target_predicate, fire));
fsm::add_transition(aim_state, aim_fire_state,                              boost ::bind(survarium::weapon_core::target_predicate, aim_fire));
fsm::add_transition(aim_state, reload_state,                                boost ::bind(survarium::weapon_core::target_predicate, reload));

fsm::add_transition(aim_fire_state, hide_state,                             boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, inactive));

if (chamber_a_round_aimed_state )
{
  fsm::add_transition(aim_fire_state, chamber_a_round_aimed_state,          boost ::bind(survarium::weapon_core::must_chamber_a_round_aimed_and_animation_ended_predicate));
}

if (this->m_is_there_chamber_a_round_state )
{
  fsm::add_transition(aim_fire_state, chamber_a_round_state,                boost ::bind(survarium::weapon_core::must_chamber_a_round_and_animation_ended_predicate));
}

fsm::add_transition(aim_fire_state, reload_state,                           boost ::bind(survarium::weapon_core::can_and_must_reload_and_animation_ended_predicate));
fsm::add_transition(aim_fire_state, idle_state,                             boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, idle));
fsm::add_transition(aim_fire_state, fire_state,                             boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, fire));
fsm::add_transition(aim_fire_state, aim_state,                              boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, aim));
fsm::add_transition(aim_fire_state, reload_state,                           boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, reload));
fsm::add_transition(aim_fire_state, fire_state,                             boost ::bind(survarium::weapon_core::is_not_trying_to_aim_predicate, idle));

if (this->m_is_there_chamber_a_round_state )
{
  fsm::add_transition(chamber_a_round_state, hide_state,                    boost ::bind(survarium::weapon_core::target_predicate, inactive));
  fsm::add_transition(chamber_a_round_state, idle_state,                    boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, idle));
  fsm::add_transition(chamber_a_round_state, idle_state,                    boost ::bind(survarium::weapon_core::instant_idle_predicate, idle));
  fsm::add_transition(chamber_a_round_state, fire_state,                    boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, fire));
  fsm::add_transition(chamber_a_round_state, aim_state,                     boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, aim));
  fsm::add_transition(chamber_a_round_state, aim_fire_state,                boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, aim_fire));

  if (chamber_a_round_aimed_state )
  {
    fsm::add_transition(chamber_a_round_state, chamber_a_round_aimed_state, boost ::bind(survarium::weapon_core::is_trying_to_aim, idle));
  }
}

if (chamber_a_round_aimed_state )
{
  fsm::add_transition(chamber_a_round_aimed_state, hide_state,              boost ::bind(survarium::weapon_core::target_predicate, inactive));
  fsm::add_transition(chamber_a_round_aimed_state, idle_state,              boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, idle));
  fsm::add_transition(chamber_a_round_aimed_state, idle_state,              boost ::bind(survarium::weapon_core::instant_idle_predicate, idle));
  fsm::add_transition(chamber_a_round_aimed_state, fire_state,              boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, fire));
  fsm::add_transition(chamber_a_round_aimed_state, aim_state,               boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, aim)/;
  fsm::add_transition(chamber_a_round_aimed_state, aim_fire_state,          boost ::bind(survarium::weapon_core::target_and_animation_ended_predicate, aim_fire));
  fsm::add_transition(chamber_a_round_aimed_state, chamber_a_round_state,   boost ::bind(survarium::weapon_core::is_not_trying_to_aim_predicate, idle));
}
