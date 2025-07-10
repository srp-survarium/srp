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
