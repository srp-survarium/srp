void __thiscall vostok::animation::single_animation_cook::on_sub_resources_loaded(
        vostok::animation::single_animation_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::unmanaged_resource *m_object; // esi
  vostok::configs::binary_config *v3; // edi
  const void *v4; // eax
  bool v5; // zf
  void *(__thiscall *call_malloc)(struct vostok::memory::doug_lea_allocator *, unsigned int); // eax
  vostok::animation::base_interpolator *v7; // ebx
  const vostok::configs::binary_config_value *v8; // eax
  float v9; // xmm0_4
  __int64 v10; // rax
  const vostok::configs::binary_config_value *v11; // eax
  float v12; // xmm0_4
  __int64 v13; // rax
  vostok::configs::binary_config *v14; // xmm0_4
  const vostok::configs::binary_config_value *v15; // eax
  vostok::animation::base_interpolator_vtbl *pointer; // xmm0_4
  __int64 v17; // rax
  vostok::animation::base_interpolator *v18; // eax
  int *v19; // esi
  vostok::animation::single_animation *v20; // ecx
  vostok::resources::query_result_for_cook *v21; // ecx
  vostok::animation::base_interpolator *v22; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v23; // [esp-Ch] [ebp-54h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v24; // [esp-8h] [ebp-50h] BYREF
  unsigned int v25; // [esp-4h] [ebp-4Ch]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v26; // [esp+10h] [ebp-38h] BYREF
  int v27; // [esp+14h] [ebp-34h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> anim; // [esp+1Ch] [ebp-2Ch] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config; // [esp+20h] [ebp-28h] BYREF
  int v30; // [esp+24h] [ebp-24h]
  vostok::resources::query_result_for_cook *parent; // [esp+2Ch] [ebp-1Ch]
  vostok::configs::binary_config_value interpolator_value; // [esp+30h] [ebp-18h] BYREF

  parent = data->m_parent_query;
  if ( data->m_queries[0].m_error_type || data->m_queries[0].m_create_resource_result == result_error )
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
    return;
  }
  v26.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v26,
    &data->m_queries[0].m_managed_resource);
  anim.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &anim,
    v26.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v26);
  if ( data->m_queries[1].m_error_type == error_type_unset
    && data->m_queries[1].m_create_resource_result != result_error )
  {
    v26.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v26,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
    m_object = (vostok::resources::unmanaged_resource *)v26.m_object;
    config.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &config,
      (vostok::configs::binary_config *)v26.m_object);
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    v3 = config.m_object;
    if ( vostok::configs::binary_config_value::value_exists(config.m_object->m_root, "interpolator")
      && (interpolator_value = *vostok::configs::binary_config_value::operator[](v3->m_root, "interpolator"),
          v4 = vostok::configs::binary_config_value::operator[](&interpolator_value, "type")->data.pointer,
          v30 = 0,
          v4) )
    {
      v5 = v4 == (const void *)1;
      call_malloc = vostok::memory::g_resources_unmanaged_allocator.call_malloc;
      if ( v5 )
      {
        v7 = (vostok::animation::base_interpolator *)call_malloc(&vostok::memory::g_resources_unmanaged_allocator, 8u);
        if ( v7 )
        {
          v15 = vostok::configs::binary_config_value::operator[](&interpolator_value, "time");
          if ( v15->type == 2 )
          {
            pointer = (vostok::animation::base_interpolator_vtbl *)v15->data.pointer;
            v7->__vftable = (vostok::animation::base_interpolator_vtbl *)&vostok::animation::linear_interpolator::`vftable';
            v7[1].__vftable = pointer;
          }
          else
          {
            v17 = (int)v15->data.pointer;
            v30 = HIDWORD(v17);
            v7->__vftable = (vostok::animation::base_interpolator_vtbl *)&vostok::animation::linear_interpolator::`vftable';
            *(float *)&v7[1].__vftable = (float)(int)v17;
          }
          goto LABEL_27;
        }
      }
      else
      {
        v7 = (vostok::animation::base_interpolator *)call_malloc(&vostok::memory::g_resources_unmanaged_allocator, 12u);
        if ( v7 )
        {
          v8 = vostok::configs::binary_config_value::operator[](&interpolator_value, "epsilon");
          if ( v8->type == 2 )
          {
            v9 = *(float *)&v8->data.pointer;
          }
          else
          {
            v10 = (int)v8->data.pointer;
            v30 = HIDWORD(v10);
            v9 = (float)(int)v10;
          }
          config.m_object = (vostok::configs::binary_config *)LODWORD(v9);
          v11 = vostok::configs::binary_config_value::operator[](&interpolator_value, "time");
          if ( v11->type == 2 )
          {
            v12 = *(float *)&v11->data.pointer;
          }
          else
          {
            v13 = (int)v11->data.pointer;
            v27 = HIDWORD(v13);
            v12 = (float)(int)v13;
          }
          *(float *)&v7[1].__vftable = v12;
          v14 = config.m_object;
          v7->__vftable = (vostok::animation::base_interpolator_vtbl *)&vostok::animation::fermi_interpolator::`vftable';
          v7[2].__vftable = (vostok::animation::base_interpolator_vtbl *)v14;
LABEL_27:
          if ( !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
          goto LABEL_29;
        }
      }
    }
    else
    {
      v18 = (vostok::animation::base_interpolator *)vostok::memory::g_resources_unmanaged_allocator.call_malloc(
                                                      &vostok::memory::g_resources_unmanaged_allocator,
                                                      4);
      if ( v18 )
      {
        v7 = v18;
        v18->__vftable = (vostok::animation::base_interpolator_vtbl *)&vostok::animation::instant_interpolator::`vftable';
        goto LABEL_27;
      }
    }
    v7 = 0;
    goto LABEL_27;
  }
  v22 = (vostok::animation::base_interpolator *)vostok::memory::g_resources_unmanaged_allocator.call_malloc(
                                                  &vostok::memory::g_resources_unmanaged_allocator,
                                                  4);
  if ( v22 )
  {
    v22->__vftable = (vostok::animation::base_interpolator_vtbl *)&vostok::animation::instant_interpolator::`vftable';
    v7 = v22;
  }
  else
  {
    v7 = 0;
  }
LABEL_29:
  type_info::name(&vostok::animation::single_animation `RTTI Type Descriptor', &__type_info_root_node);
  v19 = vostok::memory::doug_lea_allocator::malloc_impl(&vostok::memory::g_resources_unmanaged_allocator, 0x110u);
  if ( v19 )
  {
    v25 = (unsigned int)v7;
    v24.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v24,
      &anim);
    vostok::animation::single_animation::single_animation(
      v20,
      (int)v19,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v24.m_object,
      (vostok::animation::base_interpolator *)v25);
  }
  v25 = 272;
  v24.m_object = (vostok::resources::managed_resource *)&vostok::resources::nocache_memory;
  v23.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v23,
    (vostok::configs::binary_config *)v19);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    parent,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v23.m_object,
    (const vostok::resources::memory_type *)v24.m_object,
    v25);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v21,
    result_success,
    assert_on_fail_true,
    error_type_unset);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&anim);
}
