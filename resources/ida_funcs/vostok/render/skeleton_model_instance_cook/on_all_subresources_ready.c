void __thiscall vostok::render::skeleton_model_instance_cook::on_all_subresources_ready(
        vostok::render::skeleton_model_instance_cook *this,
        vostok::render::skeleton_model_instance_cook_data *cook_data)
{
  int *v2; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v3; // edi
  vostok::render::render_model_instance *m_object; // ecx
  vostok::render::render_model_instance *v5; // eax
  vostok::resources::unmanaged_resource *v6; // edx
  vostok::animation::skeleton *v7; // ecx
  vostok::animation::skeleton *v8; // eax
  vostok::resources::unmanaged_resource *type; // edx
  vostok::resources::unmanaged_resource_vtbl *v10; // ebx
  int v11; // edx
  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *p_unlink_child_resource; // ebx
  vostok::math::float4x4 *M_start; // edi
  vostok::math::float4x4 *v14; // eax
  int v15; // ecx
  vostok::resources::query_result_for_cook *v16; // ecx
  vostok::animation::skeleton *v17; // eax
  vostok::render::grass_render_model *v18; // edi
  vostok::render::render_model_instance *v19; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  int v21; // [esp+10h] [ebp-50h]
  vostok::render::skeleton_model_instance *created_resource; // [esp+14h] [ebp-4Ch]
  unsigned int i; // [esp+18h] [ebp-48h]
  vostok::resources::query_result_for_cook *parent_query; // [esp+1Ch] [ebp-44h]
  vostok::math::float4x4 __x; // [esp+20h] [ebp-40h] BYREF

  parent_query = cook_data->parent_query;
  v2 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x110u);
  v3.m_object = (vostok::resources::unmanaged_resource *)v2;
  if ( v2 )
  {
    vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)v2, 1u);
    v3.m_object->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&vostok::render::skeleton_model_instance::`vftable';
    v3.m_object[1].__vftable = 0;
    v3.m_object[1].type = 0;
    created_resource = (vostok::render::skeleton_model_instance *)v3.m_object;
  }
  else
  {
    created_resource = 0;
    v3.m_object = 0;
  }
  m_object = cook_data->render_model.m_object;
  v5 = 0;
  if ( m_object )
  {
    v5 = cook_data->render_model.m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v6 = (vostok::resources::unmanaged_resource *)v3.m_object[1].__vftable;
  v3.m_object[1].__vftable = (vostok::resources::unmanaged_resource_vtbl *)v5;
  if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  v7 = cook_data->skeleton.m_object;
  v8 = 0;
  if ( v7 )
  {
    v8 = cook_data->skeleton.m_object;
    _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
  }
  type = (vostok::resources::unmanaged_resource *)v3.m_object[1].type;
  v3.m_object[1].type = (unsigned int)v8;
  if ( type && !_InterlockedExchangeAdd(&type->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&type->vostok::resources::unmanaged_intrusive_base, type);
  v10 = v3.m_object[1].__vftable;
  v11 = *((_DWORD *)v10[14].is_increasing_quality + 81) - *((_DWORD *)v10[14].is_increasing_quality + 80);
  p_unlink_child_resource = (stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *)&v10[14].unlink_child_resource;
  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::resize(
    p_unlink_child_resource,
    v11 >> 6,
    &__x);
  i = 0;
  if ( p_unlink_child_resource->_M_finish - p_unlink_child_resource->_M_start )
  {
    v21 = 0;
    do
    {
      M_start = p_unlink_child_resource->_M_start;
      v14 = vostok::math::float4x4::identity(&__x);
      v15 = v21;
      v21 += 64;
      qmemcpy((char *)M_start + v15, v14, sizeof(vostok::math::float4x4));
      ++i;
    }
    while ( i < p_unlink_child_resource->_M_finish - p_unlink_child_resource->_M_start );
    v3.m_object = created_resource;
  }
  _InterlockedExchangeAdd(&v3.m_object->m_reference_count, 1u);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    parent_query,
    v3,
    &vostok::resources::nocache_memory,
    0x110u);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v16,
    (int)parent_query,
    result_success,
    assert_on_fail_true,
    0);
  v17 = cook_data->skeleton.m_object;
  v18 = vostok::render::g_allocator.m_object;
  if ( v17 && !_InterlockedExchangeAdd(&v17->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &cook_data->skeleton.m_object->vostok::resources::unmanaged_intrusive_base,
      cook_data->skeleton.m_object);
  v19 = cook_data->render_model.m_object;
  if ( v19 && !_InterlockedExchangeAdd(&v19->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &cook_data->render_model.m_object->vostok::resources::unmanaged_intrusive_base,
      cook_data->render_model.m_object);
  m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(v18->m_reconstruction_info_actuality_tick);
  BYTE2(v18->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (char *)&cook_data->render_model_ready);
}
