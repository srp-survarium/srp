void __thiscall vostok::physics::animated_model_instance_cook::on_subresources_loaded(
        vostok::physics::animated_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  volatile int m_result; // edx
  vostok::resources::unmanaged_resource *v3; // eax
  vostok::configs::binary_config *v4; // esi
  vostok::configs::binary_config *m_object; // edi
  vostok::configs::binary_config *v6; // ebx
  vostok::configs::binary_config *v7; // eax
  vostok::configs::binary_config_value *v8; // ecx
  vostok::resources::unmanaged_resource *m_root; // eax
  vostok::resources::query_result_for_cook *v10; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v11; // [esp-4h] [ebp-24h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp+10h] [ebp-10h] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+14h] [ebp-Ch]
  vostok::resources::memory_usage_type memory_usage; // [esp+18h] [ebp-8h] BYREF

  m_result = data->m_result;
  parent = data->m_parent_query;
  if ( m_result == 1 )
  {
    v3 = (vostok::resources::unmanaged_resource *)this->m_allocator->call_malloc(this->m_allocator, 272);
    v4 = (vostok::configs::binary_config *)v3;
    if ( v3 )
    {
      vostok::resources::unmanaged_resource::unmanaged_resource(v3, 1u);
      v4->__vftable = (vostok::configs::binary_config_vtbl *)&vostok::physics::animated_model_instance::`vftable';
      v4->m_root = 0;
    }
    else
    {
      v4 = 0;
    }
    v12.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v12,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = v12.m_object;
    v6 = 0;
    if ( v12.m_object )
    {
      v6 = v12.m_object;
      _InterlockedExchangeAdd(&v12.m_object->m_reference_count, 1u);
    }
    v7 = 0;
    if ( v6 )
    {
      v7 = v6;
      _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
    }
    v8 = (vostok::configs::binary_config_value *)v7;
    m_root = (vostok::resources::unmanaged_resource *)v4->m_root;
    v4->m_root = v8;
    if ( m_root )
    {
      if ( !_InterlockedExchangeAdd(&m_root->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &m_root->vostok::resources::unmanaged_intrusive_base,
          m_root);
      m_object = v12.m_object;
    }
    if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
    if ( m_object )
    {
      if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &m_object->vostok::resources::unmanaged_intrusive_base,
          m_object);
    }
    memory_usage.type = &vostok::resources::nocache_memory;
    memory_usage.size = 272;
    v11.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v11,
      v4);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      &memory_usage,
      parent,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v11.m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v10,
      result_success,
      assert_on_fail_true,
      error_type_unset);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
}
