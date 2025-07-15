void __thiscall vostok::render::skeleton_render_model_instance_cook::on_sub_resources_loaded(
        vostok::render::skeleton_render_model_instance_cook *this,
        vostok::render::skeleton_render_model *data)
{
  vostok::resources::query_result_for_cook *m_lock; // ecx
  vostok::resources::query_result_for_cook *m_uid; // ebp
  vostok::configs::binary_config *v4; // edi
  vostok::resources::unmanaged_resource *v5; // eax
  vostok::render::skeleton_render_model *v6; // ebx
  vostok::resources::unmanaged_intrusive_base *v7; // ecx
  void *v8; // eax
  vostok::render::skeleton_render_model_instance *v9; // ecx
  vostok::configs::binary_config *v10; // eax
  vostok::resources::query_result_for_cook *v11; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp-Ch] [ebp-24h] BYREF
  const vostok::resources::memory_type *v13; // [esp-8h] [ebp-20h]
  vostok::resources::resource_ptr<vostok::render::skeleton_render_model,vostok::resources::unmanaged_intrusive_base> v14; // [esp-4h] [ebp-1Ch]
  int v15; // [esp+14h] [ebp-4h]

  m_lock = (vostok::resources::query_result_for_cook *)data->m_parent_resources.m_lock;
  m_uid = (vostok::resources::query_result_for_cook *)data->m_uid;
  v4 = 0;
  v15 = 0;
  if ( m_lock == (vostok::resources::query_result_for_cook *)1 )
  {
    v14.m_object = (vostok::render::skeleton_render_model *)&data->m_childs;
    data = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v14.m_object);
    v5 = data;
    v6 = 0;
    if ( data )
    {
      v7 = &data->vostok::resources::unmanaged_intrusive_base;
      v6 = data;
      _InterlockedExchangeAdd(&data->m_reference_count, 1u);
      if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v7, v5);
    }
    v8 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x1B0u);
    if ( v8 )
    {
      vostok::render::skeleton_render_model_instance::skeleton_render_model_instance(v9, (int)v8);
      v4 = v10;
    }
    v14.m_object = 0;
    if ( v6 )
    {
      v14.m_object = v6;
      v9 = (vostok::render::skeleton_render_model_instance *)_InterlockedExchangeAdd(&v6->m_reference_count, 1u);
    }
    vostok::render::skeleton_render_model_instance::assign_original(v9, (int)v4, v14);
    v14.m_object = (vostok::render::skeleton_render_model *)432;
    v13 = &vostok::resources::nocache_memory;
    v12.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v12,
      v4);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      m_uid,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v12.m_object,
      v13,
      (unsigned int)v14.m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v11,
      result_success,
      assert_on_fail_true,
      error_type_unset);
    if ( v6 )
    {
      if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
    }
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_lock,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
}
