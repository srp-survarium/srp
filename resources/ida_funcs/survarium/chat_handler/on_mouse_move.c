bool __thiscall survarium::chat_handler::on_mouse_move(
        survarium::chat_handler *this,
        vostok::input::world *input_world,
        int x,
        int y,
        int z)
{
  return this->m_game_ui_mode;
}
