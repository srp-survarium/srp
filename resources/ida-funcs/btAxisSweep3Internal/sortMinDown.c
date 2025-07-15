void __userpurge btAxisSweep3Internal<unsigned short>::sortMinDown(
        unsigned __int16 edge@<ax>,
        btAxisSweep3Internal<unsigned short> *this,
        btAxisSweep3Internal<unsigned short>::Edge *axis,
        btDispatcher *__formal,
        bool updateOverlaps)
{
  btAxisSweep3Internal<unsigned short> *v5; // edx
  btAxisSweep3Internal<unsigned short>::Edge *v7; // eax
  btAxisSweep3Internal<unsigned short>::Handle *v8; // edi
  btAxisSweep3Internal<unsigned short>::Edge *v9; // ebp
  btBroadphaseProxy *v10; // esi
  int v11; // eax
  int v12; // edx
  btAxisSweep3Internal<unsigned short>::Edge v13; // ecx
  btAxisSweep3Internal<unsigned short>::Edge *pEdge; // [esp+14h] [ebp+8h]

  v5 = this;
  v7 = &this->m_pEdges[(_DWORD)axis][edge];
  v8 = &this->m_pHandles[v7->m_handle];
  v9 = v7 - 1;
  for ( pEdge = v7; v7->m_pos < v9->m_pos; pEdge = v7 )
  {
    v10 = &v5->m_pHandles[v9->m_handle];
    if ( (v9->m_pos & 1) != 0 )
    {
      v11 = (1 << (char)axis) & 3;
      v12 = (1 << ((1 << (char)axis) & 3)) & 3;
      if ( (_BYTE)__formal
        && v8->m_maxEdges[v11] >= *((_WORD *)&v10[1].m_clientObject + v11)
        && (unsigned int)*(&v10[1].m_collisionFilterMask + v11) >= v8->m_minEdges[v11]
        && v8->m_maxEdges[v12] >= *((_WORD *)&v10[1].m_clientObject + v12)
        && (unsigned int)*(&v10[1].m_collisionFilterMask + v12) >= v8->m_minEdges[v12] )
      {
        this->m_pairCache->addOverlappingPair(this->m_pairCache, v8, v10);
        if ( this->m_userPairCallback )
          this->m_userPairCallback->addOverlappingPair(this->m_userPairCallback, v8, v10);
      }
      ++*(&v10[1].m_collisionFilterMask + (_DWORD)axis);
      v5 = this;
      v7 = pEdge;
    }
    else
    {
      ++*((_WORD *)&v10[1].m_clientObject + (_DWORD)axis);
    }
    --v8->m_minEdges[(_DWORD)axis];
    v13 = *v7;
    *v7-- = *v9;
    *v9-- = v13;
  }
}
