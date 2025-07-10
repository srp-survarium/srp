unsigned __int16 __userpurge btAxisSweep3Internal<unsigned short>::addHandle@<ax>(
        btAxisSweep3Internal<unsigned short> *this@<edi>,
        const btVector3 *aabbMin@<edx>,
        const btVector3 *aabbMax,
        void *pOwner,
        __int16 collisionFilterGroup,
        __int16 collisionFilterMask,
        btDispatcher *dispatcher,
        void *multiSapProxy)
{
  btAxisSweep3Internal<unsigned short>::Handle *v8; // esi
  unsigned __int16 v9; // cx
  int v10; // eax
  int v11; // edx
  btAxisSweep3Internal<unsigned short>::Edge **m_pEdges; // ecx
  bool v13; // zf
  bool v15; // [esp+0h] [ebp-28h]
  bool v16; // [esp+0h] [ebp-28h]
  bool v17; // [esp+0h] [ebp-28h]
  int v18; // [esp+8h] [ebp-20h]
  unsigned __int16 m_firstFreeHandle; // [esp+Ch] [ebp-1Ch]
  unsigned __int16 limit; // [esp+10h] [ebp-18h]
  int v21; // [esp+14h] [ebp-14h]
  unsigned __int16 min[4]; // [esp+18h] [ebp-10h] BYREF
  unsigned __int16 max[4]; // [esp+20h] [ebp-8h] BYREF

  btAxisSweep3Internal<unsigned short>::quantize(this, min, aabbMin, 0);
  btAxisSweep3Internal<unsigned short>::quantize(this, max, aabbMax, 1);
  m_firstFreeHandle = this->m_firstFreeHandle;
  v8 = &this->m_pHandles[m_firstFreeHandle];
  v9 = v8->m_minEdges[0];
  ++this->m_numHandles;
  this->m_firstFreeHandle = v9;
  v8->m_uniqueId = m_firstFreeHandle;
  v8->m_clientObject = pOwner;
  v8->m_collisionFilterGroup = collisionFilterGroup;
  v8->m_collisionFilterMask = collisionFilterMask;
  v8->m_multiSapParentProxy = multiSapProxy;
  limit = 2 * this->m_numHandles;
  v10 = limit;
  v11 = 0;
  m_pEdges = this->m_pEdges;
  v18 = 0;
  v21 = 3;
  do
  {
    *(unsigned __int16 *)((char *)this->m_pHandles->m_maxEdges + v11) += 2;
    (*m_pEdges)[v10 + 1] = (*m_pEdges)[v10 - 1];
    (*m_pEdges)[v10 - 1].m_pos = min[v18];
    (*m_pEdges)[v10 - 1].m_handle = m_firstFreeHandle;
    (*m_pEdges)[v10].m_pos = max[v18];
    (*m_pEdges)[v10].m_handle = m_firstFreeHandle;
    v8->m_minEdges[v18] = limit - 1;
    v8->m_maxEdges[v18] = limit;
    v11 = v18 * 2 + 2;
    ++m_pEdges;
    v13 = v21-- == 1;
    ++v18;
  }
  while ( !v13 );
  btAxisSweep3Internal<unsigned short>::sortMinDown(this, 0, v8->m_minEdges[0], 0, v15);
  btAxisSweep3Internal<unsigned short>::sortMaxDown(this, 0, v8->m_maxEdges[0], dispatcher, 0);
  btAxisSweep3Internal<unsigned short>::sortMinDown(this, 1, v8->m_minEdges[1], 0, v16);
  btAxisSweep3Internal<unsigned short>::sortMaxDown(this, 1, v8->m_maxEdges[1], dispatcher, 0);
  btAxisSweep3Internal<unsigned short>::sortMinDown(this, 2, v8->m_minEdges[2], (btDispatcher *)1, v17);
  btAxisSweep3Internal<unsigned short>::sortMaxDown(this, 2, v8->m_maxEdges[2], dispatcher, 1);
  return m_firstFreeHandle;
}
