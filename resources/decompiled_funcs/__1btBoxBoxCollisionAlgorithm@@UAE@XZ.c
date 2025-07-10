void __thiscall btBoxBoxCollisionAlgorithm::~btBoxBoxCollisionAlgorithm(btBoxBoxCollisionAlgorithm *this)
{
  bool v2; // zf

  v2 = !this->m_ownManifold;
  this->__vftable = (btBoxBoxCollisionAlgorithm_vtbl *)&btBoxBoxCollisionAlgorithm::`vftable';
  if ( !v2 && this->m_manifoldPtr )
    this->m_dispatcher->releaseManifold(this->m_dispatcher, this->m_manifoldPtr);
  this->__vftable = (btBoxBoxCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
}
