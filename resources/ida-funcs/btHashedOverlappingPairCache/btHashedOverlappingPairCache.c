btHashedOverlappingPairCache *__usercall btHashedOverlappingPairCache::btHashedOverlappingPairCache@<eax>(
        btHashedOverlappingPairCache *this@<ecx>,
        btHashedOverlappingPairCache *a2@<eax>)
{
  char *v3; // edi
  char *v4; // eax
  btHashedOverlappingPairCache *v6; // [esp-8h] [ebp-18h]
  btHashedOverlappingPairCache *v7; // [esp-8h] [ebp-18h]
  int m_size; // [esp+8h] [ebp-8h]

  a2->__vftable = (btHashedOverlappingPairCache_vtbl *)&btHashedOverlappingPairCache::`vftable';
  a2->m_overlappingPairArray.m_ownsMemory = 1;
  a2->m_overlappingPairArray.m_data = 0;
  a2->m_overlappingPairArray.m_size = 0;
  a2->m_overlappingPairArray.m_capacity = 0;
  a2->m_overlapFilterCallback = 0;
  a2->m_blockedForChanges = 0;
  a2->m_hashTable.m_ownsMemory = 1;
  a2->m_hashTable.m_data = 0;
  a2->m_hashTable.m_size = 0;
  a2->m_hashTable.m_capacity = 0;
  a2->m_next.m_ownsMemory = 1;
  a2->m_next.m_data = 0;
  a2->m_next.m_size = 0;
  a2->m_next.m_capacity = 0;
  a2->m_ghostPairCallback = 0;
  if ( a2->m_overlappingPairArray.m_capacity < 2 )
  {
    v3 = (char *)btAlignedAllocInternal(0x20u);
    this = v6;
    if ( a2->m_overlappingPairArray.m_size > 0 )
    {
      this = (btHashedOverlappingPairCache *)(v3 + 8);
      m_size = a2->m_overlappingPairArray.m_size;
      do
      {
        if ( this != (btHashedOverlappingPairCache *)8 )
        {
          v4 = (char *)this + (unsigned int)a2->m_overlappingPairArray.m_data - 8 - (_DWORD)v3;
          *(_DWORD *)&this[-1].m_next.m_ownsMemory = *(_DWORD *)v4;
          this[-1].m_ghostPairCallback = (btOverlappingPairCallback *)*((_DWORD *)v4 + 1);
          this->__vftable = (btHashedOverlappingPairCache_vtbl *)*((_DWORD *)v4 + 2);
          *(_DWORD *)&this->m_overlappingPairArray.m_allocator = *((_DWORD *)v4 + 3);
        }
        this = (btHashedOverlappingPairCache *)((char *)this + 16);
        --m_size;
      }
      while ( m_size );
    }
    if ( a2->m_overlappingPairArray.m_data )
    {
      if ( a2->m_overlappingPairArray.m_ownsMemory )
      {
        btAlignedFreeInternal(a2->m_overlappingPairArray.m_data);
        this = v7;
      }
      a2->m_overlappingPairArray.m_data = 0;
    }
    a2->m_overlappingPairArray.m_data = (btBroadphasePair *)v3;
    a2->m_overlappingPairArray.m_ownsMemory = 1;
    a2->m_overlappingPairArray.m_capacity = 2;
  }
  btHashedOverlappingPairCache::growTables(this, (int)a2);
  return a2;
}
