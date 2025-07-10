void __thiscall btSphereSphereCollisionAlgorithm::~btSphereSphereCollisionAlgorithm(
        btSphereSphereCollisionAlgorithm *this)
{
  bool v2; // zf

  v2 = !this->m_ownManifold;
  this->__vftable = (btSphereSphereCollisionAlgorithm_vtbl *)&btSphereSphereCollisionAlgorithm::`vftable';
  if ( !v2 && this->m_manifoldPtr )
    this->m_dispatcher->releaseManifold(this->m_dispatcher, this->m_manifoldPtr);
  this->__vftable = (btSphereSphereCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
}
