void __thiscall survarium::grenade_set_core::register_in_game_world(
        survarium::grenade_set_core *this,
        survarium::game_world_core *w)
{
  survarium::game_world_core *v3; // ecx
  vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> *m_begin; // esi
  vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> *m_end; // edi
  survarium::serializable_object *m_object; // eax

  v3 = w;
  m_begin = this->m_grenades.m_begin;
  m_end = this->m_grenades.m_end;
  this->m_game_world_core = w;
  while ( m_begin != m_end )
  {
    m_object = (survarium::serializable_object *)m_begin->m_object;
    m_object[25].next = (survarium::serializable_object *)v3;
    survarium::game_world_core::register_serializable_object(v3, m_object + 1);
    ++m_begin;
  }
}
