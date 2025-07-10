char __thiscall vostok::engine::game_console::on_keyboard_action(
        vostok::engine::game_console *this,
        vostok::input::world *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action)
{
  return vostok::console_impl::on_keyboard_action(
           (vostok::engine::game_console *)((char *)this - 616),
           (vostok::engine::game_console *)((char *)this - 616),
           input_world,
           key,
           action);
}
