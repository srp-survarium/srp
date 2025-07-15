void __thiscall survarium::victory_item_core_cook::on_config_loaded(
        survarium::victory_item_core_cook *this,
        vostok::resources::queries_result *data,
        vostok::physics::world *physics_world)
{
  char *v3; // eax
  survarium::victory_item_core *v4; // ecx
  vostok::resources::class_id_enum v5; // eax
  vostok::resources::class_id_enum v6; // edi
  int v7; // eax
  vostok::resources::queries_result *v8; // ebx
  vostok::resources::queries_result *v9; // esi
  vostok::particle::particle_system_instance_impl *v10; // ecx
  survarium::victory_item_core_cook *v11; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp-8h] [ebp-1Ch] BYREF
  vostok::resources::class_id_enum v13; // [esp-4h] [ebp-18h]
  const char *v14; // [esp+0h] [ebp-14h]
  const char *v15; // [esp+4h] [ebp-10h]
  unsigned int v16; // [esp+8h] [ebp-Ch]
  vostok::resources::query_result_for_cook *parent; // [esp+Ch] [ebp-8h]
  vostok::resources::class_id_enum v18; // [esp+10h] [ebp-4h]

  parent = (vostok::resources::query_result_for_cook *)this;
  v3 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)this,
         (int)survarium::g_allocator,
         0x3C8u,
         "victory_item_core",
         v14,
         v15,
         v16);
  if ( v3 )
  {
    survarium::victory_item_core::victory_item_core(v4, (int)v3, physics_world);
    v6 = v5;
    v18 = v5;
  }
  else
  {
    v18 = unknown_data_class;
    v6 = unknown_data_class;
  }
  if ( v6 == -472 )
    v7 = 0;
  else
    survarium::portable_interactive_object_core::portable_interactive_object_core(
      (survarium::portable_interactive_object_core *)v4,
      v6 + 472);
  v8 = data;
  *(_DWORD *)(v6 + 444) = v7;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v8->m_queries[0].m_unmanaged_resource);
  v9 = data;
  physics_world = 0;
  if ( data )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&physics_world);
    physics_world = (vostok::physics::world *)v9;
    _InterlockedExchangeAdd((volatile signed __int32 *)&v9->m_queries[0].m_target_quality_level, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  v13 = v18;
  v12.m_object = v10;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v12,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&physics_world);
  survarium::victory_item_core_cook::process_loading_victory_item_core(
    v11,
    parent,
    (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>)v8->m_parent_query,
    (survarium::victory_item_core *)v12.m_object,
    v13);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&physics_world);
}
