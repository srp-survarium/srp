void __thiscall btAxisSweep3Internal<unsigned short>::aabbTest(
        btAxisSweep3Internal<unsigned short> *this,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax,
        btBroadphaseAabbCallback *callback)
{
  int v5; // ebx
  int v6; // eax
  btAxisSweep3Internal<unsigned short>::Edge *v7; // ecx
  bool v8; // zf
  btAxisSweep3Internal<unsigned short>::Edge *v9; // eax
  btAxisSweep3Internal<unsigned short>::Handle *v10; // eax
  char v11; // cl

  if ( this->m_raycastAccelerator )
  {
    this->m_raycastAccelerator->aabbTest(this->m_raycastAccelerator, aabbMin, aabbMax, callback);
  }
  else
  {
    v5 = 1;
    if ( 2 * this->m_numHandles + 1 > 1 )
    {
      v6 = 1;
      do
      {
        v7 = this->m_pEdges[0];
        v8 = (v7[v6].m_pos & 1) == 0;
        v9 = &v7[v6];
        if ( !v8 )
        {
          v10 = &this->m_pHandles[v9->m_handle];
          v11 = 1;
          if ( aabbMin->mVec128.m128_f32[0] > v10->m_aabbMax.mVec128.m128_f32[0]
            || v10->m_aabbMin.mVec128.m128_f32[0] > aabbMax->mVec128.m128_f32[0] )
          {
            v11 = 0;
          }
          if ( aabbMin->mVec128.m128_f32[2] > v10->m_aabbMax.mVec128.m128_f32[2]
            || v10->m_aabbMin.mVec128.m128_f32[2] > aabbMax->mVec128.m128_f32[2] )
          {
            v11 = 0;
          }
          if ( aabbMin->mVec128.m128_f32[1] <= v10->m_aabbMax.mVec128.m128_f32[1]
            && v10->m_aabbMin.mVec128.m128_f32[1] <= aabbMax->mVec128.m128_f32[1] )
          {
            if ( v11 )
              callback->process(callback, v10);
          }
        }
        v6 = (unsigned __int16)++v5;
      }
      while ( (unsigned __int16)v5 < 2 * this->m_numHandles + 1 );
    }
  }
}
