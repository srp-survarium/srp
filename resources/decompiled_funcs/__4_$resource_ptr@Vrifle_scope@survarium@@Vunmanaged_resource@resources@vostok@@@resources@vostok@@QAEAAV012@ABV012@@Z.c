vostok::resources::resource_ptr<survarium::rifle_scope,vostok::resources::unmanaged_resource> *__usercall vostok::resources::resource_ptr<survarium::rifle_scope,vostok::resources::unmanaged_resource>::operator=@<eax>(
        vostok::resources::resource_ptr<survarium::rifle_scope,vostok::resources::unmanaged_resource> *this@<ecx>,
        vostok::resources::unmanaged_resource **a2@<esi>)
{
  survarium::rifle_scope *m_object; // ecx
  survarium::rifle_scope *v3; // eax
  vostok::resources::unmanaged_resource *v4; // ecx
  vostok::resources::unmanaged_resource *v5; // eax

  m_object = this->m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v4 = v3;
  v5 = *a2;
  *a2 = v4;
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  return (vostok::resources::resource_ptr<survarium::rifle_scope,vostok::resources::unmanaged_resource> *)a2;
}
