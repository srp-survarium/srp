btCollisionAlgorithm *__thiscall btConvexConcaveCollisionAlgorithm::SwappedCreateFunc::CreateCollisionAlgorithm(
        btConvexConcaveCollisionAlgorithm::SwappedCreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  _DWORD *v4; // esi
  btCollisionAlgorithm *result; // eax
  btDispatcher *m_dispatcher1; // ecx
  int v7; // eax
  int v8; // ecx

  v4 = ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 96);
  result = 0;
  if ( v4 )
  {
    *v4 = &btCollisionAlgorithm::`vftable';
    v4[1] = ci->m_dispatcher1;
    *v4 = &btConvexConcaveCollisionAlgorithm::`vftable';
    *((_BYTE *)v4 + 8) = 1;
    m_dispatcher1 = ci->m_dispatcher1;
    v4[18] = 0;
    v4[6] = body0;
    v4[4] = &btConvexTriangleCallback::`vftable';
    v4[17] = m_dispatcher1;
    v4[5] = body1;
    v7 = (int)m_dispatcher1->getNewManifold(m_dispatcher1, body1, body0);
    v8 = v4[17];
    v4[21] = v7;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 16))(v8, v7);
    return (btCollisionAlgorithm *)v4;
  }
  return result;
}
