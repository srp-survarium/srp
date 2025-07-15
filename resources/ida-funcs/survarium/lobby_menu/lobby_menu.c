void __usercall survarium::lobby_menu::lobby_menu(survarium::lobby_menu *this@<ecx>, survarium::game *g@<eax>)
{
  vostok::memory::doug_lea_allocator *f; // ecx
  int *v4; // eax
  survarium::camera_director *v5; // ecx
  int v6; // eax
  survarium::game_camera *v7; // eax
  survarium::camera_director *m_camera_director; // edi
  void *v9; // eax
  vostok::physics::bullet_physics_world *v10; // ecx
  vostok::physics::world *v11; // eax
  survarium::lobby_menu *v12; // ecx
  vostok::physics::engine *v13; // [esp+0h] [ebp-Ch]

  survarium::base_game_scene::base_game_scene(this, g);
  f = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  this->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::lobby_menu_vtbl *)&survarium::lobby_menu::`vftable'{for `survarium::game_scene'};
  this->survarium::base_game_scene::survarium::engine::__vftable = (survarium::engine_vtbl *)&survarium::lobby_menu::`vftable'{for `survarium::engine'};
  this->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&survarium::lobby_menu::`vftable';
  this->m_lobby_game_project.m_object = 0;
  this->m_cursor_ui.m_object = 0;
  this->m_lobby_menu_ui.m_object = 0;
  this->m_message_ui.m_object = 0;
  this->m_match_making_ui.m_object = 0;
  *(_DWORD *)&this->m_update_status_handler &= ~0x80000000;
  *(_DWORD *)&this->m_update_friends_status_handler &= ~0x80000000;
  this->m_selected_profile = 0;
  this->m_ui_static_info_initialized = 0;
  this->m_is_in_match_making = 0;
  this->m_is_connected_to_lobby = 0;
  this->m_last_ping_time_in_ms = 0;
  this->m_player_max_carried_weight = 0.0;
  this->m_player_total_items_weight = 0.0;
  this->m_level_loading_progress = 0.0;
  this->m_last_queries_count = 0;
  this->m_in_destroying = 0;
  v4 = vostok::memory::doug_lea_allocator::malloc_impl(f, 0x84u);
  if ( v4 && (survarium::lobby_camera::lobby_camera((survarium::lobby_camera *)this, (int)v4), v6) )
    v7 = (survarium::game_camera *)(v6 + 4);
  else
    v7 = 0;
  m_camera_director = this->m_camera_director;
  this->m_camera = v7;
  survarium::camera_director::switch_to_camera(v5, m_camera_director, v7, "lobby camera");
  v9 = vostok::memory::g_mt_allocator.call_malloc(&vostok::memory::g_mt_allocator, 96);
  if ( v9 )
    vostok::physics::bullet_physics_world::bullet_physics_world(
      v10,
      (int)v9,
      (vostok::physics::engine *)&this->gap10,
      v13);
  else
    v11 = 0;
  this->m_physics_world = v11;
  v11->initialize(v11);
  survarium::lobby_menu::query_scene_resources(v12, this);
  this->m_match_stats.last_match_exp_delta = 0;
  this->m_match_stats.last_match_r1_delta = 0;
  this->m_match_stats.last_match_r2_delta = 0;
  this->m_match_stats.last_match_r3_delta = 0;
  this->m_match_stats.last_match_r4_delta = 0;
  this->m_match_stats.last_match_r5_delta = 0;
  this->m_match_stats.last_match_money_delta = 0;
}
