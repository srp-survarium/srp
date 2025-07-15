btPairCachingGhostObject *__usercall btPairCachingGhostObject::btPairCachingGhostObject@<eax>(
        btPairCachingGhostObject *this@<ecx>,
        btPairCachingGhostObject *a2@<esi>)
{
  btHashedOverlappingPairCache *v2; // eax
  btHashedOverlappingPairCache *v3; // ecx

  btCollisionObject::btCollisionObject(this, a2);
  ++gNumAlignedAllocs;
  a2->m_overlappingObjects.m_ownsMemory = 1;
  a2->m_overlappingObjects.m_data = 0;
  a2->m_overlappingObjects.m_size = 0;
  a2->m_overlappingObjects.m_capacity = 0;
  a2->m_internalType = 4;
  a2->__vftable = (btPairCachingGhostObject_vtbl *)&btPairCachingGhostObject::`vftable';
  v2 = (btHashedOverlappingPairCache *)sAlignedAllocFunc(0x4Cu, 16);
  if ( v2 )
    a2->m_hashPairCache = btHashedOverlappingPairCache::btHashedOverlappingPairCache(v3, v2);
  else
    a2->m_hashPairCache = 0;
  return a2;
}
