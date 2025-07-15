void __userpurge vostok::ui::ui_scroll_bar::move(vostok::ui::ui_scroll_bar *this@<ecx>, int a2@<esi>, float size)
{
  float v3; // xmm1_4
  float v4; // [esp+4h] [ebp-4h]
  float v5; // [esp+10h] [ebp+8h]
  float v6; // [esp+10h] [ebp+8h]
  float v7; // [esp+10h] [ebp+8h]
  float v8; // [esp+10h] [ebp+8h]

  (*(void (__thiscall **)(int))(*(_DWORD *)(a2 + 96) + 4))(a2 + 96);
  v4 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**(_DWORD **)(a2 + 184) + 4))(*(_DWORD *)(a2 + 184)) + size;
  v5 = ((double (__thiscall *)(_DWORD))***(_DWORD ***)(a2 + 184))(*(_DWORD *)(a2 + 184));
  if ( v5 <= (double)*(float *)((*(int (__thiscall **)(int))(*(_DWORD *)(a2 + 4) + 12))(a2 + 4) + 4) )
  {
    v3 = 0.0;
  }
  else
  {
    v6 = ((double (__thiscall *)(_DWORD))***(_DWORD ***)(a2 + 184))(*(_DWORD *)(a2 + 184));
    v7 = -(v6 - *(float *)((*(int (__thiscall **)(int))(*(_DWORD *)(a2 + 4) + 12))(a2 + 4) + 4));
    v3 = v7;
  }
  if ( v3 < v4 )
  {
    if ( v4 > 0.0 )
      v8 = 0.0;
    else
      v8 = v4;
  }
  else
  {
    v8 = v3;
  }
  (*(void (__cdecl **)(float))(**(_DWORD **)(a2 + 184) + 8))(COERCE_FLOAT(LODWORD(v8)));
}
