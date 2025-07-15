void __thiscall survarium::grenade_set_core::inventory_item_clear(survarium::grenade_set_core *this)
{
  vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> *m_end; // ebx
  vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> *i; // edi
  _DWORD *v3; // esi

  m_end = this->m_grenades.m_end;
  for ( i = this->m_grenades.m_begin; i != m_end; *((_BYTE *)v3 + 300) = 0 )
  {
    v3 = &i->m_object->__vftable;
    if ( i->m_object->m_physics_world )
      (*(void (__thiscall **)(survarium::grenade_core *))(*v3 + 20))(i->m_object);
    if ( v3[74] != -1 )
      (*(void (__thiscall **)(_DWORD *))(*v3 + 12))(v3);
    ++i;
  }
}
