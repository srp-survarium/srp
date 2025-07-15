void __usercall vostok::ui::ui_scroll_view::recalc(vostok::ui::ui_scroll_view *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  int v3; // edi
  int v4; // eax
  float v5; // xmm0_4
  float *v6; // ebx
  float v7; // xmm0_4
  vostok::ui::ui_scroll_bar *v8; // ecx
  int v9; // [esp+0h] [ebp-18h] BYREF
  float v10; // [esp+4h] [ebp-14h]
  float v11; // [esp+8h] [ebp-10h] BYREF
  float i; // [esp+Ch] [ebp-Ch]
  unsigned int v13; // [esp+10h] [ebp-8h]
  unsigned int v14; // [esp+14h] [ebp-4h]

  v2 = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 20))(a2);
  v14 = 0;
  v13 = v2;
  v9 = 0;
  v10 = 0.0;
  v11 = 0.0;
  for ( i = 0.0; v14 < v13; ++v14 )
  {
    v3 = (*(int (__thiscall **)(int, unsigned int))(*(_DWORD *)a2 + 24))(a2, v14);
    (**(void (__thiscall ***)(int, int *))v3)(v3, &v9);
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(v3);
    v5 = *(float *)(v4 + 4) + v10;
    v10 = v5;
    if ( v5 > i )
      i = v5;
    v6 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(v3);
    v7 = *v6 + *(float *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 4))(v3);
    if ( v7 > v11 )
      v11 = v7;
  }
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)(a2 + 72) + 8))(a2 + 72, &v11);
  *(_WORD *)(a2 + 68) &= ~1u;
  if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)a2 + 12))(a2, v9) )
    vostok::ui::ui_scroll_bar::move_end(v8, a2 + 136);
}
