bool __thiscall vostok::engine::game_console::on_gamepad_action(
        vostok::engine::editor_console *this,
        vostok::input::world *input_world,
        vostok::input::gamepad_button button,
        vostok::input::enum_gamepad_action action)
{
  return vostok::console_impl::on_gamepad_action(this, input_world, button, action);
}
