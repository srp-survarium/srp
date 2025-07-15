void __thiscall btAlignedObjectArray<btBroadphasePair>::quickSort<btBroadphasePairSortPredicate>(
        btAlignedObjectArray<btBroadphasePair> *this,
        btBroadphasePairSortPredicate CompareFunc)
{
  int m_size; // eax

  m_size = this->m_size;
  if ( m_size > 1 )
    btAlignedObjectArray<btBroadphasePair>::quickSortInternal<btBroadphasePairSortPredicate>(
      this,
      CompareFunc,
      0,
      m_size - 1);
}
