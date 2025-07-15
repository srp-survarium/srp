void __userpurge btAxisSweep3Internal<unsigned short>::sortMinDown(
        unsigned __int16 edge@<ax>,
        btAxisSweep3Internal<unsigned short> *this,
        int axis,
        btDispatcher *__formal,
        bool updateOverlaps)
{
  btAxisSweep3Internal<unsigned short> *v5; // edx
  int v6; // ecx
  btAxisSweep3Internal<unsigned short>::Edge *v7; // edi
  btAxisSweep3Internal<unsigned short>::Handle *v8; // esi
  btAxisSweep3Internal<unsigned short>::Edge *v9; // ebx
  int v10; // eax
  unsigned __int16 *v12; // eax
  btAxisSweep3Internal<unsigned short>::Edge v13; // eax
  btAxisSweep3Internal<unsigned short>::Handle *pHandleB; // [esp+Ch] [ebp-4h]

  v5 = this;
  v6 = axis;
  v7 = &this->m_pEdges[axis][edge];
  v8 = &this->m_pHandles[v7->m_handle];
  v9 = v7 - 1;
  if ( v7->m_pos < v7[-1].m_pos )
  {
    while ( 1 )
    {
      pHandleB = &v5->m_pHandles[v9->m_handle];
      if ( (v9->m_pos & 1) != 0 )
      {
        v10 = (1 << v6) & 3;
        if ( (_BYTE)__formal )
        {
          if ( v8->m_maxEdges[v10] >= pHandleB->m_minEdges[v10]
            && btAxisSweep3Internal<unsigned short>::testOverlap2D(v8, v10, (1 << v10) & 3, pHandleB) )
          {
            this->m_pairCache->addOverlappingPair(this->m_pairCache, v8, pHandleB);
            if ( this->m_userPairCallback )
              this->m_userPairCallback->addOverlappingPair(this->m_userPairCallback, v8, pHandleB);
          }
          v6 = axis;
        }
        v12 = &pHandleB->m_maxEdges[v6];
      }
      else
      {
        v12 = &v5->m_pHandles[v9->m_handle].m_minEdges[v6];
      }
      ++*v12;
      --v8->m_minEdges[v6];
      v13 = *v7;
      *v7 = *v9;
      *v9 = v13;
      --v7;
      --v9;
      if ( v7->m_pos >= v9->m_pos )
        break;
      v5 = this;
    }
  }
}
