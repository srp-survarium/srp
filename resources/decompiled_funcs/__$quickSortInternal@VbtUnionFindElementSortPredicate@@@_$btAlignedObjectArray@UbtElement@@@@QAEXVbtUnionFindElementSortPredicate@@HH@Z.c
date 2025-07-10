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
