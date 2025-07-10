void __usercall btPolyhedralContactClipping::clipHullAgainstHull(
        const btVector3 *separatingNormal1@<eax>,
        const btTransform *transB@<esi>,
        const btConvexPolyhedron *hullA,
        const btConvexPolyhedron *hullB,
        const btTransform *transA,
        float minDist,
        float maxDist,
        btDiscreteCollisionDetectorInterface::Result *resultOut)
{
  long double v9; // st7
  float v10; // xmm3_4
  int v11; // eax
  long double v12; // st6
  float v13; // xmm4_4
  long double v14; // st7
  const btConvexPolyhedron *v15; // edi
  int m_size; // edx
  float *v17; // ecx
  float *v18; // ecx
  int v19; // eax
  int v20; // edi
  btVector3 *m_data; // edx
  int v22; // ebx
  int v23; // ecx
  btVector3 *v24; // eax
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm4_4
  int v29; // eax
  btVector3 *v30; // edi
  btVector3 *v31; // eax
  char *v32; // ecx
  int v33; // edx
  __m128 *p_mVec128; // eax
  int v35; // [esp+1A8h] [ebp-68h]
  __int64 v36; // [esp+1ACh] [ebp-64h]
  __int64 v37; // [esp+1ACh] [ebp-64h]
  float v38; // [esp+1B4h] [ebp-5Ch]
  __int64 v39; // [esp+1B8h] [ebp-58h]
  __int64 v40; // [esp+1B8h] [ebp-58h]
  float v41; // [esp+1C0h] [ebp-50h]
  float v42; // [esp+1C0h] [ebp-50h]
  int v43; // [esp+1C0h] [ebp-50h]
  __int64 v44; // [esp+1C4h] [ebp-4Ch]
  __int64 v45; // [esp+1C4h] [ebp-4Ch]
  int v46; // [esp+1C4h] [ebp-4Ch]
  float v47; // [esp+1C8h] [ebp-48h]
  int v48; // [esp+1C8h] [ebp-48h]
  float v49; // [esp+1CCh] [ebp-44h]
  float v50; // [esp+1CCh] [ebp-44h]
  float v51; // [esp+1CCh] [ebp-44h]
  int v52; // [esp+1CCh] [ebp-44h]
  btVector3 v53; // [esp+1D0h] [ebp-40h] BYREF
  unsigned __int64 v54; // [esp+1E0h] [ebp-30h]
  unsigned __int64 v55; // [esp+1E8h] [ebp-28h]
  btAlignedObjectArray<btVector3> v56; // [esp+1FCh] [ebp-14h] BYREF

  v49 = separatingNormal1->mVec128.m128_f32[0];
  v9 = 1.0
     / sqrtf(
         (float)((float)(v49 * v49)
               + (float)(separatingNormal1->mVec128.m128_f32[1] * separatingNormal1->mVec128.m128_f32[1]))
       + (float)(separatingNormal1->mVec128.m128_f32[2] * separatingNormal1->mVec128.m128_f32[2]));
  v10 = -3.4028235e38;
  v11 = 0;
  v53.mVec128.m128_i32[3] = 0;
  v35 = -1;
  v47 = v9;
  v12 = v9 * separatingNormal1->mVec128.m128_f32[1];
  v13 = v49 * v47;
  v53.mVec128.m128_f32[0] = v49 * v47;
  v53.mVec128.m128_f32[1] = v12;
  v14 = v9 * separatingNormal1->mVec128.m128_f32[2];
  v15 = hullB;
  m_size = hullB->m_faces.m_size;
  v53.mVec128.m128_f32[2] = v14;
  if ( m_size >= 4 )
  {
    v36 = *(__int64 *)((char *)transB->m_basis.m_el[0].mVec128.m128_i64 + 4);
    v38 = transB->m_basis.m_el[0].mVec128.m128_f32[0];
    v39 = *(__int64 *)((char *)transB->m_basis.m_el[1].mVec128.m128_i64 + 4);
    v41 = transB->m_basis.m_el[1].mVec128.m128_f32[0];
    v44 = *(__int64 *)((char *)transB->m_basis.m_el[2].mVec128.m128_i64 + 4);
    v50 = transB->m_basis.m_el[2].mVec128.m128_f32[0];
    v17 = &hullB->m_faces.m_data->m_plane[1];
    do
    {
      if ( (float)((float)((float)((float)((float)((float)(*(float *)&v39 * *v17)
                                                 + (float)(*((float *)&v39 + 1) * v17[1]))
                                         + (float)(v41 * *(v17 - 1)))
                                 * v53.mVec128.m128_f32[1])
                         + (float)((float)((float)((float)(*(float *)&v44 * *v17)
                                                 + (float)(*((float *)&v44 + 1) * v17[1]))
                                         + (float)(v50 * *(v17 - 1)))
                                 * v53.mVec128.m128_f32[2]))
                 + (float)((float)((float)((float)(*v17 * *(float *)&v36) + (float)(v17[1] * *((float *)&v36 + 1)))
                                 + (float)(v38 * *(v17 - 1)))
                         * v13)) > v10 )
      {
        v10 = (float)((float)((float)((float)((float)(*(float *)&v39 * *v17) + (float)(*((float *)&v39 + 1) * v17[1]))
                                    + (float)(v41 * *(v17 - 1)))
                            * v53.mVec128.m128_f32[1])
                    + (float)((float)((float)((float)(*(float *)&v44 * *v17) + (float)(*((float *)&v44 + 1) * v17[1]))
                                    + (float)(v50 * *(v17 - 1)))
                            * v53.mVec128.m128_f32[2]))
            + (float)((float)((float)((float)(*v17 * *(float *)&v36) + (float)(v17[1] * *((float *)&v36 + 1)))
                            + (float)(v38 * *(v17 - 1)))
                    * v13);
        v35 = v11;
      }
      if ( (float)((float)((float)((float)((float)((float)(*(float *)&v39 * v17[9])
                                                 + (float)(*((float *)&v39 + 1) * v17[10]))
                                         + (float)(v41 * v17[8]))
                                 * v53.mVec128.m128_f32[1])
                         + (float)((float)((float)((float)(*(float *)&v44 * v17[9])
                                                 + (float)(*((float *)&v44 + 1) * v17[10]))
                                         + (float)(v50 * v17[8]))
                                 * v53.mVec128.m128_f32[2]))
                 + (float)((float)((float)((float)(v17[9] * *(float *)&v36) + (float)(v17[10] * *((float *)&v36 + 1)))
                                 + (float)(v38 * v17[8]))
                         * v13)) > v10 )
      {
        v10 = (float)((float)((float)((float)((float)(*(float *)&v39 * v17[9]) + (float)(*((float *)&v39 + 1) * v17[10]))
                                    + (float)(v41 * v17[8]))
                            * v53.mVec128.m128_f32[1])
                    + (float)((float)((float)((float)(*(float *)&v44 * v17[9]) + (float)(*((float *)&v44 + 1) * v17[10]))
                                    + (float)(v50 * v17[8]))
                            * v53.mVec128.m128_f32[2]))
            + (float)((float)((float)((float)(v17[9] * *(float *)&v36) + (float)(v17[10] * *((float *)&v36 + 1)))
                            + (float)(v38 * v17[8]))
                    * v13);
        v35 = v11 + 1;
      }
      if ( (float)((float)((float)((float)((float)((float)(*(float *)&v39 * v17[18])
                                                 + (float)(*((float *)&v39 + 1) * v17[19]))
                                         + (float)(v41 * v17[17]))
                                 * v53.mVec128.m128_f32[1])
                         + (float)((float)((float)((float)(*(float *)&v44 * v17[18])
                                                 + (float)(*((float *)&v44 + 1) * v17[19]))
                                         + (float)(v50 * v17[17]))
                                 * v53.mVec128.m128_f32[2]))
                 + (float)((float)((float)((float)(v17[18] * *(float *)&v36) + (float)(v17[19] * *((float *)&v36 + 1)))
                                 + (float)(v38 * v17[17]))
                         * v13)) > v10 )
      {
        v10 = (float)((float)((float)((float)((float)(*(float *)&v39 * v17[18]) + (float)(*((float *)&v39 + 1) * v17[19]))
                                    + (float)(v41 * v17[17]))
                            * v53.mVec128.m128_f32[1])
                    + (float)((float)((float)((float)(*(float *)&v44 * v17[18]) + (float)(*((float *)&v44 + 1) * v17[19]))
                                    + (float)(v50 * v17[17]))
                            * v53.mVec128.m128_f32[2]))
            + (float)((float)((float)((float)(v17[18] * *(float *)&v36) + (float)(v17[19] * *((float *)&v36 + 1)))
                            + (float)(v38 * v17[17]))
                    * v13);
        v35 = v11 + 2;
      }
      if ( (float)((float)((float)((float)((float)((float)(*(float *)&v39 * v17[27])
                                                 + (float)(*((float *)&v39 + 1) * v17[28]))
                                         + (float)(v41 * v17[26]))
                                 * v53.mVec128.m128_f32[1])
                         + (float)((float)((float)((float)(*(float *)&v44 * v17[27])
                                                 + (float)(*((float *)&v44 + 1) * v17[28]))
                                         + (float)(v50 * v17[26]))
                                 * v53.mVec128.m128_f32[2]))
                 + (float)((float)((float)((float)(v17[27] * *(float *)&v36) + (float)(v17[28] * *((float *)&v36 + 1)))
                                 + (float)(v38 * v17[26]))
                         * v13)) > v10 )
      {
        v10 = (float)((float)((float)((float)((float)(*(float *)&v39 * v17[27]) + (float)(*((float *)&v39 + 1) * v17[28]))
                                    + (float)(v41 * v17[26]))
                            * v53.mVec128.m128_f32[1])
                    + (float)((float)((float)((float)(*(float *)&v44 * v17[27]) + (float)(*((float *)&v44 + 1) * v17[28]))
                                    + (float)(v50 * v17[26]))
                            * v53.mVec128.m128_f32[2]))
            + (float)((float)((float)((float)(v17[27] * *(float *)&v36) + (float)(v17[28] * *((float *)&v36 + 1)))
                            + (float)(v38 * v17[26]))
                    * v13);
        v35 = v11 + 3;
      }
      v11 += 4;
      v17 += 36;
    }
    while ( v11 < m_size - 3 );
    v15 = hullB;
  }
  if ( v11 < m_size )
  {
    v18 = &v15->m_faces.m_data[v11].m_plane[1];
    do
    {
      v37 = *(__int64 *)((char *)transB->m_basis.m_el[0].mVec128.m128_i64 + 4);
      v40 = *(__int64 *)((char *)transB->m_basis.m_el[1].mVec128.m128_i64 + 4);
      v42 = transB->m_basis.m_el[1].mVec128.m128_f32[0];
      v45 = *(__int64 *)((char *)transB->m_basis.m_el[2].mVec128.m128_i64 + 4);
      v51 = transB->m_basis.m_el[2].mVec128.m128_f32[0];
      if ( (float)((float)((float)((float)((float)((float)(*(float *)&v40 * *v18)
                                                 + (float)(*((float *)&v40 + 1) * v18[1]))
                                         + (float)(v42 * *(v18 - 1)))
                                 * v53.mVec128.m128_f32[1])
                         + (float)((float)((float)((float)(*(float *)&v45 * *v18)
                                                 + (float)(*((float *)&v45 + 1) * v18[1]))
                                         + (float)(v51 * *(v18 - 1)))
                                 * v53.mVec128.m128_f32[2]))
                 + (float)((float)((float)((float)(*v18 * *(float *)&v37) + (float)(v18[1] * *((float *)&v37 + 1)))
                                 + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[0] * *(v18 - 1)))
                         * v13)) > v10 )
      {
        v10 = (float)((float)((float)((float)((float)(*(float *)&v40 * *v18) + (float)(*((float *)&v40 + 1) * v18[1]))
                                    + (float)(v42 * *(v18 - 1)))
                            * v53.mVec128.m128_f32[1])
                    + (float)((float)((float)((float)(*(float *)&v45 * *v18) + (float)(*((float *)&v45 + 1) * v18[1]))
                                    + (float)(v51 * *(v18 - 1)))
                            * v53.mVec128.m128_f32[2]))
            + (float)((float)((float)((float)(*v18 * *(float *)&v37) + (float)(v18[1] * *((float *)&v37 + 1)))
                            + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[0] * *(v18 - 1)))
                    * v13);
        v35 = v11;
      }
      ++v11;
      v18 += 9;
    }
    while ( v11 < m_size );
  }
  v19 = (int)&v15->m_faces.m_data[v35];
  v20 = *(_DWORD *)(v19 + 4);
  m_data = 0;
  v22 = 0;
  v23 = 0;
  v56.m_ownsMemory = 1;
  memset(&v56.m_size, 0, 12);
  v43 = v19;
  v46 = v20;
  v48 = 0;
  if ( v20 > 0 )
  {
    HIDWORD(v55) = 0;
    while ( 1 )
    {
      v24 = &hullB->m_vertices.m_data[*(_DWORD *)(*(_DWORD *)(v19 + 12) + 4 * v48)];
      v25 = v24->mVec128.m128_f32[1];
      v26 = v24->mVec128.m128_f32[0];
      v27 = v24->mVec128.m128_f32[2];
      v28 = transB->m_basis.m_el[1].mVec128.m128_f32[1];
      *(float *)&v54 = (float)((float)((float)(transB->m_basis.m_el[0].mVec128.m128_f32[0] * v24->mVec128.m128_f32[0])
                                     + (float)(v25 * transB->m_basis.m_el[0].mVec128.m128_f32[1]))
                             + (float)(v27 * transB->m_basis.m_el[0].mVec128.m128_f32[2]))
                     + transB->m_origin.mVec128.m128_f32[0];
      *((float *)&v54 + 1) = (float)((float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[0] * v26)
                                           + (float)(v28 * v25))
                                   + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[2] * v27))
                           + transB->m_origin.mVec128.m128_f32[1];
      *(float *)&v55 = (float)((float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[1] * v25)
                                     + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2] * v27))
                             + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[0] * v26))
                     + transB->m_origin.mVec128.m128_f32[2];
      if ( v22 == v23 )
      {
        if ( v22 )
        {
          v29 = 2 * v22;
          v52 = 2 * v22;
        }
        else
        {
          v52 = 1;
          v29 = 1;
        }
        if ( v23 < v29 )
        {
          if ( v29 )
          {
            ++gNumAlignedAllocs;
            v30 = (btVector3 *)sAlignedAllocFunc(16 * v29, 16);
          }
          else
          {
            v30 = 0;
          }
          if ( v22 > 0 )
          {
            v31 = v30;
            v32 = (char *)((char *)v56.m_data - (char *)v30);
            v33 = v22;
            do
            {
              if ( v31 )
              {
                v31->mVec128.m128_u64[0] = *(unsigned __int64 *)((char *)v31->mVec128.m128_u64 + (_DWORD)v32);
                v31->mVec128.m128_u64[1] = *(unsigned __int64 *)((char *)&v31->mVec128.m128_u64[1] + (_DWORD)v32);
              }
              ++v31;
              --v33;
            }
            while ( v33 );
          }
          if ( v56.m_data )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v56.m_data);
          }
          v23 = v52;
          v56.m_ownsMemory = 1;
          v56.m_data = v30;
          v56.m_capacity = v52;
          m_data = v30;
        }
      }
      p_mVec128 = &m_data[v22].mVec128;
      if ( p_mVec128 )
      {
        p_mVec128->m128_u64[0] = v54;
        p_mVec128->m128_u64[1] = v55;
      }
      ++v22;
      if ( ++v48 >= v46 )
        break;
      v19 = v43;
    }
    v56.m_size = v22;
  }
  if ( v35 >= 0 )
  {
    btPolyhedralContactClipping::clipFaceAgainstHull(transA, &v56, &v53, hullA, minDist, maxDist, resultOut);
    m_data = v56.m_data;
  }
  if ( m_data )
  {
    if ( v56.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
  }
}
