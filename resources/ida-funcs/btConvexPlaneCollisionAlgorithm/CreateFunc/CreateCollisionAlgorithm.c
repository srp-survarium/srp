btCollisionAlgorithm *__thiscall btConvexPlaneCollisionAlgorithm::CreateFunc::CreateCollisionAlgorithm(
        btConvexPlaneCollisionAlgorithm::CreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  _DWORD *v5; // esi
  btCollisionAlgorithm *result; // eax
  int v7; // ecx
  int v8; // edi
  btDispatcher *v9; // edx
  int m_minimumPointsPerturbationThreshold; // ecx
  int m_numPerturbationIterations; // edi
  btDispatcher *m_dispatcher1; // edx

  v5 = ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 28);
  result = 0;
  if ( this->m_swapped )
  {
    if ( !v5 )
      return result;
    m_minimumPointsPerturbationThreshold = this->m_minimumPointsPerturbationThreshold;
    m_numPerturbationIterations = this->m_numPerturbationIterations;
    *v5 = &btCollisionAlgorithm::`vftable';
    m_dispatcher1 = ci->m_dispatcher1;
    v5[5] = m_numPerturbationIterations;
    v5[6] = m_minimumPointsPerturbationThreshold;
    v5[1] = m_dispatcher1;
    *v5 = &btConvexPlaneCollisionAlgorithm::`vftable';
    *((_BYTE *)v5 + 8) = 0;
    v5[3] = 0;
    *((_BYTE *)v5 + 16) = 1;
    if ( m_dispatcher1->needsCollision(m_dispatcher1, body1, body0) )
    {
      v5[3] = (*(int (__thiscall **)(_DWORD, btCollisionObject *, btCollisionObject *))(*(_DWORD *)v5[1] + 8))(
                v5[1],
                body1,
                body0);
      *((_BYTE *)v5 + 8) = 1;
    }
  }
  else
  {
    if ( !v5 )
      return result;
    v7 = this->m_minimumPointsPerturbationThreshold;
    v8 = this->m_numPerturbationIterations;
    *v5 = &btCollisionAlgorithm::`vftable';
    v9 = ci->m_dispatcher1;
    v5[5] = v8;
    v5[6] = v7;
    v5[1] = v9;
    *v5 = &btConvexPlaneCollisionAlgorithm::`vftable';
    *((_BYTE *)v5 + 8) = 0;
    v5[3] = 0;
    *((_BYTE *)v5 + 16) = 0;
    if ( v9->needsCollision(v9, body0, body1) )
    {
      v5[3] = (*(int (__thiscall **)(_DWORD, btCollisionObject *, btCollisionObject *))(*(_DWORD *)v5[1] + 8))(
                v5[1],
                body0,
                body1);
      *((_BYTE *)v5 + 8) = 1;
      return (btCollisionAlgorithm *)v5;
    }
  }
  return (btCollisionAlgorithm *)v5;
}
