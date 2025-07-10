char __thiscall vostok::engine::editor_console::on_gamepad_action(
        vostok::engine::editor_console *this,
        vostok::input::world *input_world,
        vostok::input::gamepad_button button,
        vostok::input::enum_gamepad_action action)
{
  int v4; // eax

  v4 = ((int (__thiscall *)(vostok::ui::scroll_view *))this[-1].m_ui_view->remove_item)(this[-1].m_ui_view);
  (*(void (__thiscall **)(int, vostok::input::world *, vostok::input::gamepad_button, vostok::input::enum_gamepad_action))(*(_DWORD *)v4 + 4))(
    v4,
    input_world,
    button,
    action);
  return 1;
}
