void __usercall vostok::resources::queries_result::on_child_query_end(
        vostok::resources::queries_result *this@<edi>,
        vostok::resources::query_result *child@<eax>)
{
  vostok::resources::unmanaged_intrusive_base *v2; // ecx
  vostok::resources::unmanaged_resource *m_object; // eax
  signed __int32 v4; // esi
  unsigned int v5; // eax
  vostok::resources::queries_result *v6; // ecx
  char v7; // al
  vostok::resources::queries_result *v8; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> unmanaged_resource; // [esp+8h] [ebp-4h] BYREF

  unmanaged_resource.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&unmanaged_resource,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&child->m_unmanaged_resource);
  m_object = unmanaged_resource.m_object;
  if ( unmanaged_resource.m_object )
  {
    v2 = &unmanaged_resource.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&unmanaged_resource.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v2, m_object);
  }
  v4 = _InterlockedIncrement(&this->m_children_ended);
  v5 = vostok::resources::queries_result::calculate_fs_iterator_requests_count(
         (vostok::resources::queries_result *)v2,
         (int)this);
  v6 = (vostok::resources::queries_result *)(this->m_size - v5);
  if ( (vostok::resources::queries_result *)v4 == v6 )
  {
    if ( v5 )
    {
      vostok::resources::queries_result::query_fs_iterators(v6, this);
    }
    else
    {
      v7 = vostok::resources::queries_result::calculate_result_from_children(v6, (int)this);
      vostok::resources::queries_result::on_query_end(v8, (int)this, v7);
    }
  }
}
