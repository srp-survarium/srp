void __thiscall vostok::core::configs::binary_config_cook::on_binary_config_loaded(
        vostok::core::configs::binary_config_cook *this,
        survarium::pure_game_effect_emitter_base *data,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *parent_query)
{
  survarium::pure_game_effect_emitter_base *m_object; // esi
  survarium::pure_game_effect_emitter_base *v4; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v5; // edi
  vostok::resources::query_result_for_cook *v6; // ecx
  vostok::resources::query_result_for_cook *v7; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v8; // [esp-Ch] [ebp-1Ch] BYREF
  const vostok::resources::memory_type *v9; // [esp-8h] [ebp-18h]
  unsigned int v10; // [esp-4h] [ebp-14h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v11; // [esp+Ch] [ebp-4h] BYREF

  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v11,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data[1].m_children_resources);
  m_object = v11.m_object;
  data = 0;
  if ( v11.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    data = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11);
  v10 = 280;
  v9 = &vostok::resources::nocache_memory;
  v8.m_object = v4;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v8,
    data);
  v5 = parent_query;
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v6,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)parent_query,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v8.m_object,
    v9,
    v10);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v7,
    v5,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
}
