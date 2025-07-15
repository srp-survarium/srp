void __thiscall survarium::animated_model_instance_cook::on_hit_params_loaded(
        survarium::animated_model_instance_cook *this,
        vostok::resources::queries_result *data,
        vostok::configs::binary_config *new_model)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::configs::binary_config *v4; // esi
  vostok::resources::query_result_for_cook *m_parent_query; // edi
  vostok::configs::binary_config *m_object; // edi
  vostok::configs::binary_config *v7; // eax
  survarium::damage_model *v8; // ecx
  survarium::damage_model *v9; // eax
  vostok::resources::query_result_for_cook *v10; // edi
  vostok::resources::query_result_for_cook *v11; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp-4h] [ebp-24h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp+10h] [ebp-10h] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+14h] [ebp-Ch]
  vostok::resources::memory_usage_type memory_usage; // [esp+18h] [ebp-8h] BYREF

  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  v4 = 0;
  m_parent_query = data->m_parent_query;
  parent = m_parent_query;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    v13.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v13,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = v13.m_object;
    if ( v13.m_object )
    {
      v4 = v13.m_object;
      _InterlockedExchangeAdd(&v13.m_object->m_reference_count, 1u);
    }
    v7 = 0;
    if ( v4 )
    {
      v7 = v4;
      _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
    }
    v8 = (survarium::damage_model *)v7;
    v9 = (survarium::damage_model *)new_model[1].__vftable;
    new_model[1].__vftable = (vostok::configs::binary_config_vtbl *)v8;
    if ( v9 )
    {
      if ( !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v9->vostok::resources::unmanaged_intrusive_base, v9);
      m_object = v13.m_object;
    }
    if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
    if ( m_object )
    {
      if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &m_object->vostok::resources::unmanaged_intrusive_base,
          m_object);
    }
    memory_usage.type = &vostok::resources::nocache_memory;
    memory_usage.size = 288;
    v12.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v12,
      new_model);
    v10 = parent;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      &memory_usage,
      parent,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v12.m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(v11, (int)v10, result_success, assert_on_fail_true, 0);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (int)m_parent_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  }
}
