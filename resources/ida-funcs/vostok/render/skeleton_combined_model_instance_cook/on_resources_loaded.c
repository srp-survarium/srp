void __thiscall vostok::render::skeleton_combined_model_instance_cook::on_resources_loaded(
        vostok::render::skeleton_combined_model_instance_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent_query)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::resources::unmanaged_resource *v4; // eax
  vostok::render::skeleton_model_instance *v5; // esi
  vostok::render::skeleton_model_instance *v6; // edi
  vostok::resources::unmanaged_resource *v7; // ebx
  vostok::resources::unmanaged_resource *v8; // esi
  vostok::resources::unmanaged_resource *v9; // eax
  vostok::render::render_model_instance *v10; // ecx
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::configs::binary_config *v12; // ebx
  vostok::configs::binary_config *v13; // esi
  vostok::configs::binary_config *v14; // eax
  vostok::animation::skeleton *v15; // ecx
  vostok::resources::unmanaged_resource *v16; // eax
  vostok::render::render_model_instance *v17; // ebx
  int v18; // edx
  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *p_m_class_id; // ebx
  int v20; // ecx
  vostok::math::float4x4 *M_start; // edi
  vostok::math::float4x4 *v22; // eax
  vostok::configs::binary_config *v23; // edx
  vostok::math::float4x4 *v24; // esi
  unsigned int v25; // eax
  unsigned int v26; // ecx
  vostok::resources::query_result_for_cook *v27; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v28; // [esp+Ch] [ebp-8Ch] BYREF
  unsigned int i; // [esp+10h] [ebp-88h] BYREF
  vostok::render::skeleton_model_instance *created_resource; // [esp+14h] [ebp-84h]
  vostok::math::float4x4 __x; // [esp+18h] [ebp-80h] BYREF
  vostok::math::float4x4 v32; // [esp+58h] [ebp-40h] BYREF

  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  created_resource = 0;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    v4 = (vostok::resources::unmanaged_resource *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                    (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                    0x110u);
    v5 = (vostok::render::skeleton_model_instance *)v4;
    if ( v4 )
    {
      vostok::resources::unmanaged_resource::unmanaged_resource(v4, 1u);
      v5->__vftable = (vostok::render::skeleton_model_instance_vtbl *)&vostok::render::skeleton_model_instance::`vftable';
      v6 = v5;
      v5->m_render_model.m_object = 0;
      v5->m_skeleton.m_object = 0;
      created_resource = v5;
    }
    else
    {
      created_resource = 0;
      v6 = 0;
    }
    i = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&i,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    v7 = (vostok::resources::unmanaged_resource *)i;
    v8 = 0;
    if ( i )
    {
      v8 = (vostok::resources::unmanaged_resource *)i;
      _InterlockedExchangeAdd((volatile signed __int32 *)(i + 208), 1u);
    }
    v9 = 0;
    if ( v8 )
    {
      v9 = v8;
      _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
    }
    v10 = (vostok::render::render_model_instance *)v9;
    m_object = v6->m_render_model.m_object;
    v6->m_render_model.m_object = v10;
    if ( m_object )
    {
      if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &m_object->vostok::resources::unmanaged_intrusive_base,
          m_object);
      v7 = (vostok::resources::unmanaged_resource *)i;
    }
    if ( v8 && !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v8->vostok::resources::unmanaged_intrusive_base, v8);
    if ( v7 && !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v7->vostok::resources::unmanaged_intrusive_base, v7);
    v28.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v28,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
    v12 = v28.m_object;
    v13 = 0;
    if ( v28.m_object )
    {
      v13 = v28.m_object;
      _InterlockedExchangeAdd(&v28.m_object->m_reference_count, 1u);
    }
    v14 = 0;
    if ( v13 )
    {
      v14 = v13;
      _InterlockedExchangeAdd(&v13->m_reference_count, 1u);
    }
    v15 = (vostok::animation::skeleton *)v14;
    v16 = v6->m_skeleton.m_object;
    v6->m_skeleton.m_object = v15;
    if ( v16 )
    {
      if ( !_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v16->vostok::resources::unmanaged_intrusive_base, v16);
      v12 = v28.m_object;
    }
    if ( v13 && !_InterlockedExchangeAdd(&v13->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v13->vostok::resources::unmanaged_intrusive_base, v13);
    if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v12);
    v17 = v6->m_render_model.m_object;
    v18 = (char *)v17[1].grm_satisfaction_tree_hook.right_[20].left_
        - (char *)v17[1].grm_satisfaction_tree_hook.right_[20].parent_;
    p_m_class_id = (stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *)&v17[1].m_class_id;
    stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::resize(
      p_m_class_id,
      v18 >> 6,
      &__x);
    v20 = p_m_class_id->_M_finish - p_m_class_id->_M_start;
    i = 0;
    if ( v20 )
    {
      v28.m_object = 0;
      do
      {
        M_start = p_m_class_id->_M_start;
        v22 = vostok::math::float4x4::identity(&v32);
        v23 = v28.m_object;
        v28.m_object = (vostok::configs::binary_config *)((char *)v28.m_object + 64);
        v24 = v22;
        v25 = i;
        qmemcpy((char *)M_start + (_DWORD)v23, v24, sizeof(vostok::math::float4x4));
        v26 = p_m_class_id->_M_finish - p_m_class_id->_M_start;
        i = v25 + 1;
      }
      while ( v25 + 1 < v26 );
      v6 = created_resource;
    }
    _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      parent_query,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v6,
      &vostok::resources::nocache_memory,
      0x110u);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v27,
      result_success,
      assert_on_fail_true,
      error_type_unset);
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
