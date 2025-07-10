void __usercall btConvexPolyhedron::initialize(btConvexPolyhedron *this@<ecx>, int a2@<eax>)
{
  bool v3; // cc
  int v4; // eax
  int v5; // ecx
  __int16 v6; // di
  __int16 v7; // bx
  __int16 v8; // ax
  int Index; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  float v13; // xmm2_4
  float v14; // xmm1_4
  long double v15; // st7
  int v16; // eax
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm7_4
  btConvexPolyhedron *v20; // eax
  int v21; // edi
  btConvexPolyhedron *v22; // ebx
  int v23; // edx
  int v24; // edi
  int v25; // eax
  void *v26; // eax
  _QWORD *v27; // eax
  int v28; // eax
  float *v29; // edi
  int v30; // eax
  int v31; // ebx
  int v32; // ecx
  int v33; // edx
  int v34; // ecx
  float v35; // xmm3_4
  float v36; // xmm2_4
  int v37; // eax
  float v38; // xmm1_4
  float v39; // xmm6_4
  float v40; // xmm4_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm5_4
  float v44; // xmm3_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm0_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  int v51; // ebx
  float *v52; // edi
  long double v53; // st7
  float v54; // xmm6_4
  float v55; // xmm5_4
  float v56; // xmm4_4
  float v57; // xmm0_4
  float v58; // xmm2_4
  float v59; // xmm1_4
  float *v60; // eax
  float v61; // xmm3_4
  float v62; // xmm3_4
  float v63; // xmm2_4
  float v64; // xmm1_4
  float v65; // xmm0_4
  float v66; // xmm6_4
  int v67; // ebx
  float v68; // xmm7_4
  float v69; // xmm7_4
  int v70; // edi
  float v71; // xmm7_4
  int v72; // edi
  btConvexPolyhedron *v73; // ecx
  int v74; // ebx
  float v75; // xmm6_4
  float v76; // xmm0_4
  int v77; // [esp+76Ch] [ebp-98h]
  int v78; // [esp+76Ch] [ebp-98h]
  btConvexPolyhedron *v79; // [esp+770h] [ebp-94h]
  int v80; // [esp+770h] [ebp-94h]
  int v81; // [esp+770h] [ebp-94h]
  btInternalVertexPair key; // [esp+774h] [ebp-90h] BYREF
  int v83; // [esp+778h] [ebp-8Ch]
  btHashMap<btInternalVertexPair,btInternalEdge> *v84; // [esp+77Ch] [ebp-88h]
  float v85; // [esp+780h] [ebp-84h]
  float v86; // [esp+784h] [ebp-80h]
  btInternalEdge value; // [esp+788h] [ebp-7Ch] BYREF
  int v88; // [esp+78Ch] [ebp-78h]
  float v89; // [esp+790h] [ebp-74h]
  __int64 v90; // [esp+794h] [ebp-70h]
  __int64 v91; // [esp+79Ch] [ebp-68h]
  int v92; // [esp+7A4h] [ebp-60h]
  float v93; // [esp+7A8h] [ebp-5Ch]
  float v94; // [esp+7ACh] [ebp-58h]
  float v95; // [esp+7B0h] [ebp-54h]
  btHashMap<btInternalVertexPair,btInternalEdge> v96; // [esp+7B4h] [ebp-50h] BYREF

  *(_DWORD *)(a2 + 80) = 0;
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 92) = 0;
  v3 = *(_DWORD *)(a2 + 40) <= 0;
  v96.m_hashTable.m_ownsMemory = 1;
  memset(&v96.m_hashTable.m_size, 0, 12);
  v96.m_next.m_ownsMemory = 1;
  memset(&v96.m_next.m_size, 0, 12);
  v96.m_valueArray.m_ownsMemory = 1;
  memset(&v96.m_valueArray.m_size, 0, 12);
  v96.m_keyArray.m_ownsMemory = 1;
  memset(&v96.m_keyArray.m_size, 0, 12);
  v89 = 0.0;
  *(float *)&v84 = 0.0;
  if ( !v3 )
  {
    v77 = 0;
    do
    {
      this = *(btConvexPolyhedron **)(v77 + *(_DWORD *)(a2 + 48) + 4);
      v4 = 0;
      v79 = this;
      if ( (int)this > 0 )
      {
        HIDWORD(v91) = 0;
        do
        {
          v5 = *(_DWORD *)(v77 + *(_DWORD *)(a2 + 48) + 12);
          v6 = *(_WORD *)(v5 + 4 * v4);
          v88 = v4 + 1;
          key.m_v0 = v6;
          v7 = *(_WORD *)(v5 + 4 * ((v4 + 1) % (int)v79));
          key.m_v1 = v7;
          if ( v7 > v6 )
          {
            v8 = v6;
            v6 = v7;
            v7 = v8;
            key.m_v0 = v6;
            key.m_v1 = v8;
          }
          Index = btHashMap<btInternalVertexPair,btInternalEdge>::findIndex(&v96, &key);
          if ( Index == -1 )
            v86 = 0.0;
          else
            LODWORD(v86) = &v96.m_valueArray.m_data[Index];
          v10 = *(_DWORD *)(a2 + 28);
          v11 = 16 * v7;
          v12 = 16 * v6;
          v13 = *(float *)(v11 + v10 + 8) - *(float *)(v12 + v10 + 8);
          v14 = *(float *)(v11 + v10 + 4) - *(float *)(v12 + v10 + 4);
          *(float *)&v90 = *(float *)(v11 + v10) - *(float *)(v12 + v10);
          *((float *)&v90 + 1) = v14;
          *(float *)&v91 = v13;
          v15 = sqrtf((float)((float)(*(float *)&v90 * *(float *)&v90) + (float)(v13 * v13)) + (float)(v14 * v14));
          v16 = 0;
          v3 = *(_DWORD *)(a2 + 60) <= 0;
          *(float *)&v83 = 1.0 / v15;
          v17 = *(float *)&v83 * *(float *)&v90;
          v18 = *((float *)&v90 + 1) * *(float *)&v83;
          v19 = *(float *)&v91 * *(float *)&v83;
          *(float *)&v90 = *(float *)&v83 * *(float *)&v90;
          *((float *)&v90 + 1) = *((float *)&v90 + 1) * *(float *)&v83;
          *(float *)&v91 = *(float *)&v91 * *(float *)&v83;
          if ( v3 )
          {
LABEL_19:
            this = *(btConvexPolyhedron **)(a2 + 64);
            v20 = *(btConvexPolyhedron **)(a2 + 60);
            if ( v20 == this )
            {
              v21 = 2 * (_DWORD)v20;
              if ( !v20 )
                v21 = 1;
              v83 = v21;
              if ( (int)this < v21 )
              {
                if ( *(float *)&v21 == 0.0 )
                {
                  v22 = 0;
                }
                else
                {
                  ++gNumAlignedAllocs;
                  v22 = (btConvexPolyhedron *)sAlignedAllocFunc(16 * v21, 16);
                }
                if ( *(int *)(a2 + 60) > 0 )
                {
                  v23 = 0;
                  this = v22;
                  v24 = *(_DWORD *)(a2 + 60);
                  do
                  {
                    if ( this )
                    {
                      v25 = *(_DWORD *)(a2 + 68);
                      *(_QWORD *)&this->__vftable = *(_QWORD *)(v25 + v23);
                      *(_QWORD *)&(&this->__vftable)[2] = *(_QWORD *)(v23 + v25 + 8);
                    }
                    v23 += 16;
                    this = (btConvexPolyhedron *)((char *)this + 16);
                    --v24;
                  }
                  while ( v24 );
                  v21 = v83;
                }
                v26 = *(void **)(a2 + 68);
                if ( v26 )
                {
                  if ( *(_BYTE *)(a2 + 72) )
                  {
                    ++gNumAlignedFree;
                    sAlignedFreeFunc(v26);
                  }
                  *(_DWORD *)(a2 + 68) = 0;
                }
                *(_BYTE *)(a2 + 72) = 1;
                *(_DWORD *)(a2 + 68) = v22;
                *(float *)(a2 + 64) = *(float *)&v21;
              }
            }
            v27 = (_QWORD *)(*(_DWORD *)(a2 + 68) + 16 * *(_DWORD *)(a2 + 60));
            if ( v27 )
            {
              *v27 = v90;
              v27[1] = v91;
            }
            ++*(_DWORD *)(a2 + 60);
          }
          else
          {
            this = *(btConvexPolyhedron **)(a2 + 68);
            while ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&this->__vftable - v17) & _mask__AbsFloat_) > 0.000001
                 || COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&(&this->__vftable)[1] - v18) & _mask__AbsFloat_) > 0.000001
                 || COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&(&this->__vftable)[2] - v19) & _mask__AbsFloat_) > 0.000001 )
            {
              v17 = *(float *)&v90;
              v18 = *((float *)&v90 + 1);
              v19 = *(float *)&v91;
              if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&this->__vftable + *(float *)&v90) & _mask__AbsFloat_) <= 0.000001
                && COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&(&this->__vftable)[1] + *((float *)&v90 + 1)) & _mask__AbsFloat_) <= 0.000001
                && COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&(&this->__vftable)[2] + *(float *)&v91) & _mask__AbsFloat_) <= 0.000001 )
              {
                break;
              }
              ++v16;
              this = (btConvexPolyhedron *)((char *)this + 16);
              if ( v16 >= *(_DWORD *)(a2 + 60) )
                goto LABEL_19;
            }
          }
          if ( v86 == 0.0 )
          {
            LOWORD(this) = (_WORD)v84;
            value.m_face1 = -1;
            value.m_face0 = (__int16)v84;
            btHashMap<btInternalVertexPair,btInternalEdge>::insert(
              (btHashMap<btInternalVertexPair,btInternalEdge> *)this,
              &v96,
              &key,
              &value);
          }
          else
          {
            *(_WORD *)(LODWORD(v86) + 2) = (_WORD)v84;
          }
          v4 = v88;
        }
        while ( v88 < (int)v79 );
      }
      v77 += 36;
      v3 = (int)(&v84->m_hashTable.m_allocator + 1) < *(_DWORD *)(a2 + 40);
      v84 = (btHashMap<btInternalVertexPair,btInternalEdge> *)((char *)v84 + 1);
    }
    while ( v3 );
  }
  v80 = 0;
  if ( *(int *)(a2 + 40) > 0 )
  {
    v78 = 0;
    do
    {
      v28 = v78 + *(_DWORD *)(a2 + 48);
      v29 = (float *)(*(_DWORD *)(a2 + 28) + 16 * **(_DWORD **)(v28 + 12));
      v88 = *(_DWORD *)(v28 + 4);
      this = (btConvexPolyhedron *)(v88 - 2);
      v30 = 1;
      LODWORD(v85) = v88 - 2;
      if ( v88 - 2 >= 1 )
      {
        do
        {
          v31 = *(_DWORD *)(v78 + *(_DWORD *)(a2 + 48) + 12);
          v32 = *(_DWORD *)(v31 + 4 * v30);
          v33 = *(_DWORD *)(a2 + 28);
          v92 = v30 + 1;
          v34 = v33 + 16 * v32;
          v35 = v29[1];
          v36 = v29[2];
          v86 = *v29;
          v37 = *(_DWORD *)(a2 + 28) + 16 * *(_DWORD *)(v31 + 4 * ((v30 + 1) % v88));
          v38 = *(float *)(v37 + 4);
          v39 = *(float *)(v37 + 8);
          v40 = v86 - *(float *)v37;
          key = *(btInternalVertexPair *)v37;
          v95 = v38;
          v41 = v35 - v38;
          v42 = v36 - v39;
          v93 = v39;
          v43 = v86 - *(float *)v34;
          value = *(btInternalEdge *)v34;
          v44 = v35 - *(float *)(v34 + 4);
          v83 = *(int *)(v34 + 4);
          v45 = v36 - *(float *)(v34 + 8);
          v84 = *(btHashMap<btInternalVertexPair,btInternalEdge> **)(v34 + 8);
          v94 = sqrtf(
                  (float)((float)((float)((float)(v41 * v43) - (float)(v44 * v40))
                                * (float)((float)(v41 * v43) - (float)(v44 * v40)))
                        + (float)((float)((float)(v45 * v40) - (float)(v42 * v43))
                                * (float)((float)(v45 * v40) - (float)(v42 * v43))))
                + (float)((float)((float)(v44 * v42) - (float)(v45 * v41))
                        * (float)((float)(v44 * v42) - (float)(v45 * v41))))
              * 0.5;
          v30 = v92;
          v3 = v92 <= SLODWORD(v85);
          v46 = (float)((float)((float)((float)(*(float *)&v83 + v29[1]) + v95) * 0.33333334) * v94)
              + *(float *)(a2 + 84);
          v47 = (float)((float)((float)((float)(*(float *)&v84 + v29[2]) + v93) * 0.33333334) * v94)
              + *(float *)(a2 + 88);
          v48 = v94 + v89;
          *(float *)(a2 + 80) = (float)((float)((float)((float)(*(float *)&value + v86) + *(float *)&key) * 0.33333334)
                                      * v94)
                              + *(float *)(a2 + 80);
          *(float *)(a2 + 84) = v46;
          *(float *)(a2 + 88) = v47;
          v89 = v48;
        }
        while ( v3 );
      }
      v78 += 36;
      ++v80;
    }
    while ( v80 < *(_DWORD *)(a2 + 40) );
  }
  v49 = *(float *)&clear_value / v89;
  *(float *)(a2 + 80) = *(float *)(a2 + 80) * (float)(*(float *)&clear_value / v89);
  v50 = v49 * *(float *)(a2 + 84);
  *(float *)(a2 + 88) = v49 * *(float *)(a2 + 88);
  *(float *)(a2 + 84) = v50;
  v51 = 0;
  v3 = *(_DWORD *)(a2 + 40) <= 0;
  *(_DWORD *)(a2 + 112) = 2139095039;
  if ( !v3 )
  {
    v52 = (float *)(*(_DWORD *)(a2 + 48) + 24);
    do
    {
      v53 = fabsf(
              (float)((float)((float)(*(float *)(a2 + 84) * *v52) + (float)(*(float *)(a2 + 88) * v52[1]))
                    + (float)(*(v52 - 1) * *(float *)(a2 + 80)))
            + v52[2]);
      v85 = v53;
      if ( *(float *)(a2 + 112) > v53 )
        *(float *)(a2 + 112) = v85;
      ++v51;
      v52 += 9;
    }
    while ( v51 < *(_DWORD *)(a2 + 40) );
  }
  v54 = 3.4028235e38;
  v55 = 3.4028235e38;
  v56 = 3.4028235e38;
  v57 = -3.4028235e38;
  v58 = -3.4028235e38;
  v59 = -3.4028235e38;
  if ( *(int *)(a2 + 20) > 0 )
  {
    v60 = *(float **)(a2 + 28);
    this = *(btConvexPolyhedron **)(a2 + 20);
    do
    {
      if ( v54 > *v60 )
        v54 = *v60;
      if ( *v60 > v58 )
        v58 = *v60;
      v61 = v60[1];
      if ( v55 > v61 )
        v55 = v60[1];
      if ( v61 > v59 )
        v59 = v60[1];
      v62 = v60[2];
      if ( v56 > v62 )
        v56 = v60[2];
      if ( v62 > v57 )
        v57 = v60[2];
      v60 += 4;
      this = (btConvexPolyhedron *)((char *)this - 1);
    }
    while ( this );
  }
  *(float *)(a2 + 128) = v58 + v54;
  *(float *)(a2 + 132) = v59 + v55;
  *(_DWORD *)(a2 + 140) = 0;
  v63 = v58 - v54;
  *(float *)(a2 + 136) = v57 + v56;
  *(float *)(a2 + 152) = v57 - v56;
  v64 = v59 - v55;
  *(float *)(a2 + 144) = v63;
  *(float *)(a2 + 148) = v64;
  *(_DWORD *)(a2 + 156) = 0;
  v65 = sqrt(3.0);
  v66 = *(float *)(a2 + 112) / v65;
  if ( v64 <= v63 )
  {
    if ( *(float *)(a2 + 152) <= v63 )
      v67 = 0;
    else
      v67 = 2;
  }
  else if ( *(float *)(a2 + 152) <= v64 )
  {
    v67 = 1;
  }
  else
  {
    v67 = 2;
  }
  v68 = *(float *)(a2 + 4 * v67 + 144);
  *(float *)(a2 + 104) = v66;
  *(float *)(a2 + 100) = v66;
  *(float *)(a2 + 96) = v66;
  v69 = (float)((float)(v68 * 0.5) - v66) * 0.0009765625;
  *(float *)(a2 + 4 * v67 + 96) = *(float *)(a2 + 4 * v67 + 144) * 0.5;
  v70 = 0;
  while ( !btConvexPolyhedron::testContainment(this, a2) )
  {
    ++v70;
    *(float *)(a2 + 4 * v67 + 96) = *(float *)(a2 + 4 * v67 + 96) - v69;
    if ( v70 >= 1024 )
    {
      *(float *)(a2 + 104) = v66;
      *(float *)(a2 + 100) = v66;
      *(float *)(a2 + 96) = v66;
      btHashMap<btHashPtr,int>::~btHashMap<btHashPtr,int>(
        (btHashMap<btInternalVertexPair,btInternalEdge> *)this,
        (int)&v96);
      return;
    }
  }
  v71 = (float)(*(float *)(a2 + 112) - v66) * 0.0009765625;
  v72 = (1 << v67) & 3;
  v73 = (btConvexPolyhedron *)v72;
  v81 = 0;
  v74 = (1 << v72) & 3;
  while ( 1 )
  {
    v75 = *(float *)(a2 + 4 * v72 + 96);
    v85 = *(float *)(a2 + 4 * v74 + 96);
    *(float *)(a2 + 4 * v72 + 96) = v75 + v71;
    *(float *)(a2 + 4 * v74 + 96) = *(float *)(a2 + 4 * v74 + 96) + v71;
    if ( !btConvexPolyhedron::testContainment(v73, a2) )
      break;
    if ( ++v81 >= 1024 )
    {
      btHashMap<btHashPtr,int>::~btHashMap<btHashPtr,int>(
        (btHashMap<btInternalVertexPair,btInternalEdge> *)v73,
        (int)&v96);
      return;
    }
  }
  v76 = v85;
  *(float *)(a2 + 4 * v72 + 96) = v75;
  *(float *)(a2 + 4 * v74 + 96) = v76;
  btHashMap<btHashPtr,int>::~btHashMap<btHashPtr,int>((btHashMap<btInternalVertexPair,btInternalEdge> *)v73, (int)&v96);
}
