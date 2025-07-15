void __thiscall btSoftBody::applyClusters(btSoftBody *this, int drift, char a3)
{
  btSoftBody *v3; // edi
  _DWORD *v4; // eax
  btSoftBody *v5; // esi
  _DWORD *v6; // eax
  float v7; // xmm1_4
  int i; // esi
  int v9; // eax
  float v10; // xmm0_4
  float v11; // xmm0_4
  int v12; // esi
  int v13; // eax
  float *v14; // eax
  float v15; // xmm1_4
  float *v16; // eax
  float v17; // xmm1_4
  int v18; // edx
  float v19; // xmm3_4
  float v20; // xmm6_4
  float **v21; // ecx
  int v22; // eax
  float *v23; // ecx
  float v24; // xmm0_4
  float v25; // xmm5_4
  float v26; // xmm4_4
  float v27; // xmm2_4
  float v28; // xmm7_4
  float v29; // xmm1_4
  float *v30; // ecx
  float v31; // xmm0_4
  float v32; // xmm3_4
  int v33; // esi
  int v34; // edx
  float v35; // xmm0_4
  float *v36; // eax
  float v37; // xmm1_4
  float v38; // xmm2_4
  btAlignedObjectArray<GrahamVector2> *v39; // ecx
  int j; // [esp+8h] [ebp-5Ch]
  int v41; // [esp+Ch] [ebp-58h]
  btSoftBody *v42; // [esp+10h] [ebp-54h]
  float v43; // [esp+14h] [ebp-50h]
  float v44; // [esp+18h] [ebp-4Ch]
  float v45; // [esp+1Ch] [ebp-48h]
  float v46; // [esp+24h] [ebp-40h]
  float v47; // [esp+2Ch] [ebp-38h]
  _BYTE v48[4]; // [esp+3Ch] [ebp-28h] BYREF
  btSoftBody *v49; // [esp+40h] [ebp-24h]
  btSoftBody *v50; // [esp+44h] [ebp-20h]
  btSoftBody *v51; // [esp+48h] [ebp-1Ch]
  char v52; // [esp+4Ch] [ebp-18h]
  _BYTE v53[4]; // [esp+50h] [ebp-14h] BYREF
  btSoftBody *v54; // [esp+54h] [ebp-10h]
  btSoftBody *v55; // [esp+58h] [ebp-Ch]
  char *v56; // [esp+5Ch] [ebp-8h]
  char v57; // [esp+60h] [ebp-4h]

  v3 = *(btSoftBody **)(drift + 720);
  v57 = 1;
  v56 = 0;
  v55 = 0;
  v52 = 1;
  v51 = 0;
  v50 = 0;
  v42 = v3;
  if ( (int)v3 > 0 )
  {
    v57 = 1;
    v56 = (char *)btAlignedAllocInternal(16 * (_DWORD)v3);
    v55 = v3;
    v4 = v56;
    this = v3;
    do
    {
      if ( v4 )
      {
        *v4 = 0;
        v4[1] = 0;
        v4[2] = 0;
        v4[3] = 0;
        v3 = v42;
      }
      v4 += 4;
      this = (btSoftBody *)((char *)this - 1);
    }
    while ( this );
  }
  v5 = *(btSoftBody **)(drift + 720);
  v54 = v3;
  if ( (int)v5 > 0 )
  {
    v52 = 1;
    v51 = (btSoftBody *)btAlignedAllocInternal(4 * (_DWORD)v5);
    v50 = v5;
    v6 = &v51->__vftable;
    this = v5;
    do
    {
      if ( v6 )
        *v6 = 0;
      ++v6;
      this = (btSoftBody *)((char *)this - 1);
    }
    while ( this );
  }
  v7 = s_bm_current_air_resistance;
  v49 = v5;
  if ( a3 )
  {
    for ( i = 0; i < *(_DWORD *)(drift + 1072); ++i )
    {
      v9 = *(_DWORD *)(*(_DWORD *)(drift + 1080) + 4 * i);
      this = (btSoftBody *)(v9 + 324);
      if ( *(_DWORD *)(v9 + 324) )
      {
        v10 = v7 / (float)(int)this->__vftable;
        *(float *)(v9 + 288) = *(float *)(v9 + 288) * v10;
        *(float *)(v9 + 292) = *(float *)(v9 + 292) * v10;
        *(float *)(v9 + 296) = *(float *)(v9 + 296) * v10;
        v11 = v7 / (float)(int)this->__vftable;
        *(float *)(v9 + 304) = *(float *)(v9 + 304) * v11;
        this = (btSoftBody *)(v9 + 308);
        *(float *)(v9 + 308) = *(float *)(v9 + 308) * v11;
        *(float *)(v9 + 312) = *(float *)(v9 + 312) * v11;
      }
    }
  }
  for ( j = 0; j < *(_DWORD *)(drift + 1072); ++j )
  {
    this = (btSoftBody *)j;
    v12 = *(_DWORD *)(*(_DWORD *)(drift + 1080) + 4 * j);
    if ( a3 )
      v13 = *(_DWORD *)(v12 + 324);
    else
      v13 = *(_DWORD *)(v12 + 320);
    if ( v13 > 0 )
    {
      v14 = (float *)(v12 + 288);
      if ( !a3 )
        v14 = (float *)(v12 + 256);
      v15 = *(float *)(drift + 460);
      v43 = *v14 * v15;
      v44 = v14[1] * v15;
      v45 = v14[2] * v15;
      v16 = (float *)(v12 + 304);
      if ( !a3 )
        v16 = (float *)(v12 + 272);
      v17 = *(float *)(drift + 460);
      v18 = 0;
      v19 = v16[2] * v17;
      v46 = v17 * *v16;
      v20 = v16[1] * v17;
      v47 = v19;
      v41 = 0;
      if ( *(int *)(v12 + 24) > 0 )
      {
        while ( 1 )
        {
          v21 = (float **)(*(_DWORD *)(v12 + 32) + 4 * v18);
          v22 = ((int)*v21 - *(_DWORD *)(drift + 728)) / 112;
          v23 = *v21;
          v24 = v23[5] - *(float *)(v12 + 244);
          v25 = *(float *)(*(_DWORD *)(v12 + 12) + 4 * v41);
          v26 = v23[4] - *(float *)(v12 + 240);
          v27 = v23[6] - *(float *)(v12 + 248);
          v28 = v24 * v19;
          v29 = (float)((float)(v24 * v46) - (float)(v20 * v26)) + v45;
          v30 = (float *)&v56[16 * v22];
          v31 = (float)((float)((float)(v19 * v26) - (float)(v27 * v46)) + v44) * v25;
          v32 = *v30;
          v30[1] = v31 + v30[1];
          v30[2] = (float)(v29 * v25) + v30[2];
          *v30 = v32 + (float)((float)((float)((float)(v27 * v20) - v28) + v43) * v25);
          this = v51;
          v18 = v41 + 1;
          *((float *)&v51->__vftable + v22) = *((float *)&v51->__vftable + v22) + v25;
          if ( ++v41 >= *(_DWORD *)(v12 + 24) )
            break;
          v19 = v47;
        }
        v3 = v42;
      }
    }
  }
  v33 = 0;
  if ( (int)v3 > 0 )
  {
    v34 = 0;
    this = (btSoftBody *)(v56 + 8);
    do
    {
      v35 = *((float *)&v51->__vftable + v33);
      if ( v35 > 0.0 )
      {
        v36 = (float *)(*(_DWORD *)(drift + 728) + v34 + 16);
        v37 = (float)(*((float *)&this[-1].m_userIndexMapping + 7) * (float)(s_bm_current_air_resistance / v35))
            + *(float *)(*(_DWORD *)(drift + 728) + v34 + 20);
        v38 = (float)(*(float *)&this->__vftable * (float)(s_bm_current_air_resistance / v35))
            + *(float *)(*(_DWORD *)(drift + 728) + v34 + 24);
        *v36 = (float)(*((float *)&this[-1].m_userIndexMapping + 6) * (float)(s_bm_current_air_resistance / v35)) + *v36;
        v36[1] = v37;
        v36[2] = v38;
      }
      ++v33;
      this = (btSoftBody *)((char *)this + 16);
      v34 += 112;
    }
    while ( v33 < (int)v3 );
  }
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)v48);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v39, (int)v53);
}
