void __thiscall btCompoundCollisionAlgorithm::~btCompoundCollisionAlgorithm(btCompoundCollisionAlgorithm *this)
{
  btAlignedObjectArray<GrahamVector2> *v2; // ecx

  this->__vftable = (btCompoundCollisionAlgorithm_vtbl *)&btCompoundCollisionAlgorithm::`vftable';
  btCompoundCollisionAlgorithm::removeChildAlgorithms(this, (int)this);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    v2,
    (int)&this->m_childCollisionAlgorithms);
  this->__vftable = (btCompoundCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
}
