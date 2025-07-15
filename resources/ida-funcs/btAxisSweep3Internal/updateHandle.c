void __userpurge btAxisSweep3Internal<unsigned short>::updateHandle(
        unsigned __int16 handle@<ax>,
        const btVector3 *aabbMin@<ecx>,
        btAxisSweep3Internal<unsigned short> *this,
        const btVector3 *aabbMax,
        btDispatcher *dispatcher)
{
  btAxisSweep3Internal<unsigned short>::Handle *v5; // edi
  unsigned __int16 *m_maxEdges; // edi
  unsigned __int16 v7; // bx
  btAxisSweep3Internal<unsigned short>::Edge *v8; // ecx
  int v9; // esi
  int v10; // edx
  int v11; // edi
  bool v12; // [esp+0h] [ebp-38h]
  int axis; // [esp+10h] [ebp-28h]
  btAxisSweep3Internal<unsigned short>::Edge **m_pEdges; // [esp+14h] [ebp-24h]
  unsigned __int16 v15; // [esp+18h] [ebp-20h]
  unsigned __int16 *i; // [esp+1Ch] [ebp-1Ch]
  unsigned __int16 edge; // [esp+20h] [ebp-18h]
  unsigned __int16 v18; // [esp+24h] [ebp-14h]
  unsigned __int16 out[4]; // [esp+28h] [ebp-10h] BYREF
  unsigned __int16 v20[4]; // [esp+30h] [ebp-8h] BYREF

  v5 = &this->m_pHandles[handle];
  btAxisSweep3Internal<unsigned short>::quantize(out, aabbMin, 0, this);
  btAxisSweep3Internal<unsigned short>::quantize(v20, aabbMax, 1u, this);
  axis = 0;
  m_maxEdges = v5->m_maxEdges;
  m_pEdges = this->m_pEdges;
  for ( i = m_maxEdges; ; m_maxEdges = i )
  {
    v15 = *m_maxEdges;
    v7 = out[axis];
    edge = *(m_maxEdges - 3);
    v8 = &(*m_pEdges)[edge];
    v9 = v7 - v8->m_pos;
    v10 = *m_maxEdges;
    v18 = v20[axis];
    v11 = v18 - (*m_pEdges)[v10].m_pos;
    v8->m_pos = v7;
    (*m_pEdges)[v10].m_pos = v18;
    if ( v9 < 0 )
      btAxisSweep3Internal<unsigned short>::sortMinDown(edge, this, axis, (btDispatcher *)1, v12);
    if ( v11 > 0 )
      btAxisSweep3Internal<unsigned short>::sortMaxUp(v15, this, axis, (btDispatcher *)1, v12);
    if ( v9 > 0 )
      btAxisSweep3Internal<unsigned short>::sortMinUp(edge, this, axis, dispatcher, 1);
    if ( v11 < 0 )
      btAxisSweep3Internal<unsigned short>::sortMaxDown(v15, this, axis, dispatcher, 1);
    ++axis;
    ++m_pEdges;
    ++i;
    if ( axis >= 3 )
      break;
  }
}
