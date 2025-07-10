btCollisionPairCallback *__thiscall `btHashedOverlappingPairCache::cleanProxyFromPairs'::`2'::CleanPairCallback::`vector deleting destructor'(
        btCollisionPairCallback *this,
        char a2)
{
  this->__vftable = (btCollisionPairCallback_vtbl *)&btOverlapCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
