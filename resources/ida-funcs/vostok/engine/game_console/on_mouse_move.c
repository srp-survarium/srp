bool __thiscall vostok::engine::game_console::on_mouse_move(
        vostok::engine::editor_console *this,
        vostok::input::world *input_world,
        int x,
        int y,
        int z)
{
  return vostok::console_impl::on_mouse_move(this, input_world, x, y, z);
}
