void __thiscall btConvexHullShape::project(
        btConvexHullShape *this,
        const btTransform *trans,
        const btVector3 *dir,
        float *min,
        float *max)
{
  int m_size; // esi
  int v6; // ebx
  btVector3 *m_data; // esi
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm3_4
  btVector3 *v12; // esi
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm3_4
  btVector3 *v17; // esi
  int v18; // ebx
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm3_4
  btVector3 *v23; // esi
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm3_4
  bool v28; // zf
  int v29; // ebx
  btVector3 *v30; // esi
  float v31; // xmm3_4
  float v32; // xmm4_4
  float v33; // xmm5_4
  float v34; // xmm3_4
  int v35; // xmm0_4
  int v36; // [esp+18h] [ebp-10h]
  int v37; // [esp+1Ch] [ebp-Ch]
  unsigned int v38; // [esp+20h] [ebp-8h]
  int v39; // [esp+20h] [ebp-8h]
  int v40; // [esp+24h] [ebp-4h]

  *min = 3.4028235e38;
  *max = -3.4028235e38;
  m_size = this->m_unscaledPoints.m_size;
  v6 = 0;
  v40 = m_size;
  v36 = 0;
  if ( m_size >= 4 )
  {
    v38 = ((unsigned int)(m_size - 4) >> 2) + 1;
    v37 = 0;
    v36 = 4 * v38;
    do
    {
      m_data = this->m_unscaledPoints.m_data;
      v8 = this->m_localScaling.mVec128.m128_f32[0] * *(float *)((char *)m_data->mVec128.m128_f32 + v6);
      v9 = *(float *)((char *)&m_data->mVec128.m128_f32[1] + v6) * this->m_localScaling.mVec128.m128_f32[1];
      v10 = *(float *)((char *)&m_data->mVec128.m128_f32[2] + v6) * this->m_localScaling.mVec128.m128_f32[2];
      v11 = (float)((float)(dir->mVec128.m128_f32[0]
                          * (float)((float)((float)((float)(trans->m_basis.m_el[0].mVec128.m128_f32[0] * v8)
                                                  + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[1] * v9))
                                          + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[2] * v10))
                                  + trans->m_origin.mVec128.m128_f32[0]))
                  + (float)((float)((float)((float)((float)(trans->m_basis.m_el[2].mVec128.m128_f32[0] * v8)
                                                  + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v9))
                                          + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[2] * v10))
                                  + trans->m_origin.mVec128.m128_f32[2])
                          * dir->mVec128.m128_f32[2]))
          + (float)((float)((float)((float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * v8)
                                          + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v9))
                                  + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * v10))
                          + trans->m_origin.mVec128.m128_f32[1])
                  * dir->mVec128.m128_f32[1]);
      if ( *min > v11 )
        *min = v11;
      if ( v11 > *max )
        *max = v11;
      v12 = this->m_unscaledPoints.m_data;
      v13 = this->m_localScaling.mVec128.m128_f32[0] * *(float *)((char *)v12[1].mVec128.m128_f32 + v6);
      v14 = *(float *)((char *)&v12[1].mVec128.m128_f32[1] + v6) * this->m_localScaling.mVec128.m128_f32[1];
      v15 = *(float *)((char *)&v12[1].mVec128.m128_f32[2] + v6) * this->m_localScaling.mVec128.m128_f32[2];
      v16 = (float)((float)(dir->mVec128.m128_f32[0]
                          * (float)((float)((float)((float)(trans->m_basis.m_el[0].mVec128.m128_f32[0] * v13)
                                                  + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[1] * v14))
                                          + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[2] * v15))
                                  + trans->m_origin.mVec128.m128_f32[0]))
                  + (float)((float)((float)((float)((float)(trans->m_basis.m_el[2].mVec128.m128_f32[0] * v13)
                                                  + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v14))
                                          + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[2] * v15))
                                  + trans->m_origin.mVec128.m128_f32[2])
                          * dir->mVec128.m128_f32[2]))
          + (float)((float)((float)((float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * v13)
                                          + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v14))
                                  + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * v15))
                          + trans->m_origin.mVec128.m128_f32[1])
                  * dir->mVec128.m128_f32[1]);
      if ( *min > v16 )
        *min = v16;
      if ( v16 > *max )
        *max = v16;
      v17 = this->m_unscaledPoints.m_data;
      v18 = v6 + 48;
      v19 = this->m_localScaling.mVec128.m128_f32[0] * *(float *)((char *)v17[-1].mVec128.m128_f32 + v18);
      v20 = *(float *)((char *)&v17->mVec128.m128_f32[-3] + v18) * this->m_localScaling.mVec128.m128_f32[1];
      v21 = *(float *)((char *)&v17->mVec128.m128_f32[-2] + v18) * this->m_localScaling.mVec128.m128_f32[2];
      v22 = (float)((float)(dir->mVec128.m128_f32[0]
                          * (float)((float)((float)((float)(trans->m_basis.m_el[0].mVec128.m128_f32[0] * v19)
                                                  + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[1] * v20))
                                          + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[2] * v21))
                                  + trans->m_origin.mVec128.m128_f32[0]))
                  + (float)((float)((float)((float)((float)(trans->m_basis.m_el[2].mVec128.m128_f32[0] * v19)
                                                  + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v20))
                                          + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[2] * v21))
                                  + trans->m_origin.mVec128.m128_f32[2])
                          * dir->mVec128.m128_f32[2]))
          + (float)((float)((float)((float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * v19)
                                          + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v20))
                                  + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * v21))
                          + trans->m_origin.mVec128.m128_f32[1])
                  * dir->mVec128.m128_f32[1]);
      if ( *min > v22 )
        *min = v22;
      if ( v22 > *max )
        *max = v22;
      v23 = this->m_unscaledPoints.m_data;
      v24 = this->m_localScaling.mVec128.m128_f32[0] * *(float *)((char *)v23->mVec128.m128_f32 + v18);
      v25 = *(float *)((char *)&v23->mVec128.m128_f32[1] + v18) * this->m_localScaling.mVec128.m128_f32[1];
      v26 = *(float *)((char *)&v23->mVec128.m128_f32[2] + v18) * this->m_localScaling.mVec128.m128_f32[2];
      v27 = (float)((float)(dir->mVec128.m128_f32[0]
                          * (float)((float)((float)((float)(trans->m_basis.m_el[0].mVec128.m128_f32[0] * v24)
                                                  + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[1] * v25))
                                          + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[2] * v26))
                                  + trans->m_origin.mVec128.m128_f32[0]))
                  + (float)((float)((float)((float)((float)(trans->m_basis.m_el[2].mVec128.m128_f32[0] * v24)
                                                  + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v25))
                                          + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[2] * v26))
                                  + trans->m_origin.mVec128.m128_f32[2])
                          * dir->mVec128.m128_f32[2]))
          + (float)((float)((float)((float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * v24)
                                          + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v25))
                                  + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * v26))
                          + trans->m_origin.mVec128.m128_f32[1])
                  * dir->mVec128.m128_f32[1]);
      if ( *min > v27 )
        *min = v27;
      if ( v27 > *max )
        *max = v27;
      v6 = v37 + 64;
      v28 = v38-- == 1;
      v37 += 64;
    }
    while ( !v28 );
    v6 = v36;
    m_size = v40;
  }
  if ( v6 < m_size )
  {
    v29 = v6;
    v39 = m_size - v36;
    do
    {
      v30 = this->m_unscaledPoints.m_data;
      v31 = this->m_localScaling.mVec128.m128_f32[0] * v30[v29].mVec128.m128_f32[0];
      v32 = v30[v29].mVec128.m128_f32[1] * this->m_localScaling.mVec128.m128_f32[1];
      v33 = v30[v29].mVec128.m128_f32[2] * this->m_localScaling.mVec128.m128_f32[2];
      v34 = (float)((float)(dir->mVec128.m128_f32[0]
                          * (float)((float)((float)((float)(trans->m_basis.m_el[0].mVec128.m128_f32[0] * v31)
                                                  + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[1] * v32))
                                          + (float)(trans->m_basis.m_el[0].mVec128.m128_f32[2] * v33))
                                  + trans->m_origin.mVec128.m128_f32[0]))
                  + (float)((float)((float)((float)((float)(trans->m_basis.m_el[2].mVec128.m128_f32[0] * v31)
                                                  + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[1] * v32))
                                          + (float)(trans->m_basis.m_el[2].mVec128.m128_f32[2] * v33))
                                  + trans->m_origin.mVec128.m128_f32[2])
                          * dir->mVec128.m128_f32[2]))
          + (float)((float)((float)((float)((float)(trans->m_basis.m_el[1].mVec128.m128_f32[0] * v31)
                                          + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[1] * v32))
                                  + (float)(trans->m_basis.m_el[1].mVec128.m128_f32[2] * v33))
                          + trans->m_origin.mVec128.m128_f32[1])
                  * dir->mVec128.m128_f32[1]);
      if ( *min > v34 )
        *min = v34;
      if ( v34 > *max )
        *max = v34;
      ++v29;
      --v39;
    }
    while ( v39 );
  }
  v35 = *(_DWORD *)min;
  if ( *min > *max )
  {
    *min = *max;
    *(_DWORD *)max = v35;
  }
}
