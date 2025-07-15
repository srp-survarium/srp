char __thiscall vostok::engine::editor_console::on_keyboard_action(
        vostok::engine::editor_console *this,
        vostok::input::world *input_world,
        vostok::input::enum_keyboard_action key,
        int action)
{
  return vostok::console_impl::on_keyboard_action(
           (vostok::engine::editor_console *)((char *)this - 616),
           (vostok::input::world *)&this[-1].m_self_deactivate,
           (vostok::input::enum_keyboard)input_world,
           key,
           action);
}
