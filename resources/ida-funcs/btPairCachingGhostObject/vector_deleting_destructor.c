btPairCachingGhostObject *__thiscall btPairCachingGhostObject::`vector deleting destructor'(
        btPairCachingGhostObject *this,
        char a2)
{
  btPairCachingGhostObject::~btPairCachingGhostObject(this);
  if ( (a2 & 1) != 0 )
    btAlignedFreeInternal(this);
  return this;
}
