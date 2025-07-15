const vostok::ai::planning::generalized_action *__thiscall vostok::ai::planning::pddl_domain::get_action_by_type(
        vostok::ai::planning::pddl_domain *this,
        unsigned int type)
{
  vostok::ai::planning::generalized_action *it_action; // [esp+8h] [ebp-4h]

  for ( it_action = this->m_actions.m_first; it_action; it_action = it_action->next )
  {
    if ( it_action->m_type == type )
      return it_action;
  }
  return 0;
}
