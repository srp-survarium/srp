void __thiscall vostok::resources::query_result_for_cook::set_unmanaged_resource(
        vostok::resources::query_result_for_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> ptr,
        const vostok::resources::memory_type *memory_type,
        unsigned int resource_size)
{
  vostok::resources::unmanaged_resource *m_object; // edx
  vostok::resources::unmanaged_resource *v5; // eax
  vostok::resources::unmanaged_resource *v6; // esi
  vostok::resources::unmanaged_resource *v7; // eax

  m_object = ptr.m_object;
  v5 = 0;
  if ( ptr.m_object )
  {
    v5 = ptr.m_object;
    _InterlockedExchangeAdd(&ptr.m_object->m_reference_count, 1u);
    m_object = ptr.m_object;
  }
  v6 = v5;
  v7 = this->m_unmanaged_resource.m_object;
  this->m_unmanaged_resource.m_object = v6;
  if ( v7 )
  {
    if ( !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v7->vostok::resources::unmanaged_intrusive_base, v7);
    m_object = ptr.m_object;
  }
  if ( m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      m_object->m_memory_usage_self.vostok::resources::resource_base::vostok::resources::resource_quality::type = memory_type;
      ptr.m_object->m_memory_usage_self.size = resource_size;
      m_object = ptr.m_object;
    }
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &ptr.m_object->vostok::resources::unmanaged_intrusive_base,
        ptr.m_object);
  }
}
