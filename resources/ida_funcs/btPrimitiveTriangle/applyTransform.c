void __usercall btPrimitiveTriangle::applyTransform(btPrimitiveTriangle *this@<ecx>, const btTransform *t@<eax>)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  unsigned int v4; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  unsigned int v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  unsigned int v12; // xmm4_4
  unsigned __int64 v13; // [esp+0h] [ebp-10h]

  v2 = this->m_vertices[0].mVec128.m128_f32[1];
  v3 = this->m_vertices[0].mVec128.m128_f32[2];
  *(float *)&v13 = (float)((float)((float)(this->m_vertices[0].mVec128.m128_f32[0]
                                         * t->m_basis.m_el[0].mVec128.m128_f32[0])
                                 + (float)(v2 * t->m_basis.m_el[0].mVec128.m128_f32[1]))
                         + (float)(v3 * t->m_basis.m_el[0].mVec128.m128_f32[2]))
                 + t->m_origin.mVec128.m128_f32[0];
  *((float *)&v13 + 1) = (float)((float)((float)(t->m_basis.m_el[1].mVec128.m128_f32[1] * v2)
                                       + (float)(t->m_basis.m_el[1].mVec128.m128_f32[2] * v3))
                               + (float)(t->m_basis.m_el[1].mVec128.m128_f32[0] * this->m_vertices[0].mVec128.m128_f32[0]))
                       + t->m_origin.mVec128.m128_f32[1];
  *(float *)&v4 = (float)((float)((float)(t->m_basis.m_el[2].mVec128.m128_f32[1] * v2)
                                + (float)(t->m_basis.m_el[2].mVec128.m128_f32[2] * v3))
                        + (float)(t->m_basis.m_el[2].mVec128.m128_f32[0] * this->m_vertices[0].mVec128.m128_f32[0]))
                + t->m_origin.mVec128.m128_f32[2];
  this->m_vertices[0].mVec128.m128_u64[0] = v13;
  this->m_vertices[0].mVec128.m128_u64[1] = v4;
  v5 = this->m_vertices[1].mVec128.m128_f32[1];
  v6 = this->m_vertices[1].mVec128.m128_f32[0];
  v7 = this->m_vertices[1].mVec128.m128_f32[2];
  *(float *)&v13 = (float)((float)((float)(v6 * t->m_basis.m_el[0].mVec128.m128_f32[0])
                                 + (float)(v5 * t->m_basis.m_el[0].mVec128.m128_f32[1]))
                         + (float)(v7 * t->m_basis.m_el[0].mVec128.m128_f32[2]))
                 + t->m_origin.mVec128.m128_f32[0];
  *((float *)&v13 + 1) = (float)((float)((float)(t->m_basis.m_el[1].mVec128.m128_f32[1] * v5)
                                       + (float)(t->m_basis.m_el[1].mVec128.m128_f32[2] * v7))
                               + (float)(t->m_basis.m_el[1].mVec128.m128_f32[0] * v6))
                       + t->m_origin.mVec128.m128_f32[1];
  *(float *)&v8 = (float)((float)((float)(t->m_basis.m_el[2].mVec128.m128_f32[1] * v5)
                                + (float)(t->m_basis.m_el[2].mVec128.m128_f32[2] * v7))
                        + (float)(t->m_basis.m_el[2].mVec128.m128_f32[0] * v6))
                + t->m_origin.mVec128.m128_f32[2];
  this->m_vertices[1].mVec128.m128_u64[0] = v13;
  this->m_vertices[1].mVec128.m128_u64[1] = v8;
  v9 = this->m_vertices[2].mVec128.m128_f32[0];
  v10 = this->m_vertices[2].mVec128.m128_f32[2];
  v11 = this->m_vertices[2].mVec128.m128_f32[1];
  *(float *)&v13 = (float)((float)((float)(v9 * t->m_basis.m_el[0].mVec128.m128_f32[0])
                                 + (float)(v11 * t->m_basis.m_el[0].mVec128.m128_f32[1]))
                         + (float)(v10 * t->m_basis.m_el[0].mVec128.m128_f32[2]))
                 + t->m_origin.mVec128.m128_f32[0];
  *((float *)&v13 + 1) = (float)((float)((float)(t->m_basis.m_el[1].mVec128.m128_f32[1] * v11)
                                       + (float)(t->m_basis.m_el[1].mVec128.m128_f32[2] * v10))
                               + (float)(t->m_basis.m_el[1].mVec128.m128_f32[0] * v9))
                       + t->m_origin.mVec128.m128_f32[1];
  *(float *)&v12 = (float)((float)((float)(t->m_basis.m_el[2].mVec128.m128_f32[1] * v11)
                                 + (float)(t->m_basis.m_el[2].mVec128.m128_f32[2] * v10))
                         + (float)(t->m_basis.m_el[2].mVec128.m128_f32[0] * v9))
                 + t->m_origin.mVec128.m128_f32[2];
  this->m_vertices[2].mVec128.m128_u64[0] = v13;
  this->m_vertices[2].mVec128.m128_u64[1] = v12;
}
