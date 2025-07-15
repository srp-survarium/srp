bool __thiscall survarium::base_game_scene::mouse_exclusive_mode(survarium::base_game_scene *this)
{
  return !this->m_game->m_render_output_window.m_object->m_windowed;
}
