void __usercall survarium::game_world::game_world(survarium::game_world *this@<ecx>, survarium::game *game@<eax>)
{
  vostok::memory::base_allocator *f; // ecx
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  survarium::step_manager *v7; // eax
  vostok::physics::bullet_physics_world *v8; // ecx
  vostok::physics::world *v9; // eax
  void *v10; // eax
  survarium::game_world *v11; // ecx
  survarium::free_fly_camera *v12; // eax
  vostok::ai::world *world; // eax
  survarium::game *m_game; // edx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game_world,char const *>,boost::_bi::list2<boost::_bi::value<survarium::game_world *>,boost::arg<1> > > v15; // [esp-10h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game_world,char const *>,boost::_bi::list2<boost::_bi::value<survarium::game_world *>,boost::arg<1> > > v16; // [esp-10h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::game_world>,boost::_bi::list1<boost::_bi::value<survarium::game_world *> > > v17; // [esp-10h] [ebp-44h]
  vostok::physics::engine *v18; // [esp+0h] [ebp-34h]
  boost::function<void __cdecl(char const *)> functor; // [esp+10h] [ebp-24h] BYREF

  survarium::base_game_scene::base_game_scene(this, game);
  this->survarium::bullet_manager_engine::__vftable = (survarium::bullet_manager_engine_vtbl *)&survarium::bullet_manager_engine::`vftable';
  vostok::resources::unmanaged_resource::unmanaged_resource(&this->vostok::resources::unmanaged_resource, 1u);
  this->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::game_world_vtbl *)&survarium::game_world::`vftable'{for `survarium::game_scene'};
  this->survarium::base_game_scene::survarium::engine::__vftable = (survarium::engine_vtbl *)&survarium::game_world::`vftable'{for `survarium::engine'};
  this->vostok::ai::engine::__vftable = (vostok::ai::engine_vtbl *)&survarium::game_world::`vftable'{for `vostok::ai::engine'};
  this->vostok::ai::navigation::engine::__vftable = (vostok::ai::navigation::engine_vtbl *)&survarium::game_world::`vftable'{for `vostok::ai::navigation::engine'};
  this->survarium::bullet_manager_engine::__vftable = (survarium::bullet_manager_engine_vtbl *)&survarium::game_world::`vftable'{for `survarium::bullet_manager_engine'};
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::game_world::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&survarium::game_world::`vftable'{for `vostok::input::handler'};
  survarium::game_world_ui::game_world_ui((survarium::game_world_ui *)this, (int)&this->game_ui);
  this->m_enemies_for_team_1._M_impl._M_start = 0;
  this->m_enemies_for_team_1._M_impl._M_finish = 0;
  this->m_enemies_for_team_1._M_impl._M_end_of_storage._M_data = 0;
  this->m_enemies_for_team_2._M_impl._M_start = 0;
  this->m_enemies_for_team_2._M_impl._M_finish = 0;
  this->m_enemies_for_team_2._M_impl._M_end_of_storage._M_data = 0;
  this->m_game_project.m_object = 0;
  this->m_portal_sector_structure.m_object = 0;
  this->m_player_camera = 0;
  this->m_bullet_manager = 0;
  this->m_step_manager = 0;
  this->m_game_material_manager.m_object = 0;
  this->m_ai_world = 0;
  this->m_ai_navigation_world = 0;
  this->m_bullet_tracers._M_impl._M_start = 0;
  this->m_bullet_tracers._M_impl._M_finish = 0;
  this->m_bullet_tracers._M_impl._M_end_of_storage._M_data = 0;
  `vector constructor iterator'(
    (char *)this->death_particles,
    4u,
    16,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  f = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  this->m_death_particles_it = 0;
  this->m_npcs.m_size = 0;
  this->m_npcs.m_first.m_object = 0;
  this->m_npcs.m_last.m_object = 0;
  this->m_active_npc_stats = 0;
  this->m_damage_model_stats = 0;
  this->m_selected_npc.m_object = 0;
  this->m_input_mode = free_fly_mode;
  this->m_is_dictionary_created = 0;
  this->m_active_npc_set = 0;
  this->m_is_loading = 0;
  this->m_victory_items._M_impl._M_start = 0;
  this->m_victory_items._M_impl._M_finish = 0;
  this->m_victory_items._M_impl._M_end_of_storage.m_allocator = f;
  this->m_victory_items._M_impl._M_end_of_storage._M_data = 0;
  if ( (_S6_8 & 1) == 0 )
  {
    _S6_8 |= 1u;
    functor.vtable = (boost::detail::function::vtable_base *)survarium::game_world::add_enemy_position_for_team;
    (&functor.vtable)[1] = 0;
    v15.f_.f_ = (void (__thiscall *__ptr64)(survarium::game_world *, const char *))(unsigned int)survarium::game_world::add_enemy_position_for_team;
    functor.functor.obj_ptr = this;
    *(_QWORD *)&v15.l_.a1_.t_ = *(_QWORD *)&functor.functor.obj_ptr;
    boost::function1<void,char const *>::function1<void,char const *>(
      (boost::function1<void,char const *> *)f,
      (int)&functor,
      (int)this,
      v15,
      (int)v18);
    vostok::console_commands::cc_delegate::cc_delegate(
      &add_enemy_position_cc,
      "add_enemy",
      &functor,
      1,
      command_type_engine_internal);
    if ( functor.vtable )
    {
      if ( ((int)functor.vtable & 1) == 0 )
      {
        v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
        if ( v4 )
          v4(&functor.functor, &functor.functor, 2);
      }
    }
    atexit(survarium::game_world::game_world_::_2_::_dynamic_atexit_destructor_for__add_enemy_position_cc__);
  }
  if ( (_S6_8 & 2) == 0 )
  {
    _S6_8 |= 2u;
    functor.vtable = (boost::detail::function::vtable_base *)survarium::game_world::clear_enemies_positions_for_team;
    (&functor.vtable)[1] = 0;
    v16.f_.f_ = (void (__thiscall *__ptr64)(survarium::game_world *, const char *))(unsigned int)survarium::game_world::clear_enemies_positions_for_team;
    functor.functor.obj_ptr = this;
    *(_QWORD *)&v16.l_.a1_.t_ = *(_QWORD *)&functor.functor.obj_ptr;
    boost::function1<void,char const *>::function1<void,char const *>(
      (boost::function1<void,char const *> *)f,
      (int)&functor,
      (int)this,
      v16,
      (int)v18);
    vostok::console_commands::cc_delegate::cc_delegate(
      &clear_enemies_position_cc,
      "clear_enemies",
      &functor,
      1,
      command_type_engine_internal);
    if ( functor.vtable )
    {
      if ( ((int)functor.vtable & 1) == 0 )
      {
        v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
        if ( v5 )
          v5(&functor.functor, &functor.functor, 2);
      }
    }
    atexit(survarium::game_world::game_world_::_2_::_dynamic_atexit_destructor_for__clear_enemies_position_cc__);
  }
  if ( (_S6_8 & 4) == 0 )
  {
    _S6_8 |= 4u;
    functor.vtable = (boost::detail::function::vtable_base *)survarium::game_world::clear_player_spawn_info;
    (&functor.vtable)[1] = 0;
    v17.f_.f_ = (void (__thiscall *__ptr64)(survarium::game_world *))(unsigned int)survarium::game_world::clear_player_spawn_info;
    functor.functor.obj_ptr = this;
    *(_QWORD *)&v17.l_.a1_.t_ = *(_QWORD *)&functor.functor.obj_ptr;
    boost::function1<void,char const *>::function1<void,char const *>(
      (boost::function1<void,char const *> *)f,
      (int)&functor,
      (int)this,
      v17,
      (int)v18);
    vostok::console_commands::cc_delegate::cc_delegate(
      &clear_player_spawn_cc,
      "clear_player_spawn",
      &functor,
      0,
      command_type_engine_internal);
    if ( functor.vtable )
    {
      if ( ((int)functor.vtable & 1) == 0 )
      {
        v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
        if ( v6 )
          v6(&functor.functor, &functor.functor, 2);
      }
    }
    atexit(survarium::game_world::game_world_::_2_::_dynamic_atexit_destructor_for__clear_player_spawn_cc__);
  }
  v7 = (survarium::step_manager *)vostok::memory::doug_lea_allocator::malloc_impl(
                                    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                    4u);
  if ( v7 )
    v7->m_decal_id = 0;
  else
    v7 = 0;
  this->m_step_manager = v7;
  if ( vostok::memory::g_mt_allocator.call_malloc(&vostok::memory::g_mt_allocator, 96) )
    vostok::physics::bullet_physics_world::bullet_physics_world(v8, (vostok::memory::base_allocator *)&this->gap10, v18);
  else
    v9 = 0;
  this->m_physics_world = v9;
  v9->initialize(v9);
  v10 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
          0x88u);
  if ( v10 )
    survarium::free_fly_camera::free_fly_camera(
      (survarium::free_fly_camera *)this,
      (int)v10,
      this->m_camera_director,
      (survarium::camera_director *)v18);
  else
    v12 = 0;
  this->m_free_fly_camera = v12;
  survarium::game_world::register_cooks(v11);
  world = vostok::ai::create_world(&this->vostok::ai::engine);
  m_game = this->m_game;
  this->m_ai_world = world;
  this->m_ai_navigation_world = vostok::ai::navigation::create_world(
                                  &this->vostok::ai::navigation::engine,
                                  &this->m_render_scene,
                                  m_game->m_renderer->m_debug);
}
