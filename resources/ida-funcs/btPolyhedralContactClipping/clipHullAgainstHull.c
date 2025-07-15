void __usercall btPolyhedralContactClipping::clipHullAgainstHull(
        const btVector3 *separatingNormal1@<eax>,
        const btConvexPolyhedron *hullA,
        const btConvexPolyhedron *hullB,
        const btTransform *transA,
        const btTransform *transB,
        float minDist,
        float maxDist,
        btDiscreteCollisionDetectorInterface::Result *resultOut)
{
  const btConvexPolyhedron *v8; // edx
  int m_size; // ecx
  float v10; // xmm0_4
  unsigned int v11; // xmm1_4
  float v12; // xmm6_4
  int v13; // esi
  float v14; // xmm7_4
  float *v15; // eax
  float v16; // xmm5_4
  btAlignedObjectArray<GrahamVector2> *v17; // ecx
  int v18; // eax
  int v19; // esi
  float *m128_f32; // eax
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  btVector3 *v26; // eax
  btVector3 *v27; // eax
  char *v28; // esi
  char *v29; // esi
  btVector3 *v30; // edi
  int *v31; // edi
  int v32; // [esp+1Ch] [ebp-60h]
  float v33; // [esp+20h] [ebp-5Ch]
  btVector3 *v34; // [esp+20h] [ebp-5Ch]
  int v35; // [esp+24h] [ebp-58h]
  int v36; // [esp+28h] [ebp-54h]
  btAlignedObjectArray<GrahamVector2> *v37; // [esp+2Ch] [ebp-50h]
  int v38; // [esp+30h] [ebp-4Ch]
  char *v39; // [esp+34h] [ebp-48h]
  int v40; // [esp+38h] [ebp-44h]
  btVector3 v41; // [esp+3Ch] [ebp-40h] BYREF
  float v42; // [esp+4Ch] [ebp-30h]
  float v43; // [esp+50h] [ebp-2Ch]
  float v44; // [esp+54h] [ebp-28h]
  int v45; // [esp+58h] [ebp-24h]
  btAlignedObjectArray<btVector3> v46; // [esp+68h] [ebp-14h] BYREF

  v8 = hullB;
  m_size = hullB->m_faces.m_size;
  v35 = -1;
  v10 = s_bm_current_air_resistance
      / fsqrt(
          (float)((float)(separatingNormal1->mVec128.m128_f32[0] * separatingNormal1->mVec128.m128_f32[0])
                + (float)(separatingNormal1->mVec128.m128_f32[1] * separatingNormal1->mVec128.m128_f32[1]))
        + (float)(separatingNormal1->mVec128.m128_f32[2] * separatingNormal1->mVec128.m128_f32[2]));
  *(float *)&v11 = separatingNormal1->mVec128.m128_f32[0] * v10;
  v12 = v10 * separatingNormal1->mVec128.m128_f32[1];
  v41.mVec128.m128_f32[2] = v10 * separatingNormal1->mVec128.m128_f32[2];
  v41.mVec128.m128_i32[3] = 0;
  v13 = 0;
  v41.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v12), v11);
  v33 = FLOAT_N3_4028235e38;
  if ( m_size > 0 )
  {
    v15 = &hullB->m_faces.m_data->m_plane[1];
    do
    {
      v16 = v15[1];
      v14 = transB->m_basis.m_el[0].mVec128.m128_f32[2];
      if ( (float)((float)((float)((float)((float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[0] * *(v15 - 1))
                                                 + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[1] * *v15))
                                         + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[2] * v16))
                                 * v12)
                         + (float)((float)((float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[0] * *(v15 - 1))
                                                 + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[1] * *v15))
                                         + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2] * v16))
                                 * v41.mVec128.m128_f32[2]))
                 + (float)((float)((float)((float)(transB->m_basis.m_el[0].mVec128.m128_f32[1] * *v15)
                                         + (float)(v14 * v16))
                                 + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[0] * *(v15 - 1)))
                         * v41.mVec128.m128_f32[0])) > v33 )
      {
        v33 = (float)((float)((float)((float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[0] * *(v15 - 1))
                                            + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[1] * *v15))
                                    + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[2] * v16))
                            * v12)
                    + (float)((float)((float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[0] * *(v15 - 1))
                                            + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[1] * *v15))
                                    + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2] * v16))
                            * v41.mVec128.m128_f32[2]))
            + (float)((float)((float)((float)(transB->m_basis.m_el[0].mVec128.m128_f32[1] * *v15) + (float)(v14 * v16))
                            + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[0] * *(v15 - 1)))
                    * v41.mVec128.m128_f32[0]);
        v35 = v13;
      }
      ++v13;
      v15 += 9;
    }
    while ( v13 < m_size );
  }
  v17 = (btAlignedObjectArray<GrahamVector2> *)&hullB->m_faces.m_data[v35];
  v18 = 0;
  v19 = v17->m_size;
  v46.m_ownsMemory = 1;
  memset(&v46.m_size, 0, 12);
  v37 = v17;
  v40 = v19;
  v38 = 0;
  if ( v19 > 0 )
  {
    v45 = 0;
    do
    {
      m128_f32 = v8->m_vertices.m_data[v17->m_data->mVec128.m128_i32[v18]].mVec128.m128_f32;
      v21 = *m128_f32;
      v22 = m128_f32[1];
      v23 = m128_f32[2];
      v42 = (float)((float)((float)(*m128_f32 * transB->m_basis.m_el[0].mVec128.m128_f32[0])
                          + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[1] * v22))
                  + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[2] * v23))
          + transB->m_origin.mVec128.m128_f32[0];
      v24 = (float)(v21 * transB->m_basis.m_el[1].mVec128.m128_f32[0])
          + (float)(v22 * transB->m_basis.m_el[1].mVec128.m128_f32[1]);
      v25 = (float)((float)((float)(v21 * transB->m_basis.m_el[2].mVec128.m128_f32[0])
                          + (float)(v22 * transB->m_basis.m_el[2].mVec128.m128_f32[1]))
                  + (float)(v23 * transB->m_basis.m_el[2].mVec128.m128_f32[2]))
          + transB->m_origin.mVec128.m128_f32[2];
      v43 = (float)(v24 + (float)(v23 * transB->m_basis.m_el[1].mVec128.m128_f32[2]))
          + transB->m_origin.mVec128.m128_f32[1];
      v44 = v25;
      if ( v46.m_size == v46.m_capacity )
      {
        v32 = v46.m_size ? 2 * v46.m_size : 1;
        if ( v46.m_capacity < v32 )
        {
          if ( v32 )
          {
            v26 = (btVector3 *)btAlignedAllocInternal(16 * v32);
            v8 = hullB;
            v17 = v37;
            v34 = v26;
          }
          else
          {
            v34 = 0;
          }
          if ( v46.m_size > 0 )
          {
            v27 = v34;
            v28 = (char *)((char *)v46.m_data - (char *)v34);
            v39 = (char *)((char *)v46.m_data - (char *)v34);
            v36 = v46.m_size;
            while ( 1 )
            {
              if ( v27 )
              {
                v29 = &v28[(_DWORD)v27];
                v27->mVec128.m128_i32[0] = *(_DWORD *)v29;
                v29 += 4;
                v27->mVec128.m128_i32[1] = *(_DWORD *)v29;
                v29 += 4;
                v27->mVec128.m128_i32[2] = *(_DWORD *)v29;
                v27->mVec128.m128_i32[3] = *((_DWORD *)v29 + 1);
              }
              ++v27;
              if ( !--v36 )
                break;
              v28 = v39;
            }
          }
          if ( v46.m_data )
          {
            btAlignedFreeInternal(v46.m_data);
            v8 = hullB;
            v17 = v37;
          }
          v46.m_data = v34;
          v46.m_ownsMemory = 1;
          v46.m_capacity = v32;
        }
      }
      v30 = &v46.m_data[v46.m_size];
      if ( v30 )
      {
        v30->mVec128.m128_f32[0] = v42;
        v31 = &v30->mVec128.m128_i32[1];
        *(float *)v31++ = v43;
        *(float *)v31 = v44;
        v31[1] = v45;
      }
      ++v46.m_size;
      v18 = ++v38;
    }
    while ( v38 < v40 );
  }
  if ( v35 >= 0 )
    btPolyhedralContactClipping::clipFaceAgainstHull(&v46, &v41, hullA, transA, minDist, maxDist, resultOut);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v17, (int)&v46);
}
