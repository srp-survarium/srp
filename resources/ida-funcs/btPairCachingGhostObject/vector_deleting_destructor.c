btPairCachingGhostObject *__thiscall btPairCachingGhostObject::`vector deleting destructor'(
        btPairCachingGhostObject *this,
        char a2)
{
  btHashedOverlappingPairCache *m_hashPairCache; // ecx
  btHashedOverlappingPairCache *v4; // eax

  m_hashPairCache = this->m_hashPairCache;
  this->__vftable = (btPairCachingGhostObject_vtbl *)&btPairCachingGhostObject::`vftable';
  ((void (__thiscall *)(btHashedOverlappingPairCache *, _DWORD))m_hashPairCache->~btHashedOverlappingPairCache)(
    m_hashPairCache,
    0);
  v4 = this->m_hashPairCache;
  if ( v4 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v4);
  }
  btGhostObject::~btGhostObject(this);
  if ( (a2 & 1) != 0 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(this);
  }
  return this;
}
