void __thiscall vostok::ai::planning::plan_tracker::~plan_tracker(vostok::ai::planning::plan_tracker *this)
{
  const void **i; // [esp+8h] [ebp-4h]

  for ( i = this->m_current_operator.parameters.m_begin; i != this->m_current_operator.parameters.m_end; ++i )
    ;
  this->m_current_operator.parameters.m_end = this->m_current_operator.parameters.m_begin;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
