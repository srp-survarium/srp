void __thiscall vostok::ai::planning::plan_tracker::track(vostok::ai::planning::plan_tracker *this)
{
  BOOL m_first_time; // ecx

  m_first_time = this->m_first_time;
  if ( m_first_time )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_first_time);
  else
    vostok::ai::planning::action_instance::execute(
      (vostok::ai::planning::action_instance *)this->m_current_operator.action,
      &this->m_current_operator.parameters);
}
