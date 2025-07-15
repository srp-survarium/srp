void __userpurge survarium::lobby_menu::update_ui(
        survarium::lobby_menu *this@<ecx>,
        survarium::lobby_menu *a2@<esi>,
        const unsigned int frame_delta_in_ms,
        unsigned int current_time_in_ms)
{
  volatile int v4; // eax
  survarium::flash_movie_resource *m_object; // ecx
  survarium::flash_value queries_count; // [esp+38h] [ebp-18h] BYREF
  float deltaTime; // [esp+54h] [ebp+4h]

  if ( a2->m_game->m_game_world.m_is_loading )
    survarium::lobby_menu::update_level_loading_progress(this, a2);
  if ( a2->m_is_active )
  {
    *(_DWORD *)queries_count.body = 0;
    *(_DWORD *)&queries_count.body[4] = 0;
    v4 = vostok::resources::g_resources_manager.m_initialized
       ? vostok::resources::g_resources_manager.m_variable->m_pending_queries_count
       : 0;
    m_object = a2->m_lobby_menu_ui.m_object;
    *(_DWORD *)&queries_count.body[8] = v4;
    *(_DWORD *)&queries_count.body[4] = 4;
    Scaleform::GFx::Movie::Invoke(
      m_object->movie->m_movie,
      "root.set_disk_query",
      0,
      (const Scaleform::GFx::Value *)&queries_count,
      1u);
    if ( (queries_count.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)queries_count.body + 8))(
        *(_DWORD *)queries_count.body,
        &queries_count,
        *(_DWORD *)&queries_count.body[8]);
  }
  deltaTime = (double)frame_delta_in_ms * 0.001;
  ((void (__stdcall *)(float, _DWORD, int))a2->m_cursor_ui.m_object->movie->m_movie->Advance)(
    COERCE_FLOAT(LODWORD(deltaTime)),
    0,
    1);
  ((void (__stdcall *)(float, _DWORD, int))a2->m_lobby_menu_ui.m_object->movie->m_movie->Advance)(
    COERCE_FLOAT(LODWORD(deltaTime)),
    0,
    1);
  ((void (__stdcall *)(float, _DWORD, int))a2->m_message_ui.m_object->movie->m_movie->Advance)(
    COERCE_FLOAT(LODWORD(deltaTime)),
    0,
    1);
  if ( a2->m_is_in_match_making )
    ((void (__stdcall *)(float, _DWORD, int))a2->m_match_making_ui.m_object->movie->m_movie->Advance)(
      COERCE_FLOAT(LODWORD(deltaTime)),
      0,
      1);
}
