void __thiscall vostok::animation::single_animation_cook::on_sub_resources_loaded(
        vostok::animation::single_animation_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_parent_query; // ebx
  vostok::resources::query_result_for_cook *v3; // ecx
  vostok::resources::managed_resource *m_object; // esi
  vostok::resources::query_result_for_user *v5; // ecx
  vostok::particle::particle_system_instance_impl *v6; // edi
  vostok::particle::particle_system_instance_impl *v7; // esi
  vostok::configs::binary_config_value **m_lods; // esi
  vostok::configs::binary_config_value *v9; // ecx
  const void *pointer; // eax
  char *v11; // eax
  float *v12; // esi
  const vostok::configs::binary_config_value *v13; // eax
  float v14; // xmm0_4
  __int64 v15; // rax
  const vostok::configs::binary_config_value *v16; // eax
  float v17; // xmm0_4
  __int64 v18; // rax
  vostok::resources::managed_resource *v19; // xmm0_4
  char *v20; // eax
  const vostok::configs::binary_config_value *v21; // eax
  float v22; // xmm0_4
  __int64 v23; // rax
  char *v24; // eax
  float *v25; // eax
  char *v26; // eax
  float *v27; // eax
  const char *v28; // eax
  vostok::resources::managed_resource *unmanaged_memory; // eax
  vostok::resources::managed_resource *v30; // ecx
  vostok::animation::single_animation *v31; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v32; // edi
  vostok::resources::query_result_for_cook *v33; // ecx
  vostok::resources::query_result_for_cook *v34; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v35; // [esp-8h] [ebp-54h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v36; // [esp-4h] [ebp-50h] BYREF
  unsigned int v37; // [esp+0h] [ebp-4Ch]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v38; // [esp+14h] [ebp-38h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v39; // [esp+18h] [ebp-34h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v40; // [esp+1Ch] [ebp-30h] BYREF
  int v41; // [esp+20h] [ebp-2Ch]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v42; // [esp+28h] [ebp-24h]
  int v43; // [esp+30h] [ebp-1Ch]
  vostok::configs::binary_config_value v44; // [esp+34h] [ebp-18h] BYREF

  m_parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)data->m_parent_query;
  v42 = m_parent_query;
  if ( !vostok::resources::query_result_for_user::is_successful(
          (vostok::resources::query_result_for_user *)this,
          (int)data->m_queries) )
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      v3,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
    return;
  }
  m_object = vostok::resources::query_result_for_user::get_managed_resource(&data->m_queries[0], &v40)->m_object;
  v38.m_object = 0;
  if ( m_object )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v38);
    v38.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v40);
  if ( vostok::resources::query_result_for_user::is_successful(v5, (int)&data->m_queries[1]) )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v40,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[1].m_unmanaged_resource);
    v6 = (vostok::particle::particle_system_instance_impl *)v40.m_object;
    v7 = 0;
    v39.m_object = 0;
    if ( v40.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v39);
      v7 = v6;
      v39.m_object = v6;
      _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v40);
    m_lods = (vostok::configs::binary_config_value **)v7->m_lods;
    if ( vostok::configs::binary_config_value::value_exists(v9, (int)*m_lods, (unsigned int)"interpolator") )
    {
      qmemcpy((void *)&v44, vostok::configs::binary_config_value::operator[](*m_lods, "interpolator"), sizeof(v44));
      pointer = vostok::configs::binary_config_value::operator[](&v44, "type")->data.pointer;
      v41 = 0;
      if ( pointer )
      {
        if ( pointer == (const void *)1 )
        {
          v20 = type_info::raw_name(&vostok::animation::linear_interpolator `RTTI Type Descriptor');
          v12 = (float *)vostok::memory::g_resources_unmanaged_allocator.call_malloc(
                           &vostok::memory::g_resources_unmanaged_allocator,
                           8,
                           v20,
                           "vostok::animation::single_animation_cook::on_sub_resources_loaded",
                           ".\\single_animation_cook.cpp",
                           96);
          if ( v12 )
          {
            v21 = vostok::configs::binary_config_value::operator[](&v44, "time");
            if ( v21->type == 2 )
            {
              v22 = *(float *)&v21->data.pointer;
            }
            else
            {
              v23 = (int)v21->data.pointer;
              v43 = HIDWORD(v23);
              v22 = (float)(int)v23;
            }
            *(_DWORD *)v12 = &vostok::animation::linear_interpolator::`vftable';
            v12[1] = v22;
            goto LABEL_29;
          }
        }
        else
        {
          v11 = type_info::raw_name(&vostok::animation::fermi_interpolator `RTTI Type Descriptor');
          v12 = (float *)vostok::memory::g_resources_unmanaged_allocator.call_malloc(
                           &vostok::memory::g_resources_unmanaged_allocator,
                           12,
                           v11,
                           "vostok::animation::single_animation_cook::on_sub_resources_loaded",
                           ".\\single_animation_cook.cpp",
                           102);
          if ( v12 )
          {
            v13 = vostok::configs::binary_config_value::operator[](&v44, "epsilon");
            if ( v13->type == 2 )
            {
              v14 = *(float *)&v13->data.pointer;
            }
            else
            {
              v15 = (int)v13->data.pointer;
              v41 = HIDWORD(v15);
              v14 = (float)(int)v15;
            }
            v40.m_object = (vostok::resources::managed_resource *)LODWORD(v14);
            v16 = vostok::configs::binary_config_value::operator[](&v44, "time");
            if ( v16->type == 2 )
            {
              v17 = *(float *)&v16->data.pointer;
            }
            else
            {
              v18 = (int)v16->data.pointer;
              v43 = HIDWORD(v18);
              v17 = (float)(int)v18;
            }
            v12[1] = v17;
            v19 = v40.m_object;
            *(_DWORD *)v12 = &vostok::animation::fermi_interpolator::`vftable';
            *((_DWORD *)v12 + 2) = v19;
            goto LABEL_29;
          }
        }
        goto LABEL_28;
      }
      v24 = type_info::raw_name(&vostok::animation::instant_interpolator `RTTI Type Descriptor');
      v37 = 90;
    }
    else
    {
      v24 = type_info::raw_name(&vostok::animation::instant_interpolator `RTTI Type Descriptor');
      v37 = 112;
    }
    v25 = (float *)vostok::memory::g_resources_unmanaged_allocator.call_malloc(
                     &vostok::memory::g_resources_unmanaged_allocator,
                     4,
                     v24,
                     "vostok::animation::single_animation_cook::on_sub_resources_loaded",
                     ".\\single_animation_cook.cpp",
                     v37);
    if ( v25 )
    {
      v12 = v25;
      *(_DWORD *)v25 = &vostok::animation::instant_interpolator::`vftable';
LABEL_29:
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v39);
      goto LABEL_33;
    }
LABEL_28:
    v12 = 0;
    goto LABEL_29;
  }
  v26 = type_info::raw_name(&vostok::animation::instant_interpolator `RTTI Type Descriptor');
  v27 = (float *)vostok::memory::g_resources_unmanaged_allocator.call_malloc(
                   &vostok::memory::g_resources_unmanaged_allocator,
                   4,
                   v26,
                   "vostok::animation::single_animation_cook::on_sub_resources_loaded",
                   ".\\single_animation_cook.cpp",
                   117);
  if ( v27 )
  {
    *(_DWORD *)v27 = &vostok::animation::instant_interpolator::`vftable';
    v12 = v27;
  }
  else
  {
    v12 = 0;
  }
LABEL_33:
  v28 = type_info::name(&vostok::animation::single_animation `RTTI Type Descriptor', &__type_info_root_node);
  unmanaged_memory = (vostok::resources::managed_resource *)vostok::resources::allocate_unmanaged_memory(0x110u, v28);
  v30 = (vostok::resources::managed_resource *)v37;
  v40.m_object = unmanaged_memory;
  if ( unmanaged_memory )
  {
    v37 = (unsigned int)v12;
    v36.m_object = v30;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      &v36,
      &v38);
    vostok::animation::single_animation::single_animation(
      v31,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v40.m_object,
      (vostok::animation::base_interpolator *)v36.m_object,
      v37);
  }
  v37 = 272;
  v36.m_object = (vostok::resources::managed_resource *)&vostok::resources::nocache_memory;
  v35.m_object = (survarium::pure_game_effect_emitter_base *)v30;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v35,
    (survarium::pure_game_effect_emitter_base *)v40.m_object);
  v32 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v42;
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v33,
    v42,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v35.m_object,
    (const vostok::resources::memory_type *)v36.m_object,
    v37);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v34,
    v32,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v38);
}
