void __thiscall survarium::game_world::game_world(
        survarium::game_world *this,
        survarium::game_world *game,
        survarium::flash_text_manager *text_manager,
        vostok::sound::world *a4)
{
  vostok::resources::unmanaged_resource *v5; // ecx
  survarium::game_world_ui *v6; // ecx
  vostok::fixed_vector<survarium::sound_game_effect_presenter::effect_data,16>::allign_helper *v7; // esi
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  char *v11; // eax
  survarium::free_fly_camera *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // esi
  char *v14; // eax
  vostok::memory::doug_lea_allocator *v15; // ecx
  char *v16; // eax
  survarium::game_world *v17; // ecx
  survarium::demo_camera *v18; // eax
  const char *v19; // [esp+0h] [ebp-Ch]
  survarium::camera_director *v20; // [esp+0h] [ebp-Ch]
  survarium::camera_director *v21; // [esp+0h] [ebp-Ch]
  const char *v22; // [esp+4h] [ebp-8h]
  const char *v23; // [esp+4h] [ebp-8h]
  unsigned int v24; // [esp+8h] [ebp-4h]
  unsigned int v25; // [esp+8h] [ebp-4h]
  int text_managera; // [esp+18h] [ebp+Ch]

  survarium::base_game_scene::base_game_scene(this, game, (vostok::network::world *)text_manager, a4);
  game->survarium::bullet_manager_engine::__vftable = (survarium::bullet_manager_engine_vtbl *)&survarium::bullet_manager_engine::`vftable';
  vostok::resources::unmanaged_resource::unmanaged_resource(
    v5,
    &game->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable,
    fs_iterator_class);
  game->survarium::bullet_manager_engine::__vftable = (survarium::bullet_manager_engine_vtbl *)&survarium::game_world::`vftable'{for `survarium::bullet_manager_engine'};
  game->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::game_world_vtbl *)&survarium::game_world::`vftable'{for `survarium::base_game_scene'};
  game->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::game_world::`vftable'{for `vostok::resources::unmanaged_resource'};
  game->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&survarium::game_world::`vftable'{for `vostok::input::handler'};
  survarium::game_world_ui::game_world_ui(v6, (int)&game->game_ui, game);
  game->m_game_project.m_object = 0;
  *(_QWORD *)&game->m_game_effects = 0;
  survarium::first_person_game_effect_presenter::first_person_game_effect_presenter(
    &game->m_first_person_game_effect_presenter,
    game,
    &game->game_ui);
  game->m_portal_sector_structure.m_object = 0;
  game->m_bullet_tracers._M_impl._M_start = 0;
  game->m_bullet_tracers._M_impl._M_finish = 0;
  game->m_bullet_tracers._M_impl._M_end_of_storage._M_data = 0;
  game->m_match.m_object = 0;
  game->m_player_camera = 0;
  game->m_step_manager.m_decal_id = 0;
  game->m_step_manager.m_game_world = game;
  game->m_game_material_manager.m_object = 0;
  game->m_mouse_helper.m_output_window = (vostok::resources::resource_ptr<vostok::render::base_output_window,vostok::resources::unmanaged_intrusive_base> *)&text_manager[7];
  game->m_damage_model_stats = 0;
  game->m_is_loading = 0;
  game->m_draw_player_task_type = vostok::tasks::create_new_task_type(
                                    "draw_player",
                                    (vostok::enum_flags<enum vostok::tasks::task_type_flags_enum>)1);
  v7 = (vostok::fixed_vector<survarium::sound_game_effect_presenter::effect_data,16>::allign_helper *)&game->m_third_person_game_effect_presenters[24];
  text_managera = 20;
  do
  {
    if ( v7 != (vostok::fixed_vector<survarium::sound_game_effect_presenter::effect_data,16>::allign_helper *)24 )
    {
      *(_DWORD *)v7[-2].m_store = &survarium::third_person_game_effect_presenter::`vftable';
      *(_DWORD *)&v7[-2].m_store[4] = &survarium::particle_game_effect_presenter::`vftable';
      *(_DWORD *)&v7[-2].m_store[8] = game;
      *(_DWORD *)&v7[-1].m_store[8] = v7 + 4;
      *(_DWORD *)v7[-1].m_store = v7;
      *(_DWORD *)&v7[-1].m_store[4] = v7;
      *(_DWORD *)v7[4].m_store = v7 + 5;
      *(_DWORD *)&v7[4].m_store[4] = v7 + 5;
      *(_DWORD *)&v7[4].m_store[8] = v7 + 9;
      survarium::sound_game_effect_presenter::sound_game_effect_presenter(
        (survarium::sound_game_effect_presenter *)game,
        (int)v7[9].m_store,
        0,
        (const bool)v19);
    }
    v7 = (vostok::fixed_vector<survarium::sound_game_effect_presenter::effect_data,16>::allign_helper *)((char *)v7 + 560);
    --text_managera;
  }
  while ( text_managera );
  v8 = survarium::g_allocator;
  v9 = type_info::raw_name(&survarium::free_fly_camera `RTTI Type Descriptor');
  v11 = vostok::memory::doug_lea_allocator::malloc_impl(v10, (int)v8, 0x100u, v9, v19, v22, v24);
  if ( v11 )
    survarium::free_fly_camera::free_fly_camera(
      (survarium::free_fly_camera *)game,
      (int)v11,
      (survarium::base_game_scene *)game->m_camera_director,
      v20);
  else
    v12 = 0;
  v13 = survarium::g_allocator;
  game->m_free_fly_camera = v12;
  v14 = type_info::raw_name(&survarium::demo_camera `RTTI Type Descriptor');
  v16 = vostok::memory::doug_lea_allocator::malloc_impl(v15, (int)v13, 0xA4u, v14, (const char *const)v20, v23, v25);
  if ( v16 )
    survarium::demo_camera::demo_camera(
      (survarium::demo_camera *)game,
      (int)v16,
      (survarium::base_game_scene *)game->m_camera_director,
      v21);
  else
    v18 = 0;
  game->m_demo_camera = v18;
  survarium::game_world::register_cooks(v17, game);
}
