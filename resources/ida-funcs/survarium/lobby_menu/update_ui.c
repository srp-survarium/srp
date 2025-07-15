void __usercall survarium::lobby_menu::update_ui(
        survarium::lobby_menu *this@<edi>,
        const unsigned int frame_delta_in_ms@<eax>,
        survarium::flash_movie *current_time_in_ms@<ecx>)
{
  survarium::lobby_menu *p_m_last_ui_update_time_ms; // ecx
  char *v5; // eax
  double v6; // st7
  survarium::game *m_game; // eax
  unsigned int v8; // eax
  survarium::flash_value *v9; // ecx
  float delta_time; // [esp+0h] [ebp-30h]
  float v11; // [esp+14h] [ebp-1Ch]
  Scaleform::GFx::Value pargs; // [esp+18h] [ebp-18h] BYREF

  delta_time = (double)frame_delta_in_ms * 0.001;
  survarium::flash_movie::Advance(current_time_in_ms, (int)this->m_cursor_ui.m_object->movie, delta_time, 0);
  p_m_last_ui_update_time_ms = (survarium::lobby_menu *)&this->m_last_ui_update_time_ms;
  v5 = (char *)current_time_in_ms - this->m_last_ui_update_time_ms;
  if ( (unsigned int)v5 >= 0x19 )
  {
    v6 = (double)(unsigned int)v5 * 0.001;
    m_game = this->m_game;
    p_m_last_ui_update_time_ms->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::lobby_menu_vtbl *)current_time_in_ms;
    if ( m_game->m_game_world.m_is_loading )
      survarium::lobby_menu::update_level_loading_progress(p_m_last_ui_update_time_ms, (int)this);
    if ( this->m_is_active )
    {
      pargs.pObjectInterface = 0;
      pargs.Type = VT_Undefined;
      v8 = vostok::resources::pending_queries_count();
      survarium::flash_value::SetUInt(v9, (int)&pargs, v8);
      Scaleform::GFx::Movie::Invoke(
        this->m_lobby_menu_ui.m_object->movie->m_movie,
        "root.set_disk_query",
        0,
        &pargs,
        1u);
      Scaleform::GFx::Value::~Value(&pargs);
    }
    v11 = v6;
    survarium::flash_movie::Advance(
      (survarium::flash_movie *)p_m_last_ui_update_time_ms,
      (int)this->m_lobby_menu_ui.m_object->movie,
      v11,
      0);
  }
}
