void __userpurge btAxisSweep3Internal<unsigned short>::updateHandle(
        unsigned __int16 handle@<ax>,
        const btVector3 *aabbMin@<edx>,
        btAxisSweep3Internal<unsigned short> *this,
        const btVector3 *aabbMax,
        btDispatcher *dispatcher)
{
  btAxisSweep3Internal<unsigned short>::Handle *v5; // edi
  int v6; // esi
  unsigned __int16 *m_maxEdges; // eax
  int v8; // edi
  int v9; // eax
  int v10; // ebx
  bool v11; // [esp+0h] [ebp-30h]
  btAxisSweep3Internal<unsigned short>::Edge **m_pEdges; // [esp+10h] [ebp-20h]
  unsigned __int16 emin; // [esp+14h] [ebp-1Ch]
  unsigned __int16 emax; // [esp+18h] [ebp-18h]
  unsigned __int16 *v15; // [esp+1Ch] [ebp-14h]
  unsigned __int16 min[4]; // [esp+20h] [ebp-10h] BYREF
  unsigned __int16 max[4]; // [esp+28h] [ebp-8h] BYREF

  v5 = &this->m_pHandles[handle];
  btAxisSweep3Internal<unsigned short>::quantize(this, min, aabbMin, 0);
  btAxisSweep3Internal<unsigned short>::quantize(this, max, aabbMax, 1);
  v6 = 0;
  m_maxEdges = v5->m_maxEdges;
  m_pEdges = this->m_pEdges;
  v15 = v5->m_maxEdges;
  do
  {
    emin = *(m_maxEdges - 3);
    emax = *m_maxEdges;
    v8 = min[v6] - (*m_pEdges)[emin].m_pos;
    v9 = *m_maxEdges;
    v10 = max[v6] - (*m_pEdges)[v9].m_pos;
    (*m_pEdges)[emin].m_pos = min[v6];
    (*m_pEdges)[v9].m_pos = max[v6];
    if ( v8 < 0 )
      btAxisSweep3Internal<unsigned short>::sortMinDown(this, v6, emin, (btDispatcher *)1, v11);
    if ( v10 > 0 )
      btAxisSweep3Internal<unsigned short>::sortMaxUp(this, v6, emax, (btDispatcher *)1, v11);
    if ( v8 > 0 )
      btAxisSweep3Internal<unsigned short>::sortMinUp(this, v6, emin, dispatcher, 1);
    if ( v10 < 0 )
      btAxisSweep3Internal<unsigned short>::sortMaxDown(this, v6, emax, dispatcher, 1);
    ++m_pEdges;
    ++v6;
    m_maxEdges = ++v15;
  }
  while ( v6 < 3 );
}
