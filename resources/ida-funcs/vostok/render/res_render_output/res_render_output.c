void __userpurge vostok::render::res_render_output::res_render_output(
        vostok::render::res_render_output *this@<ecx>,
        int a2@<esi>,
        HWND__ *window,
        bool windowed)
{
  unsigned int *v4; // ecx
  HWND v5; // eax
  vostok::render::res_render_output *v6; // ecx

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = &unk_C80000;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = a2 + 24;
  *(_DWORD *)(a2 + 16) = a2 + 24;
  *(_BYTE *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 20) = a2 + 152;
  *(_DWORD *)(a2 + 212) = 0;
  *(_DWORD *)(a2 + 216) = 0;
  *(_DWORD *)(a2 + 220) = 0;
  *(_DWORD *)(a2 + 224) = 0;
  *(_DWORD *)(a2 + 228) = window;
  *(_DWORD *)(a2 + 232) = 0;
  *(_BYTE *)(a2 + 236) = 1;
  *(_BYTE *)(a2 + 237) = windowed;
  *(_BYTE *)(a2 + 238) = 0;
  memset(a2 + 152, 0, 0x3Cu);
  if ( !*(_BYTE *)(a2 + 237) )
  {
    SetWindowLongA(*(HWND *)(a2 + 228), -16, *(_DWORD *)(a2 + 8));
    SetWindowLongA(*(HWND *)(a2 + 228), -20, *(_DWORD *)(a2 + 8));
  }
  v5 = *(HWND *)(a2 + 228);
  *(_DWORD *)(a2 + 168) = 28;
  *(_DWORD *)(a2 + 192) = 1;
  *(_DWORD *)(a2 + 188) = 32;
  if ( v5 )
    vostok::render::res_render_output::select_resolution(
      v4,
      (unsigned int *)(a2 + 152),
      (_DWORD *)(a2 + 156),
      (HWND__ *)*(unsigned __int8 *)(a2 + 237),
      v5);
  else
    GetLastError();
  *(_DWORD *)(a2 + 196) = *(_DWORD *)(a2 + 228);
  *(_DWORD *)(a2 + 200) = *(unsigned __int8 *)(a2 + 237);
  *(_DWORD *)(a2 + 160) = 0;
  *(_DWORD *)(a2 + 164) = 0;
  *(_DWORD *)(a2 + 180) = 1;
  *(_DWORD *)(a2 + 184) = 0;
  *(_DWORD *)(a2 + 204) = 0;
  *(_DWORD *)(a2 + 208) = 0;
  vostok::render::res_render_output::initialize_swap_chain(v6, a2);
}
