void __cdecl vostok::animation::bi_spline_skeleton_animation_impl_cook::on_resources_ready(
        vostok::resources::queries_result *results,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *parent_query)
{
  vostok::resources::query_result_for_user *v2; // ecx
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v3; // ebx
  const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v4; // edi
  vostok::resources::unmanaged_resource *obj_ptr; // eax
  assert_on_fail_bool v6; // eax
  bool is_successful; // al
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::resources::queries_result *v9; // esi
  survarium::pure_game_effect_emitter_base *v10; // esi
  survarium::pure_game_effect_emitter_base *v11; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v12; // edi
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::query_result_for_cook *v14; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v15; // [esp-Ch] [ebp-24h] BYREF
  const vostok::resources::memory_type *v16; // [esp-8h] [ebp-20h]
  assert_on_fail_bool v17; // [esp-4h] [ebp-1Ch]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v18; // [esp+Ch] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v19; // [esp+10h] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v20; // [esp+14h] [ebp-4h] BYREF

  v3 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)results;
  if ( results->m_result == 1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v19,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&results->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v19.m_object;
    v20.m_object = 0;
    if ( v19.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v20);
      v20.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19);
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v18,
      v3 + 259);
    v9 = (vostok::resources::queries_result *)v18.m_object;
    results = 0;
    if ( v18.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&results);
      results = v9;
      _InterlockedExchangeAdd((volatile signed __int32 *)&v9->m_queries[0].m_target_quality_level, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v18);
    v10 = (survarium::pure_game_effect_emitter_base *)v20.m_object;
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&results,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v20.m_object->m_lods);
    v17 = 272;
    v16 = &vostok::resources::nocache_memory;
    v15.m_object = v11;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v15,
      v10);
    v12 = parent_query;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v13,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)parent_query,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v15.m_object,
      v16,
      v17);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v14,
      v12,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&results);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v20);
  }
  else
  {
    v4 = parent_query;
    obj_ptr = (vostok::resources::unmanaged_resource *)parent_query[7].m_on_out_of_memory.functor.obj_ptr;
    v6 = !obj_ptr || obj_ptr->m_parent_resources.m_first;
    v17 = v6;
    is_successful = vostok::resources::query_result_for_user::is_successful(v2, (int)results->m_queries);
    vostok::resources::query_result_for_cook::finish_query(
      (vostok::resources::query_result_for_cook *)(736 * is_successful),
      v4,
      (vostok::resources::query_result_for_user::error_type_enum)v3[184 * is_successful + 84].m_object,
      v17);
  }
}
