void __usercall vostok::engine::engine_world::show_window(vostok::engine::engine_world *this@<ecx>, int a2@<esi>)
{
  HWND v2; // eax

  if ( *(_DWORD *)(a2 + 636) )
  {
    v2 = (HWND)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 636) + 12))(*(_DWORD *)(a2 + 636));
    SetForegroundWindow(v2);
  }
  else
  {
    ShowWindow(*(HWND *)(a2 + 672), 5);
    SetForegroundWindow(*(HWND *)(a2 + 672));
    (*(void (__thiscall **)(int))(*(_DWORD *)(a2 + 8) + 52))(a2 + 8);
  }
}
