bool __thiscall survarium::chat_handler::on_mouse_key_action(
        survarium::chat_handler *this,
        vostok::input::world *input_world,
        vostok::input::mouse_button button,
        vostok::input::enum_mouse_key_action action)
{
  return this->m_game_ui_mode;
}
