void __thiscall survarium::weapon_preview_state_cook::on_preview_animation_ready(
        survarium::weapon_preview_state_cook *this,
        vostok::resources::queries_result *data,
        vostok::mutable_buffer buffer,
        survarium::weapon_core *weapon)
{
  vostok::resources::managed_resource *m_object; // esi
  survarium::weapon_core_base_state *v5; // ecx
  char *m_data; // ebx
  survarium::pure_game_effect_emitter_base *v7; // edi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_parent_query; // ebx
  survarium::pure_game_effect_emitter_base *v9; // ecx
  vostok::resources::query_result_for_cook *v10; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v11; // [esp-4h] [ebp-1Ch] BYREF
  vostok::resources::memory_usage_type v12; // [esp+Ch] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v13; // [esp+14h] [ebp-4h] BYREF

  m_object = vostok::resources::query_result_for_user::get_managed_resource(
               &data->m_queries[0],
               (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v12.size)->m_object;
  v13.m_object = 0;
  if ( m_object )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v13);
    v13.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v12.size);
  m_data = buffer.m_data;
  if ( buffer.m_data )
  {
    survarium::weapon_core_base_state::weapon_core_base_state(v5, (int)buffer.m_data, weapon, weapon_state_count);
    *(_DWORD *)buffer.m_data = &survarium::weapon_preview_state::`vftable'{for `vostok::ai::fsm_state'};
    *((_DWORD *)buffer.m_data + 6) = &survarium::weapon_preview_state::`vftable'{for `vostok::resources::unmanaged_resource'};
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)buffer.m_data
    + 76,
      &v13);
  }
  else
  {
    m_data = 0;
  }
  if ( m_data )
    v7 = (survarium::pure_game_effect_emitter_base *)(m_data + 24);
  else
    v7 = 0;
  m_parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)data->m_parent_query;
  v11.m_object = (survarium::pure_game_effect_emitter_base *)v5;
  v12.type = &vostok::resources::nocache_memory;
  v12.size = 312;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v11,
    v7);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(&v12, v9, m_parent_query, v11);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v10,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)data->m_parent_query,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v13);
}
