void __thiscall btConvexHullShape::project(
        btConvexHullShape *this,
        const btTransform *trans,
        const btVector3 *dir,
        float *min,
        float *max)
{
  float *v5; // edx
  btVector3 *v6; // edx
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm2_4
  int v11; // xmm1_4
  int v12; // [esp+0h] [ebp-8h]
  int m_size; // [esp+4h] [ebp-4h]

  v5 = max;
  *min = FLOAT_3_4028235e38;
  *max = FLOAT_N3_4028235e38;
  if ( this->m_unscaledPoints.m_size > 0 )
  {
    v12 = 0;
    m_size = this->m_unscaledPoints.m_size;
    do
    {
      v6 = &this->m_unscaledPoints.m_data[v12];
      v7 = this->m_localScaling.mVec128.m128_f32[0] * v6->mVec128.m128_f32[0];
      v8 = v6->mVec128.m128_f32[1] * this->m_localScaling.mVec128.m128_f32[1];
      v9 = v6->mVec128.m128_f32[2] * this->m_localScaling.mVec128.m128_f32[2];
      v10 = (float)((float)(dir->mVec128.m128_f32[0]
                          * (float)((float)((float)((float)(trans->m_basis.m_el[0].mVec128.m128_f32[0] * v7)
                                                  + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[1] * v8))
                                          + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[2] * v9))
                                  + trans->m_origin.mVec128.m128_f32[0]))
                  + (float)((float)((float)((float)((float)(trans->m_basis.m_el[2].mVec128.m128_f32[0] * v7)
                                                  + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v8))
                                          + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[2] * v9))
                                  + trans->m_origin.mVec128.m128_f32[2])
                          * dir->mVec128.m128_f32[2]))
          + (float)((float)((float)((float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * v7)
                                          + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v8))
                                  + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * v9))
                          + trans->m_origin.mVec128.m128_f32[1])
                  * dir->mVec128.m128_f32[1]);
      if ( *min > v10 )
        *min = v10;
      v5 = max;
      if ( v10 > *max )
        *max = v10;
      ++v12;
      --m_size;
    }
    while ( m_size );
  }
  v11 = *(_DWORD *)min;
  if ( *min > *v5 )
  {
    *min = *v5;
    *(_DWORD *)v5 = v11;
  }
}
