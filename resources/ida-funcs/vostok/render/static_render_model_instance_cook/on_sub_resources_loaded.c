void __thiscall vostok::render::static_render_model_instance_cook::on_sub_resources_loaded(
        vostok::render::static_render_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::resources::query_result_for_cook *m_parent_query; // esi
  vostok::render::static_render_model *v4; // ebx
  vostok::render::static_render_model_instance *v5; // eax
  vostok::resources::unmanaged_intrusive_base *v6; // ecx
  void *v7; // eax
  vostok::render::static_render_model_instance *v8; // ecx
  vostok::render::static_render_model_instance *v9; // eax
  int v10; // ecx
  vostok::render::static_render_model_instance *v11; // ecx
  vostok::configs::binary_config *v12; // esi
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v14; // [esp-Ch] [ebp-3Ch] BYREF
  const vostok::resources::memory_type *v15; // [esp-8h] [ebp-38h]
  vostok::resources::resource_ptr<vostok::render::static_render_model,vostok::resources::unmanaged_intrusive_base> v16; // [esp-4h] [ebp-34h]
  vostok::render::static_render_model_instance *created_resource; // [esp+10h] [ebp-20h] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+14h] [ebp-1Ch]
  vostok::configs::binary_config_value cfg; // [esp+18h] [ebp-18h] BYREF

  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  m_parent_query = data->m_parent_query;
  v4 = 0;
  parent = m_parent_query;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    created_resource = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&created_resource,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    v5 = created_resource;
    if ( created_resource )
    {
      v6 = &created_resource->vostok::resources::unmanaged_intrusive_base;
      v4 = (vostok::render::static_render_model *)created_resource;
      _InterlockedExchangeAdd(&created_resource->m_reference_count, 1u);
      if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v6, v5);
    }
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x198u);
    if ( v7 )
    {
      vostok::render::static_render_model_instance::static_render_model_instance(v8, (int)v7);
      m_parent_query = parent;
      created_resource = v9;
    }
    else
    {
      created_resource = 0;
    }
    if ( m_parent_query->m_user_data )
    {
      vostok::configs::binary_config_value::binary_config_value((vostok::configs::binary_config_value *)v8);
      vostok::variant<32>::try_get<vostok::configs::binary_config_value>(parent->m_user_data, &cfg, v10);
      vostok::render::static_render_model_instance::add_sectors_holder(v11, (int)created_resource, cfg);
    }
    v16.m_object = 0;
    if ( v4 )
    {
      v16.m_object = v4;
      v8 = (vostok::render::static_render_model_instance *)_InterlockedExchangeAdd(&v4->m_reference_count, 1u);
    }
    v12 = (vostok::configs::binary_config *)created_resource;
    vostok::render::static_render_model_instance::assign_original(v8, (int)created_resource, v16);
    v16.m_object = (vostok::render::static_render_model *)408;
    v15 = &vostok::resources::nocache_memory;
    v14.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v14,
      v12);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      parent,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v14.m_object,
      v15,
      (unsigned int)v16.m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v13,
      result_success,
      assert_on_fail_true,
      error_type_unset);
    if ( v4 )
    {
      if ( !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
    }
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
}
