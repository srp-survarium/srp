char __thiscall vostok::engine::game_console::on_gamepad_action(
        vostok::engine::game_console *this,
        vostok::input::world *input_world,
        vostok::input::gamepad_button button,
        vostok::input::enum_gamepad_action action)
{
  int v4; // eax

  v4 = ((int (__thiscall *)(vostok::ui::text_edit *))this[-1].m_text_edit->set_caret_position)(this[-1].m_text_edit);
  (*(void (__thiscall **)(int, vostok::input::world *, vostok::input::gamepad_button, vostok::input::enum_gamepad_action))(*(_DWORD *)v4 + 4))(
    v4,
    input_world,
    button,
    action);
  return 1;
}
