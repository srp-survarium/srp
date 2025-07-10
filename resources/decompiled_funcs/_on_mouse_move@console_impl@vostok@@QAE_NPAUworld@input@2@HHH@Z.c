char __userpurge vostok::console_impl::on_mouse_move@<al>(
        vostok::console_impl *this@<ecx>,
        int a2@<eax>,
        vostok::input::world *input_world,
        int x,
        int y,
        int z)
{
  int v6; // eax

  v6 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 20) + 4))(*(_DWORD *)(a2 + 20));
  (*(void (__thiscall **)(int, vostok::input::world *, int, int, int))(*(_DWORD *)v6 + 12))(v6, input_world, x, y, z);
  return 1;
}
