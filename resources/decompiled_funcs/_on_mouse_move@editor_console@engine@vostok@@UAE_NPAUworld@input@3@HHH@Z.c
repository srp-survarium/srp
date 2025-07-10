char __thiscall vostok::engine::editor_console::on_mouse_move(
        vostok::engine::editor_console *this,
        vostok::input::world *input_world,
        int x,
        int y,
        int z)
{
  int v5; // eax

  v5 = ((int (__thiscall *)(vostok::ui::scroll_view *))this[-1].m_ui_view->remove_item)(this[-1].m_ui_view);
  (*(void (__thiscall **)(int, vostok::input::world *, int, int, int))(*(_DWORD *)v5 + 12))(v5, input_world, x, y, z);
  return 1;
}
