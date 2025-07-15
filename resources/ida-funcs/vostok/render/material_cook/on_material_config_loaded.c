void __thiscall vostok::render::material_cook::on_material_config_loaded(
        vostok::render::material_cook *this,
        vostok::particle::particle_system_instance_impl *result)
{
  vostok::resources::query_result_for_cook *m_lock; // ecx
  vostok::resources::query_result_for_cook *m_uid; // ebx
  vostok::render::material_cook *v4; // ecx

  m_lock = (vostok::resources::query_result_for_cook *)result->m_parent_resources.m_lock;
  m_uid = (vostok::resources::query_result_for_cook *)result->m_uid;
  if ( m_lock == (vostok::resources::query_result_for_cook *)1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&result,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&result->m_lods[1].m_emitter_instance_list);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
    vostok::render::material_cook::on_material_binary_config_loaded(v4, m_uid, result);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_lock,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_uid,
      result_success,
      assert_on_fail_false,
      result_out_of_memory|0x8);
  }
}
