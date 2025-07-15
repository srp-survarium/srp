bool __thiscall survarium::chat_handler::on_gamepad_action(
        survarium::chat_handler *this,
        vostok::input::world *input_world,
        vostok::input::gamepad_button button,
        vostok::input::enum_gamepad_action action)
{
  return this->m_game_ui_mode;
}
