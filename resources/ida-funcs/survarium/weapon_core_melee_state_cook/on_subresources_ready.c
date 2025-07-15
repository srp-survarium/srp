void __thiscall survarium::weapon_core_melee_state_cook::on_subresources_ready(
        survarium::weapon_core_melee_state_cook *this,
        vostok::resources::queries_result *data,
        vostok::mutable_buffer buffer,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *params)
{
  char *m_data; // ebx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v5; // esi
  vostok::resources::queries_result *v6; // ebx
  vostok::resources::managed_resource *m_object; // edi
  vostok::resources::managed_resource *v8; // edi
  survarium::pure_game_effect_emitter_base *v9; // ecx
  survarium::pure_game_effect_emitter_base *v10; // edi
  vostok::resources::query_result_for_cook *m_parent_query; // eax
  survarium::pure_game_effect_emitter_base *v12; // ecx
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v14; // [esp-4h] [ebp-1Ch] BYREF
  vostok::resources::memory_usage_type v15; // [esp+10h] [ebp-8h] BYREF

  m_data = buffer.m_data;
  if ( buffer.m_data )
  {
    v5 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)buffer.m_data;
    survarium::weapon_core_base_state::weapon_core_base_state(
      (survarium::weapon_core_base_state *)this,
      (int)buffer.m_data,
      (survarium::weapon_core *)params[1].m_object,
      weapon_state_melee);
    *(_DWORD *)m_data = &survarium::weapon_core_melee_state::`vftable'{for `vostok::ai::fsm_state'};
    *((_DWORD *)m_data + 6) = &survarium::weapon_core_melee_state::`vftable'{for `vostok::resources::unmanaged_resource'};
    *((_DWORD *)m_data + 76) = 0;
    *((_DWORD *)m_data + 77) = 0;
    *((_DWORD *)m_data + 78) = 0;
  }
  else
  {
    v5 = 0;
  }
  v6 = data;
  m_object = vostok::resources::query_result_for_user::get_managed_resource(
               &data->m_queries[0],
               (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data)->m_object;
  params = 0;
  if ( m_object )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&params);
    params = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&params,
    v5 + 76);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&params);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data);
  v8 = vostok::resources::query_result_for_user::get_managed_resource(
         &v6->m_queries[1],
         (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data)->m_object;
  params = 0;
  if ( v8 )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&params);
    params = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v8;
    _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
  }
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&params,
    v5 + 77);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&params);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data);
  if ( v5 )
    v10 = (survarium::pure_game_effect_emitter_base *)&v5[6];
  else
    v10 = 0;
  m_parent_query = v6->m_parent_query;
  v14.m_object = v9;
  v15.type = &vostok::resources::nocache_memory;
  v15.size = 320;
  params = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)m_parent_query;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v14,
    v10);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(&v15, v12, params, v14);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v13,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v6->m_parent_query,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
