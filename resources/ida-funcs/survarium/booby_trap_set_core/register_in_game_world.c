void __thiscall survarium::booby_trap_set_core::register_in_game_world(
        survarium::booby_trap_set_core *this,
        survarium::game_world_core *game_world)
{
  survarium::game_world_core *v3; // ecx
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *m_begin; // esi
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *m_end; // edi
  survarium::serializable_object *m_object; // eax

  v3 = game_world;
  m_begin = this->m_traps.m_begin;
  m_end = this->m_traps.m_end;
  this->m_game_world_core = game_world;
  while ( m_begin != m_end )
  {
    m_object = (survarium::serializable_object *)m_begin->m_object;
    m_object[34].prev = (survarium::serializable_object *)v3;
    survarium::game_world_core::register_serializable_object(v3, m_object + 11);
    ++m_begin;
  }
}
