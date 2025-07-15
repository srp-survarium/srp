void __thiscall survarium::booby_trap_set_core::inventory_item_clear(survarium::booby_trap_set_core *this)
{
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *m_begin; // esi
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *m_end; // edi

  m_begin = this->m_traps.m_begin;
  m_end = this->m_traps.m_end;
  while ( m_begin != m_end )
  {
    m_begin->m_object->inventory_item_clear(m_begin->m_object);
    ++m_begin;
  }
}
