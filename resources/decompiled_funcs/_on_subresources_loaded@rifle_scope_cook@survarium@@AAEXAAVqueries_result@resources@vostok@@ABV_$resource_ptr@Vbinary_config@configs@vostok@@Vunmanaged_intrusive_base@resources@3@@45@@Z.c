void __thiscall survarium::rifle_scope_cook::on_subresources_loaded(
        survarium::rifle_scope_cook *this,
        vostok::resources::queries_result *results,
        const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *config)
{
  vostok::configs::binary_config *v3; // ebx
  vostok::configs::binary_config *m_object; // eax
  vostok::resources::unmanaged_intrusive_base *v5; // ecx
  vostok::configs::binary_config *v6; // eax
  vostok::resources::unmanaged_intrusive_base *v7; // ecx
  vostok::configs::binary_config_value *v8; // edi
  const vostok::configs::binary_config_value *v9; // eax
  float v10; // xmm0_4
  __int64 pointer; // rax
  const vostok::configs::binary_config_value *v12; // eax
  float v13; // xmm0_4
  __int64 v14; // rax
  const vostok::configs::binary_config_value *v15; // eax
  float change_scope_factor; // xmm0_4
  __int64 v17; // rax
  vostok::configs::binary_config *v18; // eax
  vostok::resources::query_result_for_cook *m_parent_query; // edi
  vostok::resources::query_result_for_cook *v20; // ecx
  vostok::render::static_model_instance *v21; // eax
  vostok::resources::unmanaged_intrusive_base *v22; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> near_plane_factor; // [esp+Ch] [ebp-34h] BYREF
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> idle_scope; // [esp+1Ch] [ebp-24h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v25; // [esp+20h] [ebp-20h] BYREF
  float fov_factor; // [esp+24h] [ebp-1Ch]
  float v27; // [esp+28h] [ebp-18h]
  int v28; // [esp+2Ch] [ebp-14h]
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> aimed_scope; // [esp+34h] [ebp-Ch] BYREF
  vostok::resources::memory_usage_type hide_weapon_on_aim; // [esp+38h] [ebp-8h] BYREF

  v3 = 0;
  hide_weapon_on_aim.type = 0;
  v25.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v25,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&results->m_queries[0].m_unmanaged_resource);
  m_object = v25.m_object;
  idle_scope.m_object = 0;
  if ( v25.m_object )
  {
    v5 = &v25.m_object->vostok::resources::unmanaged_intrusive_base;
    idle_scope.m_object = (vostok::render::static_model_instance *)v25.m_object;
    _InterlockedExchangeAdd(&v25.m_object->m_reference_count, 1u);
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v5, m_object);
  }
  v25.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v25,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&results->m_queries[1].m_unmanaged_resource);
  v6 = v25.m_object;
  aimed_scope.m_object = 0;
  if ( v25.m_object )
  {
    v3 = v25.m_object;
    v7 = &v25.m_object->vostok::resources::unmanaged_intrusive_base;
    aimed_scope.m_object = (vostok::render::static_model_instance *)v25.m_object;
    _InterlockedExchangeAdd(&v25.m_object->m_reference_count, 1u);
    if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v7, v6);
  }
  v8 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 config->m_object->m_root,
                                                 "data");
  if ( vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
         0x120u) )
  {
    v9 = vostok::configs::binary_config_value::operator[](v8, "near_plane_factor");
    if ( v9->type == 2 )
    {
      v10 = *(float *)&v9->data.pointer;
    }
    else
    {
      pointer = (int)v9->data.pointer;
      hide_weapon_on_aim.size = HIDWORD(pointer);
      v10 = (float)(int)pointer;
    }
    v25.m_object = (vostok::configs::binary_config *)LODWORD(v10);
    v12 = vostok::configs::binary_config_value::operator[](v8, "fov_factor");
    if ( v12->type == 2 )
    {
      v13 = *(float *)&v12->data.pointer;
    }
    else
    {
      v14 = (int)v12->data.pointer;
      hide_weapon_on_aim.size = HIDWORD(v14);
      v13 = (float)(int)v14;
    }
    fov_factor = v13;
    LOBYTE(hide_weapon_on_aim.type) = vostok::configs::binary_config_value::operator[](v8, "hide_weapon_on_aim")->data.pointer != 0;
    v15 = vostok::configs::binary_config_value::operator[](v8, "change_scope_factor");
    if ( v15->type == 2 )
    {
      change_scope_factor = *(float *)&v15->data.pointer;
    }
    else
    {
      v17 = (int)v15->data.pointer;
      v28 = HIDWORD(v17);
      change_scope_factor = (float)(int)v17;
    }
    v27 = change_scope_factor;
    survarium::rifle_scope::rifle_scope(
      (survarium::rifle_scope *)&idle_scope,
      &idle_scope,
      &aimed_scope,
      change_scope_factor,
      (const bool)hide_weapon_on_aim.type,
      fov_factor,
      *(const float *)&v25.m_object);
  }
  else
  {
    v18 = 0;
  }
  m_parent_query = results->m_parent_query;
  hide_weapon_on_aim.type = &vostok::resources::nocache_memory;
  hide_weapon_on_aim.size = 288;
  near_plane_factor.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &near_plane_factor,
    v18);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    &hide_weapon_on_aim,
    m_parent_query,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)near_plane_factor.m_object);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v20,
    (int)m_parent_query,
    result_success,
    assert_on_fail_true,
    0);
  if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
  v21 = idle_scope.m_object;
  if ( idle_scope.m_object )
  {
    v22 = &idle_scope.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&idle_scope.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v22, v21);
  }
}
