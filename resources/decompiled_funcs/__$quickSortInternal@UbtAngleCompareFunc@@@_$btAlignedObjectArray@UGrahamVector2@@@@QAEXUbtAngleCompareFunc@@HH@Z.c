void __thiscall btAlignedObjectArray<GrahamVector2>::quickSortInternal<btAngleCompareFunc>(
        btAlignedObjectArray<GrahamVector2> *this,
        btAngleCompareFunc CompareFunc,
        int lo,
        int hi)
{
  int v4; // edi
  int v5; // esi
  GrahamVector2 *v7; // eax
  GrahamVector2 *m_data; // edx
  GrahamVector2 *i; // ecx
  float m_angle; // xmm0_4
  GrahamVector2 *j; // ecx
  float v12; // xmm0_4
  unsigned __int64 v13; // xmm0_8
  unsigned __int64 v14; // xmm1_8
  __int64 v15; // xmm2_8
  __int64 v16; // xmm3_8
  __m128 *p_mVec128; // eax
  GrahamVector2 *v18; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  btAngleCompareFunc x_8; // [esp+8h] [ebp-48h]
  btAngleCompareFunc x_8a; // [esp+8h] [ebp-48h]
  unsigned __int64 v25; // [esp+30h] [ebp-20h]
  unsigned __int64 v26; // [esp+38h] [ebp-18h]
  __int64 v27; // [esp+40h] [ebp-10h]

  v4 = CompareFunc.m_anchor.mVec128.m128_i32[1];
  v5 = CompareFunc.m_anchor.mVec128.m128_i32[0];
  v7 = &this->m_data[(CompareFunc.m_anchor.mVec128.m128_i32[0] + CompareFunc.m_anchor.mVec128.m128_i32[1]) / 2];
  v25 = v7->mVec128.m128_u64[0];
  v26 = v7->mVec128.m128_u64[1];
  v27 = *(_QWORD *)&v7->m_angle;
  do
  {
    m_data = this->m_data;
    for ( i = &m_data[v5]; ; ++i )
    {
      while ( 1 )
      {
        m_angle = i->m_angle;
        if ( m_angle == *(float *)&v27 )
          break;
        if ( *(float *)&v27 <= m_angle )
          goto LABEL_5;
LABEL_19:
        ++v5;
        ++i;
      }
      v19 = (float)((float)((float)(i->mVec128.m128_f32[2] - *(float *)&lo)
                          * (float)(i->mVec128.m128_f32[2] - *(float *)&lo))
                  + (float)((float)(i->mVec128.m128_f32[1] - CompareFunc.m_anchor.mVec128.m128_f32[3])
                          * (float)(i->mVec128.m128_f32[1] - CompareFunc.m_anchor.mVec128.m128_f32[3])))
          + (float)((float)(i->mVec128.m128_f32[0] - CompareFunc.m_anchor.mVec128.m128_f32[2])
                  * (float)(i->mVec128.m128_f32[0] - CompareFunc.m_anchor.mVec128.m128_f32[2]));
      v20 = (float)((float)((float)(*(float *)&v26 - *(float *)&lo) * (float)(*(float *)&v26 - *(float *)&lo))
                  + (float)((float)(*((float *)&v25 + 1) - CompareFunc.m_anchor.mVec128.m128_f32[3])
                          * (float)(*((float *)&v25 + 1) - CompareFunc.m_anchor.mVec128.m128_f32[3])))
          + (float)((float)(*(float *)&v25 - CompareFunc.m_anchor.mVec128.m128_f32[2])
                  * (float)(*(float *)&v25 - CompareFunc.m_anchor.mVec128.m128_f32[2]));
      if ( v19 == v20 )
        break;
      if ( v20 <= v19 )
        goto LABEL_5;
      ++v5;
    }
    if ( i->m_orgIndex < SHIDWORD(v27) )
      goto LABEL_19;
LABEL_5:
    for ( j = &m_data[v4]; ; --j )
    {
      while ( 1 )
      {
        v12 = j->m_angle;
        if ( *(float *)&v27 == v12 )
          break;
        if ( v12 <= *(float *)&v27 )
          goto LABEL_8;
LABEL_24:
        --v4;
        --j;
      }
      v21 = (float)((float)((float)(*(float *)&v26 - *(float *)&lo) * (float)(*(float *)&v26 - *(float *)&lo))
                  + (float)((float)(*((float *)&v25 + 1) - CompareFunc.m_anchor.mVec128.m128_f32[3])
                          * (float)(*((float *)&v25 + 1) - CompareFunc.m_anchor.mVec128.m128_f32[3])))
          + (float)((float)(*(float *)&v25 - CompareFunc.m_anchor.mVec128.m128_f32[2])
                  * (float)(*(float *)&v25 - CompareFunc.m_anchor.mVec128.m128_f32[2]));
      v22 = (float)((float)((float)(j->mVec128.m128_f32[2] - *(float *)&lo)
                          * (float)(j->mVec128.m128_f32[2] - *(float *)&lo))
                  + (float)((float)(j->mVec128.m128_f32[1] - CompareFunc.m_anchor.mVec128.m128_f32[3])
                          * (float)(j->mVec128.m128_f32[1] - CompareFunc.m_anchor.mVec128.m128_f32[3])))
          + (float)((float)(j->mVec128.m128_f32[0] - CompareFunc.m_anchor.mVec128.m128_f32[2])
                  * (float)(j->mVec128.m128_f32[0] - CompareFunc.m_anchor.mVec128.m128_f32[2]));
      if ( v21 == v22 )
        break;
      if ( v22 <= v21 )
        goto LABEL_8;
      --v4;
    }
    if ( SHIDWORD(v27) < j->m_orgIndex )
      goto LABEL_24;
LABEL_8:
    if ( v5 > v4 )
      break;
    v13 = m_data[v5].mVec128.m128_u64[0];
    v14 = m_data[v5].mVec128.m128_u64[1];
    v15 = *(_QWORD *)&m_data[v5].m_angle;
    v16 = *(_QWORD *)(&m_data[v5].m_orgIndex + 1);
    p_mVec128 = &m_data[v5].mVec128;
    p_mVec128->m128_u64[0] = m_data[v4].mVec128.m128_u64[0];
    p_mVec128->m128_u64[1] = m_data[v4].mVec128.m128_u64[1];
    p_mVec128[1].m128_u64[0] = *(_QWORD *)&m_data[v4].m_angle;
    p_mVec128[1].m128_u64[1] = *(_QWORD *)(&m_data[v4].m_orgIndex + 1);
    v18 = &this->m_data[v4];
    v18->mVec128.m128_u64[0] = v13;
    v18->mVec128.m128_u64[1] = v14;
    ++v5;
    --v4;
    *(_QWORD *)&v18->m_angle = v15;
    *(_QWORD *)(&v18->m_orgIndex + 1) = v16;
  }
  while ( v5 <= v4 );
  if ( CompareFunc.m_anchor.mVec128.m128_i32[0] < v4 )
  {
    x_8.m_anchor.mVec128.m128_u64[1] = CompareFunc.m_anchor.mVec128.m128_u64[1];
    x_8.m_anchor.mVec128.m128_u64[0] = __PAIR64__(v4, CompareFunc.m_anchor.mVec128.m128_u32[0]);
    btAlignedObjectArray<GrahamVector2>::quickSortInternal<btAngleCompareFunc>(
      this,
      (btAngleCompareFunc)x_8.m_anchor.mVec128,
      lo,
      hi);
  }
  if ( v5 < CompareFunc.m_anchor.mVec128.m128_i32[1] )
  {
    x_8a.m_anchor.mVec128.m128_u64[1] = CompareFunc.m_anchor.mVec128.m128_u64[1];
    x_8a.m_anchor.mVec128.m128_u64[0] = __PAIR64__(CompareFunc.m_anchor.mVec128.m128_u32[1], v5);
    btAlignedObjectArray<GrahamVector2>::quickSortInternal<btAngleCompareFunc>(
      this,
      (btAngleCompareFunc)x_8a.m_anchor.mVec128,
      lo,
      hi);
  }
}
