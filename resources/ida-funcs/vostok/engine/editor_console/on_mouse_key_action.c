bool __thiscall vostok::engine::editor_console::on_mouse_key_action(
        vostok::engine::editor_console *this,
        vostok::input::world *input_world,
        vostok::input::mouse_button button,
        vostok::input::enum_mouse_key_action action)
{
  return vostok::console_impl::on_mouse_key_action(this, input_world, button, action);
}
