void __thiscall btConvexPolyhedron::initialize(btConvexPolyhedron *this, int a2)
{
  bool v2; // cc
  float v3; // eax
  int v4; // ecx
  __int16 v5; // si
  __int16 v6; // di
  __int16 v7; // ax
  int Index; // eax
  int v9; // edx
  float *v10; // eax
  float *v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  int v16; // eax
  btHashMap<btInternalVertexPair,btInternalEdge> *v17; // ecx
  btHashMap<btInternalVertexPair,btInternalEdge> *v18; // eax
  int v19; // esi
  btHashMap<btInternalVertexPair,btInternalEdge> *v20; // eax
  int v21; // eax
  int v22; // edx
  int *v23; // esi
  float *v24; // edi
  float *v25; // edi
  int v26; // edi
  int v27; // eax
  float v28; // ecx
  _DWORD *v29; // eax
  btInternalEdge v30; // edx
  float *v31; // ecx
  int v32; // eax
  int v33; // edi
  float *v34; // esi
  float v35; // xmm6_4
  float v36; // xmm3_4
  float v37; // xmm4_4
  float *v38; // eax
  float v39; // xmm5_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm5_4
  float v44; // xmm6_4
  float v45; // xmm0_4
  float v46; // xmm1_4
  float v47; // xmm6_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  float v50; // xmm1_4
  int v51; // ecx
  float *v52; // eax
  float v53; // xmm2_4
  float v54; // xmm2_4
  float v55; // xmm7_4
  float v56; // xmm6_4
  float v57; // xmm4_4
  float v58; // xmm3_4
  float *v59; // eax
  float v60; // xmm5_4
  float v61; // xmm5_4
  float v62; // xmm3_4
  float v63; // xmm4_4
  float v64; // xmm2_4
  float v65; // xmm0_4
  float v66; // xmm6_4
  float *v67; // eax
  float v68; // xmm7_4
  float *v69; // esi
  float v70; // xmm7_4
  float v71; // xmm7_4
  float *v72; // esi
  float *v73; // edi
  float v74; // xmm6_4
  float v75; // xmm0_4
  btAlignedObjectArray<GrahamVector2> *v76; // ecx
  btAlignedObjectArray<GrahamVector2> *v77; // ecx
  btAlignedObjectArray<GrahamVector2> *v78; // ecx
  btHashMap<btInternalVertexPair,btInternalEdge> *v79; // [esp-10h] [ebp-B4h]
  btHashMap<btInternalVertexPair,btInternalEdge> *v80; // [esp-10h] [ebp-B4h]
  float v81; // [esp+4h] [ebp-A0h]
  int v82; // [esp+4h] [ebp-A0h]
  int v83; // [esp+4h] [ebp-A0h]
  int v84; // [esp+8h] [ebp-9Ch]
  int v85; // [esp+8h] [ebp-9Ch]
  btHashMap<btInternalVertexPair,btInternalEdge> *v86; // [esp+Ch] [ebp-98h]
  int v87; // [esp+Ch] [ebp-98h]
  int v88; // [esp+10h] [ebp-94h]
  btInternalVertexPair key; // [esp+14h] [ebp-90h] BYREF
  float v90; // [esp+18h] [ebp-8Ch]
  btInternalEdge value; // [esp+1Ch] [ebp-88h] BYREF
  int v92; // [esp+20h] [ebp-84h]
  float v93; // [esp+24h] [ebp-80h]
  float v94; // [esp+28h] [ebp-7Ch]
  float v95; // [esp+2Ch] [ebp-78h]
  int v96; // [esp+30h] [ebp-74h]
  btInternalEdge *v97; // [esp+3Ch] [ebp-68h]
  int v98; // [esp+40h] [ebp-64h]
  btHashMap<btInternalVertexPair,btInternalEdge> v99; // [esp+44h] [ebp-60h] BYREF
  float v100; // [esp+94h] [ebp-10h]

  *(_DWORD *)(a2 + 80) = 0;
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 92) = 0;
  v2 = *(_DWORD *)(a2 + 40) <= 0;
  v99.m_hashTable.m_ownsMemory = 1;
  memset(&v99.m_hashTable.m_size, 0, 12);
  v99.m_next.m_ownsMemory = 1;
  memset(&v99.m_next.m_size, 0, 12);
  v99.m_valueArray.m_ownsMemory = 1;
  memset(&v99.m_valueArray.m_size, 0, 12);
  v99.m_keyArray.m_ownsMemory = 1;
  memset(&v99.m_keyArray.m_size, 0, 12);
  v81 = 0.0;
  v88 = 0;
  if ( !v2 )
  {
    v84 = 0;
    do
    {
      v3 = 0.0;
      v92 = *(_DWORD *)(*(_DWORD *)(a2 + 48) + v84 + 4);
      if ( v92 > 0 )
      {
        v96 = 0;
        do
        {
          v4 = *(_DWORD *)(*(_DWORD *)(a2 + 48) + v84 + 12);
          v5 = *(_WORD *)(v4 + 4 * LODWORD(v3));
          LODWORD(v90) = LODWORD(v3) + 1;
          key.m_v0 = v5;
          v6 = *(_WORD *)(v4 + 4 * ((LODWORD(v3) + 1) % v92));
          key.m_v1 = v6;
          if ( v6 > v5 )
          {
            v7 = v5;
            v5 = v6;
            v6 = v7;
            key.m_v0 = v5;
            key.m_v1 = v7;
          }
          Index = btHashMap<btInternalVertexPair,btInternalEdge>::findIndex(&v99, &key);
          if ( Index == -1 )
            v97 = 0;
          else
            v97 = &v99.m_valueArray.m_data[Index];
          v9 = *(_DWORD *)(a2 + 28);
          v10 = (float *)(v9 + 16 * v5);
          v11 = (float *)(v9 + 16 * v6);
          v12 = *v11 - *v10;
          v13 = v11[2] - v10[2];
          v14 = v11[1] - v10[1];
          v15 = s_bm_current_air_resistance
              / fsqrt((float)((float)(v12 * v12) + (float)(v13 * v13)) + (float)(v14 * v14));
          v16 = 0;
          v2 = *(_DWORD *)(a2 + 60) <= 0;
          v93 = v12 * v15;
          v94 = v14 * v15;
          v95 = v13 * v15;
          if ( v2 )
          {
LABEL_19:
            v17 = *(btHashMap<btInternalVertexPair,btInternalEdge> **)(a2 + 64);
            v18 = *(btHashMap<btInternalVertexPair,btInternalEdge> **)(a2 + 60);
            if ( v18 == v17 )
            {
              v19 = v18 ? 2 * (_DWORD)v18 : 1;
              v98 = v19;
              if ( (int)v17 < v19 )
              {
                if ( v19 )
                {
                  v20 = (btHashMap<btInternalVertexPair,btInternalEdge> *)btAlignedAllocInternal(16 * v19);
                  v17 = v79;
                  v86 = v20;
                }
                else
                {
                  v86 = 0;
                }
                v21 = *(_DWORD *)(a2 + 60);
                if ( v21 > 0 )
                {
                  v17 = v86;
                  v22 = 0;
                  do
                  {
                    if ( v17 )
                    {
                      v23 = (int *)(v22 + *(_DWORD *)(a2 + 68));
                      *(_DWORD *)&v17->m_hashTable.m_allocator = *v23++;
                      v17->m_hashTable.m_size = *v23++;
                      v17->m_hashTable.m_capacity = *v23;
                      v17->m_hashTable.m_data = (int *)v23[1];
                      v19 = v98;
                    }
                    v22 += 16;
                    v17 = (btHashMap<btInternalVertexPair,btInternalEdge> *)((char *)v17 + 16);
                    --v21;
                  }
                  while ( v21 );
                }
                if ( *(_DWORD *)(a2 + 68) )
                {
                  if ( *(_BYTE *)(a2 + 72) )
                  {
                    btAlignedFreeInternal(*(void **)(a2 + 68));
                    v17 = v80;
                  }
                  *(_DWORD *)(a2 + 68) = 0;
                }
                *(_BYTE *)(a2 + 72) = 1;
                *(_DWORD *)(a2 + 68) = v86;
                *(_DWORD *)(a2 + 64) = v19;
              }
            }
            v24 = (float *)(*(_DWORD *)(a2 + 68) + 16 * *(_DWORD *)(a2 + 60));
            if ( v24 )
            {
              *v24 = v93;
              v25 = v24 + 1;
              *v25++ = v94;
              *v25 = v95;
              *((_DWORD *)v25 + 1) = v96;
            }
            ++*(_DWORD *)(a2 + 60);
          }
          else
          {
            v17 = *(btHashMap<btInternalVertexPair,btInternalEdge> **)(a2 + 68);
            while ( (COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v17->m_hashTable.m_allocator - v93) & _mask__AbsFloat_) > 0.000001
                  || COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v17->m_hashTable.m_size - v94) & _mask__AbsFloat_) > 0.000001
                  || COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v17->m_hashTable.m_capacity - v95) & _mask__AbsFloat_) > 0.000001)
                 && (COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v17->m_hashTable.m_allocator + v93) & _mask__AbsFloat_) > 0.000001
                  || COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v17->m_hashTable.m_size + v94) & _mask__AbsFloat_) > 0.000001
                  || COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v17->m_hashTable.m_capacity + v95) & _mask__AbsFloat_) > 0.000001) )
            {
              ++v16;
              v17 = (btHashMap<btInternalVertexPair,btInternalEdge> *)((char *)v17 + 16);
              if ( v16 >= *(_DWORD *)(a2 + 60) )
                goto LABEL_19;
            }
          }
          if ( v97 )
          {
            v97->m_face1 = v88;
          }
          else
          {
            value.m_face1 = -1;
            value.m_face0 = v88;
            btHashMap<btInternalVertexPair,btInternalEdge>::insert(v17, &v99, &key, &value);
          }
          v3 = v90;
        }
        while ( SLODWORD(v90) < v92 );
      }
      ++v88;
      v84 += 36;
    }
    while ( v88 < *(_DWORD *)(a2 + 40) );
  }
  v26 = 0;
  v87 = 0;
  if ( *(int *)(a2 + 40) > 0 )
  {
    v85 = 0;
    do
    {
      v27 = v85 + *(_DWORD *)(a2 + 48);
      v28 = *(float *)(v27 + 4);
      v29 = *(_DWORD **)(v27 + 12);
      v30 = (btInternalEdge)(LODWORD(v28) - 2);
      v90 = v28;
      v31 = (float *)(*(_DWORD *)(a2 + 28) + 16 * *v29);
      v32 = 1;
      value = v30;
      if ( *(int *)&v30 >= 1 )
      {
        do
        {
          v33 = *(_DWORD *)(*(_DWORD *)(a2 + 48) + v85 + 12);
          v34 = (float *)(*(_DWORD *)(a2 + 28) + 16 * *(_DWORD *)(v33 + 4 * v32));
          v92 = v32 + 1;
          v35 = *v31;
          v36 = v31[1];
          v37 = v31[2];
          v38 = (float *)(*(_DWORD *)(a2 + 28) + 16 * *(_DWORD *)(v33 + 4 * ((v32 + 1) % SLODWORD(v90))));
          v39 = v38[2];
          v40 = v38[1];
          v100 = *v31 - *v38;
          v41 = v36 - v40;
          v42 = v37 - v39;
          v43 = *v34;
          v93 = v35 - *v34;
          v44 = v34[2];
          v94 = v36 - v34[1];
          v45 = fsqrt(
                  (float)((float)((float)((float)(v41 * v93) - (float)(v94 * v100))
                                * (float)((float)(v41 * v93) - (float)(v94 * v100)))
                        + (float)((float)((float)((float)(v37 - v44) * v100) - (float)(v42 * v93))
                                * (float)((float)((float)(v37 - v44) * v100) - (float)(v42 * v93))))
                + (float)((float)((float)(v94 * v42) - (float)((float)(v37 - v44) * v41))
                        * (float)((float)(v94 * v42) - (float)((float)(v37 - v44) * v41))))
              * 0.5;
          v46 = (float)((float)(v31[1] + v34[1]) + v38[1]) * 0.33333334;
          v47 = (float)(v44 + v31[2]) + v38[2];
          *(float *)(a2 + 80) = (float)((float)((float)((float)(v43 + *v31) + *v38) * 0.33333334) * v45)
                              + *(float *)(a2 + 80);
          *(float *)(a2 + 84) = *(float *)(a2 + 84) + (float)(v46 * v45);
          v32 = v92;
          v2 = v92 <= *(_DWORD *)&value;
          *(float *)(a2 + 88) = *(float *)(a2 + 88) + (float)((float)(v47 * 0.33333334) * v45);
          v81 = v45 + v81;
        }
        while ( v2 );
      }
      ++v87;
      v85 += 36;
    }
    while ( v87 < *(_DWORD *)(a2 + 40) );
    v26 = 0;
  }
  v48 = s_bm_current_air_resistance / v81;
  *(float *)(a2 + 80) = (float)(s_bm_current_air_resistance / v81) * *(float *)(a2 + 80);
  *(float *)(a2 + 84) = *(float *)(a2 + 84) * v48;
  v49 = *(float *)(a2 + 88) * v48;
  v50 = FLOAT_3_4028235e38;
  *(float *)(a2 + 88) = v49;
  v51 = 0;
  v2 = *(_DWORD *)(a2 + 40) <= 0;
  *(float *)(a2 + 112) = FLOAT_3_4028235e38;
  if ( !v2 )
  {
    v52 = (float *)(*(_DWORD *)(a2 + 48) + 24);
    do
    {
      LODWORD(v53) = COERCE_UNSIGNED_INT(
                       (float)((float)((float)(*(float *)(a2 + 88) * v52[1]) + (float)(*v52 * *(float *)(a2 + 84)))
                             + (float)(*(float *)(a2 + 80) * *(v52 - 1)))
                     + v52[2])
                   & _mask__AbsFloat_;
      if ( *(float *)(a2 + 112) > v53 )
        *(float *)(a2 + 112) = v53;
      ++v51;
      v52 += 9;
    }
    while ( v51 < *(_DWORD *)(a2 + 40) );
  }
  v54 = FLOAT_N3_4028235e38;
  v55 = FLOAT_3_4028235e38;
  v56 = FLOAT_3_4028235e38;
  v57 = FLOAT_N3_4028235e38;
  v58 = FLOAT_N3_4028235e38;
  if ( *(int *)(a2 + 20) > 0 )
  {
    v59 = *(float **)(a2 + 28);
    v51 = *(_DWORD *)(a2 + 20);
    do
    {
      if ( v55 > *v59 )
        v55 = *v59;
      if ( *v59 > v57 )
        v57 = *v59;
      v60 = v59[1];
      if ( v56 > v60 )
        v56 = v59[1];
      if ( v60 > v58 )
        v58 = v59[1];
      v61 = v59[2];
      if ( v50 > v61 )
        v50 = v59[2];
      if ( v61 > v54 )
        v54 = v59[2];
      v59 += 4;
      --v51;
    }
    while ( v51 );
  }
  *(float *)(a2 + 128) = v57 + v55;
  *(_DWORD *)(a2 + 140) = 0;
  *(float *)(a2 + 132) = v58 + v56;
  *(float *)(a2 + 136) = v54 + v50;
  v62 = v58 - v56;
  *(_DWORD *)(a2 + 156) = 0;
  v63 = v57 - v55;
  v64 = v54 - v50;
  *(float *)(a2 + 144) = v63;
  *(float *)(a2 + 148) = v62;
  *(float *)(a2 + 152) = v64;
  v65 = sqrt(3.0);
  v66 = *(float *)(a2 + 112) / v65;
  if ( v62 <= v63 )
  {
    if ( *(float *)(a2 + 152) <= v63 )
      goto LABEL_76;
LABEL_75:
    v26 = 2;
    goto LABEL_76;
  }
  if ( v64 > v62 )
    goto LABEL_75;
  v26 = 1;
LABEL_76:
  v82 = 0;
  v67 = (float *)(a2 + 4 * v26 + 144);
  v68 = *v67;
  *(float *)(a2 + 104) = v66;
  *(float *)(a2 + 100) = v66;
  *(float *)(a2 + 96) = v66;
  v69 = (float *)(a2 + 4 * v26 + 96);
  v70 = (float)((float)(v68 * 0.5) - v66) * 0.0009765625;
  *v69 = *v67 * 0.5;
  while ( !btConvexPolyhedron::testContainment((btConvexPolyhedron *)v51, a2) )
  {
    ++v82;
    *v69 = *v69 - v70;
    if ( v82 >= 1024 )
    {
      *(float *)(a2 + 104) = v66;
      *(float *)(a2 + 100) = v66;
      *(float *)(a2 + 96) = v66;
      goto LABEL_85;
    }
  }
  v71 = (float)(*(float *)(a2 + 112) - v66) * 0.0009765625;
  v51 = (1 << v26) & 3;
  v72 = (float *)(a2 + 4 * v51 + 96);
  v83 = 0;
  v73 = (float *)(a2 + 4 * ((1 << v51) & 3) + 96);
  while ( 1 )
  {
    v74 = *v72;
    v90 = *v73;
    *v72 = v74 + v71;
    *v73 = *v73 + v71;
    if ( !btConvexPolyhedron::testContainment((btConvexPolyhedron *)v51, a2) )
      break;
    if ( ++v83 >= 1024 )
      goto LABEL_85;
  }
  v75 = v90;
  *v72 = v74;
  *v73 = v75;
LABEL_85:
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)v51,
    (int)&v99.m_keyArray);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v76, (int)&v99.m_valueArray);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v77, (int)&v99.m_next);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v78, (int)&v99);
}
