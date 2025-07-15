void __thiscall vostok::animation::fingers_to_weapon_corrector::process(
        vostok::animation::fingers_to_weapon_corrector *this,
        const unsigned int current_time_in_ms,
        vostok::math::float4x4 *matrices,
        float a4)
{
  double (__thiscall ***v4)(_DWORD, _DWORD); // esi
  int v5; // ebx
  int v6; // eax
  char *v7; // eax
  _DWORD *v8; // edx
  void *v9; // edi
  const void *v10; // esi
  bool v11; // zf
  double v12; // st7
  int v13; // ecx
  int v14; // eax
  int v15; // eax
  float v16; // [esp+8h] [ebp-1Ch]
  int v17; // [esp+1Ch] [ebp-8h]
  float v18; // [esp+1Ch] [ebp-8h]

  v4 = (double (__thiscall ***)(_DWORD, _DWORD))(current_time_in_ms + 5912);
  v5 = current_time_in_ms + 2880;
  do
  {
    v6 = *(_DWORD *)(v5 + 60);
    if ( v6 + 300 > (unsigned int)matrices )
    {
      v16 = (double)((unsigned int)matrices - v6) * 0.001;
      v12 = (**v4)(v4, LODWORD(v16));
      v13 = *(_DWORD *)(v5 + 68);
      v18 = v12;
      if ( v13 != 3 || (v14 = *(_DWORD *)(v5 + 64), v14 == 3) )
      {
        v15 = *(_DWORD *)(v5 + 64);
        if ( v15 == 3 )
        {
          if ( v13 != 3 )
            vostok::animation::interpolate_hand_matrices(
              (const vostok::math::float4x4 *)(v5 + 960 * (v13 - 3)),
              (const unsigned int *)v5,
              (struct vostok::math::float4x4 *)LODWORD(v18),
              a4);
        }
        else if ( v13 != 3 )
        {
          vostok::animation::interpolate_hand_matrices(
            (const vostok::math::float4x4 *)(v5 - 2880 + 960 * v15),
            (const vostok::math::float4x4 *)(v5 - 2880 + 960 * v13),
            (const unsigned int *)v5,
            (struct vostok::math::float4x4 *)LODWORD(v18),
            a4);
        }
      }
      else
      {
        vostok::animation::interpolate_hand_matrices(
          (const vostok::math::float4x4 *)(v5 + 960 * (v14 - 3)),
          (const unsigned int *)v5,
          COERCE_STRUCT_VOSTOK_MATH_FLOAT4X4_(s_bm_current_air_resistance - v18),
          a4);
      }
    }
    else if ( *(_BYTE *)(v5 + 72) )
    {
      v7 = (char *)(v5 + 960 * (*(_DWORD *)(v5 + 64) - 3));
      v8 = (_DWORD *)v5;
      v17 = 15;
      do
      {
        v9 = (void *)(LODWORD(a4) + (*v8 << 6));
        v10 = v7;
        ++v8;
        v7 += 64;
        v11 = v17-- == 1;
        qmemcpy(v9, v10, 0x40u);
      }
      while ( !v11 );
      v4 = (double (__thiscall ***)(_DWORD, _DWORD))(current_time_in_ms + 5912);
    }
    v5 += 2956;
  }
  while ( (double (__thiscall ***)(_DWORD, _DWORD))(v5 - 2880) != v4 );
}
