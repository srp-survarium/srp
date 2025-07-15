void __usercall vostok::input::input_world::process_on_deactivate(vostok::input::input_world *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  int v3; // eax

  v2 = *(_DWORD *)(a2 + 28);
  if ( v2 )
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v2 + 2316) + 32))(*(_DWORD *)(v2 + 2316));
  v3 = *(_DWORD *)(a2 + 32);
  if ( v3 )
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v3 + 40) + 32))(*(_DWORD *)(v3 + 40));
}
