void __usercall GrahamScanConvexHull2D(
        btAlignedObjectArray<GrahamVector2> *hull@<edi>,
        btAlignedObjectArray<GrahamVector2> *originalPoints)
{
  btAlignedObjectArray<GrahamVector2> *v2; // esi
  int m_size; // eax
  int m_capacity; // ecx
  int v5; // eax
  __m128 *p_mVec128; // edx
  int v7; // ebx
  GrahamVector2 *v8; // esi
  int v9; // edx
  GrahamVector2 *v10; // ecx
  int v11; // ebx
  GrahamVector2 *m_data; // eax
  unsigned __int64 v13; // xmm0_8
  __m128 *v14; // eax
  GrahamVector2 *v15; // eax
  GrahamVector2 *v16; // eax
  int v17; // ebx
  int v18; // ecx
  btAlignedObjectArray<GrahamVector2> *v19; // edx
  float *m128_f32; // eax
  float v21; // xmm0_4
  int v22; // ebx
  int v23; // esi
  GrahamVector2 *v24; // eax
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  btAlignedObjectArray<GrahamVector2> *v28; // ebx
  GrahamVector2 *v29; // eax
  int v30; // edx
  int v31; // ecx
  int v32; // eax
  unsigned __int64 *v33; // esi
  int v34; // eax
  GrahamVector2 *v35; // ebx
  int v36; // edx
  GrahamVector2 *v37; // ecx
  int v38; // esi
  GrahamVector2 *v39; // eax
  unsigned __int64 v40; // xmm0_8
  __m128 *v41; // eax
  GrahamVector2 *v42; // eax
  GrahamVector2 *v43; // eax
  int v44; // edx
  GrahamVector2 *v45; // ecx
  int v46; // eax
  float v47; // xmm5_4
  float v48; // xmm2_4
  float v49; // xmm3_4
  float *v50; // ecx
  GrahamVector2 *v51; // ebx
  int v52; // eax
  int v53; // esi
  GrahamVector2 *v54; // ecx
  int v55; // edx
  int v56; // esi
  GrahamVector2 *v57; // eax
  unsigned __int64 v58; // xmm0_8
  __m128 *v59; // eax
  GrahamVector2 *v60; // eax
  GrahamVector2 *v61; // eax
  btAngleCompareFunc v62; // [esp+1Ch] [ebp-48h]
  int v63; // [esp+44h] [ebp-20h]
  int v64; // [esp+44h] [ebp-20h]
  GrahamVector2 *v65; // [esp+44h] [ebp-20h]
  int v66; // [esp+48h] [ebp-1Ch]
  int v67; // [esp+48h] [ebp-1Ch]
  int v68; // [esp+48h] [ebp-1Ch]
  int v69; // [esp+48h] [ebp-1Ch]
  unsigned __int64 *v70; // [esp+4Ch] [ebp-18h]
  int v71; // [esp+4Ch] [ebp-18h]
  __m128 *v72; // [esp+50h] [ebp-14h]
  float v73; // [esp+50h] [ebp-14h]
  int v74; // [esp+50h] [ebp-14h]

  v2 = originalPoints;
  m_size = originalPoints->m_size;
  if ( m_size <= 1 )
  {
    v63 = 0;
    if ( m_size > 0 )
    {
      do
      {
        m_capacity = hull->m_capacity;
        v5 = hull->m_size;
        p_mVec128 = &v2->m_data->mVec128;
        v72 = p_mVec128;
        if ( v5 == m_capacity )
        {
          v7 = 2 * v5;
          if ( !v5 )
            v7 = 1;
          v66 = v7;
          if ( m_capacity < v7 )
          {
            if ( v7 )
            {
              ++gNumAlignedAllocs;
              v8 = (GrahamVector2 *)sAlignedAllocFunc(32 * v7, 16);
            }
            else
            {
              v8 = 0;
            }
            if ( hull->m_size > 0 )
            {
              v9 = 0;
              v10 = v8;
              v11 = hull->m_size;
              do
              {
                if ( v10 )
                {
                  m_data = hull->m_data;
                  v13 = m_data[v9].mVec128.m128_u64[0];
                  v14 = &m_data[v9].mVec128;
                  v10->mVec128.m128_u64[0] = v13;
                  v10->mVec128.m128_u64[1] = v14->m128_u64[1];
                  *(_QWORD *)&v10->m_angle = v14[1].m128_u64[0];
                  *(_QWORD *)(&v10->m_orgIndex + 1) = v14[1].m128_u64[1];
                }
                ++v9;
                ++v10;
                --v11;
              }
              while ( v11 );
              v7 = v66;
            }
            v15 = hull->m_data;
            if ( v15 )
            {
              if ( hull->m_ownsMemory )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(v15);
              }
              hull->m_data = 0;
            }
            p_mVec128 = v72;
            hull->m_data = v8;
            v2 = originalPoints;
            hull->m_ownsMemory = 1;
            hull->m_capacity = v7;
          }
        }
        v16 = &hull->m_data[hull->m_size];
        if ( v16 )
        {
          v16->mVec128.m128_u64[0] = p_mVec128->m128_u64[0];
          v16->mVec128.m128_u64[1] = p_mVec128->m128_u64[1];
          *(_QWORD *)&v16->m_angle = p_mVec128[1].m128_u64[0];
          *(_QWORD *)(&v16->m_orgIndex + 1) = p_mVec128[1].m128_u64[1];
        }
        ++hull->m_size;
        ++v63;
      }
      while ( v63 < v2->m_size );
    }
    return;
  }
  v17 = 0;
  v18 = 0;
  v67 = 0;
  v19 = originalPoints;
  do
  {
    m128_f32 = v19->m_data->mVec128.m128_f32;
    v21 = *(float *)((char *)m128_f32 + v18);
    if ( *m128_f32 > v21 || v21 <= *m128_f32 && m128_f32[1] > *(float *)((char *)m128_f32 + v18 + 4) )
    {
      btAlignedObjectArray<GrahamVector2>::swap(originalPoints, 0, v17);
      v18 = v67;
      v19 = originalPoints;
    }
    ++v17;
    v18 += 32;
    v67 = v18;
  }
  while ( v17 < v19->m_size );
  v22 = 0;
  if ( originalPoints->m_size > 0 )
  {
    v23 = 0;
    do
    {
      v24 = originalPoints->m_data;
      v25 = v24[v23].mVec128.m128_f32[1] - v24->mVec128.m128_f32[1];
      v26 = v24[v23].mVec128.m128_f32[2] - v24->mVec128.m128_f32[2];
      v27 = v24[v23].mVec128.m128_f32[0] - v24->mVec128.m128_f32[0];
      v73 = ((float)((float)(v27 * 0.0) - v26) + (float)((float)(v26 * 0.0) - (float)(v25 * 0.0))) * 0.0
          + (float)(v25 - (float)(v27 * 0.0));
      ++v22;
      v24[v23++].m_angle = v73 / sqrtf((float)((float)(v25 * v25) + (float)(v26 * v26)) + (float)(v27 * v27));
    }
    while ( v22 < originalPoints->m_size );
  }
  v28 = originalPoints;
  v29 = originalPoints->m_data;
  v62.m_anchor.mVec128.m128_u64[1] = v29->mVec128.m128_u64[0];
  v62.m_anchor.mVec128.m128_i32[1] = originalPoints->m_size - 1;
  v62.m_anchor.mVec128.m128_i32[0] = 1;
  btAlignedObjectArray<GrahamVector2>::quickSortInternal<btAngleCompareFunc>(
    originalPoints,
    (btAngleCompareFunc)v62.m_anchor.mVec128,
    v29->mVec128.m128_i32[2],
    v29->mVec128.m128_i32[3]);
  v30 = 0;
  v68 = 0;
  v74 = 2;
  do
  {
    v31 = hull->m_capacity;
    v32 = hull->m_size;
    v33 = (unsigned __int64 *)((char *)v28->m_data + v30);
    v70 = v33;
    if ( v32 == v31 )
    {
      v34 = v32 ? 2 * v32 : 1;
      v64 = v34;
      if ( v31 < v34 )
      {
        if ( v34 )
        {
          ++gNumAlignedAllocs;
          v35 = (GrahamVector2 *)sAlignedAllocFunc(32 * v34, 16);
        }
        else
        {
          v35 = 0;
        }
        if ( hull->m_size > 0 )
        {
          v36 = 0;
          v37 = v35;
          v38 = hull->m_size;
          do
          {
            if ( v37 )
            {
              v39 = hull->m_data;
              v40 = v39[v36].mVec128.m128_u64[0];
              v41 = &v39[v36].mVec128;
              v37->mVec128.m128_u64[0] = v40;
              v37->mVec128.m128_u64[1] = v41->m128_u64[1];
              *(_QWORD *)&v37->m_angle = v41[1].m128_u64[0];
              *(_QWORD *)(&v37->m_orgIndex + 1) = v41[1].m128_u64[1];
            }
            ++v36;
            ++v37;
            --v38;
          }
          while ( v38 );
          v33 = v70;
        }
        v42 = hull->m_data;
        if ( v42 )
        {
          if ( hull->m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v42);
          }
          hull->m_data = 0;
        }
        v30 = v68;
        hull->m_data = v35;
        v28 = originalPoints;
        hull->m_ownsMemory = 1;
        hull->m_capacity = v64;
      }
    }
    v43 = &hull->m_data[hull->m_size];
    if ( v43 )
    {
      v43->mVec128.m128_u64[0] = *v33;
      v43->mVec128.m128_u64[1] = v33[1];
      *(_QWORD *)&v43->m_angle = v33[2];
      *(_QWORD *)(&v43->m_orgIndex + 1) = v33[3];
    }
    ++hull->m_size;
    v30 += 32;
    v68 = v30;
  }
  while ( v30 < 64 );
  if ( v28->m_size != 2 )
  {
    v69 = 2;
    while ( 1 )
    {
      while ( 1 )
      {
        v44 = hull->m_size;
        if ( v44 > 1 )
          break;
LABEL_81:
        ++v69;
        if ( ++v74 == v28->m_size )
          return;
      }
      v45 = hull->m_data;
      v46 = v44 - 2;
      v47 = v45[v46].mVec128.m128_f32[1];
      v48 = v45[v46].mVec128.m128_f32[2];
      v49 = v45[v46].mVec128.m128_f32[0];
      v50 = v45[v44 - 1].mVec128.m128_f32;
      v51 = &originalPoints->m_data[v69];
      if ( (float)((float)((float)((float)((float)((float)(v48 - v50[2]) * (float)(v49 - v51->mVec128.m128_f32[0]))
                                         - (float)((float)(v48 - v51->mVec128.m128_f32[2]) * (float)(v49 - *v50)))
                                 + (float)((float)((float)(v47 - v50[1]) * (float)(v48 - v51->mVec128.m128_f32[2]))
                                         - (float)((float)(v48 - v50[2]) * (float)(v47 - v51->mVec128.m128_f32[1]))))
                         * 0.0)
                 + (float)((float)((float)(v47 - v51->mVec128.m128_f32[1]) * (float)(v49 - *v50))
                         - (float)((float)(v47 - v50[1]) * (float)(v49 - v51->mVec128.m128_f32[0])))) > 0.0 )
      {
        v52 = hull->m_capacity;
        if ( v44 == v52 )
        {
          v53 = 2 * v44;
          v71 = 2 * v44;
          if ( v52 < 2 * v44 )
          {
            if ( v53 )
            {
              ++gNumAlignedAllocs;
              v65 = (GrahamVector2 *)sAlignedAllocFunc(v44 << 6, 16);
            }
            else
            {
              v65 = 0;
            }
            if ( hull->m_size > 0 )
            {
              v54 = v65;
              v55 = 0;
              v56 = hull->m_size;
              do
              {
                if ( v54 )
                {
                  v57 = hull->m_data;
                  v58 = v57[v55].mVec128.m128_u64[0];
                  v59 = &v57[v55].mVec128;
                  v54->mVec128.m128_u64[0] = v58;
                  v54->mVec128.m128_u64[1] = v59->m128_u64[1];
                  *(_QWORD *)&v54->m_angle = v59[1].m128_u64[0];
                  *(_QWORD *)(&v54->m_orgIndex + 1) = v59[1].m128_u64[1];
                }
                ++v55;
                ++v54;
                --v56;
              }
              while ( v56 );
              v53 = v71;
            }
            v60 = hull->m_data;
            if ( v60 )
            {
              if ( hull->m_ownsMemory )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(v60);
              }
              hull->m_data = 0;
            }
            hull->m_ownsMemory = 1;
            hull->m_data = v65;
            hull->m_capacity = v53;
          }
        }
        v61 = &hull->m_data[hull->m_size];
        if ( v61 )
        {
          v61->mVec128.m128_u64[0] = v51->mVec128.m128_u64[0];
          v61->mVec128.m128_u64[1] = v51->mVec128.m128_u64[1];
          *(_QWORD *)&v61->m_angle = *(_QWORD *)&v51->m_angle;
          *(_QWORD *)(&v61->m_orgIndex + 1) = *(_QWORD *)(&v51->m_orgIndex + 1);
        }
        ++hull->m_size;
        v28 = originalPoints;
        goto LABEL_81;
      }
      v28 = originalPoints;
      hull->m_size = v44 - 1;
    }
  }
}
