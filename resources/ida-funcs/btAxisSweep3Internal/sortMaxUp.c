void __userpurge btAxisSweep3Internal<unsigned short>::sortMaxUp(
        unsigned __int16 edge@<ax>,
        btAxisSweep3Internal<unsigned short> *this,
        int axis,
        btDispatcher *__formal,
        bool updateOverlaps)
{
  int v5; // ecx
  btAxisSweep3Internal<unsigned short> *v6; // esi
  btAxisSweep3Internal<unsigned short>::Edge *v7; // ebx
  btAxisSweep3Internal<unsigned short>::Edge *v8; // edi
  const btAxisSweep3Internal<unsigned short>::Handle *v9; // edx
  int v10; // eax
  bool v11; // al
  btAxisSweep3Internal<unsigned short>::Handle *m_pHandles; // ecx
  unsigned __int16 *v13; // edx
  btAxisSweep3Internal<unsigned short>::Edge v14; // eax
  btBroadphaseProxy *v15; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  btBroadphaseProxy *v17; // [esp+10h] [ebp-Ch]
  btAxisSweep3Internal<unsigned short>::Handle *pHandleA; // [esp+14h] [ebp-8h]
  const btAxisSweep3Internal<unsigned short>::Handle *v19; // [esp+18h] [ebp-4h]

  LOBYTE(v5) = axis;
  v6 = this;
  v7 = &this->m_pEdges[axis][edge];
  v8 = v7 + 1;
  pHandleA = &this->m_pHandles[v7->m_handle];
  while ( v8->m_handle && v7->m_pos >= v8->m_pos )
  {
    v9 = &v6->m_pHandles[v8->m_handle];
    v16 = v8->m_handle << 6;
    v10 = (1 << v5) & 3;
    v19 = v9;
    if ( (v8->m_pos & 1) != 0 )
    {
      v5 = axis;
      v13 = &v9->m_maxEdges[axis];
    }
    else
    {
      if ( (_BYTE)__formal )
      {
        if ( pHandleA->m_maxEdges[v10] < v9->m_minEdges[v10] )
        {
          v11 = 0;
        }
        else
        {
          v11 = btAxisSweep3Internal<unsigned short>::testOverlap2D(pHandleA, v10, (1 << v10) & 3, v9);
          v6 = this;
          v9 = v19;
        }
        if ( v11 )
        {
          m_pHandles = v6->m_pHandles;
          v17 = (btAxisSweep3Internal<unsigned short>::Handle *)((char *)m_pHandles + v16);
          v15 = &m_pHandles[v7->m_handle];
          v6->m_pairCache->addOverlappingPair(v6->m_pairCache, v15, v17);
          if ( v6->m_userPairCallback )
            v6->m_userPairCallback->addOverlappingPair(v6->m_userPairCallback, v15, v17);
          v9 = v19;
        }
      }
      v5 = axis;
      v13 = &v9->m_minEdges[axis];
    }
    --*v13;
    ++pHandleA->m_maxEdges[v5];
    v14 = *v7;
    *v7 = *v8;
    *v8 = v14;
    ++v7;
    ++v8;
  }
}
