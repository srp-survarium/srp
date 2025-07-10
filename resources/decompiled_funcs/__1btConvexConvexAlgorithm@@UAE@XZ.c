void __thiscall btConvexConvexAlgorithm::~btConvexConvexAlgorithm(btConvexConvexAlgorithm *this)
{
  bool v2; // zf

  v2 = !this->m_ownManifold;
  this->__vftable = (btConvexConvexAlgorithm_vtbl *)&btConvexConvexAlgorithm::`vftable';
  if ( !v2 && this->m_manifoldPtr )
    this->m_dispatcher->releaseManifold(this->m_dispatcher, this->m_manifoldPtr);
  this->__vftable = (btConvexConvexAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
}
