void __thiscall vostok::render::static_model_instance_cook::on_subresources_loaded(
        vostok::render::static_model_instance_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent_query)
{
  int *v3; // eax
  int *v4; // esi
  vostok::configs::binary_config *m_object; // ebx
  vostok::configs::binary_config *v6; // edi
  vostok::configs::binary_config *v7; // eax
  vostok::configs::binary_config *v8; // ecx
  vostok::resources::unmanaged_resource *v9; // eax
  vostok::resources::unmanaged_resource *v10; // eax
  vostok::configs::binary_config *v11; // ebx
  vostok::configs::binary_config *v12; // edi
  vostok::configs::binary_config *v13; // eax
  vostok::configs::binary_config *v14; // ecx
  vostok::resources::unmanaged_resource *v15; // eax
  vostok::resources::query_result_for_cook *v16; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v17; // [esp-Ch] [ebp-28h] BYREF
  const vostok::resources::memory_type *v18; // [esp-8h] [ebp-24h]
  unsigned int v19; // [esp-4h] [ebp-20h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v20; // [esp+10h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v21; // [esp+14h] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v22; // [esp+18h] [ebp-4h] BYREF

  v22.m_object = 0;
  if ( data->m_result == 1 )
  {
    v3 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x110u);
    v4 = v3;
    if ( v3 )
    {
      vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)v3, 1u);
      *v4 = (int)&vostok::render::static_model_instance::`vftable';
      v4[66] = 0;
      v4[67] = 0;
    }
    else
    {
      v4 = 0;
    }
    v20.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v20,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = v20.m_object;
    v6 = 0;
    if ( v20.m_object )
    {
      v6 = v20.m_object;
      _InterlockedExchangeAdd(&v20.m_object->m_reference_count, 1u);
    }
    v7 = 0;
    if ( v6 )
    {
      v7 = v6;
      _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
    }
    v8 = v7;
    v9 = (vostok::resources::unmanaged_resource *)v4[66];
    v4[66] = (int)v8;
    if ( v9 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v9->vostok::resources::unmanaged_intrusive_base, v9);
    if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    v10 = (vostok::resources::unmanaged_resource *)v4[67];
    v4[67] = 0;
    if ( v10 && !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v10->vostok::resources::unmanaged_intrusive_base, v10);
    if ( data->m_size > 1 )
    {
      v21.m_object = 0;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        &v21,
        (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
      v11 = v21.m_object;
      v22.m_object = 0;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        &v22,
        v21.m_object);
      v12 = v22.m_object;
      v13 = 0;
      if ( v22.m_object )
      {
        v13 = v22.m_object;
        _InterlockedExchangeAdd(&v22.m_object->m_reference_count, 1u);
      }
      v14 = v13;
      v15 = (vostok::resources::unmanaged_resource *)v4[67];
      v4[67] = (int)v14;
      if ( v15 && !_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v15->vostok::resources::unmanaged_intrusive_base, v15);
      if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v12);
      if ( v11 )
      {
        if ( !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v11->vostok::resources::unmanaged_intrusive_base, v11);
      }
    }
    v19 = 272;
    v18 = &vostok::resources::nocache_memory;
    v17.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v17,
      (vostok::configs::binary_config *)v4);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      parent_query,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v17.m_object,
      v18,
      v19);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v16,
      (int)parent_query,
      result_success,
      assert_on_fail_true,
      0);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      (int)parent_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  }
}
