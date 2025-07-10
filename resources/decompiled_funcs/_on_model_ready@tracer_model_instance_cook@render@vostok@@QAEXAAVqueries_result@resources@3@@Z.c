void __thiscall vostok::render::tracer_model_instance_cook::on_model_ready(
        vostok::render::tracer_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_cook *m_parent_query; // eax
  int *v3; // eax
  int *v4; // ebx
  vostok::configs::binary_config *m_object; // eax
  vostok::resources::unmanaged_intrusive_base *v6; // ecx
  vostok::resources::query_result_for_cook *v7; // edi
  vostok::resources::query_result_for_cook *v8; // ecx
  vostok::render::static_model_instance *v9; // eax
  vostok::resources::unmanaged_intrusive_base *v10; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v11; // [esp-Ch] [ebp-64h] BYREF
  const vostok::resources::memory_type *v12; // [esp-8h] [ebp-60h]
  unsigned int v13; // [esp-4h] [ebp-5Ch]
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> static_model; // [esp+Ch] [ebp-4Ch]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v15; // [esp+10h] [ebp-48h] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+14h] [ebp-44h]
  vostok::math::float4x4 v17; // [esp+18h] [ebp-40h] BYREF

  m_parent_query = data->m_parent_query;
  parent = m_parent_query;
  if ( data->m_queries[0].m_error_type || data->m_queries[0].m_create_resource_result == result_error )
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      (int)m_parent_query,
      result_success,
      assert_on_fail_true,
      0);
  }
  else
  {
    v3 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x150u);
    v4 = v3;
    if ( v3 )
    {
      vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)v3, 1u);
      *v4 = (int)&vostok::render::tracer_model_instance::`vftable';
      v4[82] = 0;
      v4[83] = -1;
    }
    else
    {
      v4 = 0;
    }
    v15.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v15,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = v15.m_object;
    static_model.m_object = 0;
    if ( v15.m_object )
    {
      v6 = &v15.m_object->vostok::resources::unmanaged_intrusive_base;
      static_model.m_object = (vostok::render::static_model_instance *)v15.m_object;
      _InterlockedExchangeAdd(&v15.m_object->m_reference_count, 1u);
      if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v6, m_object);
    }
    vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>::operator=(
      (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)&static_model.m_object->m_render_model,
      (vostok::resources::unmanaged_resource **)v4 + 82);
    qmemcpy(v4 + 66, vostok::math::float4x4::identity(&v17), 0x40u);
    v13 = 336;
    v12 = &vostok::resources::nocache_memory;
    v4[83] = 0;
    v11.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v11,
      (vostok::configs::binary_config *)v4);
    v7 = parent;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      parent,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v11.m_object,
      v12,
      v13);
    vostok::resources::query_result_for_cook::finish_query_impl(v8, (int)v7, result_success, assert_on_fail_true, 0);
    v9 = static_model.m_object;
    if ( static_model.m_object )
    {
      v10 = &static_model.m_object->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&static_model.m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v10, v9);
    }
  }
}
