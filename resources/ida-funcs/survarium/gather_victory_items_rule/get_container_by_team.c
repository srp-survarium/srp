const survarium::victory_items_container_core *__thiscall survarium::gather_victory_items_rule::get_container_by_team(
        survarium::gather_victory_items_rule *this,
        survarium::game_team_id team)
{
  vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *i; // eax

  for ( i = this->m_containers._M_impl._M_start; i->m_object->m_owner_team != team; ++i )
    ;
  return i->m_object;
}
