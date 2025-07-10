btCollisionAlgorithm *__thiscall btSphereSphereCollisionAlgorithm::CreateFunc::CreateCollisionAlgorithm(
        btSphereSphereCollisionAlgorithm::CreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  _BYTE *v4; // esi
  btCollisionAlgorithm *result; // eax
  btDispatcher *m_dispatcher1; // ecx

  v4 = ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 16);
  result = 0;
  if ( v4 )
  {
    *(_DWORD *)v4 = &btCollisionAlgorithm::`vftable';
    m_dispatcher1 = ci->m_dispatcher1;
    v4[8] = 0;
    *((_DWORD *)v4 + 3) = 0;
    *((_DWORD *)v4 + 1) = m_dispatcher1;
    *(_DWORD *)v4 = &btSphereSphereCollisionAlgorithm::`vftable';
    *((_DWORD *)v4 + 3) = m_dispatcher1->getNewManifold(m_dispatcher1, body0, body1);
    v4[8] = 1;
    return (btCollisionAlgorithm *)v4;
  }
  return result;
}
