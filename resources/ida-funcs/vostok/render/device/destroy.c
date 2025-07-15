void __thiscall vostok::render::device::destroy(vostok::render::device *this)
{
  int v1; // esi
  int v2; // esi

  (*(void (__stdcall **)(int))(*(_DWORD *)dword_D0D0DC + 440))(dword_D0D0DC);
  v1 = dword_D0D0D8;
  (*(void (__stdcall **)(int))(*(_DWORD *)dword_D0D0D8 + 4))(dword_D0D0D8);
  (*(void (__stdcall **)(int))(*(_DWORD *)v1 + 8))(v1);
  if ( dword_D0D0D8 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)dword_D0D0D8 + 8))(dword_D0D0D8);
    dword_D0D0D8 = 0;
  }
  v2 = dword_D0D0D4;
  (*(void (__stdcall **)(int))(*(_DWORD *)dword_D0D0D4 + 4))(dword_D0D0D4);
  (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 8))(v2);
  if ( dword_D0D0D4 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)dword_D0D0D4 + 8))(dword_D0D0D4);
    dword_D0D0D4 = 0;
  }
  if ( dword_D0D0D0 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)dword_D0D0D0 + 8))(dword_D0D0D0);
    dword_D0D0D0 = 0;
  }
}
