void __thiscall vostok::render::skeleton_model_instance_cook::on_render_model_loaded(
        vostok::render::skeleton_model_instance_cook *this,
        vostok::resources::queries_result *result,
        vostok::render::skeleton_model_instance_cook_data *cook_data)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::resources::queries_result *m_object; // esi
  vostok::render::skeleton_model_instance_cook_data *v5; // esi
  vostok::render::skeleton_model_instance_cook *v6; // ecx
  bool v7; // zf
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v8; // [esp+Ch] [ebp-4h] BYREF

  m_result = (vostok::resources::query_result_for_cook *)result->m_result;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v8,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&result->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::resources::queries_result *)v8.m_object;
    result = 0;
    if ( v8.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
      result = m_object;
      _InterlockedExchangeAdd((volatile signed __int32 *)&m_object->m_queries[0].m_target_quality_level, 1u);
    }
    v5 = cook_data;
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&result,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&cook_data->render_model);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v8);
    v7 = !v5->skeleton_ready;
    v5->render_model_ready = 1;
    if ( !v7 )
      vostok::render::skeleton_model_instance_cook::on_all_subresources_ready(v6, v5);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)cook_data->parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
