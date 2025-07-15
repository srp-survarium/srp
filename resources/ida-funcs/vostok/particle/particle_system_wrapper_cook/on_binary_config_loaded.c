void __thiscall vostok::particle::particle_system_wrapper_cook::on_binary_config_loaded(
        vostok::particle::particle_system_wrapper_cook *this,
        vostok::resources::queries_result *result)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_parent_query; // edi
  vostok::resources::queries_result *m_object; // esi
  char *v5; // eax
  _DWORD *v6; // eax
  vostok::particle::particle_system *v7; // ecx
  vostok::memory::base_allocator *v8; // eax
  vostok::memory::base_allocator *v9; // esi
  survarium::pure_game_effect_emitter_base *v10; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v11; // edi
  vostok::resources::query_result_for_cook *v12; // ecx
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v14; // [esp-Ch] [ebp-20h] BYREF
  const vostok::resources::memory_type *v15; // [esp-8h] [ebp-1Ch]
  unsigned int v16; // [esp-4h] [ebp-18h]
  bool v17; // [esp+0h] [ebp-14h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v18; // [esp+Ch] [ebp-8h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v19; // [esp+10h] [ebp-4h] BYREF

  m_result = (vostok::resources::query_result_for_cook *)result->m_result;
  m_parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)result->m_parent_query;
  v18 = m_parent_query;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v19,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&result->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::resources::queries_result *)v19.m_object;
    result = 0;
    if ( v19.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
      result = m_object;
      _InterlockedExchangeAdd((volatile signed __int32 *)&m_object->m_queries[0].m_target_quality_level, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19);
    v19.m_object = (survarium::pure_game_effect_emitter_base *)result->m_queries[0].m_next_for_grm_observer_list;
    v5 = type_info::raw_name(&vostok::particle::particle_system `RTTI Type Descriptor');
    v6 = vostok::memory::g_resources_unmanaged_allocator.call_malloc(
           &vostok::memory::g_resources_unmanaged_allocator,
           280,
           v5,
           "vostok::particle::particle_system_wrapper_cook::on_binary_config_loaded",
           ".\\particle_system_wrapper_cook.cpp",
           142);
    if ( v6 )
    {
      vostok::particle::particle_system::particle_system(v7, v6);
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    v16 = (unsigned int)v19.m_object;
    v9[13].m_arena_start = 0;
    v9[13].m_arena_id = 0;
    vostok::particle::particle_system::load_from_config<vostok::configs::binary_config_value>(
      v7,
      v9,
      &vostok::memory::g_resources_unmanaged_allocator,
      (const vostok::configs::binary_config_value *)v16,
      v17);
    v16 = 280;
    v15 = &vostok::resources::unmanaged_memory;
    v14.m_object = v10;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v14,
      (survarium::pure_game_effect_emitter_base *)v9);
    v11 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v18;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v12,
      v18,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v14.m_object,
      v15,
      v16);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v13,
      v11,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
