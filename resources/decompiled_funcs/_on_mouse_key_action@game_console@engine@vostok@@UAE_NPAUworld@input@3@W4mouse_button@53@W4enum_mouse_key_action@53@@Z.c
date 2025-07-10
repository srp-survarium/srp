char __thiscall vostok::engine::game_console::on_mouse_key_action(
        vostok::engine::game_console *this,
        vostok::input::world *input_world,
        vostok::input::mouse_button button,
        vostok::input::enum_mouse_key_action action)
{
  int v4; // eax

  v4 = ((int (__thiscall *)(vostok::ui::text_edit *))this[-1].m_text_edit->set_caret_position)(this[-1].m_text_edit);
  (*(void (__thiscall **)(int, vostok::input::world *, vostok::input::mouse_button, vostok::input::enum_mouse_key_action))(*(_DWORD *)v4 + 8))(
    v4,
    input_world,
    button,
    action);
  return 1;
}
