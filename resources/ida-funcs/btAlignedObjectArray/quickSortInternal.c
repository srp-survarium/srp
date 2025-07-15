void __thiscall btAlignedObjectArray<GrahamVector2>::quickSortInternal<btAngleCompareFunc>(
        btAlignedObjectArray<GrahamVector2> *this,
        btAngleCompareFunc CompareFunc,
        int lo,
        int hi)
{
  GrahamVector2 *m_data; // edi
  const GrahamVector2 *i; // edi
  btAngleCompareFunc v7; // [esp-18h] [ebp-58h]
  btAngleCompareFunc v8; // [esp-18h] [ebp-58h]
  int hia; // [esp+14h] [ebp-2Ch]
  _QWORD v10[5]; // [esp+18h] [ebp-28h] BYREF

  hia = CompareFunc.m_anchor.mVec128.m128_i32[1];
  LODWORD(v10[0]) = CompareFunc.m_anchor.mVec128.m128_i32[0];
  qmemcpy(
    &v10[1],
    &this->m_data[(CompareFunc.m_anchor.mVec128.m128_i32[1] + CompareFunc.m_anchor.mVec128.m128_i32[0]) / 2],
    0x20u);
  do
  {
    m_data = this->m_data;
    for ( HIDWORD(v10[0]) = &m_data[LODWORD(v10[0])];
          btAngleCompareFunc::operator()(
            (btAngleCompareFunc *)&CompareFunc.m_anchor.m_floats[2],
            (const GrahamVector2 *)HIDWORD(v10[0]),
            (const GrahamVector2 *)&v10[1]);
          ++LODWORD(v10[0]) )
    {
      HIDWORD(v10[0]) += 32;
    }
    for ( i = &m_data[hia];
          btAngleCompareFunc::operator()(
            (btAngleCompareFunc *)&CompareFunc.m_anchor.m_floats[2],
            (const GrahamVector2 *)&v10[1],
            i);
          --i )
    {
      --hia;
    }
    if ( SLODWORD(v10[0]) > hia )
      break;
    btAlignedObjectArray<GrahamVector2>::swap(v10[0], this, hia);
    ++LODWORD(v10[0]);
    --hia;
  }
  while ( SLODWORD(v10[0]) <= hia );
  if ( CompareFunc.m_anchor.mVec128.m128_i32[0] < hia )
  {
    v7.m_anchor.mVec128.m128_u64[1] = CompareFunc.m_anchor.mVec128.m128_u64[1];
    v7.m_anchor.mVec128.m128_u64[0] = __PAIR64__(hia, CompareFunc.m_anchor.mVec128.m128_u32[0]);
    btAlignedObjectArray<GrahamVector2>::quickSortInternal<btAngleCompareFunc>(
      this,
      (btAngleCompareFunc)v7.m_anchor.mVec128,
      lo,
      hi);
  }
  if ( SLODWORD(v10[0]) < CompareFunc.m_anchor.mVec128.m128_i32[1] )
  {
    v8.m_anchor.mVec128.m128_u64[1] = CompareFunc.m_anchor.mVec128.m128_u64[1];
    v8.m_anchor.mVec128.m128_u64[0] = __PAIR64__(CompareFunc.m_anchor.mVec128.m128_u32[1], v10[0]);
    btAlignedObjectArray<GrahamVector2>::quickSortInternal<btAngleCompareFunc>(
      this,
      (btAngleCompareFunc)v8.m_anchor.mVec128,
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
  btBroadphasePair *v5; // eax
  btCollisionAlgorithm *m_algorithm; // ecx
  int m_internalTmpValue; // eax
  btBroadphasePair *m_data; // esi
  const btBroadphasePair *i; // ebx
  const btBroadphasePair *j; // esi
  int index1; // [esp+18h] [ebp-18h]
  int index0; // [esp+1Ch] [ebp-14h]
  btBroadphasePair v13; // [esp+20h] [ebp-10h] BYREF

  index1 = hi;
  v5 = &this->m_data[(lo + hi) / 2];
  index0 = lo;
  v13.m_pProxy0 = v5->m_pProxy0;
  v13.m_pProxy1 = v5->m_pProxy1;
  m_algorithm = v5->m_algorithm;
  m_internalTmpValue = v5->m_internalTmpValue;
  v13.m_algorithm = m_algorithm;
  v13.m_internalTmpValue = m_internalTmpValue;
  do
  {
    m_data = this->m_data;
    for ( i = &m_data[index0];
          btBroadphasePairSortPredicate::operator()((btBroadphasePairSortPredicate *)m_algorithm, i, &v13);
          ++i )
    {
      ++index0;
    }
    for ( j = &m_data[index1];
          btBroadphasePairSortPredicate::operator()((btBroadphasePairSortPredicate *)m_algorithm, &v13, j);
          --j )
    {
      --index1;
    }
    if ( index0 > index1 )
      break;
    btAlignedObjectArray<btBroadphasePair>::swap(this, index0++, index1--);
  }
  while ( index0 <= index1 );
  if ( lo < index1 )
    btAlignedObjectArray<btBroadphasePair>::quickSortInternal<btBroadphasePairSortPredicate>(
      this,
      CompareFunc,
      lo,
      index1);
  if ( index0 < hi )
    btAlignedObjectArray<btBroadphasePair>::quickSortInternal<btBroadphasePairSortPredicate>(
      this,
      CompareFunc,
      index0,
      hi);
}


void __thiscall btAlignedObjectArray<btPersistentManifold *>::quickSortInternal<btPersistentManifoldSortPredicate>(
        btAlignedObjectArray<btPersistentManifold *> *this,
        btPersistentManifoldSortPredicate CompareFunc,
        int lo,
        int hi)
{
  int v4; // ebx
  int v5; // edi
  btAlignedObjectArray<btPersistentManifold *> *v6; // esi
  btPersistentManifold **m_data; // esi
  int v8; // ebx
  int v9; // ebx
  int v10; // ebx
  btPersistentManifold *v11; // edx
  btPersistentManifold **v12; // eax
  btPersistentManifold *v13; // ecx
  int IslandId; // [esp+10h] [ebp-Ch]
  const btPersistentManifold **v16; // [esp+10h] [ebp-Ch]
  const btPersistentManifold **v17; // [esp+10h] [ebp-Ch]
  const btPersistentManifold *v18; // [esp+14h] [ebp-8h]
  int v19; // [esp+18h] [ebp-4h]

  v4 = lo;
  v5 = hi;
  v6 = this;
  v19 = lo;
  v18 = this->m_data[(lo + hi) / 2];
  while ( 1 )
  {
    m_data = v6->m_data;
    IslandId = getIslandId(v18);
    if ( getIslandId(m_data[v4]) < IslandId )
    {
      v16 = (const btPersistentManifold **)&m_data[v19];
      do
      {
        ++v19;
        ++v16;
        v8 = getIslandId(v18);
      }
      while ( getIslandId(*v16) < v8 );
    }
    v9 = getIslandId(m_data[v5]);
    if ( getIslandId(v18) < v9 )
    {
      v17 = (const btPersistentManifold **)&m_data[v5];
      do
      {
        --v17;
        --v5;
        v10 = getIslandId(*v17);
      }
      while ( getIslandId(v18) < v10 );
    }
    v4 = v19;
    if ( v19 > v5 )
      break;
    v11 = m_data[v5];
    v12 = &m_data[v19];
    v13 = *v12;
    v6 = this;
    *v12 = v11;
    v4 = v19 + 1;
    this->m_data[v5--] = v13;
    v19 = v4;
    if ( v4 > v5 )
      goto LABEL_12;
  }
  v6 = this;
LABEL_12:
  if ( lo < v5 )
    btAlignedObjectArray<btPersistentManifold *>::quickSortInternal<btPersistentManifoldSortPredicate>(
      v6,
      CompareFunc,
      lo,
      v5);
  if ( v4 < hi )
    btAlignedObjectArray<btPersistentManifold *>::quickSortInternal<btPersistentManifoldSortPredicate>(
      v6,
      CompareFunc,
      v4,
      hi);
}


void __thiscall btAlignedObjectArray<btTypedConstraint *>::quickSortInternal<btSortConstraintOnIslandPredicate>(
        btAlignedObjectArray<btTypedConstraint *> *this,
        btSortConstraintOnIslandPredicate CompareFunc,
        int lo,
        int hi)
{
  int v4; // ebx
  int v5; // edi
  btTypedConstraint **m_data; // esi
  btTypedConstraint **v7; // eax
  btTypedConstraint *v8; // ecx
  btSortConstraintOnIslandPredicate *v9; // [esp+0h] [ebp-18h]
  btSortConstraintOnIslandPredicate *v10; // [esp+0h] [ebp-18h]
  const btTypedConstraint **v11; // [esp+Ch] [ebp-Ch]
  const btTypedConstraint **v12; // [esp+Ch] [ebp-Ch]
  btAlignedObjectArray<btTypedConstraint *> *v13; // [esp+10h] [ebp-8h]
  const btTypedConstraint *v14; // [esp+14h] [ebp-4h]

  v4 = lo;
  v5 = hi;
  v13 = this;
  v14 = this->m_data[(lo + hi) / 2];
  while ( 1 )
  {
    m_data = this->m_data;
    if ( btSortConstraintOnIslandPredicate::operator()(v14, m_data[v4], v9) )
    {
      v11 = (const btTypedConstraint **)&m_data[v4];
      do
      {
        ++v11;
        ++v4;
      }
      while ( btSortConstraintOnIslandPredicate::operator()(v14, *v11, v10) );
    }
    if ( btSortConstraintOnIslandPredicate::operator()(m_data[v5], v14, v10) )
    {
      v12 = (const btTypedConstraint **)&m_data[v5];
      do
      {
        --v12;
        --v5;
      }
      while ( btSortConstraintOnIslandPredicate::operator()(*v12, v14, v9) );
    }
    if ( v4 > v5 )
      break;
    v7 = &m_data[v4];
    v8 = *v7;
    *v7 = m_data[v5];
    ++v4;
    v13->m_data[v5--] = v8;
    if ( v4 > v5 )
      break;
    this = v13;
  }
  if ( lo < v5 )
    btAlignedObjectArray<btTypedConstraint *>::quickSortInternal<btSortConstraintOnIslandPredicate>(
      v13,
      CompareFunc,
      lo,
      v5);
  if ( v4 < hi )
    btAlignedObjectArray<btTypedConstraint *>::quickSortInternal<btSortConstraintOnIslandPredicate>(
      v13,
      CompareFunc,
      v4,
      hi);
}


void __thiscall btAlignedObjectArray<btElement>::quickSortInternal<btUnionFindElementSortPredicate>(
        btAlignedObjectArray<btElement> *this,
        btUnionFindElementSortPredicate CompareFunc,
        int lo,
        int hi)
{
  int v4; // esi
  int v5; // edi
  int m_id; // ebx
  btElement *m_data; // edx
  btElement *j; // eax
  btElement *k; // eax
  btElement *v10; // eax
  int v11; // ecx
  btElement *v12; // eax
  int v14; // [esp+10h] [ebp-10h]
  int m_sz; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]

  v4 = hi;
  v5 = lo;
  m_id = this->m_data[(lo + hi) / 2].m_id;
  for ( i = m_id; ; m_id = i )
  {
    m_data = this->m_data;
    for ( j = &m_data[v5]; j->m_id < m_id; ++j )
      ++v5;
    for ( k = &m_data[v4]; m_id < k->m_id; --k )
      --v4;
    if ( v5 > v4 )
      break;
    v10 = &m_data[v5];
    v14 = v10->m_id;
    m_sz = v10->m_sz;
    v11 = v4;
    v10->m_id = m_data[v4].m_id;
    v10->m_sz = m_data[v4].m_sz;
    v12 = this->m_data;
    ++v5;
    v12[v11].m_id = v14;
    --v4;
    v12[v11].m_sz = m_sz;
    if ( v5 > v4 )
      break;
  }
  if ( lo < v4 )
    btAlignedObjectArray<btElement>::quickSortInternal<btUnionFindElementSortPredicate>(this, CompareFunc, lo, v4);
  if ( v5 < hi )
    btAlignedObjectArray<btElement>::quickSortInternal<btUnionFindElementSortPredicate>(this, CompareFunc, v5, hi);
}
