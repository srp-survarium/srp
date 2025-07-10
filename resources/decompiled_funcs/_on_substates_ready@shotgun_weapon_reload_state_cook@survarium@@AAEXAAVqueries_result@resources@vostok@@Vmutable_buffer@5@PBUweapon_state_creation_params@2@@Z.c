void __thiscall survarium::shotgun_weapon_reload_state_cook::on_substates_ready(
        survarium::shotgun_weapon_reload_state_cook *this,
        vostok::resources::queries_result *data,
        vostok::mutable_buffer buffer,
        const survarium::weapon_state_creation_params *params)
{
  vostok::resources::unmanaged_resource *m_object; // ebx
  survarium::weapon_core_shotgun_reload_base_substate *v5; // esi
  vostok::resources::unmanaged_resource *v6; // ebx
  survarium::weapon_core_shotgun_reload_base_substate *v7; // esi
  vostok::resources::unmanaged_resource *v8; // ebx
  survarium::weapon_core_shotgun_reload_base_substate *v9; // esi
  int v10; // eax
  vostok::configs::binary_config *v11; // eax
  vostok::resources::query_result_for_cook *v12; // ecx
  survarium::weapon_core_shotgun_reload_base_substate *v13; // eax
  vostok::resources::unmanaged_intrusive_base *v14; // ecx
  survarium::weapon_core_shotgun_reload_base_substate *v15; // eax
  vostok::resources::unmanaged_intrusive_base *v16; // ecx
  survarium::weapon_core_shotgun_reload_base_substate *v17; // eax
  vostok::resources::unmanaged_intrusive_base *v18; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v19; // [esp-4h] [ebp-24h] BYREF
  vostok::resources::resource_ptr<survarium::weapon_core_shotgun_reload_base_substate,vostok::resources::unmanaged_intrusive_base> finish_substate; // [esp+Ch] [ebp-14h] BYREF
  vostok::resources::resource_ptr<survarium::weapon_core_shotgun_reload_base_substate,vostok::resources::unmanaged_intrusive_base> reload_one_substate; // [esp+10h] [ebp-10h] BYREF
  vostok::resources::resource_ptr<survarium::weapon_core_shotgun_reload_base_substate,vostok::resources::unmanaged_intrusive_base> start_substate; // [esp+14h] [ebp-Ch] BYREF
  vostok::resources::memory_usage_type memory_usage; // [esp+18h] [ebp-8h] BYREF

  start_substate.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&start_substate,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::resources::unmanaged_resource *)start_substate.m_object;
  if ( start_substate.m_object )
    v5 = (survarium::weapon_core_shotgun_reload_base_substate *)((char *)start_substate.m_object - 24);
  else
    v5 = 0;
  start_substate.m_object = 0;
  vostok::intrusive_ptr<survarium::weapon_core_shotgun_reload_base_substate,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &start_substate,
    v5);
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  reload_one_substate.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&reload_one_substate,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
  v6 = (vostok::resources::unmanaged_resource *)reload_one_substate.m_object;
  if ( reload_one_substate.m_object )
    v7 = (survarium::weapon_core_shotgun_reload_base_substate *)((char *)reload_one_substate.m_object - 24);
  else
    v7 = 0;
  reload_one_substate.m_object = 0;
  vostok::intrusive_ptr<survarium::weapon_core_shotgun_reload_base_substate,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &reload_one_substate,
    v7);
  if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  finish_substate.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&finish_substate,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[2].m_unmanaged_resource);
  v8 = (vostok::resources::unmanaged_resource *)finish_substate.m_object;
  if ( finish_substate.m_object )
    v9 = (survarium::weapon_core_shotgun_reload_base_substate *)((char *)finish_substate.m_object - 24);
  else
    v9 = 0;
  finish_substate.m_object = 0;
  vostok::intrusive_ptr<survarium::weapon_core_shotgun_reload_base_substate,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &finish_substate,
    v9);
  if ( v8 && !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v8->vostok::resources::unmanaged_intrusive_base, v8);
  if ( buffer.m_data
    && (survarium::shotgun_weapon_reload_state::shotgun_weapon_reload_state(
          &start_substate,
          (survarium::shotgun_weapon_reload_state *)buffer.m_data,
          params->weapon,
          &reload_one_substate,
          &finish_substate),
        v10) )
  {
    v11 = (vostok::configs::binary_config *)(v10 + 24);
  }
  else
  {
    v11 = 0;
  }
  memory_usage.type = &vostok::resources::nocache_memory;
  memory_usage.size = 32;
  v19.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v19,
    v11);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    data->m_parent_query,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v19.m_object,
    &memory_usage);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v12,
    result_success,
    assert_on_fail_true,
    error_type_unset);
  v13 = finish_substate.m_object;
  if ( finish_substate.m_object )
  {
    v14 = &finish_substate.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&finish_substate.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v14, &v13->vostok::resources::unmanaged_resource);
  }
  v15 = reload_one_substate.m_object;
  if ( reload_one_substate.m_object )
  {
    v16 = &reload_one_substate.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&reload_one_substate.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v16, &v15->vostok::resources::unmanaged_resource);
  }
  v17 = start_substate.m_object;
  if ( start_substate.m_object )
  {
    v18 = &start_substate.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&start_substate.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v18, &v17->vostok::resources::unmanaged_resource);
  }
}
