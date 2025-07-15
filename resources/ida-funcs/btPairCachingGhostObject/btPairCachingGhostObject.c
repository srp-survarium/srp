btPairCachingGhostObject *__usercall btPairCachingGhostObject::btPairCachingGhostObject@<eax>(
        btPairCachingGhostObject *this@<ecx>,
        btPairCachingGhostObject *a2@<eax>)
{
  btHashedOverlappingPairCache *v3; // eax
  btHashedOverlappingPairCache *v4; // eax
  btHashedOverlappingPairCache *v6; // [esp-4h] [ebp-8h]

  btCollisionObject::btCollisionObject(this, (int)a2);
  a2->m_overlappingObjects.m_data = 0;
  a2->m_overlappingObjects.m_size = 0;
  a2->m_overlappingObjects.m_capacity = 0;
  a2->m_overlappingObjects.m_ownsMemory = 1;
  a2->m_internalType = 4;
  a2->__vftable = (btPairCachingGhostObject_vtbl *)&btPairCachingGhostObject::`vftable';
  v3 = (btHashedOverlappingPairCache *)btAlignedAllocInternal(0x4Cu);
  if ( v3 )
    v4 = btHashedOverlappingPairCache::btHashedOverlappingPairCache(v6, v3);
  else
    v4 = 0;
  a2->m_hashPairCache = v4;
  return a2;
}
