void __thiscall vostok::render::material_cook::on_material_binary_config_loaded(
        vostok::render::material_cook *this,
        vostok::resources::query_result_for_cook *parent,
        vostok::particle::particle_system_instance_impl *cfg)
{
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  vostok::particle::particle_system_instance_impl *v6; // ecx
  vostok::render::material *v7; // ecx
  int v8; // eax
  int v9; // edi
  char *requested_path; // edx
  survarium::pure_game_effect_emitter_base *v11; // ecx
  vostok::resources::query_result_for_cook *v12; // ecx
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v14; // [esp-Ch] [ebp-1Ch] BYREF
  const vostok::resources::memory_type *v15; // [esp-8h] [ebp-18h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v16[4]; // [esp-4h] [ebp-14h] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> in_config; // [esp+Ch] [ebp-4h]

  v3 = vostok::render::g_allocator;
  v4 = type_info::raw_name(&vostok::render::material `RTTI Type Descriptor');
  in_config.m_object = (vostok::configs::binary_config *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                           v5,
                                                           (int)v3,
                                                           0x1A0u,
                                                           v4,
                                                           (const char *const)v16[1].m_object,
                                                           (const char *const)v16[2].m_object,
                                                           (const unsigned int)v16[3].m_object);
  if ( in_config.m_object )
  {
    v16[0].m_object = v6;
    vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
      v16,
      cfg);
    vostok::render::material::material(v7, in_config, v16[0]);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(parent);
  v11 = *(survarium::pure_game_effect_emitter_base **)(v9 + 264);
  if ( v11 != (survarium::pure_game_effect_emitter_base *)requested_path )
  {
    *(_DWORD *)(v9 + 268) = v11;
    LOBYTE(v11->__vftable) = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)(v9 + 264), requested_path);
  }
  v16[0].m_object = (vostok::particle::particle_system_instance_impl *)416;
  v15 = &vostok::resources::nocache_memory;
  v14.m_object = v11;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v14,
    (survarium::pure_game_effect_emitter_base *)v9);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v12,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)parent,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v14.m_object,
    v15,
    (unsigned int)v16[0].m_object);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v13,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
