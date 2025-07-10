void __userpurge btAxisSweep3Internal<unsigned short>::sortMaxDown(
        unsigned __int16 edge@<ax>,
        btAxisSweep3Internal<unsigned short> *this,
        int axis,
        btDispatcher *dispatcher,
        bool updateOverlaps)
{
  int v5; // edx
  btAxisSweep3Internal<unsigned short>::Edge *v7; // edi
  btAxisSweep3Internal<unsigned short>::Handle *v8; // esi
  btAxisSweep3Internal<unsigned short>::Edge *v9; // eax
  int v10; // ecx
  btAxisSweep3Internal<unsigned short>::Handle *m_pHandles; // eax
  btBroadphaseProxy *v12; // ebp
  btBroadphaseProxy *v13; // esi
  int v14; // eax
  int v15; // edx
  btAxisSweep3Internal<unsigned short>::Edge v16; // ecx
  btAxisSweep3Internal<unsigned short>::Handle *pHandlePrev; // [esp+18h] [ebp-8h]
  btAxisSweep3Internal<unsigned short>::Handle *pHandleEdge; // [esp+1Ch] [ebp-4h]
  btAxisSweep3Internal<unsigned short>::Edge *pPrev; // [esp+24h] [ebp+4h]

  v5 = axis;
  v7 = &this->m_pEdges[axis][edge];
  v8 = &this->m_pHandles[v7->m_handle];
  v9 = v7 - 1;
  pPrev = v7 - 1;
  pHandleEdge = v8;
  if ( v7->m_pos < v7[-1].m_pos )
  {
    do
    {
      v10 = v9->m_handle << 6;
      pHandlePrev = (btAxisSweep3Internal<unsigned short>::Handle *)((char *)this->m_pHandles + v10);
      if ( (v9->m_pos & 1) != 0 )
      {
        ++*(unsigned __int16 *)((char *)&this->m_pHandles->m_maxEdges[v5] + v10);
      }
      else
      {
        m_pHandles = this->m_pHandles;
        v12 = (btAxisSweep3Internal<unsigned short>::Handle *)((char *)m_pHandles + v10);
        v13 = &m_pHandles[v7->m_handle];
        v14 = (1 << v5) & 3;
        v15 = (1 << v14) & 3;
        if ( updateOverlaps
          && *(&v13[1].m_collisionFilterMask + v14) >= *((_WORD *)&v12[1].m_clientObject + v14)
          && *(&v12[1].m_collisionFilterMask + v14) >= *((_WORD *)&v13[1].m_clientObject + v14)
          && *(&v13[1].m_collisionFilterMask + v15) >= *((_WORD *)&v12[1].m_clientObject + v15)
          && *(&v12[1].m_collisionFilterMask + v15) >= *((_WORD *)&v13[1].m_clientObject + v15) )
        {
          this->m_pairCache->removeOverlappingPair(this->m_pairCache, v13, v12, dispatcher);
          if ( this->m_userPairCallback )
            this->m_userPairCallback->removeOverlappingPair(this->m_userPairCallback, v13, v12, dispatcher);
        }
        ++pHandlePrev->m_minEdges[axis];
        v9 = pPrev;
        v8 = pHandleEdge;
        v5 = axis;
      }
      --v8->m_maxEdges[v5];
      v16 = *v7;
      *v7 = *v9;
      *v9 = v16;
      v16.m_pos = v7[-1].m_pos;
      --v7;
      pPrev = --v9;
    }
    while ( v16.m_pos < v9->m_pos );
  }
}
