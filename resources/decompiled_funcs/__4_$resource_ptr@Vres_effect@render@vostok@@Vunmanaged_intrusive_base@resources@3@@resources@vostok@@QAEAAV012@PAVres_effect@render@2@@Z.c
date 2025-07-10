vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *__usercall vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *this@<ecx>,
        vostok::resources::unmanaged_resource **a2@<esi>)
{
  vostok::resources::unmanaged_resource *v2; // eax

  v2 = *a2;
  *a2 = 0;
  if ( v2 && !_InterlockedExchangeAdd(&v2->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v2->vostok::resources::unmanaged_intrusive_base, v2);
  return (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)a2;
}
