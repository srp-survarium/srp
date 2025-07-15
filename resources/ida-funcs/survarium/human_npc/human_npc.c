void __thiscall survarium::human_npc::human_npc(
        survarium::human_npc *this,
        survarium::human_npc *game_world,
        survarium::game_world *game_worlda)
{
  vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *v3; // esi
  vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> **v4; // eax
  float *v5; // esi
  float **v6; // eax
  survarium::game *m_game; // ecx
  vostok::resources::unmanaged_resource *m_object; // eax
  __int64 v9; // xmm0_8
  boost::function3<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum> *v10; // ecx
  boost::detail::function::vtable_base *vtable; // eax
  void (__cdecl *v12)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  survarium::game_world_vtbl *v13; // xmm0_4
  boost::_bi::bind_t<void,boost::_mfi::cmf3<void,survarium::human_npc,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>,boost::_bi::list4<boost::_bi::value<survarium::human_npc *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > v14; // [esp-10h] [ebp-94h]
  int v15; // [esp+0h] [ebp-84h]
  __int64 v16; // [esp+18h] [ebp-6Ch]
  boost::function4<void,unsigned int,float,float,char const *> v17; // [esp+20h] [ebp-64h] BYREF
  vostok::math::float4x4 v18; // [esp+40h] [ebp-44h] BYREF

  v3 = (vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)&game_world->vostok::loose_ptr_base;
  v4 = (vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> **)pt3malloc(8u);
  if ( v4 )
  {
    *v4 = v3;
    v4[1] = 0;
  }
  else
  {
    v4 = 0;
  }
  v3->m_object = (vostok::render::base_scene_view *)v4;
  v3->m_object->type = (unsigned int)&v4[1]->m_object + 1;
  vostok::sound::sound_producer::sound_producer(&game_world->vostok::sound::sound_producer);
  vostok::sound::sound_receiver::sound_receiver(&game_world->vostok::sound::sound_receiver);
  game_world->survarium::hit_receiver::vostok::collision::game_object::__vftable = (survarium::hit_receiver_vtbl *)&vostok::collision::game_object::`vftable';
  v5 = (float *)&game_world->vostok::loose_ptr_base;
  v6 = (float **)pt3malloc(8u);
  if ( v6 )
  {
    *v6 = v5;
    v6[1] = 0;
  }
  else
  {
    v6 = 0;
  }
  *(_DWORD *)v5 = v6;
  *(_DWORD *)(*(_DWORD *)v5 + 4) = (char *)v6[1] + 1;
  game_world->survarium::hit_receiver::vostok::collision::game_object::__vftable = (survarium::hit_receiver_vtbl *)&survarium::hit_receiver::`vftable';
  vostok::resources::unmanaged_resource::unmanaged_resource(&game_world->survarium::game_object_, 1u);
  game_world->survarium::game_object_::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::game_object__vtbl *)&survarium::game_object_::`vftable';
  game_world->m_game_scene = game_worlda;
  game_world->survarium::game_object_::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::game_object__vtbl *)&survarium::human_npc::`vftable'{for `survarium::game_object_'};
  game_world->vostok::ai::npc::__vftable = (survarium::human_npc_vtbl *)&survarium::human_npc::`vftable'{for `vostok::ai::npc'};
  game_world->vostok::ai::game_object::__vftable = (vostok::ai::game_object_vtbl *)&survarium::human_npc::`vftable'{for `vostok::ai::game_object'};
  game_world->vostok::sound::sound_producer::__vftable = (vostok::sound::sound_producer_vtbl *)&survarium::human_npc::`vftable'{for `vostok::sound::sound_producer'};
  game_world->vostok::sound::sound_receiver::__vftable = (vostok::sound::sound_receiver_vtbl *)&survarium::human_npc::`vftable'{for `vostok::sound::sound_receiver'};
  game_world->survarium::hit_receiver::vostok::collision::game_object::__vftable = (survarium::hit_receiver_vtbl *)&survarium::human_npc::`vftable'{for `survarium::hit_receiver'};
  game_world->next_npc.m_object = 0;
  game_world->m_ai_world = game_worlda->m_ai_world;
  game_world->m_sound_world = game_worlda->m_game->m_sound_world;
  game_world->m_physics_world = game_worlda->m_physics_world;
  game_world->m_game_world = game_worlda;
  game_world->m_brain_unit.m_object = 0;
  m_game = game_worlda->m_game;
  game_world->m_renderer = m_game->m_renderer;
  game_world->m_model_instance.m_object = 0;
  game_world->m_visibility_parameters.m_transparency = 0.0;
  survarium::human_npc::npc_game_attributes::npc_game_attributes(
    (survarium::human_npc::npc_game_attributes *)m_game,
    (int)&game_world->m_game_attributes);
  qmemcpy((void *)&game_world->m_transform, vostok::math::float4x4::identity(&v18), sizeof(game_world->m_transform));
  game_world->m_last_tick_time_in_ms = 0;
  game_world->m_scene.m_object = 0;
  m_object = game_worlda->m_render_scene.m_object;
  if ( m_object )
  {
    game_world->m_scene.m_object = (vostok::render::base_scene *)m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  game_world->m_sound_scene.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&game_world->m_sound_scene,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&game_worlda->m_sound_scene);
  v14.f_.f_ = (void (__thiscall *__ptr64)(survarium::human_npc *, const char *, survarium::hit_affects_type_enum, survarium::affect_event_type_enum))(unsigned int)survarium::human_npc::on_affect_event;
  LODWORD(v16) = game_world;
  v9 = v16;
  game_world->m_current_animation = 0;
  game_world->m_current_movement_target = 0;
  game_world->m_animations_selector = 0;
  game_world->m_current_target = 0;
  game_world->m_current_weapon = 0;
  game_world->m_is_patrolling = 0;
  *(_QWORD *)&v14.l_.a1_.t_ = v9;
  boost::function3<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>::function3<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>(
    v10,
    (int)&v17,
    0,
    v14,
    v15);
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    &v17,
    (int)&game_world->m_affects_subscription);
  vtable = v17.vtable;
  game_world->m_affects_subscription.next = 0;
  if ( vtable )
  {
    if ( ((unsigned __int8)vtable & 1) == 0 )
    {
      v12 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
      if ( v12 )
        v12(&v17.functor, &v17.functor, 2);
    }
  }
  v13 = (survarium::game_world_vtbl *)clear_value;
  game_world->m_sound_perceived = 0;
  game_world->m_sound_produced = 0;
  game_world->m_dbg_sound = 0;
  game_world->m_default_animation.m_object = 0;
  game_world->m_animation_space_graph.m_object = 0;
  LODWORD(game_world->m_feet_adjustment_speed) = v13;
}
