void __usercall vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
        vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<ecx>,
        survarium::inventory **a2@<eax>)
{
  survarium::inventory *m_object; // ecx

  *a2 = 0;
  m_object = this->m_object;
  if ( m_object )
  {
    *a2 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}
