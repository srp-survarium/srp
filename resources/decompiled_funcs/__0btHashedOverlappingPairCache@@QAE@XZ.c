btHashedOverlappingPairCache *__usercall btHashedOverlappingPairCache::btHashedOverlappingPairCache@<eax>(
        btHashedOverlappingPairCache *this@<ecx>,
        btHashedOverlappingPairCache *a2@<eax>)
{
  char *v3; // ebp
  int v4; // edx
  int m_size; // edi
  char *v6; // eax
  int v7; // ebp
  char *v8; // eax
  btBroadphasePair *m_data; // eax
  char *v11; // [esp+8h] [ebp-4h]

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
    ++gNumAlignedAllocs;
    v3 = (char *)sAlignedAllocFunc(0x20u, 16);
    v11 = v3;
    if ( a2->m_overlappingPairArray.m_size > 0 )
    {
      this = (btHashedOverlappingPairCache *)(v3 + 8);
      v4 = -8 - (_DWORD)v3;
      m_size = a2->m_overlappingPairArray.m_size;
      do
      {
        if ( this != (btHashedOverlappingPairCache *)8 )
        {
          v6 = (char *)a2->m_overlappingPairArray.m_data + v4;
          v7 = *(int *)((char *)&this->__vftable + (_DWORD)v6);
          v8 = &v6[(_DWORD)this];
          *(_DWORD *)&this[-1].m_next.m_ownsMemory = v7;
          this[-1].m_ghostPairCallback = (btOverlappingPairCallback *)*((_DWORD *)v8 + 1);
          this->__vftable = (btHashedOverlappingPairCache_vtbl *)*((_DWORD *)v8 + 2);
          v3 = v11;
          *(_DWORD *)&this->m_overlappingPairArray.m_allocator = *((_DWORD *)v8 + 3);
        }
        this = (btHashedOverlappingPairCache *)((char *)this + 16);
        --m_size;
      }
      while ( m_size );
    }
    m_data = a2->m_overlappingPairArray.m_data;
    if ( m_data )
    {
      if ( a2->m_overlappingPairArray.m_ownsMemory )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(m_data);
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
