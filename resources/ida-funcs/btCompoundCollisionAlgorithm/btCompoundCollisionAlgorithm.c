void __stdcall btCompoundCollisionAlgorithm::btCompoundCollisionAlgorithm(
        btCompoundCollisionAlgorithm *this,
        const btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0)
{
  bool isSwapped; // al
  btCollisionObject *body1; // ecx
  bool v5; // zf
  btCollisionObject *v6; // eax

  this->__vftable = (btCompoundCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  this->m_dispatcher = ci->m_dispatcher1;
  this->__vftable = (btCompoundCollisionAlgorithm_vtbl *)&btCompoundCollisionAlgorithm::`vftable';
  this->m_childCollisionAlgorithms.m_ownsMemory = 1;
  this->m_childCollisionAlgorithms.m_data = 0;
  this->m_childCollisionAlgorithms.m_size = 0;
  this->m_childCollisionAlgorithms.m_capacity = 0;
  this->m_isSwapped = isSwapped;
  v5 = !isSwapped;
  this->m_sharedManifold = ci->m_manifold;
  this->m_ownsManifold = 0;
  v6 = body1;
  if ( v5 )
    v6 = body0;
  this->m_compoundShapeRevision = (int)v6->m_collisionShape[5].m_userPointer;
  btCompoundCollisionAlgorithm::preallocateChildAlgorithms(this, body0, body1);
}
