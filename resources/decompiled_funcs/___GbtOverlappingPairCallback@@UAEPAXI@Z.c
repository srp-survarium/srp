btGhostPairCallback *__thiscall btOverlappingPairCallback::`scalar deleting destructor'(
        btGhostPairCallback *this,
        char a2)
{
  this->__vftable = (btGhostPairCallback_vtbl *)&btOverlappingPairCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
