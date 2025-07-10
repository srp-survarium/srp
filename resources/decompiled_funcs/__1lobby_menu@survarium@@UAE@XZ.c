void __thiscall survarium::lobby_menu::~lobby_menu(survarium::lobby_menu *this)
{
  survarium::lobby_menu *v1; // edi
  bool v2; // zf
  void **v3; // eax
  int f; // esi
  char *v5; // eax
  vostok::memory::detail::call_destructor_predicate *m_character; // esi
  int v7; // ebp
  char *v8; // eax
  malloc_state *v9; // esi
  survarium::simple_game_project *m_object; // eax
  void **v11; // esi
  _BYTE *v12; // ebp
  survarium::flash_movie_resource *v13; // eax
  survarium::flash_movie_resource *v14; // eax
  survarium::flash_movie_resource *v15; // eax
  survarium::flash_movie_resource *v16; // eax
  survarium::simple_game_project *v17; // eax

  v1 = this;
  v2 = *(_DWORD *)&this->m_update_status_handler >= 0;
  this->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::lobby_menu_vtbl *)&survarium::lobby_menu::`vftable'{for `survarium::game_scene'};
  this->survarium::base_game_scene::survarium::engine::__vftable = (survarium::engine_vtbl *)&survarium::lobby_menu::`vftable'{for `survarium::engine'};
  this->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&survarium::lobby_menu::`vftable';
  if ( !v2 )
    survarium::scheduler::unregister(&this->m_game->m_scheduler, &this->m_update_status_handler);
  if ( *(_DWORD *)&v1->m_update_friends_status_handler < 0 )
    survarium::scheduler::unregister(&v1->m_game->m_scheduler, &v1->m_update_friends_status_handler);
  v3 = (void **)&v1->m_camera->__vftable;
  f = (int)survarium::g_allocator.f_.f_;
  if ( v3 )
  {
    v5 = __RTCastToVoid(v3);
    if ( v5 )
    {
      *(_BYTE *)(f + 42) = 0;
      vostok_mspace_free(*(malloc_state **)(f + 20), v5);
    }
    v1->m_camera = 0;
  }
  m_character = (vostok::memory::detail::call_destructor_predicate *)v1->m_character;
  v7 = (int)survarium::g_allocator.f_.f_;
  if ( m_character )
  {
    vostok::memory::detail::call_destructor_predicate::operator()<survarium::profile_player_character>(m_character);
    v8 = (char *)m_character;
    v9 = *(malloc_state **)(v7 + 20);
    *(_BYTE *)(v7 + 42) = 0;
    vostok_mspace_free(v9, v8);
    v1->m_character = 0;
  }
  m_object = v1->m_lobby_game_project.m_object;
  v1->m_lobby_game_project.m_object = 0;
  if ( m_object )
  {
    this = (survarium::lobby_menu *)&m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)this,
        m_object);
  }
  survarium::lobby_menu::on_ui_destroy(this, (int)v1);
  v11 = (void **)&v1->m_physics_world->survarium::base_game_scene::__vftable;
  (*((void (__thiscall **)(void **))*v11 + 3))(v11);
  v12 = __RTCastToVoid(v11);
  (*(void (__thiscall **)(void **, _DWORD))*v11)(v11, 0);
  vostok::memory::g_mt_allocator.call_free(&vostok::memory::g_mt_allocator, v12);
  v13 = v1->m_match_making_ui.m_object;
  if ( v13 && !_InterlockedExchangeAdd(&v13->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &v1->m_match_making_ui.m_object->vostok::resources::unmanaged_intrusive_base,
      v1->m_match_making_ui.m_object);
  v14 = v1->m_message_ui.m_object;
  if ( v14 && !_InterlockedExchangeAdd(&v14->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &v1->m_message_ui.m_object->vostok::resources::unmanaged_intrusive_base,
      v1->m_message_ui.m_object);
  v15 = v1->m_lobby_menu_ui.m_object;
  if ( v15 && !_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &v1->m_lobby_menu_ui.m_object->vostok::resources::unmanaged_intrusive_base,
      v1->m_lobby_menu_ui.m_object);
  v16 = v1->m_cursor_ui.m_object;
  if ( v16 && !_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &v1->m_cursor_ui.m_object->vostok::resources::unmanaged_intrusive_base,
      v1->m_cursor_ui.m_object);
  v17 = v1->m_lobby_game_project.m_object;
  if ( v17 && !_InterlockedExchangeAdd(&v17->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &v1->m_lobby_game_project.m_object->vostok::resources::unmanaged_intrusive_base,
      v1->m_lobby_game_project.m_object);
  survarium::base_game_scene::~base_game_scene(v1);
}
