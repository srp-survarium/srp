btCollisionAlgorithm *__thiscall btSoftBodyConcaveCollisionAlgorithm::SwappedCreateFunc::CreateCollisionAlgorithm(
        btSoftBodyConcaveCollisionAlgorithm::SwappedCreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  _DWORD *v4; // esi
  btCollisionAlgorithm *result; // eax
  btDispatcher *m_dispatcher1; // ecx

  v4 = ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 176);
  result = 0;
  if ( v4 )
  {
    *v4 = &btCollisionAlgorithm::`vftable';
    m_dispatcher1 = ci->m_dispatcher1;
    v4[1] = ci->m_dispatcher1;
    *v4 = &btSoftBodyConcaveCollisionAlgorithm::`vftable';
    LOBYTE(m_dispatcher1) = 1;
    *((_BYTE *)v4 + 8) = 1;
    v4[17] = ci->m_dispatcher1;
    v4[18] = 0;
    v4[4] = &btSoftBodyTriangleCallback::`vftable';
    v4[23] = 0;
    v4[21] = 0;
    v4[22] = 0;
    *((_BYTE *)v4 + 96) = 1;
    v4[28] = 0;
    v4[26] = 0;
    v4[27] = 0;
    *((_BYTE *)v4 + 116) = 1;
    v4[33] = 0;
    v4[31] = 0;
    v4[32] = 0;
    *((_BYTE *)v4 + 136) = 1;
    v4[38] = 0;
    v4[36] = 0;
    v4[37] = 0;
    *((_BYTE *)v4 + 156) = 1;
    v4[5] = body1;
    v4[6] = body0;
    btSoftBodyTriangleCallback::clearCache((btSoftBodyTriangleCallback *)m_dispatcher1);
    return (btCollisionAlgorithm *)v4;
  }
  return result;
}
