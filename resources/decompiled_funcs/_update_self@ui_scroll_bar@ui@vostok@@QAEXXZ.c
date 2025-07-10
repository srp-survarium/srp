void __usercall vostok::ui::ui_scroll_bar::update_self(vostok::ui::ui_scroll_bar *this@<ecx>, int a2@<edi>)
{
  void (__thiscall ***v2)(int, vostok::math::float2 *); // esi
  float *v3; // eax
  int (__thiscall *v4)(int); // edx
  float *v5; // eax
  int (__thiscall *v6)(int); // edx
  float v7; // xmm0_4
  double v8; // st7
  float y; // xmm0_4
  int v10; // ecx
  float v11; // xmm0_4
  void (__thiscall *v12)(int, vostok::math::float2 *); // edx
  float v13; // [esp+4h] [ebp-28h]
  float max_track_len; // [esp+8h] [ebp-24h]
  float max_track_lena; // [esp+8h] [ebp-24h]
  float btn_h; // [esp+Ch] [ebp-20h]
  float max_pos; // [esp+14h] [ebp-18h]
  float max_posa; // [esp+14h] [ebp-18h]
  vostok::math::float2 track_size; // [esp+18h] [ebp-14h] BYREF
  vostok::math::float2 track_pos; // [esp+20h] [ebp-Ch] BYREF

  v2 = (void (__thiscall ***)(int, vostok::math::float2 *))(a2 + 96);
  btn_h = *(float *)((*(int (__thiscall **)(int))(*(_DWORD *)(a2 + 188) + 12))(a2 + 188) + 4);
  v3 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)(a2 + 96) + 12))(a2 + 96);
  track_size.x = *v3;
  v4 = *(int (__thiscall **)(int))(*(_DWORD *)(a2 + 96) + 4);
  track_size.y = v3[1];
  v5 = (float *)v4(a2 + 96);
  track_pos.x = *v5;
  v6 = *(int (__thiscall **)(int))(*(_DWORD *)(a2 + 4) + 12);
  track_pos.y = v5[1];
  v7 = *(float *)(v6(a2 + 4) + 4);
  if ( v7 <= 0.0 )
    v7 = 0.0;
  v13 = v7;
  max_pos = v7 - (float)(btn_h * 2.0);
  max_track_len = max_pos;
  if ( max_pos < 0.0 )
    max_track_len = 0.0;
  v8 = v7 / ((double (__thiscall *)(_DWORD))***(_DWORD ***)(a2 + 184))(*(_DWORD *)(a2 + 184)) * max_track_len;
  track_size.y = v8;
  if ( v8 > 0.0 )
  {
    y = track_size.y;
    if ( max_track_len < track_size.y )
      y = max_track_len;
  }
  else
  {
    y = 0.0;
  }
  v10 = *(_DWORD *)(a2 + 184);
  track_size.y = y;
  max_track_lena = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v10 + 4))(v10);
  if ( COERCE_FLOAT(LODWORD(max_track_lena) & 0x7FFFFFFF) >= 0.0000099999997 )
  {
    max_posa = max_pos - track_size.y;
    track_pos.y = COERCE_FLOAT(LODWORD(max_track_lena) & 0x7FFFFFFF)
                / (((double (__thiscall *)(_DWORD))***(_DWORD ***)(a2 + 184))(*(_DWORD *)(a2 + 184)) - v13)
                * max_posa;
    v11 = track_pos.y;
  }
  else
  {
    v11 = 0.0;
  }
  v12 = **v2;
  track_pos.y = v11 + btn_h;
  v12(a2 + 96, &track_pos);
  (*v2)[2](a2 + 96, &track_size);
}
