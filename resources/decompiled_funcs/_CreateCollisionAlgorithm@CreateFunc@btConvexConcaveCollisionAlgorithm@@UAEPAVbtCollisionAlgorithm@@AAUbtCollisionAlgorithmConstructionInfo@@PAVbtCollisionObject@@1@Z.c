btCollisionAlgorithm *__thiscall btConvexConcaveCollisionAlgorithm::CreateFunc::CreateCollisionAlgorithm(
        btConvexConcaveCollisionAlgorithm::CreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  _BYTE *v4; // esi
  btCollisionAlgorithm *result; // eax
  btDispatcher *m_dispatcher1; // ecx
  btDispatcher *v7; // ecx
  int v8; // eax
  int v9; // ecx

  v4 = ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 96);
  result = 0;
  if ( v4 )
  {
    *(_DWORD *)v4 = &btCollisionAlgorithm::`vftable';
    m_dispatcher1 = ci->m_dispatcher1;
    v4[8] = 0;
    *((_DWORD *)v4 + 1) = m_dispatcher1;
    *(_DWORD *)v4 = &btConvexConcaveCollisionAlgorithm::`vftable';
    v7 = ci->m_dispatcher1;
    *((_DWORD *)v4 + 18) = 0;
    *((_DWORD *)v4 + 6) = body1;
    *((_DWORD *)v4 + 4) = &btConvexTriangleCallback::`vftable';
    *((_DWORD *)v4 + 17) = v7;
    *((_DWORD *)v4 + 5) = body0;
    v8 = (int)v7->getNewManifold(v7, body0, body1);
    v9 = *((_DWORD *)v4 + 17);
    *((_DWORD *)v4 + 21) = v8;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 16))(v9, v8);
    return (btCollisionAlgorithm *)v4;
  }
  return result;
}
