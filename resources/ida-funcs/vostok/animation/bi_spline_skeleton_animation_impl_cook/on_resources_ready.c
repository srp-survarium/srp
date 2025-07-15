void __cdecl vostok::animation::bi_spline_skeleton_animation_impl_cook::on_resources_ready(
        vostok::resources::queries_result *results,
        vostok::resources::query_result_for_cook *const parent_query)
{
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v2; // ebp
  vostok::resources::queries_result *m_parent; // eax
  assert_on_fail_bool v4; // ecx
  bool v5; // al
  vostok::configs::binary_config *m_object; // eax
  vostok::configs::binary_config *v7; // esi
  vostok::resources::unmanaged_intrusive_base *v8; // ecx
  vostok::configs::binary_config *v9; // edi
  vostok::resources::query_result_for_cook *v10; // ecx
  vostok::resources::unmanaged_resource *v11; // eax
  vostok::resources::unmanaged_intrusive_base *p_m_target_quality_level; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp-Ch] [ebp-24h] BYREF
  const vostok::resources::memory_type *v14; // [esp-8h] [ebp-20h]
  vostok::resources::query_result_for_user::error_type_enum m_error_type; // [esp-4h] [ebp-1Ch]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v16; // [esp+10h] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v17; // [esp+14h] [ebp-4h] BYREF

  v17.m_object = 0;
  v2 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)results;
  if ( results->m_result == 1 )
  {
    v16.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v16,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&results->m_queries[0].m_unmanaged_resource);
    m_object = v16.m_object;
    v7 = 0;
    if ( v16.m_object )
    {
      v8 = &v16.m_object->vostok::resources::unmanaged_intrusive_base;
      v7 = v16.m_object;
      _InterlockedExchangeAdd(&v16.m_object->m_reference_count, 1u);
      if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v8, m_object);
    }
    v17.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v17,
      v2 + 255);
    v9 = v17.m_object;
    results = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&results,
      v17.m_object);
    if ( v9 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v9->vostok::resources::unmanaged_intrusive_base, v9);
    vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
      (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&v7->m_root,
      (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&results);
    m_error_type = 272;
    v14 = &vostok::resources::nocache_memory;
    v13.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v13,
      v7);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      parent_query,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v13.m_object,
      v14,
      m_error_type);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v10,
      result_success,
      assert_on_fail_true,
      error_type_unset);
    v11 = (vostok::resources::unmanaged_resource *)results;
    if ( results )
    {
      p_m_target_quality_level = (vostok::resources::unmanaged_intrusive_base *)&results->m_queries[0].m_target_quality_level;
      if ( !_InterlockedExchangeAdd(
              (volatile signed __int32 *)&results->m_queries[0].m_target_quality_level,
              0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(p_m_target_quality_level, v11);
    }
    if ( v7 && !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v7->vostok::resources::unmanaged_intrusive_base, v7);
  }
  else
  {
    m_parent = parent_query->m_parent;
    v4 = !m_parent || m_parent->m_assert_on_fail;
    v5 = results->m_queries[0].m_error_type == error_type_unset
      && results->m_queries[0].m_create_resource_result != result_error;
    m_error_type = results->m_queries[v5].m_error_type;
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)(2 * (m_error_type == error_type_unset) + 1),
      (vostok::resources::cook_base::result_enum)(2 * (m_error_type == error_type_unset) + 1),
      v4,
      m_error_type);
  }
}
