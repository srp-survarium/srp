void __userpurge btConvexPolyhedron::project(
        const btTransform *trans@<eax>,
        const btVector3 *dir@<ecx>,
        float *max@<edi>,
        btConvexPolyhedron *this,
        float *min)
{
  float v5; // xmm5_4
  int m_size; // esi
  btVector3 *m_data; // edx
  float v8; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm1_4
  int v13; // xmm1_4
  float v14; // [esp+0h] [ebp-40h]
  float v15; // [esp+34h] [ebp-Ch]
  __int64 v16; // [esp+38h] [ebp-8h]

  v5 = FLOAT_3_4028235e38;
  m_size = this->m_vertices.m_size;
  *min = FLOAT_3_4028235e38;
  *max = FLOAT_N3_4028235e38;
  if ( m_size > 0 )
  {
    m_data = this->m_vertices.m_data;
    v16 = *(__int64 *)((char *)dir->mVec128.m128_i64 + 4);
    v15 = dir->mVec128.m128_f32[0];
    v14 = FLOAT_N3_4028235e38;
    do
    {
      v8 = (float)((float)((float)(m_data->mVec128.m128_f32[2] * trans->m_basis.m_el[0].mVec128.m128_f32[2])
                         + (float)(m_data->mVec128.m128_f32[0] * trans->m_basis.m_el[0].mVec128.m128_f32[0]))
                 + (float)(m_data->mVec128.m128_f32[1] * trans->m_basis.m_el[0].mVec128.m128_f32[1]))
         + trans->m_origin.mVec128.m128_f32[0];
      v9 = m_data->mVec128.m128_f32[2];
      v10 = (float)((float)((float)(m_data->mVec128.m128_f32[0] * trans->m_basis.m_el[2].mVec128.m128_f32[0])
                          + (float)(m_data->mVec128.m128_f32[1] * trans->m_basis.m_el[2].mVec128.m128_f32[1]))
                  + (float)(v9 * trans->m_basis.m_el[2].mVec128.m128_f32[2]))
          + trans->m_origin.mVec128.m128_f32[2];
      v11 = (float)((float)((float)(m_data->mVec128.m128_f32[0] * trans->m_basis.m_el[1].mVec128.m128_f32[0])
                          + (float)(m_data->mVec128.m128_f32[1] * trans->m_basis.m_el[1].mVec128.m128_f32[1]))
                  + (float)(v9 * trans->m_basis.m_el[1].mVec128.m128_f32[2]))
          + trans->m_origin.mVec128.m128_f32[1];
      v12 = (float)((float)(v15 * v8) + (float)(*(float *)&v16 * v11)) + (float)(*((float *)&v16 + 1) * v10);
      if ( v5 > v12 )
        v5 = (float)((float)(v15 * v8) + (float)(*(float *)&v16 * v11)) + (float)(*((float *)&v16 + 1) * v10);
      if ( v12 > v14 )
        v14 = (float)((float)(v15 * v8) + (float)(*(float *)&v16 * v11)) + (float)(*((float *)&v16 + 1) * v10);
      ++m_data;
      --m_size;
    }
    while ( m_size );
    *min = v5;
    *max = v14;
  }
  v13 = *(_DWORD *)min;
  if ( *min > *max )
  {
    *min = *max;
    *(_DWORD *)max = v13;
  }
}
