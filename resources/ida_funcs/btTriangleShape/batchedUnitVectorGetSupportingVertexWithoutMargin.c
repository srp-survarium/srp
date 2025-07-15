void __thiscall btTriangleShape::batchedUnitVectorGetSupportingVertexWithoutMargin(
        btTriangleShape *this,
        const btVector3 *vectors,
        btVector3 *supportVerticesOut,
        int numVectors)
{
  int v4; // ebx
  btVector3 *v5; // esi
  float *v6; // edx
  unsigned int v7; // ebx
  float v8; // xmm2_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm4_4
  int v14; // eax
  int v15; // eax
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  int v21; // eax
  int v22; // eax
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm3_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm4_4
  int v29; // eax
  int v30; // eax
  float v31; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm3_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm4_4
  int v37; // eax
  btVector3 *v38; // edx
  float *v39; // esi
  int v40; // edi
  float v41; // xmm4_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm0_4
  int v46; // eax
  int v47; // [esp+10h] [ebp-4h]

  v4 = 0;
  if ( numVectors >= 4 )
  {
    v5 = supportVerticesOut + 2;
    v6 = &vectors[1].mVec128.m128_f32[1];
    v7 = ((unsigned int)(numVectors - 4) >> 2) + 1;
    v47 = 4 * v7;
    do
    {
      v8 = *(v6 - 3);
      v9 = *(v6 - 5);
      v10 = *(v6 - 4);
      v11 = (float)((float)(this->m_vertices1[0].mVec128.m128_f32[0] * v9)
                  + (float)(this->m_vertices1[0].mVec128.m128_f32[2] * v8))
          + (float)(this->m_vertices1[0].mVec128.m128_f32[1] * v10);
      v12 = (float)((float)(this->m_vertices1[1].mVec128.m128_f32[1] * v10)
                  + (float)(this->m_vertices1[1].mVec128.m128_f32[2] * v8))
          + (float)(this->m_vertices1[1].mVec128.m128_f32[0] * v9);
      v13 = (float)((float)(this->m_vertices1[2].mVec128.m128_f32[0] * v9)
                  + (float)(v10 * this->m_vertices1[2].mVec128.m128_f32[1]))
          + (float)(v8 * this->m_vertices1[2].mVec128.m128_f32[2]);
      if ( v12 <= v11 )
      {
        if ( v13 <= v11 )
          v14 = 0;
        else
          v14 = 2;
      }
      else if ( v13 <= v12 )
      {
        v14 = 1;
      }
      else
      {
        v14 = 2;
      }
      v15 = 16 * (v14 + 5);
      v5[-2].mVec128.m128_u64[0] = *(_QWORD *)((char *)&this->__vftable + v15);
      v5[-2].mVec128.m128_u64[1] = *(_QWORD *)((char *)&this->m_userPointer + v15);
      v16 = v6[1];
      v17 = *(v6 - 1);
      v18 = (float)((float)(this->m_vertices1[0].mVec128.m128_f32[0] * v17)
                  + (float)(this->m_vertices1[0].mVec128.m128_f32[2] * v16))
          + (float)(*v6 * this->m_vertices1[0].mVec128.m128_f32[1]);
      v19 = (float)((float)(this->m_vertices1[1].mVec128.m128_f32[2] * v16)
                  + (float)(this->m_vertices1[1].mVec128.m128_f32[0] * v17))
          + (float)(*v6 * this->m_vertices1[1].mVec128.m128_f32[1]);
      v20 = (float)((float)(*v6 * this->m_vertices1[2].mVec128.m128_f32[1])
                  + (float)(this->m_vertices1[2].mVec128.m128_f32[0] * v17))
          + (float)(v16 * this->m_vertices1[2].mVec128.m128_f32[2]);
      if ( v19 <= v18 )
      {
        if ( v20 <= v18 )
          v21 = 0;
        else
          v21 = 2;
      }
      else if ( v20 <= v19 )
      {
        v21 = 1;
      }
      else
      {
        v21 = 2;
      }
      v22 = 16 * (v21 + 5);
      v5[-1].mVec128.m128_u64[0] = *(_QWORD *)((char *)&this->__vftable + v22);
      v5[-1].mVec128.m128_u64[1] = *(_QWORD *)((char *)&this->m_userPointer + v22);
      v23 = v6[5];
      v24 = v6[3];
      v25 = v6[4];
      v26 = (float)((float)(this->m_vertices1[0].mVec128.m128_f32[0] * v24)
                  + (float)(this->m_vertices1[0].mVec128.m128_f32[2] * v23))
          + (float)(this->m_vertices1[0].mVec128.m128_f32[1] * v25);
      v27 = (float)((float)(this->m_vertices1[1].mVec128.m128_f32[1] * v25)
                  + (float)(this->m_vertices1[1].mVec128.m128_f32[2] * v23))
          + (float)(this->m_vertices1[1].mVec128.m128_f32[0] * v24);
      v28 = (float)((float)(this->m_vertices1[2].mVec128.m128_f32[0] * v24)
                  + (float)(v25 * this->m_vertices1[2].mVec128.m128_f32[1]))
          + (float)(v23 * this->m_vertices1[2].mVec128.m128_f32[2]);
      if ( v27 <= v26 )
      {
        if ( v28 <= v26 )
          v29 = 0;
        else
          v29 = 2;
      }
      else if ( v28 <= v27 )
      {
        v29 = 1;
      }
      else
      {
        v29 = 2;
      }
      v30 = 16 * (v29 + 5);
      v5->mVec128.m128_u64[0] = *(_QWORD *)((char *)&this->__vftable + v30);
      v5->mVec128.m128_u64[1] = *(_QWORD *)((char *)&this->m_userPointer + v30);
      v31 = v6[9];
      v32 = v6[7];
      v33 = v6[8];
      v34 = (float)((float)(this->m_vertices1[0].mVec128.m128_f32[0] * v32)
                  + (float)(this->m_vertices1[0].mVec128.m128_f32[2] * v31))
          + (float)(this->m_vertices1[0].mVec128.m128_f32[1] * v33);
      v35 = (float)((float)(this->m_vertices1[1].mVec128.m128_f32[1] * v33)
                  + (float)(this->m_vertices1[1].mVec128.m128_f32[2] * v31))
          + (float)(this->m_vertices1[1].mVec128.m128_f32[0] * v32);
      v36 = (float)((float)(this->m_vertices1[2].mVec128.m128_f32[0] * v32)
                  + (float)(v33 * this->m_vertices1[2].mVec128.m128_f32[1]))
          + (float)(v31 * this->m_vertices1[2].mVec128.m128_f32[2]);
      if ( v35 <= v34 )
      {
        if ( v36 <= v34 )
          v37 = 0;
        else
          v37 = 2;
      }
      else if ( v36 <= v35 )
      {
        v37 = 1;
      }
      else
      {
        v37 = 2;
      }
      v5[1].mVec128.m128_u64[0] = this->m_vertices1[v37].mVec128.m128_u64[0];
      v5[1].mVec128.m128_u64[1] = this->m_vertices1[v37].mVec128.m128_u64[1];
      v6 += 16;
      v5 += 4;
      --v7;
    }
    while ( v7 );
    v4 = v47;
  }
  if ( v4 < numVectors )
  {
    v38 = &supportVerticesOut[v4];
    v39 = &vectors[v4].mVec128.m128_f32[1];
    v40 = numVectors - v4;
    do
    {
      v41 = *(v39 - 1);
      v42 = v39[1];
      v43 = (float)((float)(*v39 * this->m_vertices1[0].mVec128.m128_f32[1])
                  + (float)(this->m_vertices1[0].mVec128.m128_f32[0] * v41))
          + (float)(this->m_vertices1[0].mVec128.m128_f32[2] * v42);
      v44 = (float)((float)(this->m_vertices1[1].mVec128.m128_f32[2] * v42)
                  + (float)(this->m_vertices1[1].mVec128.m128_f32[1] * *v39))
          + (float)(this->m_vertices1[1].mVec128.m128_f32[0] * v41);
      v45 = (float)((float)(v42 * this->m_vertices1[2].mVec128.m128_f32[2])
                  + (float)(*v39 * this->m_vertices1[2].mVec128.m128_f32[1]))
          + (float)(this->m_vertices1[2].mVec128.m128_f32[0] * v41);
      if ( v44 <= v43 )
      {
        if ( v45 <= v43 )
          v46 = 0;
        else
          v46 = 2;
      }
      else if ( v45 <= v44 )
      {
        v46 = 1;
      }
      else
      {
        v46 = 2;
      }
      v38->mVec128.m128_u64[0] = this->m_vertices1[v46].mVec128.m128_u64[0];
      v38->mVec128.m128_u64[1] = this->m_vertices1[v46].mVec128.m128_u64[1];
      v39 += 4;
      ++v38;
      --v40;
    }
    while ( v40 );
  }
}
