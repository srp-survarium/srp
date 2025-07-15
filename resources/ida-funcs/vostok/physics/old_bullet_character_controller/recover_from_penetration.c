void __thiscall vostok::physics::old_bullet_character_controller::recover_from_penetration(
        vostok::physics::old_bullet_character_controller *this,
        int current_loop,
        int a3)
{
  int v3; // esi
  int v4; // xmm1_4
  int *v5; // ecx
  int v6; // eax
  btAlignedObjectArray<GrahamVector2> *v7; // ecx
  int v8; // edi
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  float v14; // xmm0_4
  float *v15; // edx
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm4_4
  int *v20; // esi
  int *v21; // esi
  float v22; // xmm5_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm4_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm5_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  btVector3 *NormalizedVector; // eax
  _DWORD *v33; // esi
  float v34; // xmm1_4
  float v35; // xmm2_4
  _DWORD *v36; // esi
  bool v37; // [esp+19h] [ebp-6Dh]
  float v38; // [esp+1Ah] [ebp-6Ch]
  float v39; // [esp+1Eh] [ebp-68h]
  float *v40; // [esp+22h] [ebp-64h]
  int v41; // [esp+26h] [ebp-60h]
  int v42; // [esp+2Ah] [ebp-5Ch]
  int v43; // [esp+2Eh] [ebp-58h]
  int v44; // [esp+32h] [ebp-54h]
  int i; // [esp+36h] [ebp-50h]
  btVector3 v46; // [esp+46h] [ebp-40h] BYREF
  btVector3 v47; // [esp+56h] [ebp-30h] BYREF
  char v48[4]; // [esp+72h] [ebp-14h] BYREF
  int v49; // [esp+76h] [ebp-10h]
  int v50; // [esp+7Ah] [ebp-Ch]
  void *ptr; // [esp+7Eh] [ebp-8h]
  char v52; // [esp+82h] [ebp-4h]

  v3 = *(_DWORD *)(*(_DWORD *)(current_loop + 20) + 24);
  (*(void (__thiscall **)(_DWORD, _DWORD, int))(**(_DWORD **)(current_loop + 464) + 36))(
    *(_DWORD *)(current_loop + 464),
    *(_DWORD *)(current_loop + 360),
    v3);
  (*(void (__thiscall **)(int, _DWORD, int, int))(*(_DWORD *)v3 + 28))(
    v3,
    *(_DWORD *)(current_loop + 464),
    *(_DWORD *)(current_loop + 20) + 28,
    v3);
  v4 = *(_DWORD *)(current_loop + 116);
  v5 = *(int **)(current_loop + 464);
  v40 = (float *)(current_loop + 80);
  *(_DWORD *)(current_loop + 80) = *(_DWORD *)(current_loop + 224);
  *(_DWORD *)(current_loop + 84) = *(_DWORD *)(current_loop + 228);
  *(_DWORD *)(current_loop + 88) = *(_DWORD *)(current_loop + 232);
  *(_DWORD *)(current_loop + 92) = *(_DWORD *)(current_loop + 236);
  v52 = 1;
  ptr = 0;
  v49 = 0;
  v50 = 0;
  v44 = v4 & 0x7FFFFFFF;
  v6 = *v5;
  v39 = 0.0;
  memset(&v46, 0, sizeof(v46));
  v43 = 0;
  if ( (*(int (__thiscall **)(int *))(v6 + 32))(v5) <= 0 )
    goto LABEL_41;
  v42 = 0;
  do
  {
    v8 = v49;
    if ( v49 < 0 )
    {
      if ( v50 < 0 )
      {
        if ( ptr && v52 )
          btAlignedFreeInternal(ptr);
        v52 = 1;
        ptr = 0;
        v50 = 0;
      }
      if ( v8 < 0 )
      {
        v9 = 4 * v8;
        do
        {
          if ( (char *)ptr + v9 )
            *(_DWORD *)((char *)ptr + v9) = 0;
          v9 += 4;
        }
        while ( v9 < 0 );
      }
    }
    v10 = *(_DWORD *)(current_loop + 464);
    v49 = 0;
    v11 = v42 + *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)v10 + 24))(v10) + 12);
    if ( (*(_BYTE *)(*(_DWORD *)v11 + 4) & 1) == 0 && (*(_BYTE *)(*(_DWORD *)(v11 + 4) + 4) & 1) == 0 )
    {
      if ( *(_DWORD *)(v11 + 8) )
        (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)(v11 + 8) + 12))(*(_DWORD *)(v11 + 8), v48);
      v12 = 0;
      for ( i = 0; i < v49; ++i )
      {
        v13 = *((_DWORD *)ptr + v12);
        v37 = *(_DWORD *)(v13 + 1168) == current_loop + 160;
        if ( *(_DWORD *)(v13 + 1168) == current_loop + 160 )
          v14 = FLOAT_N1_0;
        else
          v14 = s_bm_current_air_resistance;
        v38 = v14;
        v41 = 0;
        if ( *(int *)(v13 + 1176) > 0 )
        {
          v15 = (float *)(v13 + 88);
          do
          {
            if ( v15[2] < 0.0 )
            {
              v16 = *(v15 - 2) * v38;
              v17 = *(v15 - 1) * v38;
              v18 = *v15 * v38;
              v46.mVec128.m128_f32[0] = v16 + v46.mVec128.m128_f32[0];
              v19 = v15[2];
              v46.mVec128.m128_f32[1] = v17 + v46.mVec128.m128_f32[1];
              v46.mVec128.m128_f32[2] = v18 + v46.mVec128.m128_f32[2];
              if ( v39 > v19 )
                v39 = v19;
              v20 = (int *)(v15 - 18);
              if ( !v37 )
                v20 = (int *)(v15 - 14);
              v47.mVec128.m128_i32[0] = *v20;
              v21 = v20 + 1;
              v47.mVec128.m128_i32[1] = *v21;
              v47.mVec128.m128_u64[1] = *(_QWORD *)(v21 + 1);
              v22 = v16 * v19;
              v23 = v17 * v19;
              v24 = v18 * v19;
              if ( v47.mVec128.m128_f32[1] <= 0.0 )
              {
                v25 = (float)((float)((float)(*(float *)&v44 - COERCE_FLOAT(v47.mVec128.m128_i32[1] & 0x7FFFFFFF))
                                    / *(float *)&v44)
                            * (float)((float)(*(float *)&v44 - COERCE_FLOAT(v47.mVec128.m128_i32[1] & 0x7FFFFFFF))
                                    / *(float *)&v44))
                    * (float)((float)(*(float *)&v44 - COERCE_FLOAT(v47.mVec128.m128_i32[1] & 0x7FFFFFFF))
                            / *(float *)&v44);
                v26 = s_bm_current_air_resistance - v25;
              }
              else
              {
                v25 = s_bm_current_air_resistance;
                v26 = 0.0;
              }
              v27 = v23 * v26;
              v28 = v22 * v25;
              v29 = v24 * v25;
              if ( v27 < 0.0 )
                v27 = 0.0;
              v30 = v27 + *(float *)(current_loop + 84);
              v31 = v29 + *(float *)(current_loop + 88);
              *v40 = *v40 + v28;
              *(float *)(current_loop + 84) = v30;
              *(float *)(current_loop + 88) = v31;
            }
            ++v41;
            v15 += 72;
          }
          while ( v41 < *(_DWORD *)(v13 + 1176) );
        }
        v12 = i + 1;
      }
    }
    ++v43;
    v42 += 16;
  }
  while ( v43 < (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(current_loop + 464) + 32))(*(_DWORD *)(current_loop + 464)) );
  if ( v39 < 0.0 && a3 )
  {
    NormalizedVector = vostok::physics::getNormalizedVector(&v46, &v47);
    v33 = (_DWORD *)(current_loop + 80);
    v34 = (float)(NormalizedVector->mVec128.m128_f32[1] * v39) + *(float *)(current_loop + 84);
    v35 = (float)(NormalizedVector->mVec128.m128_f32[2] * v39) + *(float *)(current_loop + 88);
    *v40 = (float)(NormalizedVector->mVec128.m128_f32[0] * v39) + *v40;
    *(float *)(current_loop + 84) = v34;
    *(float *)(current_loop + 88) = v35;
  }
  else
  {
LABEL_41:
    v33 = (_DWORD *)(current_loop + 80);
  }
  *(_DWORD *)(current_loop + 224) = *v33;
  v36 = v33 + 1;
  *(_DWORD *)(current_loop + 228) = *v36++;
  *(_DWORD *)(current_loop + 232) = *v36;
  *(_DWORD *)(current_loop + 236) = v36[1];
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v7, (int)v48);
}
