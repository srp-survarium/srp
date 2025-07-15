btHashedOverlappingPairCache *__thiscall btHashedOverlappingPairCache::`scalar deleting destructor'(
        btHashedOverlappingPairCache *this,
        char a2)
{
  btHashedOverlappingPairCache::~btHashedOverlappingPairCache(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
