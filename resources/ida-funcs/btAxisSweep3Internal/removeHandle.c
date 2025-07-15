void __userpurge btAxisSweep3Internal<unsigned short>::removeHandle(
        btAxisSweep3Internal<unsigned short> *this@<ecx>,
        btAxisSweep3Internal<unsigned short> *a2@<esi>,
        unsigned __int16 handle,
        btDispatcher *dispatcher)
{
  btBroadphaseProxy *v4; // ebx
  int v5; // eax
  int i; // edx
  unsigned __int16 *v7; // ebx
  btAxisSweep3Internal<unsigned short>::Edge *v8; // edi
  unsigned __int16 v9; // ax
  unsigned __int16 v10; // ax
  bool v11; // [esp+0h] [ebp-18h]
  int v12; // [esp+8h] [ebp-10h]
  int v13; // [esp+Ch] [ebp-Ch]
  btAxisSweep3Internal<unsigned short>::Edge **m_pEdges; // [esp+10h] [ebp-8h]
  int axis; // [esp+14h] [ebp-4h]

  v12 = handle << 6;
  v4 = (btAxisSweep3Internal<unsigned short>::Handle *)((char *)a2->m_pHandles + v12);
  if ( !a2->m_pairCache->hasDeferredRemoval(a2->m_pairCache) )
    a2->m_pairCache->removeOverlappingPairsContainingProxy(a2->m_pairCache, v4, dispatcher);
  v5 = 2 * a2->m_numHandles;
  for ( i = 54; i < 60; i += 2 )
    *(_WORD *)((char *)&a2->m_pHandles->m_clientObject + i) -= 2;
  axis = 0;
  v13 = v5;
  v7 = (unsigned __int16 *)&v4[1];
  m_pEdges = a2->m_pEdges;
  do
  {
    v8 = *m_pEdges;
    v9 = v7[3];
    (*m_pEdges)[v9].m_pos = a2->m_handleSentinel;
    btAxisSweep3Internal<unsigned short>::sortMaxUp(v9, a2, axis, 0, v11);
    v10 = *v7;
    v8[v10].m_pos = a2->m_handleSentinel;
    btAxisSweep3Internal<unsigned short>::sortMinUp(v10, a2, axis, dispatcher, 0);
    ++m_pEdges;
    ++axis;
    v8[v13 - 1].m_handle = 0;
    ++v7;
    v8[v13 - 1].m_pos = a2->m_handleSentinel;
  }
  while ( axis < 3 );
  *(unsigned __int16 *)((char *)a2->m_pHandles->m_minEdges + v12) = a2->m_firstFreeHandle;
  a2->m_firstFreeHandle = handle;
  --a2->m_numHandles;
}
