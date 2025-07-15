void __thiscall btAlignedObjectArray<btConvexHullInternal::Point32>::quickSortInternal<bool (__cdecl *)(btConvexHullInternal::Point32 const &,btConvexHullInternal::Point32 const &)>(
        btAlignedObjectArray<btConvexHullInternal::Point32> *this,
        bool (__cdecl *CompareFunc)(const btConvexHullInternal::Point32 *, const btConvexHullInternal::Point32 *),
        int lo,
        int hi)
{
  int v4; // ebx
  int v6; // edi
  int i; // eax
  int j; // eax
  btConvexHullInternal::Point32 *m_data; // edx
  __int64 v11; // xmm0_8
  __int64 v12; // xmm1_8
  btConvexHullInternal::Point32 *v13; // ecx
  btConvexHullInternal::Point32 *v14; // ecx
  btConvexHullInternal::Point32 x; // [esp+10h] [ebp-10h] BYREF
  bool (__cdecl *CompareFunca)(const btConvexHullInternal::Point32 *, const btConvexHullInternal::Point32 *); // [esp+24h] [ebp+4h]
  bool (__cdecl *CompareFuncb)(const btConvexHullInternal::Point32 *, const btConvexHullInternal::Point32 *); // [esp+24h] [ebp+4h]

  v4 = lo;
  v6 = hi;
  x = this->m_data[(lo + hi) / 2];
  do
  {
    if ( CompareFunc(&this->m_data[v4], &x) )
    {
      for ( i = 16 * v4; ; i = (int)CompareFunca )
      {
        ++v4;
        CompareFunca = (bool (__cdecl *)(const btConvexHullInternal::Point32 *, const btConvexHullInternal::Point32 *))(i + 16);
        if ( !CompareFunc((const btConvexHullInternal::Point32 *)((char *)this->m_data + i + 16), &x) )
          break;
      }
    }
    if ( CompareFunc(&x, &this->m_data[v6]) )
    {
      for ( j = 16 * v6; ; j = (int)CompareFuncb )
      {
        --v6;
        CompareFuncb = (bool (__cdecl *)(const btConvexHullInternal::Point32 *, const btConvexHullInternal::Point32 *))(j - 16);
        if ( !CompareFunc(&x, (const btConvexHullInternal::Point32 *)((char *)this->m_data + j - 16)) )
          break;
      }
    }
    if ( v4 > v6 )
      break;
    m_data = this->m_data;
    v11 = *(_QWORD *)&m_data[v4].x;
    v12 = *(_QWORD *)&m_data[v4].z;
    v13 = &m_data[v4];
    *(_QWORD *)&v13->x = *(_QWORD *)&m_data[v6].x;
    *(_QWORD *)&v13->z = *(_QWORD *)&m_data[v6].z;
    v14 = &this->m_data[v6];
    ++v4;
    --v6;
    *(_QWORD *)&v14->x = v11;
    *(_QWORD *)&v14->z = v12;
  }
  while ( v4 <= v6 );
  if ( lo < v6 )
    btAlignedObjectArray<btConvexHullInternal::Point32>::quickSortInternal<bool (__cdecl *)(btConvexHullInternal::Point32 const &,btConvexHullInternal::Point32 const &)>(
      this,
      CompareFunc,
      lo,
      v6);
  if ( v4 < hi )
    btAlignedObjectArray<btConvexHullInternal::Point32>::quickSortInternal<bool (__cdecl *)(btConvexHullInternal::Point32 const &,btConvexHullInternal::Point32 const &)>(
      this,
      CompareFunc,
      v4,
      hi);
}


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


void __thiscall btAlignedObjectArray<btBroadphasePair>::quickSortInternal<btBroadphasePairSortPredicate>(
        btAlignedObjectArray<btBroadphasePair> *this,
        btBroadphasePairSortPredicate CompareFunc,
        int lo,
        int hi)
{
  int v4; // ebx
  int v5; // edi
  btAlignedObjectArray<btBroadphasePair> *v6; // esi
  btBroadphasePair *v7; // eax
  btBroadphaseProxy *m_pProxy1; // edx
  btCollisionAlgorithm *m_algorithm; // ecx
  int m_internalTmpValue; // edx
  btBroadphasePairSortPredicate *v11; // ecx
  const btBroadphasePair *v12; // esi
  btBroadphasePairSortPredicate *v13; // ecx
  const btBroadphasePair *v14; // esi
  const btBroadphasePair *v16; // [esp+2Ch] [ebp-14h]
  const btBroadphasePair *v17; // [esp+2Ch] [ebp-14h]
  btBroadphasePair b; // [esp+30h] [ebp-10h] BYREF

  v4 = hi;
  v5 = lo;
  v6 = this;
  v7 = &this->m_data[(lo + hi) / 2];
  m_pProxy1 = v7->m_pProxy1;
  b.m_pProxy0 = v7->m_pProxy0;
  m_algorithm = v7->m_algorithm;
  b.m_pProxy1 = m_pProxy1;
  m_internalTmpValue = v7->m_internalTmpValue;
  b.m_algorithm = m_algorithm;
  b.m_internalTmpValue = m_internalTmpValue;
  do
  {
    v16 = &v6->m_data[v5];
    if ( btBroadphasePairSortPredicate::operator()((btBroadphasePairSortPredicate *)(16 * v5), v16, &b) )
    {
      v12 = v16;
      do
      {
        ++v12;
        ++v5;
      }
      while ( btBroadphasePairSortPredicate::operator()(v11, v12, &b) );
      v6 = this;
    }
    v17 = &v6->m_data[v4];
    if ( btBroadphasePairSortPredicate::operator()((btBroadphasePairSortPredicate *)(16 * v4), &b, v17) )
    {
      v14 = v17;
      do
      {
        --v14;
        --v4;
      }
      while ( btBroadphasePairSortPredicate::operator()(v13, &b, v14) );
      v6 = this;
    }
    if ( v5 > v4 )
      break;
    btAlignedObjectArray<btBroadphasePair>::swap(v6, v5, v4);
    v6 = this;
    ++v5;
    --v4;
  }
  while ( v5 <= v4 );
  if ( lo < v4 )
    btAlignedObjectArray<btBroadphasePair>::quickSortInternal<btBroadphasePairSortPredicate>(v6, CompareFunc, lo, v4);
  if ( v5 < hi )
    btAlignedObjectArray<btBroadphasePair>::quickSortInternal<btBroadphasePairSortPredicate>(v6, CompareFunc, v5, hi);
}


void __thiscall btAlignedObjectArray<btPersistentManifold *>::quickSortInternal<btPersistentManifoldSortPredicate>(
        btAlignedObjectArray<btPersistentManifold *> *this,
        btPersistentManifoldSortPredicate CompareFunc,
        int lo,
        int hi)
{
  int v4; // ebx
  int v5; // edi
  btPersistentManifold **m_data; // esi
  _DWORD *m_body0; // ebp
  btPersistentManifold **i; // edx
  int v9; // ecx
  int v10; // eax
  int v11; // ebp
  btPersistentManifold **j; // edx
  btPersistentManifold *v13; // ecx
  int v14; // esi
  int v15; // eax
  btPersistentManifold *v16; // eax
  btAlignedObjectArray<btPersistentManifold *> *v17; // [esp+10h] [ebp-Ch]
  btPersistentManifold *x; // [esp+14h] [ebp-8h]
  btPersistentManifold **v19; // [esp+18h] [ebp-4h]

  v4 = hi;
  v5 = lo;
  v17 = this;
  x = this->m_data[(lo + hi) / 2];
  do
  {
    m_data = this->m_data;
    m_body0 = x->m_body0;
    v19 = m_data;
    for ( i = &m_data[v5]; ; ++i )
    {
      v9 = *((_DWORD *)(*i)->m_body0 + 55);
      if ( v9 < 0 )
        v9 = *((_DWORD *)(*i)->m_body1 + 55);
      v10 = m_body0[55];
      if ( v10 < 0 )
        v10 = *((_DWORD *)x->m_body1 + 55);
      if ( v9 >= v10 )
        break;
      ++v5;
    }
    v11 = m_body0[55];
    for ( j = &m_data[v4]; ; --j )
    {
      v13 = *j;
      if ( v11 < 0 )
        v14 = *((_DWORD *)x->m_body1 + 55);
      else
        v14 = v11;
      v15 = *((_DWORD *)v13->m_body0 + 55);
      if ( v15 < 0 )
        v15 = *((_DWORD *)v13->m_body1 + 55);
      if ( v14 >= v15 )
        break;
      --v4;
    }
    if ( v5 > v4 )
      break;
    v16 = v19[v5];
    v19[v5] = v19[v4];
    this = v17;
    v17->m_data[v4] = v16;
    ++v5;
    --v4;
  }
  while ( v5 <= v4 );
  if ( lo < v4 )
    btAlignedObjectArray<btPersistentManifold *>::quickSortInternal<btPersistentManifoldSortPredicate>(
      v17,
      CompareFunc,
      lo,
      v4);
  if ( v5 < hi )
    btAlignedObjectArray<btPersistentManifold *>::quickSortInternal<btPersistentManifoldSortPredicate>(
      v17,
      CompareFunc,
      v5,
      hi);
}


void __thiscall btAlignedObjectArray<btTypedConstraint *>::quickSortInternal<btSortConstraintOnIslandPredicate>(
        btAlignedObjectArray<btTypedConstraint *> *this,
        btSortConstraintOnIslandPredicate CompareFunc,
        int lo,
        int hi)
{
  int v4; // ebp
  int v5; // edi
  btTypedConstraint **i; // edx
  btTypedConstraint *v7; // ecx
  int m_islandTag1; // esi
  int v9; // eax
  btTypedConstraint **j; // edx
  int v11; // ecx
  int v12; // eax
  btTypedConstraint *v13; // eax
  btTypedConstraint *x; // [esp+10h] [ebp-Ch]
  btAlignedObjectArray<btTypedConstraint *> *v15; // [esp+14h] [ebp-8h]
  btTypedConstraint **m_data; // [esp+18h] [ebp-4h]

  v4 = hi;
  v5 = lo;
  v15 = this;
  x = this->m_data[(lo + hi) / 2];
  while ( 1 )
  {
    m_data = this->m_data;
    for ( i = &m_data[v5]; ; ++i )
    {
      v7 = *i;
      if ( x->m_rbA->m_islandTag1 < 0 )
        m_islandTag1 = x->m_rbB->m_islandTag1;
      else
        m_islandTag1 = x->m_rbA->m_islandTag1;
      v9 = v7->m_rbA->m_islandTag1;
      if ( v9 < 0 )
        v9 = v7->m_rbB->m_islandTag1;
      if ( v9 >= m_islandTag1 )
        break;
      ++v5;
    }
    for ( j = &m_data[v4]; ; --j )
    {
      v11 = (*j)->m_rbA->m_islandTag1;
      if ( v11 < 0 )
        v11 = (*j)->m_rbB->m_islandTag1;
      v12 = x->m_rbA->m_islandTag1 < 0 ? x->m_rbB->m_islandTag1 : x->m_rbA->m_islandTag1;
      if ( v12 >= v11 )
        break;
      --v4;
    }
    if ( v5 > v4 )
      break;
    v13 = m_data[v5];
    m_data[v5] = m_data[v4];
    v15->m_data[v4] = v13;
    if ( ++v5 > --v4 )
      break;
    this = v15;
  }
  if ( lo < v4 )
    btAlignedObjectArray<btTypedConstraint *>::quickSortInternal<btSortConstraintOnIslandPredicate>(
      v15,
      CompareFunc,
      lo,
      v4);
  if ( v5 < hi )
    btAlignedObjectArray<btTypedConstraint *>::quickSortInternal<btSortConstraintOnIslandPredicate>(
      v15,
      CompareFunc,
      v5,
      hi);
}


void __thiscall btAlignedObjectArray<btElement>::quickSortInternal<btUnionFindElementSortPredicate>(
        btAlignedObjectArray<btElement> *this,
        btUnionFindElementSortPredicate CompareFunc,
        int lo,
        int hi)
{
  int v5; // ecx
  int v6; // esi
  int m_id; // edx
  btElement *m_data; // eax
  btElement *i; // edi
  btElement *j; // edi
  int v11; // edi
  btElement *v12; // eax
  btAlignedObjectArray<btElement> *v13; // [esp+Ch] [ebp-Ch]
  int x_4; // [esp+14h] [ebp-4h]

  v5 = hi;
  v6 = lo;
  m_id = this->m_data[(lo + hi) / 2].m_id;
  v13 = this;
  do
  {
    m_data = this->m_data;
    for ( i = &m_data[v6]; i->m_id < m_id; ++v6 )
      ++i;
    for ( j = &m_data[v5]; m_id < j->m_id; --v5 )
      --j;
    if ( v6 > v5 )
      break;
    v11 = m_data[v6].m_id;
    x_4 = m_data[v6].m_sz;
    m_data[v6].m_id = m_data[v5].m_id;
    m_data[v6].m_sz = m_data[v5].m_sz;
    this = v13;
    v12 = v13->m_data;
    v12[v5].m_id = v11;
    v12[v5].m_sz = x_4;
    ++v6;
    --v5;
  }
  while ( v6 <= v5 );
  if ( lo < v5 )
    btAlignedObjectArray<btElement>::quickSortInternal<btUnionFindElementSortPredicate>(this, CompareFunc, lo, v5);
  if ( v6 < hi )
    btAlignedObjectArray<btElement>::quickSortInternal<btUnionFindElementSortPredicate>(this, CompareFunc, v6, hi);
}
