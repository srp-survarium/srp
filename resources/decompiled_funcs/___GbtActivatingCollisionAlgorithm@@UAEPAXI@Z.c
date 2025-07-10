btEmptyAlgorithm *__thiscall btActivatingCollisionAlgorithm::`scalar deleting destructor'(
        btEmptyAlgorithm *this,
        char a2)
{
  this->__vftable = (btEmptyAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
