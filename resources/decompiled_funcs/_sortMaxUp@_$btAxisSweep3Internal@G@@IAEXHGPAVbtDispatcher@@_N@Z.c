void __userpurge btAxisSweep3Internal<unsigned short>::sortMaxUp(
        unsigned __int16 edge@<cx>,
        btAxisSweep3Internal<unsigned short> *this,
        int axis,
        btDispatcher *__formal,
        bool updateOverlaps)
{
  btAxisSweep3Internal<unsigned short> *v5; // eax
  btAxisSweep3Internal<unsigned short>::Edge *v6; // ecx
  btAxisSweep3Internal<unsigned short>::Edge *v7; // ebx
  int v8; // ebp
  char *v9; // esi
  int v10; // eax
  int v11; // edx
  btAxisSweep3Internal<unsigned short>::Handle *v12; // ecx
  btAxisSweep3Internal<unsigned short>::Handle *m_pHandles; // eax
  btBroadphaseProxy *v14; // ebp
  btBroadphaseProxy *v15; // edi
  int v16; // eax
  btAxisSweep3Internal<unsigned short>::Edge v17; // ecx
  btAxisSweep3Internal<unsigned short>::Handle *pHandleEdge; // [esp+10h] [ebp-8h]
  btAxisSweep3Internal<unsigned short>::Edge *pEdge; // [esp+14h] [ebp-4h]

  v5 = this;
  v6 = &this->m_pEdges[axis][edge];
  v7 = v6 + 1;
  pEdge = v6;
  pHandleEdge = &this->m_pHandles[v6->m_handle];
  if ( v6[1].m_handle )
  {
    while ( v6->m_pos >= v7->m_pos )
    {
      v8 = v7->m_handle << 6;
      v9 = (char *)v5->m_pHandles + v8;
      v10 = (1 << axis) & 3;
      v11 = (1 << ((1 << axis) & 3)) & 3;
      if ( (v7->m_pos & 1) != 0 )
      {
        v16 = axis;
        --*(_WORD *)&v9[2 * axis + 54];
        v12 = pHandleEdge;
      }
      else
      {
        v12 = pHandleEdge;
        if ( (_BYTE)__formal
          && pHandleEdge->m_maxEdges[v10] >= *(_WORD *)&v9[2 * v10 + 48]
          && *(_WORD *)&v9[2 * v10 + 54] >= pHandleEdge->m_minEdges[v10]
          && pHandleEdge->m_maxEdges[v11] >= *(_WORD *)&v9[2 * v11 + 48]
          && *(_WORD *)&v9[2 * v11 + 54] >= pHandleEdge->m_minEdges[v11] )
        {
          m_pHandles = this->m_pHandles;
          v14 = (btAxisSweep3Internal<unsigned short>::Handle *)((char *)m_pHandles + v8);
          v15 = &m_pHandles[pEdge->m_handle];
          this->m_pairCache->addOverlappingPair(this->m_pairCache, v15, v14);
          if ( this->m_userPairCallback )
            this->m_userPairCallback->addOverlappingPair(this->m_userPairCallback, v15, v14);
          v12 = pHandleEdge;
        }
        v16 = axis;
        --*(_WORD *)&v9[2 * axis + 48];
      }
      ++v12->m_maxEdges[v16];
      v17 = *pEdge;
      *pEdge = *v7;
      *v7++ = v17;
      ++pEdge;
      if ( !v7->m_handle )
        break;
      v6 = pEdge;
      v5 = this;
    }
  }
}
