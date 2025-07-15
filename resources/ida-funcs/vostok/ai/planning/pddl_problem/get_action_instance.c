const vostok::ai::planning::action_instance *__thiscall vostok::ai::planning::pddl_problem::get_action_instance(
        vostok::ai::planning::pddl_problem *this,
        unsigned int action_type)
{
  survarium::game_camera *m_type; // ecx
  unsigned int i; // [esp+14h] [ebp-4h]

  for ( i = 0; i < this->m_action_instances.m_end - this->m_action_instances.m_begin; ++i )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    m_type = (survarium::game_camera *)this->m_action_instances.m_begin[i]->m_prototype->m_type;
    if ( m_type == (survarium::game_camera *)action_type )
    {
      survarium::weapon_user_dead_state::finalize(m_type);
      return this->m_action_instances.m_begin[i];
    }
  }
  return 0;
}
