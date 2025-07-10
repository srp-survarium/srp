char __thiscall survarium::lobby_camera::on_mouse_key_action(
        survarium::lobby_camera *this,
        vostok::input::world *input_world,
        vostok::input::mouse_button button,
        vostok::input::enum_mouse_key_action actions_mask)
{
  if ( this->m_game_scene->is_mouse_over_ui(this->m_game_scene) || button != mouse_button_right )
    return 0;
  if ( this->m_capture_move || actions_mask )
  {
    if ( actions_mask == ms_key_up )
      this->m_capture_move = 0;
    return 1;
  }
  else
  {
    this->m_capture_move = 1;
    return 1;
  }
}
