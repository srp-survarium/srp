void __usercall survarium::game::initialize_input(survarium::game *this@<ecx>, int a2@<esi>)
{
  vostok::input::input_world *v2; // edi
  HWND__ *v3; // eax

  if ( a2 )
    v2 = (vostok::input::input_world *)(a2 + 8);
  else
    v2 = 0;
  v3 = (HWND__ *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 124) + 16))(*(_DWORD *)(a2 + 124));
  *(_DWORD *)(a2 + 140) = vostok::input::create_world(v2, v3);
}
