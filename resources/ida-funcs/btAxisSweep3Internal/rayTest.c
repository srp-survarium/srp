void __thiscall btAxisSweep3Internal<unsigned short>::rayTest(
        btAxisSweep3Internal<unsigned short> *this,
        const btVector3 *rayFrom,
        const btVector3 *rayTo,
        btBroadphaseRayCallback *rayCallback,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax)
{
  int v7; // eax
  btAxisSweep3Internal<unsigned short>::Edge *v8; // eax
  unsigned __int16 v9; // [esp+1Ch] [ebp+18h]

  if ( this->m_raycastAccelerator )
  {
    this->m_raycastAccelerator->rayTest(this->m_raycastAccelerator, rayFrom, rayTo, rayCallback, aabbMin, aabbMax);
  }
  else
  {
    v9 = 1;
    if ( 2 * this->m_numHandles + 1 > 1 )
    {
      v7 = 1;
      do
      {
        v8 = &this->m_pEdges[0][v7];
        if ( (v8->m_pos & 1) != 0 )
          rayCallback->process(rayCallback, &this->m_pHandles[v8->m_handle]);
        v7 = ++v9;
      }
      while ( v9 < 2 * this->m_numHandles + 1 );
    }
  }
}
