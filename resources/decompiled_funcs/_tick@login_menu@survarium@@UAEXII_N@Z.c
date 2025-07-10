void __thiscall survarium::login_menu::tick(
        survarium::login_menu *this,
        unsigned int frame_delta_in_ms,
        unsigned int current_time_in_ms,
        const bool is_game_paused)
{
  survarium::camera_director *m_camera_director; // eax
  vostok::physics::world *m_physics_world; // ecx
  unsigned int m_block_btn_time; // eax
  float deltaTime; // [esp+30h] [ebp+Ch]

  m_camera_director = this->m_camera_director;
  if ( m_camera_director->m_active_camera )
    m_camera_director->m_active_camera->tick(m_camera_director->m_active_camera);
  if ( !is_game_paused )
  {
    m_physics_world = this->m_physics_world;
    if ( m_physics_world )
      m_physics_world->tick(m_physics_world, current_time_in_ms);
  }
  m_block_btn_time = this->m_block_btn_time;
  if ( m_block_btn_time && m_block_btn_time < current_time_in_ms )
  {
    this->m_block_btn_time = 0;
    survarium::login_menu::enable_button(this, 1);
  }
  deltaTime = (double)frame_delta_in_ms * 0.001;
  ((void (__stdcall *)(_DWORD, _DWORD, int))this->m_login_menu_ui.m_object->movie->m_movie->Advance)(
    LODWORD(deltaTime),
    0,
    1);
  ((void (__stdcall *)(_DWORD, _DWORD, int))this->m_cursor_ui.m_object->movie->m_movie->Advance)(
    LODWORD(deltaTime),
    0,
    1);
}
