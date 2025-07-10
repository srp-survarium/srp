btConvexPlaneCollisionAlgorithm *__thiscall btConvexPlaneCollisionAlgorithm::`scalar deleting destructor'(
        btConvexPlaneCollisionAlgorithm *this,
        char a2)
{
  bool v3; // zf

  v3 = !this->m_ownManifold;
  this->__vftable = (btConvexPlaneCollisionAlgorithm_vtbl *)&btConvexPlaneCollisionAlgorithm::`vftable';
  if ( !v3 && this->m_manifoldPtr )
    this->m_dispatcher->releaseManifold(this->m_dispatcher, this->m_manifoldPtr);
  this->__vftable = (btConvexPlaneCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
