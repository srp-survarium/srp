btCollisionAlgorithm *__thiscall btSphereTriangleCollisionAlgorithm::CreateFunc::CreateCollisionAlgorithm(
        btSphereTriangleCollisionAlgorithm::CreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  _DWORD *v5; // esi
  btPersistentManifold *m_manifold; // eax
  bool m_swapped; // cl
  btDispatcher *m_dispatcher1; // edx

  v5 = ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 20);
  if ( !v5 )
    return 0;
  m_manifold = ci->m_manifold;
  m_swapped = this->m_swapped;
  *v5 = &btCollisionAlgorithm::`vftable';
  m_dispatcher1 = ci->m_dispatcher1;
  v5[1] = ci->m_dispatcher1;
  *v5 = &btSphereTriangleCollisionAlgorithm::`vftable';
  *((_BYTE *)v5 + 8) = 0;
  v5[3] = m_manifold;
  *((_BYTE *)v5 + 16) = m_swapped;
  if ( !m_manifold )
  {
    v5[3] = m_dispatcher1->getNewManifold(m_dispatcher1, body0, body1);
    *((_BYTE *)v5 + 8) = 1;
  }
  return (btCollisionAlgorithm *)v5;
}
