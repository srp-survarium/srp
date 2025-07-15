char __thiscall vostok::engine::game_console::on_mouse_move(
        vostok::engine::game_console *this,
        vostok::input::world *input_world,
        int x,
        int y,
        int z)
{
  int v5; // eax

  v5 = ((int (__thiscall *)(vostok::ui::text_edit *))this[-1].m_text_edit->set_caret_position)(this[-1].m_text_edit);
  (*(void (__thiscall **)(int, vostok::input::world *, int, int, int))(*(_DWORD *)v5 + 12))(v5, input_world, x, y, z);
  return 1;
}
