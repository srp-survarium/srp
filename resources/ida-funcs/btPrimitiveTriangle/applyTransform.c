void __usercall btPrimitiveTriangle::applyTransform(btPrimitiveTriangle *this@<ecx>, const btTransform *t@<eax>)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  unsigned int v4; // xmm3_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // [esp+14h] [ebp-Ch]
  unsigned __int64 v12; // [esp+14h] [ebp-Ch]

  v2 = this->m_vertices[0].mVec128.m128_f32[1];
  v3 = this->m_vertices[0].mVec128.m128_f32[2];
  v11 = (float)((float)((float)(t->m_basis.m_el[1].mVec128.m128_f32[1] * v2)
                      + (float)(t->m_basis.m_el[1].mVec128.m128_f32[2] * v3))
              + (float)(t->m_basis.m_el[1].mVec128.m128_f32[0] * this->m_vertices[0].mVec128.m128_f32[0]))
      + t->m_origin.mVec128.m128_f32[1];
  *(float *)&v4 = (float)((float)((float)(t->m_basis.m_el[2].mVec128.m128_f32[1] * v2)
                                + (float)(t->m_basis.m_el[2].mVec128.m128_f32[2] * v3))
                        + (float)(t->m_basis.m_el[2].mVec128.m128_f32[0] * this->m_vertices[0].mVec128.m128_f32[0]))
                + t->m_origin.mVec128.m128_f32[2];
  this->m_vertices[0].mVec128.m128_f32[0] = (float)((float)((float)(this->m_vertices[0].mVec128.m128_f32[0]
                                                                  * t->m_basis.m_el[0].mVec128.m128_f32[0])
                                                          + (float)(v2 * t->m_basis.m_el[0].mVec128.m128_f32[1]))
                                                  + (float)(v3 * t->m_basis.m_el[0].mVec128.m128_f32[2]))
                                          + t->m_origin.mVec128.m128_f32[0];
  this->m_vertices[0].mVec128.m128_f32[1] = v11;
  this->m_vertices[0].mVec128.m128_u64[1] = v4;
  v5 = this->m_vertices[1].mVec128.m128_f32[1];
  v6 = this->m_vertices[1].mVec128.m128_f32[0];
  v7 = this->m_vertices[1].mVec128.m128_f32[2];
  *(float *)&v12 = (float)((float)((float)(t->m_basis.m_el[1].mVec128.m128_f32[1] * v5)
                                 + (float)(t->m_basis.m_el[1].mVec128.m128_f32[2] * v7))
                         + (float)(t->m_basis.m_el[1].mVec128.m128_f32[0] * v6))
                 + t->m_origin.mVec128.m128_f32[1];
  *((float *)&v12 + 1) = (float)((float)((float)(t->m_basis.m_el[2].mVec128.m128_f32[1] * v5)
                                       + (float)(t->m_basis.m_el[2].mVec128.m128_f32[2] * v7))
                               + (float)(t->m_basis.m_el[2].mVec128.m128_f32[0] * v6))
                       + t->m_origin.mVec128.m128_f32[2];
  this->m_vertices[1].mVec128.m128_f32[0] = (float)((float)((float)(v6 * t->m_basis.m_el[0].mVec128.m128_f32[0])
                                                          + (float)(v5 * t->m_basis.m_el[0].mVec128.m128_f32[1]))
                                                  + (float)(v7 * t->m_basis.m_el[0].mVec128.m128_f32[2]))
                                          + t->m_origin.mVec128.m128_f32[0];
  *(unsigned __int64 *)((char *)this->m_vertices[1].mVec128.m128_u64 + 4) = v12;
  this->m_vertices[1].mVec128.m128_i32[3] = 0;
  v8 = this->m_vertices[2].mVec128.m128_f32[1];
  v9 = this->m_vertices[2].mVec128.m128_f32[0];
  v10 = this->m_vertices[2].mVec128.m128_f32[2];
  *(float *)&v12 = (float)((float)((float)(t->m_basis.m_el[1].mVec128.m128_f32[1] * v8)
                                 + (float)(t->m_basis.m_el[1].mVec128.m128_f32[2] * v10))
                         + (float)(t->m_basis.m_el[1].mVec128.m128_f32[0] * v9))
                 + t->m_origin.mVec128.m128_f32[1];
  *((float *)&v12 + 1) = (float)((float)((float)(t->m_basis.m_el[2].mVec128.m128_f32[1] * v8)
                                       + (float)(t->m_basis.m_el[2].mVec128.m128_f32[2] * v10))
                               + (float)(t->m_basis.m_el[2].mVec128.m128_f32[0] * v9))
                       + t->m_origin.mVec128.m128_f32[2];
  this->m_vertices[2].mVec128.m128_f32[0] = (float)((float)((float)(v9 * t->m_basis.m_el[0].mVec128.m128_f32[0])
                                                          + (float)(v8 * t->m_basis.m_el[0].mVec128.m128_f32[1]))
                                                  + (float)(v10 * t->m_basis.m_el[0].mVec128.m128_f32[2]))
                                          + t->m_origin.mVec128.m128_f32[0];
  *(unsigned __int64 *)((char *)this->m_vertices[2].mVec128.m128_u64 + 4) = v12;
  this->m_vertices[2].mVec128.m128_i32[3] = 0;
}
