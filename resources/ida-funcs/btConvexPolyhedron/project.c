void __userpurge btConvexPolyhedron::project(
        const btTransform *trans@<eax>,
        const btVector3 *dir@<ecx>,
        btConvexPolyhedron *this,
        float *min,
        float *max)
{
  btConvexPolyhedron *v5; // edx
  float v6; // xmm4_4
  float *v7; // ebx
  int m_size; // edi
  int v10; // ecx
  btVector3 *m_data; // edx
  float v12; // xmm7_4
  float *v13; // edx
  unsigned int v14; // ecx
  float *v15; // ebx
  float v16; // xmm3_4
  float v17; // xmm3_4
  float v18; // xmm3_4
  float v19; // xmm3_4
  float v20; // xmm7_4
  float v21; // xmm0_4
  float *v22; // esi
  float v23; // xmm6_4
  float *m128_f32; // eax
  int v25; // edi
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // [esp+0h] [ebp-44h]
  unsigned __int64 v29; // [esp+4h] [ebp-40h]
  float v30; // [esp+4h] [ebp-40h]
  float v31; // [esp+8h] [ebp-3Ch]
  float v32; // [esp+Ch] [ebp-38h]
  float v33; // [esp+Ch] [ebp-38h]
  float v34; // [esp+10h] [ebp-34h]
  float v35; // [esp+10h] [ebp-34h]
  float v36; // [esp+14h] [ebp-30h]
  float v37; // [esp+14h] [ebp-30h]
  float v38; // [esp+18h] [ebp-2Ch]
  float v39; // [esp+18h] [ebp-2Ch]
  float v40; // [esp+1Ch] [ebp-28h]
  float v41; // [esp+1Ch] [ebp-28h]
  __int64 v42; // [esp+20h] [ebp-24h]
  __int64 v43; // [esp+20h] [ebp-24h]
  float v44; // [esp+28h] [ebp-1Ch]
  float v45; // [esp+28h] [ebp-1Ch]
  float v46; // [esp+2Ch] [ebp-18h]
  float v47; // [esp+30h] [ebp-14h]
  float v48; // [esp+30h] [ebp-14h]
  float v49; // [esp+34h] [ebp-10h]
  float v50; // [esp+34h] [ebp-10h]
  float v51; // [esp+38h] [ebp-Ch]
  float v52; // [esp+38h] [ebp-Ch]
  float *v53; // [esp+3Ch] [ebp-8h]
  int i; // [esp+40h] [ebp-4h]
  float ia; // [esp+40h] [ebp-4h]

  v5 = this;
  v6 = 3.4028235e38;
  v7 = max;
  m_size = this->m_vertices.m_size;
  *min = 3.4028235e38;
  v10 = 0;
  *max = -3.4028235e38;
  if ( m_size >= 4 )
  {
    m_data = this->m_vertices.m_data;
    v51 = trans->m_basis.m_el[0].mVec128.m128_f32[2];
    v29 = trans->m_basis.m_el[0].mVec128.m128_u64[0];
    v12 = trans->m_basis.m_el[1].mVec128.m128_f32[1];
    v32 = trans->m_origin.mVec128.m128_f32[0];
    v36 = trans->m_basis.m_el[1].mVec128.m128_f32[2];
    v34 = trans->m_basis.m_el[1].mVec128.m128_f32[0];
    v38 = trans->m_origin.mVec128.m128_f32[1];
    v42 = *(__int64 *)((char *)trans->m_basis.m_el[2].mVec128.m128_i64 + 4);
    v53 = &m_data->mVec128.m128_f32[1];
    v40 = trans->m_basis.m_el[2].mVec128.m128_f32[0];
    v44 = trans->m_origin.mVec128.m128_f32[2];
    v13 = &m_data[1].mVec128.m128_f32[1];
    v49 = dir->mVec128.m128_f32[2];
    v14 = ((unsigned int)(m_size - 4) >> 2) + 1;
    v47 = dir->mVec128.m128_f32[1];
    i = 4 * v14;
    v15 = v53;
    v46 = dir->mVec128.m128_f32[0];
    v28 = -3.4028235e38;
    do
    {
      v16 = (float)((float)(v46
                          * (float)((float)((float)((float)(*v15 * *((float *)&v29 + 1))
                                                  + (float)(*(float *)&v29 * *(v15 - 1)))
                                          + (float)(v51 * v15[1]))
                                  + v32))
                  + (float)(v47
                          * (float)((float)((float)((float)(v34 * *(v15 - 1)) + (float)(v36 * v15[1]))
                                          + (float)(*v15 * v12))
                                  + v38)))
          + (float)(v49
                  * (float)((float)((float)((float)(v40 * *(v15 - 1)) + (float)(*((float *)&v42 + 1) * v15[1]))
                                  + (float)(*v15 * *(float *)&v42))
                          + v44));
      if ( v6 > v16 )
        v6 = (float)((float)(v46
                           * (float)((float)((float)((float)(*v15 * *((float *)&v29 + 1))
                                                   + (float)(*(float *)&v29 * *(v15 - 1)))
                                           + (float)(v51 * v15[1]))
                                   + v32))
                   + (float)(v47
                           * (float)((float)((float)((float)(v34 * *(v15 - 1)) + (float)(v36 * v15[1]))
                                           + (float)(*v15 * v12))
                                   + v38)))
           + (float)(v49
                   * (float)((float)((float)((float)(v40 * *(v15 - 1)) + (float)(*((float *)&v42 + 1) * v15[1]))
                                   + (float)(*v15 * *(float *)&v42))
                           + v44));
      if ( v16 > v28 )
        v28 = (float)((float)(v46
                            * (float)((float)((float)((float)(*v15 * *((float *)&v29 + 1))
                                                    + (float)(*(float *)&v29 * *(v15 - 1)))
                                            + (float)(v51 * v15[1]))
                                    + v32))
                    + (float)(v47
                            * (float)((float)((float)((float)(v34 * *(v15 - 1)) + (float)(v36 * v15[1]))
                                            + (float)(*v15 * v12))
                                    + v38)))
            + (float)(v49
                    * (float)((float)((float)((float)(v40 * *(v15 - 1)) + (float)(*((float *)&v42 + 1) * v15[1]))
                                    + (float)(*v15 * *(float *)&v42))
                            + v44));
      v17 = (float)((float)(v46
                          * (float)((float)((float)((float)(*((float *)&v29 + 1) * *v13)
                                                  + (float)(*(float *)&v29 * v15[3]))
                                          + (float)(v51 * v13[1]))
                                  + v32))
                  + (float)(v47
                          * (float)((float)((float)((float)(v34 * v15[3]) + (float)(v36 * v13[1])) + (float)(v12 * *v13))
                                  + v38)))
          + (float)(v49
                  * (float)((float)((float)((float)(v40 * v15[3]) + (float)(*((float *)&v42 + 1) * v13[1]))
                                  + (float)(*(float *)&v42 * *v13))
                          + v44));
      if ( v6 > v17 )
        v6 = (float)((float)(v46
                           * (float)((float)((float)((float)(*((float *)&v29 + 1) * *v13)
                                                   + (float)(*(float *)&v29 * v15[3]))
                                           + (float)(v51 * v13[1]))
                                   + v32))
                   + (float)(v47
                           * (float)((float)((float)((float)(v34 * v15[3]) + (float)(v36 * v13[1])) + (float)(v12 * *v13))
                                   + v38)))
           + (float)(v49
                   * (float)((float)((float)((float)(v40 * v15[3]) + (float)(*((float *)&v42 + 1) * v13[1]))
                                   + (float)(*(float *)&v42 * *v13))
                           + v44));
      if ( v17 > v28 )
        v28 = (float)((float)(v46
                            * (float)((float)((float)((float)(*((float *)&v29 + 1) * *v13)
                                                    + (float)(*(float *)&v29 * v15[3]))
                                            + (float)(v51 * v13[1]))
                                    + v32))
                    + (float)(v47
                            * (float)((float)((float)((float)(v34 * v15[3]) + (float)(v36 * v13[1]))
                                            + (float)(v12 * *v13))
                                    + v38)))
            + (float)(v49
                    * (float)((float)((float)((float)(v40 * v15[3]) + (float)(*((float *)&v42 + 1) * v13[1]))
                                    + (float)(*(float *)&v42 * *v13))
                            + v44));
      v18 = (float)((float)(v46
                          * (float)((float)((float)((float)(*(float *)&v29 * v15[7])
                                                  + (float)(*((float *)&v29 + 1) * v13[4]))
                                          + (float)(v51 * v13[5]))
                                  + v32))
                  + (float)(v47
                          * (float)((float)((float)((float)(v34 * v15[7]) + (float)(v12 * v13[4]))
                                          + (float)(v36 * v13[5]))
                                  + v38)))
          + (float)(v49
                  * (float)((float)((float)((float)(v40 * v15[7]) + (float)(*(float *)&v42 * v13[4]))
                                  + (float)(*((float *)&v42 + 1) * v13[5]))
                          + v44));
      if ( v6 > v18 )
        v6 = (float)((float)(v46
                           * (float)((float)((float)((float)(*(float *)&v29 * v15[7])
                                                   + (float)(*((float *)&v29 + 1) * v13[4]))
                                           + (float)(v51 * v13[5]))
                                   + v32))
                   + (float)(v47
                           * (float)((float)((float)((float)(v34 * v15[7]) + (float)(v12 * v13[4]))
                                           + (float)(v36 * v13[5]))
                                   + v38)))
           + (float)(v49
                   * (float)((float)((float)((float)(v40 * v15[7]) + (float)(*(float *)&v42 * v13[4]))
                                   + (float)(*((float *)&v42 + 1) * v13[5]))
                           + v44));
      if ( v18 > v28 )
        v28 = (float)((float)(v46
                            * (float)((float)((float)((float)(*(float *)&v29 * v15[7])
                                                    + (float)(*((float *)&v29 + 1) * v13[4]))
                                            + (float)(v51 * v13[5]))
                                    + v32))
                    + (float)(v47
                            * (float)((float)((float)((float)(v34 * v15[7]) + (float)(v12 * v13[4]))
                                            + (float)(v36 * v13[5]))
                                    + v38)))
            + (float)(v49
                    * (float)((float)((float)((float)(v40 * v15[7]) + (float)(*(float *)&v42 * v13[4]))
                                    + (float)(*((float *)&v42 + 1) * v13[5]))
                            + v44));
      v19 = (float)((float)(v46
                          * (float)((float)((float)((float)(*(float *)&v29 * v15[11])
                                                  + (float)(*((float *)&v29 + 1) * v13[8]))
                                          + (float)(v51 * v13[9]))
                                  + v32))
                  + (float)(v47
                          * (float)((float)((float)((float)(v34 * v15[11]) + (float)(v12 * v13[8]))
                                          + (float)(v36 * v13[9]))
                                  + v38)))
          + (float)(v49
                  * (float)((float)((float)((float)(v40 * v15[11]) + (float)(*(float *)&v42 * v13[8]))
                                  + (float)(*((float *)&v42 + 1) * v13[9]))
                          + v44));
      if ( v6 > v19 )
        v6 = (float)((float)(v46
                           * (float)((float)((float)((float)(*(float *)&v29 * v15[11])
                                                   + (float)(*((float *)&v29 + 1) * v13[8]))
                                           + (float)(v51 * v13[9]))
                                   + v32))
                   + (float)(v47
                           * (float)((float)((float)((float)(v34 * v15[11]) + (float)(v12 * v13[8]))
                                           + (float)(v36 * v13[9]))
                                   + v38)))
           + (float)(v49
                   * (float)((float)((float)((float)(v40 * v15[11]) + (float)(*(float *)&v42 * v13[8]))
                                   + (float)(*((float *)&v42 + 1) * v13[9]))
                           + v44));
      if ( v19 > v28 )
        v28 = (float)((float)(v46
                            * (float)((float)((float)((float)(*(float *)&v29 * v15[11])
                                                    + (float)(*((float *)&v29 + 1) * v13[8]))
                                            + (float)(v51 * v13[9]))
                                    + v32))
                    + (float)(v47
                            * (float)((float)((float)((float)(v34 * v15[11]) + (float)(v12 * v13[8]))
                                            + (float)(v36 * v13[9]))
                                    + v38)))
            + (float)(v49
                    * (float)((float)((float)((float)(v40 * v15[11]) + (float)(*(float *)&v42 * v13[8]))
                                    + (float)(*((float *)&v42 + 1) * v13[9]))
                            + v44));
      v15 += 16;
      v13 += 16;
      --v14;
    }
    while ( v14 );
    v7 = max;
    v10 = i;
    *min = v6;
    v5 = this;
    *max = v28;
  }
  if ( v10 >= m_size )
  {
    v22 = min;
  }
  else
  {
    v31 = trans->m_basis.m_el[0].mVec128.m128_f32[1];
    v20 = trans->m_basis.m_el[0].mVec128.m128_f32[2];
    v30 = trans->m_basis.m_el[0].mVec128.m128_f32[0];
    v33 = trans->m_origin.mVec128.m128_f32[0];
    v37 = trans->m_basis.m_el[1].mVec128.m128_f32[2];
    ia = trans->m_basis.m_el[1].mVec128.m128_f32[1];
    v35 = trans->m_basis.m_el[1].mVec128.m128_f32[0];
    v39 = trans->m_origin.mVec128.m128_f32[1];
    v43 = *(__int64 *)((char *)trans->m_basis.m_el[2].mVec128.m128_i64 + 4);
    v41 = trans->m_basis.m_el[2].mVec128.m128_f32[0];
    v45 = trans->m_origin.mVec128.m128_f32[2];
    v50 = dir->mVec128.m128_f32[2];
    v48 = dir->mVec128.m128_f32[1];
    v21 = dir->mVec128.m128_f32[0];
    v22 = min;
    v23 = *min;
    m128_f32 = v5->m_vertices.m_data[v10].mVec128.m128_f32;
    v52 = *v7;
    v25 = m_size - v10;
    do
    {
      v26 = (float)((float)(v21
                          * (float)((float)((float)((float)(v30 * *m128_f32) + (float)(v31 * m128_f32[1]))
                                          + (float)(v20 * m128_f32[2]))
                                  + v33))
                  + (float)(v48
                          * (float)((float)((float)((float)(v35 * *m128_f32) + (float)(ia * m128_f32[1]))
                                          + (float)(v37 * m128_f32[2]))
                                  + v39)))
          + (float)(v50
                  * (float)((float)((float)((float)(v41 * *m128_f32) + (float)(*(float *)&v43 * m128_f32[1]))
                                  + (float)(*((float *)&v43 + 1) * m128_f32[2]))
                          + v45));
      if ( v23 > v26 )
        v23 = (float)((float)(v21
                            * (float)((float)((float)((float)(v30 * *m128_f32) + (float)(v31 * m128_f32[1]))
                                            + (float)(v20 * m128_f32[2]))
                                    + v33))
                    + (float)(v48
                            * (float)((float)((float)((float)(v35 * *m128_f32) + (float)(ia * m128_f32[1]))
                                            + (float)(v37 * m128_f32[2]))
                                    + v39)))
            + (float)(v50
                    * (float)((float)((float)((float)(v41 * *m128_f32) + (float)(*(float *)&v43 * m128_f32[1]))
                                    + (float)(*((float *)&v43 + 1) * m128_f32[2]))
                            + v45));
      if ( v26 > v52 )
        v52 = (float)((float)(v21
                            * (float)((float)((float)((float)(v30 * *m128_f32) + (float)(v31 * m128_f32[1]))
                                            + (float)(v20 * m128_f32[2]))
                                    + v33))
                    + (float)(v48
                            * (float)((float)((float)((float)(v35 * *m128_f32) + (float)(ia * m128_f32[1]))
                                            + (float)(v37 * m128_f32[2]))
                                    + v39)))
            + (float)(v50
                    * (float)((float)((float)((float)(v41 * *m128_f32) + (float)(*(float *)&v43 * m128_f32[1]))
                                    + (float)(*((float *)&v43 + 1) * m128_f32[2]))
                            + v45));
      m128_f32 += 4;
      --v25;
    }
    while ( v25 );
    *min = v23;
    *v7 = v52;
  }
  v27 = *v22;
  if ( *v22 > *v7 )
  {
    *v22 = *v7;
    *v7 = v27;
  }
}
