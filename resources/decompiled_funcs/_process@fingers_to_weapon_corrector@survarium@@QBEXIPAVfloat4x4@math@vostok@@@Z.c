void __userpurge survarium::fingers_to_weapon_corrector::process(
        survarium::fingers_to_weapon_corrector *this@<ecx>,
        int a2@<eax>,
        unsigned int current_time_in_ms,
        vostok::math::float4x4 *matrices)
{
  _BYTE *v4; // edi
  _BYTE *v5; // esi
  int v6; // eax
  _BYTE *v7; // edx
  _DWORD *v8; // eax
  int v9; // ebx
  vostok::math::float4x4 *v10; // edi
  const void *v11; // esi
  double (__thiscall *v12)(_BYTE *, _DWORD); // edx
  double v13; // st7
  float phalanges_count; // [esp+4h] [ebp-20h]
  float v15; // [esp+8h] [ebp-1Ch]
  _BYTE *v16; // [esp+1Ch] [ebp-8h]
  _BYTE *v17; // [esp+20h] [ebp-4h]

  v4 = (_BYTE *)(a2 + 2056);
  v17 = (_BYTE *)(a2 + 2056);
  v5 = (_BYTE *)(a2 + 1024);
  v16 = (_BYTE *)(a2 + 1024);
  do
  {
    v6 = *((_DWORD *)v5 - 1);
    if ( v6 + 100 > current_time_in_ms )
    {
      v12 = **(double (__thiscall ***)(_BYTE *, _DWORD))v4;
      v15 = (double)(current_time_in_ms - v6) * 0.001;
      if ( *v5 )
        v13 = 1.0 - v12(v4, LODWORD(v15));
      else
        v13 = v12(v4, LODWORD(v15));
      phalanges_count = v13;
      survarium::interpolate_hand_matrices(
        (const vostok::math::float4x4 *)v5 - 16,
        (const unsigned int *)v5 - 16,
        phalanges_count,
        *(const float *)&matrices);
    }
    else if ( *v5 )
    {
      v7 = v5 - 1024;
      v8 = v5 - 64;
      v9 = 15;
      do
      {
        v10 = &matrices[*v8];
        v11 = v7;
        ++v8;
        v7 += 64;
        --v9;
        qmemcpy((void *)v10, v11, sizeof(vostok::math::float4x4));
      }
      while ( v9 );
      v5 = v16;
      v4 = v17;
    }
    v5 += 1028;
    v16 = v5;
  }
  while ( v5 - 1024 != v4 );
}
