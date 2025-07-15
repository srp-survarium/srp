const survarium::game_match_rule_base *__thiscall survarium::game_world_core::game_rule(
        survarium::game_world_core *this)
{
  vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> *m_begin; // eax
  vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> *m_end; // ecx

  m_begin = this->m_game_rules.m_begin;
  m_end = this->m_game_rules.m_end;
  while ( 1 )
  {
    if ( m_begin == m_end )
      return 0;
    if ( m_begin->m_object->type == gather_victory_items_rule_type )
      break;
    ++m_begin;
  }
  return m_begin->m_object;
}
