char __thiscall vostok::engine::editor_console::on_mouse_key_action(
        vostok::engine::editor_console *this,
        vostok::input::world *input_world,
        vostok::input::mouse_button button,
        vostok::input::enum_mouse_key_action action)
{
  int v4; // eax

  v4 = ((int (__thiscall *)(vostok::ui::scroll_view *))this[-1].m_ui_view->remove_item)(this[-1].m_ui_view);
  (*(void (__thiscall **)(int, vostok::input::world *, vostok::input::mouse_button, vostok::input::enum_mouse_key_action))(*(_DWORD *)v4 + 8))(
    v4,
    input_world,
    button,
    action);
  return 1;
}
