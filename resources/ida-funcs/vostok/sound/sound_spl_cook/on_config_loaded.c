void __thiscall vostok::sound::sound_spl_cook::on_config_loaded(
        vostok::sound::sound_spl_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent)
{
  char *v3; // eax
  vostok::particle::particle_system_instance_impl *v4; // eax
  vostok::resources::unmanaged_resource *v5; // ecx
  vostok::particle::particle_system_instance_impl *v6; // esi
  vostok::particle::particle_system_instance_impl *m_object; // esi
  const vostok::configs::binary_config_value *v8; // esi
  survarium::pure_game_effect_emitter_base *v9; // edi
  int v10; // ecx
  vostok::resources::query_result_for_cook *v11; // ecx
  vostok::resources::query_result_for_cook *v12; // ecx
  _BYTE v13[28]; // [esp-14h] [ebp-34h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v14; // [esp+14h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v15; // [esp+18h] [ebp-8h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v16; // [esp+1Ch] [ebp-4h] BYREF

  v3 = type_info::raw_name(&vostok::sound::sound_spl `RTTI Type Descriptor');
  v4 = (vostok::particle::particle_system_instance_impl *)vostok::memory::g_resources_unmanaged_allocator.call_malloc(
                                                            &vostok::memory::g_resources_unmanaged_allocator,
                                                            328,
                                                            v3,
                                                            "vostok::sound::sound_spl_cook::on_config_loaded",
                                                            ".\\sound_spl_cook.cpp",
                                                            49);
  v6 = v4;
  if ( v4 )
  {
    vostok::resources::unmanaged_resource::unmanaged_resource(v5, v4, fs_iterator_class);
    v6->__vftable = (vostok::particle::particle_system_instance_impl_vtbl *)&vostok::sound::sound_spl::`vftable';
    v6->m_lods[0].m_emitter_instance_list.m_last = 0;
    v6->m_lods[0].m_distance = 0.0;
    v6->m_lods[1].m_emitter_instance_list.m_last = 0;
    v6->m_lods[1].m_distance = 0.0;
  }
  else
  {
    v6 = 0;
  }
  v15.m_object = 0;
  if ( v6 )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v15);
    v15.m_object = v6;
    _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v16,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v16.m_object;
  v14.m_object = 0;
  if ( v16.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v14);
    v14.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v16);
  v8 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)v14.m_object->m_lods[0].m_template.m_object,
         "spl");
  *(_DWORD *)v13 = &vostok::memory::g_resources_unmanaged_allocator;
  qmemcpy(&v13[4], v8, 0x18u);
  vostok::math::curve_line_points<float,0>::load<vostok::configs::binary_config_value>(
    0,
    (vostok::math::curve_line_points<float,0> *)v15.m_object->m_lods,
    *(vostok::configs::binary_config_value *)v13,
    *(int *)&v13[24]);
  qmemcpy(
    &v13[4],
    vostok::configs::binary_config_value::operator[](
      (vostok::configs::binary_config_value *)v14.m_object->m_lods[0].m_template.m_object,
      "volume"),
    0x18u);
  v9 = (survarium::pure_game_effect_emitter_base *)v15.m_object;
  *(_DWORD *)v13 = &vostok::memory::g_resources_unmanaged_allocator;
  vostok::math::curve_line_points<float,0>::load<vostok::configs::binary_config_value>(
    0,
    (vostok::math::curve_line_points<float,0> *)&v15.m_object->m_lods[1],
    *(vostok::configs::binary_config_value *)v13,
    *(int *)&v13[24]);
  *(_DWORD *)&v13[24] = 328;
  *(_DWORD *)&v13[20] = &vostok::resources::nocache_memory;
  *(_DWORD *)&v13[16] = v10;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v13[16],
    v9);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v11,
    parent,
    *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v13[16],
    *(const vostok::resources::memory_type **)&v13[20],
    *(unsigned int *)&v13[24]);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v12,
    (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v14);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v15);
}
