void __userpurge btAxisSweep3Internal<unsigned short>::removeHandle(
        btAxisSweep3Internal<unsigned short> *this@<ecx>,
        btAxisSweep3Internal<unsigned short> *a2@<esi>,
        unsigned __int16 handle,
        btDispatcher *dispatcher)
{
  char *v4; // ebp
  int m_numHandles; // eax
  int v6; // ebx
  unsigned __int16 *v7; // ebp
  btAxisSweep3Internal<unsigned short>::Edge *v8; // edi
  unsigned __int16 v9; // cx
  unsigned __int16 v10; // ax
  bool v11; // [esp+0h] [ebp-1Ch]
  btAxisSweep3Internal<unsigned short>::Edge **m_pEdges; // [esp+Ch] [ebp-10h]
  int v13; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]

  v15 = handle << 6;
  v4 = (char *)a2->m_pHandles + v15;
  if ( !a2->m_pairCache->hasDeferredRemoval(a2->m_pairCache) )
    a2->m_pairCache->removeOverlappingPairsContainingProxy(a2->m_pairCache, (btBroadphaseProxy *)v4, dispatcher);
  m_numHandles = a2->m_numHandles;
  a2->m_pHandles->m_maxEdges[0] -= 2;
  a2->m_pHandles->m_maxEdges[1] -= 2;
  a2->m_pHandles->m_maxEdges[2] -= 2;
  m_numHandles *= 2;
  v6 = 0;
  v13 = 4 * m_numHandles - 2;
  v14 = 4 * m_numHandles - 4;
  v7 = (unsigned __int16 *)(v4 + 48);
  m_pEdges = a2->m_pEdges;
  do
  {
    v8 = *m_pEdges;
    v9 = v7[3];
    (*m_pEdges)[v9].m_pos = a2->m_handleSentinel;
    btAxisSweep3Internal<unsigned short>::sortMaxUp(a2, v6, v9, 0, v11);
    v10 = *v7;
    v8[v10].m_pos = a2->m_handleSentinel;
    btAxisSweep3Internal<unsigned short>::sortMinUp(a2, v6, v10, dispatcher, 0);
    ++m_pEdges;
    *(unsigned __int16 *)((char *)&v8->m_pos + v13) = 0;
    ++v6;
    ++v7;
    *(unsigned __int16 *)((char *)&v8->m_pos + v14) = a2->m_handleSentinel;
  }
  while ( v6 < 3 );
  *(unsigned __int16 *)((char *)a2->m_pHandles->m_minEdges + v15) = a2->m_firstFreeHandle;
  --a2->m_numHandles;
  a2->m_firstFreeHandle = handle;
}
