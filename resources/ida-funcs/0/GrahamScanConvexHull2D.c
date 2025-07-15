void __cdecl GrahamScanConvexHull2D(
        btAlignedObjectArray<GrahamVector2> *originalPoints,
        btAlignedObjectArray<GrahamVector2> *hull)
{
  btAlignedObjectArray<GrahamVector2> *v2; // esi
  int m_size; // eax
  int m_capacity; // ecx
  int v5; // eax
  int v6; // edi
  int v7; // eax
  GrahamVector2 *v8; // edx
  GrahamVector2 *v9; // edi
  int v10; // edi
  GrahamVector2 *v11; // eax
  float v12; // xmm0_4
  int v13; // ecx
  int i; // edx
  GrahamVector2 *v15; // eax
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm7_4
  GrahamVector2 *v19; // esi
  int v20; // ecx
  int v21; // eax
  int v22; // esi
  int v23; // eax
  GrahamVector2 *v24; // edx
  GrahamVector2 *v25; // edi
  int v26; // esi
  GrahamVector2 *v27; // ecx
  float *m128_f32; // eax
  float *v29; // ecx
  GrahamVector2 *v30; // edx
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm4_4
  int v34; // eax
  int v35; // esi
  int v36; // eax
  GrahamVector2 *v37; // edx
  GrahamVector2 *v38; // edi
  btAngleCompareFunc v39; // [esp-18h] [ebp-48h]
  int v40; // [esp+18h] [ebp-18h]
  int v41; // [esp+18h] [ebp-18h]
  int v42; // [esp+18h] [ebp-18h]
  GrahamVector2 *v43; // [esp+1Ch] [ebp-14h]
  GrahamVector2 *v44; // [esp+1Ch] [ebp-14h]
  GrahamVector2 *v45; // [esp+1Ch] [ebp-14h]
  int v46; // [esp+20h] [ebp-10h]
  int v47; // [esp+20h] [ebp-10h]
  int v48; // [esp+20h] [ebp-10h]
  int v49; // [esp+20h] [ebp-10h]
  int v50; // [esp+24h] [ebp-Ch]
  int v51; // [esp+24h] [ebp-Ch]
  GrahamVector2 *m_data; // [esp+28h] [ebp-8h]
  int v53; // [esp+28h] [ebp-8h]
  int v54; // [esp+28h] [ebp-8h]
  GrahamVector2 *v55; // [esp+2Ch] [ebp-4h]
  GrahamVector2 *v56; // [esp+2Ch] [ebp-4h]

  v2 = originalPoints;
  m_size = originalPoints->m_size;
  if ( m_size <= 1 )
  {
    v46 = 0;
    if ( m_size > 0 )
    {
      do
      {
        m_capacity = hull->m_capacity;
        m_data = v2->m_data;
        v5 = hull->m_size;
        if ( v5 == m_capacity )
        {
          v6 = v5 ? 2 * v5 : 1;
          v50 = v6;
          if ( m_capacity < v6 )
          {
            if ( v6 )
              v43 = (GrahamVector2 *)btAlignedAllocInternal(32 * v6);
            else
              v43 = 0;
            v7 = hull->m_size;
            if ( v7 > 0 )
            {
              v40 = 0;
              v8 = v43;
              do
              {
                if ( v8 )
                {
                  qmemcpy(v8, &hull->m_data[v40], sizeof(GrahamVector2));
                  v2 = originalPoints;
                  v6 = v50;
                }
                ++v40;
                ++v8;
                --v7;
              }
              while ( v7 );
            }
            if ( hull->m_data )
            {
              if ( hull->m_ownsMemory )
                btAlignedFreeInternal(hull->m_data);
              hull->m_data = 0;
            }
            hull->m_ownsMemory = 1;
            hull->m_data = v43;
            hull->m_capacity = v6;
          }
        }
        v9 = &hull->m_data[hull->m_size];
        if ( v9 )
        {
          qmemcpy(v9, m_data, sizeof(GrahamVector2));
          v2 = originalPoints;
        }
        ++hull->m_size;
        ++v46;
      }
      while ( v46 < v2->m_size );
    }
    return;
  }
  v10 = 0;
  v47 = 0;
  do
  {
    v11 = originalPoints->m_data;
    v12 = v11[v47].mVec128.m128_f32[0];
    if ( v11->mVec128.m128_f32[0] > v12
      || v12 <= v11->mVec128.m128_f32[0] && v11->mVec128.m128_f32[1] > v11[v47].mVec128.m128_f32[1] )
    {
      btAlignedObjectArray<GrahamVector2>::swap(0, originalPoints, v10);
    }
    ++v47;
    ++v10;
  }
  while ( v10 < originalPoints->m_size );
  v13 = 0;
  for ( i = 0; i < originalPoints->m_size; ++v13 )
  {
    v15 = originalPoints->m_data;
    v16 = v15[v13].mVec128.m128_f32[2] - v15->mVec128.m128_f32[2];
    v17 = v15[v13].mVec128.m128_f32[0] - v15->mVec128.m128_f32[0];
    v18 = v15[v13].mVec128.m128_f32[1] - v15->mVec128.m128_f32[1];
    v15[v13].m_angle = (float)((float)((float)((float)((float)(v17 * 0.0) - v16)
                                             + (float)((float)(v16 * 0.0) - (float)(v18 * 0.0)))
                                     * 0.0)
                             + (float)(v18 - (float)(v17 * 0.0)))
                     / fsqrt((float)((float)(v18 * v18) + (float)(v16 * v16)) + (float)(v17 * v17));
    ++i;
  }
  v19 = originalPoints->m_data;
  v39.m_anchor.mVec128.m128_i32[2] = v19->mVec128.m128_i32[0];
  v19 = (GrahamVector2 *)((char *)v19 + 4);
  v39.m_anchor.mVec128.m128_i32[3] = v19->mVec128.m128_i32[0];
  v39.m_anchor.mVec128.m128_i32[1] = originalPoints->m_size - 1;
  v39.m_anchor.mVec128.m128_i32[0] = 1;
  btAlignedObjectArray<GrahamVector2>::quickSortInternal<btAngleCompareFunc>(
    originalPoints,
    (btAngleCompareFunc)v39.m_anchor.mVec128,
    v19->mVec128.m128_i32[1],
    v19->mVec128.m128_i32[2]);
  v41 = 0;
  v51 = 2;
  do
  {
    v20 = hull->m_capacity;
    v55 = &originalPoints->m_data[v41];
    v21 = hull->m_size;
    if ( v21 == v20 )
    {
      v22 = v21 ? 2 * v21 : 1;
      v53 = v22;
      if ( v20 < v22 )
      {
        if ( v22 )
          v44 = (GrahamVector2 *)btAlignedAllocInternal(32 * v22);
        else
          v44 = 0;
        v23 = hull->m_size;
        if ( v23 > 0 )
        {
          v48 = 0;
          v24 = v44;
          do
          {
            if ( v24 )
            {
              qmemcpy(v24, &hull->m_data[v48], sizeof(GrahamVector2));
              v22 = v53;
            }
            ++v48;
            ++v24;
            --v23;
          }
          while ( v23 );
        }
        if ( hull->m_data )
        {
          if ( hull->m_ownsMemory )
            btAlignedFreeInternal(hull->m_data);
          hull->m_data = 0;
        }
        hull->m_ownsMemory = 1;
        hull->m_data = v44;
        hull->m_capacity = v22;
      }
    }
    v25 = &hull->m_data[hull->m_size];
    if ( v25 )
      qmemcpy(v25, v55, sizeof(GrahamVector2));
    ++v41;
    ++hull->m_size;
  }
  while ( v41 < 2 );
  if ( originalPoints->m_size != 2 )
  {
    v42 = 2;
    while ( 1 )
    {
      while ( 1 )
      {
        v26 = hull->m_size;
        if ( v26 > 1 )
          break;
LABEL_78:
        ++v51;
        ++v42;
        if ( v51 == originalPoints->m_size )
          return;
      }
      v27 = hull->m_data;
      m128_f32 = v27[v26 - 2].mVec128.m128_f32;
      v29 = v27[v26 - 1].mVec128.m128_f32;
      v30 = &originalPoints->m_data[v42];
      v31 = m128_f32[1];
      v32 = m128_f32[2] - v30->mVec128.m128_f32[2];
      v33 = m128_f32[2] - v29[2];
      v56 = v30;
      if ( (float)((float)((float)((float)((float)(v33 * (float)(*m128_f32 - v30->mVec128.m128_f32[0]))
                                         - (float)(v32 * (float)(*m128_f32 - *v29)))
                                 + (float)((float)((float)(v31 - v29[1]) * v32)
                                         - (float)(v33 * (float)(v31 - v30->mVec128.m128_f32[1]))))
                         * 0.0)
                 + (float)((float)((float)(v31 - v30->mVec128.m128_f32[1]) * (float)(*m128_f32 - *v29))
                         - (float)((float)(v31 - v29[1]) * (float)(*m128_f32 - v30->mVec128.m128_f32[0])))) > 0.0 )
      {
        v34 = hull->m_capacity;
        if ( v26 == v34 )
        {
          v35 = 2 * v26;
          v54 = v35;
          if ( v34 < v35 )
          {
            if ( v35 )
              v45 = (GrahamVector2 *)btAlignedAllocInternal(32 * v35);
            else
              v45 = 0;
            v36 = hull->m_size;
            if ( v36 > 0 )
            {
              v49 = 0;
              v37 = v45;
              do
              {
                if ( v37 )
                {
                  qmemcpy(v37, &hull->m_data[v49], sizeof(GrahamVector2));
                  v35 = v54;
                }
                ++v49;
                ++v37;
                --v36;
              }
              while ( v36 );
            }
            if ( hull->m_data )
            {
              if ( hull->m_ownsMemory )
                btAlignedFreeInternal(hull->m_data);
              hull->m_data = 0;
            }
            hull->m_ownsMemory = 1;
            hull->m_data = v45;
            hull->m_capacity = v35;
          }
        }
        v38 = &hull->m_data[hull->m_size];
        if ( v38 )
          qmemcpy(v38, v56, sizeof(GrahamVector2));
        ++hull->m_size;
        goto LABEL_78;
      }
      hull->m_size = v26 - 1;
    }
  }
}
