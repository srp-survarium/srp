unsigned __int16 __userpurge btAxisSweep3Internal<unsigned short>::addHandle@<ax>(
        btAxisSweep3Internal<unsigned short> *this@<ecx>,
        btAxisSweep3Internal<unsigned short> *a2@<edi>,
        const btVector3 *aabbMin,
        btVector3 *aabbMax,
        void *pOwner,
        __int16 collisionFilterGroup,
        btDispatcher *collisionFilterMask,
        btDispatcher *dispatcher,
        void *multiSapProxy)
{
  btAxisSweep3Internal<unsigned short>::Handle *v9; // esi
  unsigned __int16 v10; // cx
  int v11; // ecx
  btAxisSweep3Internal<unsigned short>::Edge **m_pEdges; // eax
  int v13; // edx
  unsigned __int16 *v14; // edx
  bool v15; // zf
  bool v17; // [esp+0h] [ebp-28h]
  bool v18; // [esp+0h] [ebp-28h]
  bool v19; // [esp+0h] [ebp-28h]
  int v20; // [esp+8h] [ebp-20h]
  unsigned __int16 m_firstFreeHandle; // [esp+Ch] [ebp-1Ch]
  unsigned __int16 v22; // [esp+10h] [ebp-18h]
  int v23; // [esp+14h] [ebp-14h]
  unsigned __int16 out[4]; // [esp+18h] [ebp-10h] BYREF
  unsigned __int16 v25[4]; // [esp+20h] [ebp-8h] BYREF

  btAxisSweep3Internal<unsigned short>::quantize(out, (const btVector3 *)this, 0, a2);
  btAxisSweep3Internal<unsigned short>::quantize(v25, aabbMin, 1u, a2);
  m_firstFreeHandle = a2->m_firstFreeHandle;
  v9 = &a2->m_pHandles[m_firstFreeHandle];
  v10 = v9->m_minEdges[0];
  ++a2->m_numHandles;
  a2->m_firstFreeHandle = v10;
  v9->m_uniqueId = m_firstFreeHandle;
  v9->m_clientObject = aabbMax;
  v9->m_collisionFilterGroup = (__int16)pOwner;
  v9->m_collisionFilterMask = collisionFilterGroup;
  v9->m_multiSapParentProxy = dispatcher;
  v22 = 2 * a2->m_numHandles;
  v11 = v22;
  v20 = 0;
  m_pEdges = a2->m_pEdges;
  v23 = 3;
  do
  {
    a2->m_pHandles->m_maxEdges[v20] += 2;
    (*m_pEdges)[v11 + 1] = (*m_pEdges)[v11 - 1];
    (*m_pEdges)[v11 - 1].m_pos = out[v20];
    (*m_pEdges)[v11 - 1].m_handle = m_firstFreeHandle;
    (*m_pEdges)[v11].m_pos = v25[v20];
    (*m_pEdges)[v11].m_handle = m_firstFreeHandle;
    v13 = v20 * 2;
    ++v20;
    v14 = (unsigned __int16 *)((char *)v9->m_maxEdges + v13);
    *(v14 - 3) = v22 - 1;
    ++m_pEdges;
    v15 = v23-- == 1;
    *v14 = v22;
  }
  while ( !v15 );
  btAxisSweep3Internal<unsigned short>::sortMinDown(v9->m_minEdges[0], a2, 0, 0, v17);
  btAxisSweep3Internal<unsigned short>::sortMaxDown(v9->m_maxEdges[0], a2, 0, collisionFilterMask, 0);
  btAxisSweep3Internal<unsigned short>::sortMinDown(v9->m_minEdges[1], a2, 1, 0, v18);
  btAxisSweep3Internal<unsigned short>::sortMaxDown(v9->m_maxEdges[1], a2, 1, collisionFilterMask, 0);
  btAxisSweep3Internal<unsigned short>::sortMinDown(v9->m_minEdges[2], a2, 2, (btDispatcher *)1, v19);
  btAxisSweep3Internal<unsigned short>::sortMaxDown(v9->m_maxEdges[2], a2, 2, collisionFilterMask, 1);
  return m_firstFreeHandle;
}
