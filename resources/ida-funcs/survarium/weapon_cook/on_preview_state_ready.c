void __thiscall survarium::weapon_cook::on_preview_state_ready(
        survarium::weapon_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *data,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *params,
        survarium::weapon_core *object_to_cook)
{
  vostok::memory::doug_lea_allocator *v4; // esi
  vostok::memory::doug_lea_allocator *v5; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v6; // ebx
  survarium::weapon_core *v7; // esi
  int *v8; // ecx
  int v9; // eax
  vostok::resources::query_result_for_cook *m_object; // eax
  survarium::pure_game_effect_emitter_base *v11; // ecx
  survarium::pure_game_effect_emitter_base *v12; // ecx
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v14[4]; // [esp-4h] [ebp-20h] BYREF
  vostok::resources::memory_usage_type v15; // [esp+Ch] [ebp-10h] BYREF
  survarium::weapon_cook *v16; // [esp+14h] [ebp-8h]

  v4 = survarium::g_allocator;
  v16 = this;
  if ( params )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(params);
    vostok::memory::doug_lea_allocator::free_impl(
      v5,
      (int)v4,
      (char *)params,
      (const char *const)v14[1].m_object,
      (const char *const)v14[2].m_object,
      (const unsigned int)v14[3].m_object);
  }
  v6 = data;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data[75]);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&data,
    (vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *)&params);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  v7 = object_to_cook;
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>>::push_back(
    (const vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *)&params,
    &object_to_cook->m_logic_states);
  vostok::ai::fsm::add_state((vostok::ai::fsm *)params, &v7->m_logic->m_states.m_size);
  v8 = (int *)v16;
  v7->m_chamber_a_round_on_reload = 0;
  v9 = *v8;
  v15.type = &vostok::resources::nocache_memory;
  v15.size = (*(int (__thiscall **)(int *, survarium::weapon_core *))(v9 + 44))(v8, v7);
  m_object = (vostok::resources::query_result_for_cook *)v6[8].m_object;
  v14[0].m_object = v11;
  data = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)m_object;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    v14,
    (survarium::pure_game_effect_emitter_base *)&v7->survarium::inventory_item);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(&v15, v12, data, v14[0]);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v13,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v6[8].m_object,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&params);
}
