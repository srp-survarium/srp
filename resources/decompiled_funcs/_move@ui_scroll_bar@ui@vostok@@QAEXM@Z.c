void __userpurge vostok::ui::ui_scroll_bar::move(
        vostok::ui::ui_scroll_bar *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        float size,
        float a5)
{
  float v5; // xmm1_4
  float retaddr; // [esp+Ch] [ebp+0h]
  float v7; // [esp+14h] [ebp+8h]
  float v8; // [esp+14h] [ebp+8h]
  float v9; // [esp+14h] [ebp+8h]
  float v10; // [esp+14h] [ebp+8h]

  (*(void (__thiscall **)(int, int))(*(_DWORD *)(a3 + 96) + 4))(a3 + 96, a2);
  retaddr = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**(_DWORD **)(a3 + 184) + 4))(*(_DWORD *)(a3 + 184)) + a5;
  v7 = ((double (__thiscall *)(_DWORD))***(_DWORD ***)(a3 + 184))(*(_DWORD *)(a3 + 184));
  if ( v7 <= (double)*(float *)((*(int (__thiscall **)(int))(*(_DWORD *)(a3 + 4) + 12))(a3 + 4) + 4) )
  {
    v5 = 0.0;
  }
  else
  {
    v8 = ((double (__thiscall *)(_DWORD))***(_DWORD ***)(a3 + 184))(*(_DWORD *)(a3 + 184));
    v9 = -(v8 - *(float *)((*(int (__thiscall **)(int))(*(_DWORD *)(a3 + 4) + 12))(a3 + 4) + 4));
    v5 = v9;
  }
  if ( v5 < retaddr )
  {
    if ( retaddr > 0.0 )
      v10 = 0.0;
    else
      v10 = retaddr;
  }
  else
  {
    v10 = v5;
  }
  (*(void (__cdecl **)(float))(**(_DWORD **)(a3 + 184) + 8))(COERCE_FLOAT(LODWORD(v10)));
}
