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
