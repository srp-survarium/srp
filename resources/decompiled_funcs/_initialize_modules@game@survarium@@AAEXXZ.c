void __usercall survarium::game::initialize_modules(survarium::game *this@<ecx>, int a2@<eax>)
{
  vostok::input::input_world *v3; // edi
  HWND__ *v4; // eax
  survarium::game *v5; // ecx

  if ( a2 )
    v3 = (vostok::input::input_world *)(a2 + 8);
  else
    v3 = 0;
  v4 = (HWND__ *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 124) + 16))(*(_DWORD *)(a2 + 124));
  *(_DWORD *)(a2 + 140) = vostok::input::create_world(v3, v4);
  survarium::game::initialize_ui(v5, (_DWORD *)a2);
}
