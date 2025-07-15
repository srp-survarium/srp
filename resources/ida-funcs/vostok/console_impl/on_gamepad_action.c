char __userpurge vostok::console_impl::on_gamepad_action@<al>(
        vostok::console_impl *this@<ecx>,
        int a2@<eax>,
        vostok::input::world *input_world,
        vostok::input::gamepad_button button,
        vostok::input::enum_gamepad_action action)
{
  int v5; // eax

  v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 20) + 4))(*(_DWORD *)(a2 + 20));
  (*(void (__thiscall **)(int, vostok::input::world *, vostok::input::gamepad_button, vostok::input::enum_gamepad_action))(*(_DWORD *)v5 + 4))(
    v5,
    input_world,
    button,
    action);
  return 1;
}
