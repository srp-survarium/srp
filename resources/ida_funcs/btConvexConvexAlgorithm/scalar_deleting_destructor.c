btConvexConvexAlgorithm *__thiscall btConvexConvexAlgorithm::`scalar deleting destructor'(
        btConvexConvexAlgorithm *this,
        char a2)
{
  bool v3; // zf

  v3 = !this->m_ownManifold;
  this->__vftable = (btConvexConvexAlgorithm_vtbl *)&btConvexConvexAlgorithm::`vftable';
  if ( !v3 && this->m_manifoldPtr )
    this->m_dispatcher->releaseManifold(this->m_dispatcher, this->m_manifoldPtr);
  this->__vftable = (btConvexConvexAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
