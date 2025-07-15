void __thiscall btAxisSweep3Internal<unsigned short>::rayTest(
        btAxisSweep3Internal<unsigned short> *this,
        const btVector3 *rayFrom,
        const btVector3 *rayTo,
        btBroadphaseRayCallback *rayCallback,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax)
{
  int v7; // edi
  int v8; // eax
  btAxisSweep3Internal<unsigned short>::Edge *v9; // ecx
  bool v10; // zf
  btAxisSweep3Internal<unsigned short>::Edge *v11; // eax

  if ( this->m_raycastAccelerator )
  {
    this->m_raycastAccelerator->rayTest(this->m_raycastAccelerator, rayFrom, rayTo, rayCallback, aabbMin, aabbMax);
  }
  else
  {
    v7 = 1;
    if ( 2 * this->m_numHandles + 1 > 1 )
    {
      v8 = 1;
      do
      {
        v9 = this->m_pEdges[0];
        v10 = (v9[v8].m_pos & 1) == 0;
        v11 = &v9[v8];
        if ( !v10 )
          rayCallback->process(rayCallback, &this->m_pHandles[v11->m_handle]);
        v8 = (unsigned __int16)++v7;
      }
      while ( (unsigned __int16)v7 < 2 * this->m_numHandles + 1 );
    }
  }
}
