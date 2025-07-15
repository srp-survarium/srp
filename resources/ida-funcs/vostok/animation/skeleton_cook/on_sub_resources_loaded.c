void __thiscall vostok::animation::skeleton_cook::on_sub_resources_loaded(
        vostok::animation::skeleton_cook *this,
        vostok::resources::queries_result *result)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::resources::query_result_for_cook *m_parent_query; // edi
  vostok::configs::binary_config *m_object; // esi
  unsigned int v5; // ebx
  unsigned int v6; // ebp
  char *v7; // esi
  int v8; // ecx
  unsigned int v9; // edx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp-Ch] [ebp-30h] BYREF
  assert_on_fail_bool v11; // [esp-8h] [ebp-2Ch]
  vostok::resources::query_result_for_user::error_type_enum v12; // [esp-4h] [ebp-28h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp+10h] [ebp-14h] BYREF
  unsigned int bones_count; // [esp+14h] [ebp-10h] BYREF
  char *bones_ids_buffer; // [esp+18h] [ebp-Ch] BYREF
  vostok::configs::binary_config_value *config; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int last_index; // [esp+20h] [ebp-4h] BYREF

  last_index = 0;
  m_result = (vostok::resources::query_result_for_cook *)result->m_result;
  m_parent_query = result->m_parent_query;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    v13.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v13,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result->m_queries[0].m_unmanaged_resource);
    m_object = v13.m_object;
    bones_count = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&bones_count,
      v13.m_object);
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    result = 0;
    v5 = bones_count;
    bones_count = get_bones_count(
                    *(const vostok::configs::binary_config_value **)(bones_count + 264),
                    (unsigned int *)&result);
    v6 = 20 * bones_count;
    v7 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(
                   &vostok::memory::g_resources_unmanaged_allocator,
                   (unsigned int)(&result->m_queries[0].m_creation_source + 5 * bones_count));
    if ( v7 )
    {
      bones_ids_buffer = &v7[v6 + 272];
      last_index = 1;
      config = **(vostok::configs::binary_config_value ***)(v5 + 264);
      add_bone(
        0,
        (vostok::animation::skeleton_bone *)(v7 + 272),
        0,
        &last_index,
        &config,
        (const char **)&bones_ids_buffer,
        (unsigned int *)&result);
      vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)v7, 1u);
      v9 = bones_count;
      v12 = 272;
      v11 = (assert_on_fail_bool)&vostok::resources::nocache_memory;
      *(_DWORD *)v7 = &vostok::animation::skeleton::`vftable';
      *((_DWORD *)v7 + 66) = v9;
      v10.m_object = 0;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        &v10,
        (vostok::configs::binary_config *)v7);
      vostok::resources::query_result_for_cook::set_unmanaged_resource(
        m_parent_query,
        (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v10.m_object,
        (const vostok::resources::memory_type *)v11,
        v12);
      v12 = error_type_unset;
      v11 = assert_on_fail_true;
      v10.m_object = (vostok::configs::binary_config *)3;
    }
    else
    {
      v12 = error_type_unset;
      v8 = 272;
      v11 = assert_on_fail_true;
      m_parent_query->m_out_of_memory.type = &vostok::resources::unmanaged_memory;
      m_parent_query->m_out_of_memory.size = 272;
      v10.m_object = (vostok::configs::binary_config *)5;
    }
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)v8,
      (vostok::resources::cook_base::result_enum)v10.m_object,
      v11,
      v12);
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v5 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(v5 + 208),
        (vostok::resources::unmanaged_resource *)v5);
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
