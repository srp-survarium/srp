void __stdcall btCompoundCollisionAlgorithm::btCompoundCollisionAlgorithm(
        btCompoundCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  int v3; // eax
  bool v4; // cl
  btCollisionObject *v5; // eax

  this->__vftable = (btCompoundCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  this->m_dispatcher = *(btDispatcher **)v3;
  this->__vftable = (btCompoundCollisionAlgorithm_vtbl *)&btCompoundCollisionAlgorithm::`vftable';
  this->m_childCollisionAlgorithms.m_data = 0;
  this->m_childCollisionAlgorithms.m_size = 0;
  this->m_childCollisionAlgorithms.m_capacity = 0;
  this->m_childCollisionAlgorithms.m_ownsMemory = 1;
  this->m_isSwapped = v4;
  this->m_sharedManifold = *(btPersistentManifold **)(v3 + 4);
  v5 = body1;
  if ( !v4 )
    v5 = body0;
  this->m_ownsManifold = 0;
  this->m_compoundShapeRevision = (int)v5->m_collisionShape[5].m_userPointer;
  btCompoundCollisionAlgorithm::preallocateChildAlgorithms(this, body0, body1);
}
