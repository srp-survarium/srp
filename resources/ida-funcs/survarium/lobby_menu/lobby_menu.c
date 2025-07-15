void __thiscall survarium::lobby_menu::lobby_menu(
        survarium::lobby_menu *this,
        survarium::lobby_menu *g,
        survarium::flash_text_manager *text_manager)
{
  survarium::flash_external_handler *v3; // ecx
  survarium::flash_function_handler *v4; // ecx
  survarium::game_effect_player *v5; // ecx
  vostok::timing::floating_timer *v6; // ecx
  LARGE_INTEGER QPC; // rax
  vostok::timing::floating_timer *v8; // ecx
  float v9; // eax
  vostok::memory::doug_lea_allocator *v10; // esi
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  char *v13; // eax
  int v14; // eax
  float v15; // eax
  vostok::memory::doug_lea_allocator *v16; // esi
  char *v17; // eax
  vostok::memory::doug_lea_allocator *v18; // ecx
  char *v19; // eax
  float v20; // eax
  vostok::memory::doug_lea_allocator *v21; // esi
  char *v22; // eax
  vostok::memory::doug_lea_allocator *v23; // ecx
  char *v24; // eax
  survarium::lobby_character *v25; // eax
  vostok::memory::doug_lea_allocator *v26; // esi
  char *v27; // eax
  vostok::memory::doug_lea_allocator *v28; // ecx
  char *v29; // eax
  float v30; // eax
  vostok::memory::doug_lea_allocator *v31; // esi
  char *v32; // eax
  vostok::memory::doug_lea_allocator *v33; // ecx
  char *v34; // eax
  float v35; // eax
  float v36; // edi
  survarium::camera_director *m_camera_director; // esi
  survarium::lobby_menu *v38; // ecx
  float v39; // [esp-4h] [ebp-1Ch]
  float v40; // [esp-4h] [ebp-1Ch]
  float v41; // [esp-4h] [ebp-1Ch]
  const char *v42; // [esp+0h] [ebp-18h]
  vostok::physics::world *v43; // [esp+0h] [ebp-18h]
  survarium::camera_director *v44; // [esp+0h] [ebp-18h]
  const char *v45; // [esp+0h] [ebp-18h]
  const char *v46; // [esp+0h] [ebp-18h]
  float v47; // [esp+0h] [ebp-18h]
  const char *v48; // [esp+4h] [ebp-14h]
  const char *v49; // [esp+4h] [ebp-14h]
  const char *v50; // [esp+4h] [ebp-14h]
  const char *v51; // [esp+4h] [ebp-14h]
  const char *v52; // [esp+4h] [ebp-14h]
  unsigned int v53; // [esp+8h] [ebp-10h]
  unsigned int v54; // [esp+8h] [ebp-10h]
  unsigned int v55; // [esp+8h] [ebp-10h]
  unsigned int v56; // [esp+8h] [ebp-10h]
  unsigned int v57; // [esp+8h] [ebp-10h]
  vostok::math::float3 position; // [esp+Ch] [ebp-Ch] BYREF

  survarium::base_game_scene::base_game_scene(this, g, (vostok::network::world *)text_manager, 0);
  survarium::flash_external_handler::flash_external_handler(v3, &g->survarium::flash_external_handler::__vftable);
  survarium::flash_function_handler::flash_function_handler(v4, &g->survarium::flash_function_handler::__vftable);
  g->survarium::flash_function_handler::__vftable = (survarium::flash_function_handler_vtbl *)&survarium::lobby_menu::`vftable'{for `survarium::flash_function_handler'};
  g->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::lobby_menu_vtbl *)&survarium::lobby_menu::`vftable'{for `survarium::base_game_scene'};
  g->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&survarium::lobby_menu::`vftable'{for `vostok::input::handler'};
  g->survarium::flash_external_handler::__vftable = (survarium::flash_external_handler_vtbl *)&survarium::lobby_menu::`vftable'{for `survarium::flash_external_handler'};
  g->m_mouse_helper.m_output_window = (vostok::resources::resource_ptr<vostok::render::base_output_window,vostok::resources::unmanaged_intrusive_base> *)&text_manager[7];
  g->m_lobby_game_project.m_object = 0;
  survarium::game_effect_player::game_effect_player(v5, (int)&g->m_effect_player);
  survarium::first_person_game_effect_presenter::first_person_game_effect_presenter(&g->m_effect_presenter, g, 0);
  g->m_cursor_ui.m_object = 0;
  g->m_lobby_menu_ui.m_object = 0;
  g->m_selected_profile_idx = 0;
  g->m_maintenance_remain = 0;
  g->m_ui_static_info_initialized = 0;
  g->m_is_in_match_making = 0;
  *(_QWORD *)&g->m_last_ping_time_in_ms = 0;
  *(float *)&g->m_player_ammo_bags_count = 0.0;
  g->m_dynamic_quick_slots_count = 0;
  g->m_player_total_items_weight = 0.0;
  g->m_level_loading_progress = 0.0;
  g->m_last_queries_count = 0;
  *(float *)&g->m_in_destroying = 0.0;
  g->m_last_ui_update_time_ms = 0;
  vostok::timing::floating_timer::floating_timer(v6, (LARGE_INTEGER *)&g->m_timer);
  g->m_static_game_parameters_config.m_object = 0;
  *(_QWORD *)&g->m_skills_tree_config.m_object = 0;
  QPC = vostok::timing::get_QPC();
  LODWORD(g->m_timer.m_start_time) = QPC.LowPart;
  LODWORD(g->m_timer.m_stop_floating_ticks) = QPC.LowPart;
  HIDWORD(g->m_timer.m_start_time) = QPC.HighPart;
  g->m_timer.m_current_time = 0;
  HIDWORD(g->m_timer.m_stop_floating_ticks) = QPC.HighPart;
  g->m_current_time_in_ms = vostok::timing::floating_timer::get_elapsed_msec(v8, &g->m_timer);
  *(_DWORD *)&g->m_update_status_handler &= ~0x80000000;
  *(_DWORD *)&g->m_update_friends_status_handler &= ~0x80000000;
  *(_DWORD *)&g->m_update_squad_status_handler &= ~0x80000000;
  vostok::physics::create_world_bt((vostok::physics::engine *)&g->m_mouse_helper);
  *(float *)&g->m_physics_world = v9;
  (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v9) + 8))(COERCE_FLOAT(LODWORD(v9)));
  v10 = survarium::g_allocator;
  v11 = type_info::raw_name(&survarium::lobby_camera `RTTI Type Descriptor');
  v13 = vostok::memory::doug_lea_allocator::malloc_impl(v12, (int)v10, 0xD4u, v11, v42, v48, v53);
  if ( v13 )
    survarium::lobby_camera::lobby_camera(
      (survarium::lobby_camera *)g,
      (int)v13,
      (survarium::lobby_menu *)g->m_physics_world,
      v43);
  else
    v14 = 0;
  if ( v14 )
    LODWORD(v15) = v14 + 4;
  else
    v15 = 0.0;
  v16 = survarium::g_allocator;
  *(float *)&g->m_camera = v15;
  v17 = type_info::raw_name(&survarium::demo_camera `RTTI Type Descriptor');
  v19 = vostok::memory::doug_lea_allocator::malloc_impl(v18, (int)v16, 0xA4u, v17, (const char *const)v43, v49, v54);
  if ( v19 )
    survarium::demo_camera::demo_camera(
      (survarium::demo_camera *)g,
      (int)v19,
      (survarium::base_game_scene *)g->m_camera_director,
      v44);
  else
    v20 = 0.0;
  v21 = survarium::g_allocator;
  *(float *)&g->m_demo_camera = v20;
  v22 = type_info::raw_name(&survarium::lobby_character `RTTI Type Descriptor');
  v24 = vostok::memory::doug_lea_allocator::malloc_impl(v23, (int)v21, 0x11E8u, v22, (const char *const)v44, v50, v55);
  if ( v24 )
  {
    v39 = *(float *)&g->m_physics_world;
    memset(&position, 0, sizeof(position));
    survarium::lobby_character::lobby_character(
      &position,
      (survarium::lobby_character *)v24,
      g,
      (vostok::physics::world *)LODWORD(v39),
      *(const float *)&v45);
  }
  else
  {
    v25 = 0;
  }
  v26 = survarium::g_allocator;
  g->m_character = v25;
  v27 = type_info::raw_name(&survarium::lobby_character `RTTI Type Descriptor');
  v29 = vostok::memory::doug_lea_allocator::malloc_impl(v28, (int)v26, 0x11E8u, v27, v45, v51, v56);
  if ( v29 )
  {
    v40 = *(float *)&g->m_physics_world;
    *(_QWORD *)&position.x = LODWORD(s_bm_current_air_resistance);
    position.z = c_anim_center;
    survarium::lobby_character::lobby_character(
      &position,
      (survarium::lobby_character *)v29,
      g,
      (vostok::physics::world *)LODWORD(v40),
      *(const float *)&v46);
  }
  else
  {
    v30 = 0.0;
  }
  v31 = survarium::g_allocator;
  *(float *)g->m_squad_member = v30;
  v32 = type_info::raw_name(&survarium::lobby_character `RTTI Type Descriptor');
  v34 = vostok::memory::doug_lea_allocator::malloc_impl(v33, (int)v31, 0x11E8u, v32, v46, v52, v57);
  if ( v34 )
  {
    v41 = *(float *)&g->m_physics_world;
    *(_QWORD *)&position.x = LODWORD(FLOAT_N1_0);
    position.z = c_anim_center;
    survarium::lobby_character::lobby_character(
      &position,
      (survarium::lobby_character *)v34,
      g,
      (vostok::physics::world *)LODWORD(v41),
      v47);
  }
  else
  {
    v35 = 0.0;
  }
  v36 = *(float *)&g->m_camera;
  m_camera_director = g->m_camera_director;
  *(float *)&g->m_squad_member[1] = v35;
  survarium::camera_director::switch_to_camera(m_camera_director, (survarium::game_camera *)LODWORD(v36));
  survarium::lobby_menu::query_scene_resources(v38, g);
}
