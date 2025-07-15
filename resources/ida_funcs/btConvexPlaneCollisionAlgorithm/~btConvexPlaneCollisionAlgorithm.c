void __thiscall btConvexPlaneCollisionAlgorithm::~btConvexPlaneCollisionAlgorithm(
        btConvexPlaneCollisionAlgorithm *this)
{
  bool v2; // zf

  v2 = !this->m_ownManifold;
  this->__vftable = (btConvexPlaneCollisionAlgorithm_vtbl *)&btConvexPlaneCollisionAlgorithm::`vftable';
  if ( !v2 && this->m_manifoldPtr )
    this->m_dispatcher->releaseManifold(this->m_dispatcher, this->m_manifoldPtr);
  this->__vftable = (btConvexPlaneCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
}
