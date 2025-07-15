void __usercall survarium::booby_trap_set::on_trap_removed_message(
        survarium::booby_trap_set *this@<ecx>,
        unsigned __int8 index@<al>)
{
  survarium::booby_trap_core *m_object; // eax
  survarium::booby_trap_core *v3; // esi

  m_object = this->m_traps.m_begin[index].m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  this->remove_trap(this, v3);
  if ( v3 )
  {
    if ( !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
  }
}
