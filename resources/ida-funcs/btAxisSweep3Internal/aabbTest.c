void __thiscall btAxisSweep3Internal<unsigned short>::aabbTest(
        btAxisSweep3Internal<unsigned short> *this,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax,
        btBroadphaseAabbCallback *callback)
{
  int v5; // eax
  btAxisSweep3Internal<unsigned short>::Edge *v6; // eax
  btAxisSweep3Internal<unsigned short>::Handle *v7; // eax
  char v8; // cl
  int v9; // [esp+4h] [ebp-4h]

  if ( this->m_raycastAccelerator )
  {
    this->m_raycastAccelerator->aabbTest(this->m_raycastAccelerator, aabbMin, aabbMax, callback);
  }
  else
  {
    v5 = 1;
    v9 = 1;
    if ( 2 * this->m_numHandles + 1 > 1 )
    {
      do
      {
        v6 = &this->m_pEdges[0][v5];
        if ( (v6->m_pos & 1) != 0 )
        {
          v7 = &this->m_pHandles[v6->m_handle];
          v8 = 1;
          if ( aabbMin->mVec128.m128_f32[0] > v7->m_aabbMax.mVec128.m128_f32[0]
            || v7->m_aabbMin.mVec128.m128_f32[0] > aabbMax->mVec128.m128_f32[0] )
          {
            v8 = 0;
          }
          if ( aabbMin->mVec128.m128_f32[2] > v7->m_aabbMax.mVec128.m128_f32[2]
            || v7->m_aabbMin.mVec128.m128_f32[2] > aabbMax->mVec128.m128_f32[2] )
          {
            v8 = 0;
          }
          if ( aabbMin->mVec128.m128_f32[1] > v7->m_aabbMax.mVec128.m128_f32[1]
            || v7->m_aabbMin.mVec128.m128_f32[1] > aabbMax->mVec128.m128_f32[1] )
          {
            v8 = 0;
          }
          if ( v8 )
            callback->process(callback, v7);
        }
        v5 = (unsigned __int16)++v9;
      }
      while ( (unsigned __int16)v9 < 2 * this->m_numHandles + 1 );
    }
  }
}
