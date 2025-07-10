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
