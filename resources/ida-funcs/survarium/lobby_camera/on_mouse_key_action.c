bool __thiscall survarium::lobby_camera::on_mouse_key_action(
        survarium::lobby_camera *this,
        vostok::input::world *input_world,
        vostok::input::mouse_button button,
        vostok::input::enum_mouse_key_action actions_mask)
{
  this->m_game_scene->is_mouse_over_ui(this->m_game_scene);
  return 0;
}
