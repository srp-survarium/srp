void __thiscall btTriangleShape::batchedUnitVectorGetSupportingVertexWithoutMargin(
        btTriangleShape *this,
        const btVector3 *vectors,
        btVector3 *supportVerticesOut,
        int numVectors)
{
  float *v5; // eax
  float v6; // xmm4_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  int v11; // edx
  btVector3 *v12; // esi
  int *v13; // edi
  bool v14; // zf
  int v15; // [esp+Ch] [ebp-4h]

  if ( numVectors > 0 )
  {
    v5 = &vectors->mVec128.m128_f32[1];
    v15 = numVectors;
    while ( 1 )
    {
      v6 = *(v5 - 1);
      v7 = v5[1];
      v8 = (float)((float)(*v5 * this->m_vertices1[0].mVec128.m128_f32[1])
                 + (float)(this->m_vertices1[0].mVec128.m128_f32[0] * v6))
         + (float)(this->m_vertices1[0].mVec128.m128_f32[2] * v7);
      v9 = (float)((float)(this->m_vertices1[1].mVec128.m128_f32[2] * v7)
                 + (float)(this->m_vertices1[1].mVec128.m128_f32[1] * *v5))
         + (float)(this->m_vertices1[1].mVec128.m128_f32[0] * v6);
      v10 = (float)((float)(v7 * this->m_vertices1[2].mVec128.m128_f32[2])
                  + (float)(*v5 * this->m_vertices1[2].mVec128.m128_f32[1]))
          + (float)(this->m_vertices1[2].mVec128.m128_f32[0] * v6);
      if ( v9 <= v8 )
        break;
      if ( v10 > v9 )
        goto LABEL_7;
      v11 = 1;
LABEL_9:
      v12 = &this->m_vertices1[v11];
      supportVerticesOut->mVec128.m128_i32[0] = v12->mVec128.m128_i32[0];
      v12 = (btVector3 *)((char *)v12 + 4);
      supportVerticesOut->mVec128.m128_i32[1] = v12->mVec128.m128_i32[0];
      v12 = (btVector3 *)((char *)v12 + 4);
      supportVerticesOut->mVec128.m128_i32[2] = v12->mVec128.m128_i32[0];
      v13 = &supportVerticesOut->mVec128.m128_i32[3];
      v5 += 4;
      ++supportVerticesOut;
      v14 = v15-- == 1;
      *v13 = v12->mVec128.m128_i32[1];
      if ( v14 )
        return;
    }
    if ( v10 <= v8 )
    {
      v11 = 0;
      goto LABEL_9;
    }
LABEL_7:
    v11 = 2;
    goto LABEL_9;
  }
}
