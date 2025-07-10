void __thiscall btPairCachingGhostObject::~btPairCachingGhostObject(btPairCachingGhostObject *this)
{
  btHashedOverlappingPairCache *m_hashPairCache; // ecx
  btHashedOverlappingPairCache *v3; // eax

  m_hashPairCache = this->m_hashPairCache;
  this->__vftable = (btPairCachingGhostObject_vtbl *)&btPairCachingGhostObject::`vftable';
  ((void (__thiscall *)(btHashedOverlappingPairCache *, _DWORD))m_hashPairCache->~btHashedOverlappingPairCache)(
    m_hashPairCache,
    0);
  v3 = this->m_hashPairCache;
  if ( v3 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v3);
  }
  btGhostObject::~btGhostObject(this);
}
