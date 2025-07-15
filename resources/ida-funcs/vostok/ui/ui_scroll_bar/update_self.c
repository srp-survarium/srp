void __usercall vostok::ui::ui_scroll_bar::update_self(vostok::ui::ui_scroll_bar *this@<ecx>, int a2@<esi>)
{
  float v2; // xmm0_4
  void (__thiscall ***v3)(int, float *); // edi
  int v4; // eax
  float *v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  float *v8; // eax
  float v9; // xmm0_4
  int v10; // eax
  float v11; // xmm1_4
  float v12; // xmm0_4
  int v13; // ecx
  float v14; // xmm0_4
  void (__thiscall **v15)(int, float *); // eax
  float v16; // [esp+4h] [ebp-24h] BYREF
  float v17; // [esp+8h] [ebp-20h]
  float v18; // [esp+Ch] [ebp-1Ch] BYREF
  float v19; // [esp+10h] [ebp-18h]
  float v20; // [esp+14h] [ebp-14h]
  int v21; // [esp+18h] [ebp-10h]
  float v22; // [esp+1Ch] [ebp-Ch]
  float v23; // [esp+20h] [ebp-8h]
  float v24; // [esp+24h] [ebp-4h]

  v2 = *(float *)((*(int (__thiscall **)(int))(*(_DWORD *)(a2 + 188) + 12))(a2 + 188) + 4);
  v3 = (void (__thiscall ***)(int, float *))(a2 + 96);
  v4 = *(_DWORD *)(a2 + 96);
  v22 = v2;
  v5 = (float *)(*(int (__thiscall **)(int))(v4 + 12))(a2 + 96);
  v18 = *v5;
  v6 = v5[1];
  v7 = *(_DWORD *)(a2 + 96);
  v19 = v6;
  v8 = (float *)(*(int (__thiscall **)(int))(v7 + 4))(a2 + 96);
  v16 = *v8;
  v9 = v8[1];
  v10 = *(_DWORD *)(a2 + 4);
  v17 = v9;
  v11 = *(float *)((*(int (__thiscall **)(int))(v10 + 12))(a2 + 4) + 4);
  if ( v11 <= 0.0 )
    v11 = 0.0;
  v24 = v11;
  v20 = v11 - (float)(v22 * 2.0);
  v23 = v20;
  if ( v20 < 0.0 )
    v23 = 0.0;
  v19 = v24 / ((double (__thiscall *)(_DWORD))***(_DWORD ***)(a2 + 184))(*(_DWORD *)(a2 + 184)) * v23;
  if ( v19 > 0.0 )
  {
    v12 = v23;
    if ( v23 >= v19 )
      v12 = v19;
  }
  else
  {
    v12 = 0.0;
  }
  v13 = *(_DWORD *)(a2 + 184);
  v19 = v12;
  v23 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v13 + 4))(v13);
  v21 = LODWORD(v23) & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(v23) & 0x7FFFFFFF) >= 0.0000099999997 )
  {
    v21 = LODWORD(v23);
    LODWORD(v23) &= ~0x80000000;
    v20 = v20 - v19;
    v17 = v23 / (((double (__thiscall *)(_DWORD))***(_DWORD ***)(a2 + 184))(*(_DWORD *)(a2 + 184)) - v24) * v20;
    v14 = v17;
  }
  else
  {
    v14 = 0.0;
  }
  v15 = *v3;
  v17 = v14 + v22;
  (*v15)(a2 + 96, &v16);
  (*v3)[2](a2 + 96, &v18);
}
