btCompoundCollisionAlgorithm *__thiscall btCompoundCollisionAlgorithm::CreateFunc::CreateCollisionAlgorithm(
        btCompoundCollisionAlgorithm::CreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  btCompoundCollisionAlgorithm *v4; // esi
  btCompoundCollisionAlgorithm *result; // eax

  v4 = (btCompoundCollisionAlgorithm *)ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 44);
  result = 0;
  if ( v4 )
  {
    v4->__vftable = (btCompoundCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
    v4->m_dispatcher = ci->m_dispatcher1;
    v4->__vftable = (btCompoundCollisionAlgorithm_vtbl *)&btCompoundCollisionAlgorithm::`vftable';
    v4->m_childCollisionAlgorithms.m_ownsMemory = 1;
    v4->m_childCollisionAlgorithms.m_data = 0;
    v4->m_childCollisionAlgorithms.m_size = 0;
    v4->m_childCollisionAlgorithms.m_capacity = 0;
    v4->m_isSwapped = 0;
    v4->m_sharedManifold = ci->m_manifold;
    v4->m_ownsManifold = 0;
    v4->m_compoundShapeRevision = (int)body0->m_collisionShape[5].m_userPointer;
    btCompoundCollisionAlgorithm::preallocateChildAlgorithms(v4, body0, body1);
    return v4;
  }
  return result;
}
