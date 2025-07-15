btSoftRigidCollisionAlgorithm *__thiscall btEmptyAlgorithm::`scalar deleting destructor'(
        btSoftRigidCollisionAlgorithm *this,
        char a2)
{
  this->__vftable = (btSoftRigidCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
