void __usercall survarium::weapon::~weapon(survarium::weapon *this@<ecx>, int a2@<eax>)
{
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v3; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // esi
  unsigned __int8 v5; // bl
  int v6; // eax
  unsigned __int8 j; // bl
  int v8; // eax
  survarium::weapon_core *v9; // ecx
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *i; // [esp+Ch] [ebp-4h]

  v3 = *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 1672);
  v4 = v3 + 1;
  *(_DWORD *)a2 = &survarium::weapon::`vftable'{for `survarium::interactive_object'};
  *(_DWORD *)(a2 + 16) = &survarium::weapon::`vftable'{for `survarium::inventory_item'};
  if ( v3[1].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v5 = 0;
    for ( i = *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + v3[40].m_object->m_fat_it.m_type);
          v5 < *(_BYTE *)(a2 + 1504);
          ++v5 )
    {
      v6 = 4 * v5;
      if ( *(_DWORD *)(*(_DWORD *)(v6 + *(_DWORD *)(a2 + 1496)) + 744) )
        vostok::render::scene_renderer::remove_particle_system_instance(
          (vostok::render::scene_renderer *)(v6 + *(_DWORD *)(a2 + 1496)),
          i,
          v4,
          (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(v6 + *(_DWORD *)(a2 + 1496)));
    }
    for ( j = 0; j < *(_BYTE *)(a2 + 1505); ++j )
    {
      v8 = 4 * j;
      if ( *(_DWORD *)(*(_DWORD *)(v8 + *(_DWORD *)(a2 + 1500)) + 744) )
        vostok::render::scene_renderer::remove_particle_system_instance(
          (vostok::render::scene_renderer *)(v8 + *(_DWORD *)(a2 + 1500)),
          i,
          v4,
          (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(v8 + *(_DWORD *)(a2 + 1500)));
    }
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 1676));
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 1668));
  vostok::circular_buffer<survarium::fx_history_item,10>::~circular_buffer<survarium::fx_history_item,10>((vostok::circular_buffer<survarium::fx_history_item,10> *)(a2 + 1508));
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)(a2 + 1280));
  survarium::weapon_core::~weapon_core(v9, a2);
}
