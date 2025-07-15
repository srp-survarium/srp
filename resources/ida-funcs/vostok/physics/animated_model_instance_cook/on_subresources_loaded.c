void __thiscall vostok::physics::animated_model_instance_cook::on_subresources_loaded(
        vostok::physics::animated_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v2; // edi
  volatile int m_result; // edx
  vostok::resources::query_result_for_cook *m_parent_query; // eax
  vostok::memory::base_allocator *m_allocator; // esi
  char *v6; // eax
  survarium::pure_game_effect_emitter_base *v7; // eax
  vostok::resources::unmanaged_resource *v8; // ecx
  survarium::pure_game_effect_emitter_base *v9; // esi
  vostok::resources::queries_result *m_object; // esi
  survarium::pure_game_effect_emitter_base *v11; // esi
  survarium::pure_game_effect_emitter_base *v12; // ecx
  vostok::resources::query_result_for_cook *v13; // edi
  survarium::pure_game_effect_emitter_base *v14; // ecx
  vostok::resources::query_result_for_cook *v15; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v16; // [esp-4h] [ebp-28h] BYREF
  vostok::resources::memory_usage_type memory_usage; // [esp+Ch] [ebp-18h] BYREF
  vostok::resources::query_result_for_cook *v18; // [esp+14h] [ebp-10h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v19; // [esp+18h] [ebp-Ch] BYREF
  survarium::pure_game_effect_emitter_base *object; // [esp+1Ch] [ebp-8h]

  v2 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)data;
  m_result = data->m_result;
  m_parent_query = data->m_parent_query;
  v18 = m_parent_query;
  if ( m_result == 1 )
  {
    m_allocator = this->m_allocator;
    v6 = type_info::raw_name(&vostok::physics::animated_model_instance `RTTI Type Descriptor');
    v7 = (survarium::pure_game_effect_emitter_base *)m_allocator->call_malloc(
                                                       m_allocator,
                                                       272u,
                                                       v6,
                                                       "vostok::physics::animated_model_instance_cook::on_subresources_loaded",
                                                       ".\\animated_model_instance_cook.cpp",
                                                       125u);
    v9 = v7;
    if ( v7 )
    {
      vostok::resources::unmanaged_resource::unmanaged_resource(v8, v7, fs_iterator_class);
      v9->__vftable = (survarium::pure_game_effect_emitter_base_vtbl *)&vostok::physics::animated_model_instance::`vftable';
      v9[1].__vftable = 0;
      object = v9;
    }
    else
    {
      object = 0;
    }
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v19,
      v2 + 75);
    m_object = (vostok::resources::queries_result *)v19.m_object;
    data = 0;
    if ( v19.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
      data = m_object;
      _InterlockedExchangeAdd((volatile signed __int32 *)&m_object->m_queries[0].m_target_quality_level, 1u);
    }
    v11 = object;
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&data,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&object[1]);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19);
    v16.m_object = v12;
    memory_usage.type = &vostok::resources::nocache_memory;
    memory_usage.size = 272;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v16,
      v11);
    v13 = v18;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(&memory_usage, v14, v18, v16);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v15,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v13,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
