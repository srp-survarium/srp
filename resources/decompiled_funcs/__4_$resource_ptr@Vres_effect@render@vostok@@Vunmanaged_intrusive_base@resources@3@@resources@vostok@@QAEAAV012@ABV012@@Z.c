vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *__usercall vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *this@<ecx>,
        vostok::resources::unmanaged_resource **a2@<esi>)
{
  vostok::animation::skeleton *m_object; // ecx
  vostok::animation::skeleton *v3; // eax
  vostok::resources::unmanaged_resource *v4; // edx

  m_object = this->m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v4 = *a2;
  *a2 = v3;
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  return (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)a2;
}
