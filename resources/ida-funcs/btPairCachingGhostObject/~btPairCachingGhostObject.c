void __thiscall btPairCachingGhostObject::~btPairCachingGhostObject(btPairCachingGhostObject *this)
{
  void **p_m_hashPairCache; // edi
  btHashedOverlappingPairCache *m_hashPairCache; // ecx

  p_m_hashPairCache = (void **)&this->m_hashPairCache;
  m_hashPairCache = this->m_hashPairCache;
  this->__vftable = (btPairCachingGhostObject_vtbl *)&btPairCachingGhostObject::`vftable';
  ((void (__thiscall *)(btHashedOverlappingPairCache *, _DWORD))m_hashPairCache->~btHashedOverlappingPairCache)(
    m_hashPairCache,
    0);
  btAlignedFreeInternal(*p_m_hashPairCache);
  btGhostObject::~btGhostObject(this);
}
