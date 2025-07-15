void __thiscall survarium::weapon_ammunition_cook::on_config_ready(
        survarium::weapon_ammunition_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent)
{
  vostok::resources::queries_result *size; // esi
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  survarium::inventory_item *v7; // ecx
  survarium::pure_game_effect_emitter_base *v8; // esi
  const vostok::configs::binary_config_value *v9; // eax
  survarium::weapon_ammunition *v10; // ecx
  survarium::pure_game_effect_emitter_base *v11; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v12; // edi
  survarium::pure_game_effect_emitter_base *v13; // ecx
  vostok::resources::query_result_for_cook *v14; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v15[3]; // [esp-4h] [ebp-14h] BYREF
  vostok::resources::memory_usage_type v16; // [esp+8h] [ebp-8h] BYREF

  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v16.size,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  size = (vostok::resources::queries_result *)v16.size;
  data = 0;
  if ( v16.size )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    data = size;
    _InterlockedExchangeAdd((volatile signed __int32 *)&size->m_queries[0].m_target_quality_level, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v16.size);
  v4 = survarium::g_allocator;
  v5 = type_info::raw_name(&survarium::weapon_ammunition `RTTI Type Descriptor');
  v8 = (survarium::pure_game_effect_emitter_base *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                     v6,
                                                     (int)v4,
                                                     0x168u,
                                                     v5,
                                                     (const char *const)v15[1].m_object,
                                                     (const char *const)v15[2].m_object,
                                                     (const unsigned int)v16.type);
  if ( v8 )
  {
    survarium::inventory_item::inventory_item(v7, (int)v8, disabled, 1);
    v8->__vftable = (survarium::pure_game_effect_emitter_base_vtbl *)&survarium::weapon_ammunition::`vftable';
  }
  else
  {
    v8 = 0;
  }
  v9 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)data->m_queries[0].m_next_for_grm_observer_list,
         "data");
  survarium::weapon_ammunition::load(v10, (int)v8, v9);
  v15[0].m_object = v11;
  v16.type = &vostok::resources::nocache_memory;
  v16.size = 360;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    v15,
    v8);
  v12 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent;
  vostok::resources::query_result_for_cook::set_unmanaged_resource(&v16, v13, parent, v15[0]);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v14,
    v12,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
}
