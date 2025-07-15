void __thiscall vostok::collision::animated_object_cook::translate_query(
        vostok::collision::animated_object_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::configs::binary_config_value **p_m_root; // esi
  survarium::pure_game_effect_emitter_base *v4; // eax
  survarium::pure_game_effect_emitter_base *v5; // edi
  const vostok::configs::binary_config_value *v6; // eax
  unsigned int v7; // eax
  survarium::pure_game_effect_emitter_base *v8; // ecx
  survarium::pure_game_effect_emitter_base *v9; // ecx
  vostok::resources::query_result_for_cook *v10; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v11; // [esp-4h] [ebp-24h] BYREF
  vostok::collision::animated_object_cook_data out_value; // [esp+10h] [ebp-10h] BYREF
  vostok::resources::memory_usage_type memory_usage; // [esp+18h] [ebp-8h] BYREF

  out_value.config.m_object = 0;
  out_value.skeleton.m_object = 0;
  vostok::variant<32>::try_get<vostok::collision::animated_object_cook_data>(
    (vostok::variant<32> *)this,
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)parent->m_user_data,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&out_value);
  p_m_root = &out_value.config.m_object->m_root;
  vostok::physics::new_animated_bt_hit_model(out_value.config.m_object->m_root, &out_value.skeleton, this->m_allocator);
  v5 = v4;
  v6 = *p_m_root;
  memory_usage.type = &vostok::resources::nocache_memory;
  v7 = vostok::physics::calculate_bt_animated_body_size_from_hit_targets_config(v6);
  v11.m_object = v8;
  memory_usage.size = v7;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v11,
    v5);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(&memory_usage, v9, parent, v11);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v10,
    (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&out_value.skeleton);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&out_value);
}
