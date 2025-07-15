bool __usercall btPrimitiveTriangle::overlap_test_conservative@<al>(
        btPrimitiveTriangle *this@<ecx>,
        const btPrimitiveTriangle *other@<eax>)
{
  float v2; // xmm0_4

  v2 = other->m_margin + this->m_margin;
  return ((float)((float)((float)((float)((float)(this->m_plane.mVec128.m128_f32[2]
                                                * other->m_vertices[0].mVec128.m128_f32[2])
                                        + (float)(this->m_plane.mVec128.m128_f32[1]
                                                * other->m_vertices[0].mVec128.m128_f32[1]))
                                + (float)(other->m_vertices[0].mVec128.m128_f32[0] * this->m_plane.mVec128.m128_f32[0]))
                        - this->m_plane.mVec128.m128_f32[3])
                - v2) <= 0.0
       || (float)((float)((float)((float)((float)(this->m_plane.mVec128.m128_f32[2]
                                                * other->m_vertices[1].mVec128.m128_f32[2])
                                        + (float)(this->m_plane.mVec128.m128_f32[1]
                                                * other->m_vertices[1].mVec128.m128_f32[1]))
                                + (float)(other->m_vertices[1].mVec128.m128_f32[0] * this->m_plane.mVec128.m128_f32[0]))
                        - this->m_plane.mVec128.m128_f32[3])
                - v2) <= 0.0
       || (float)((float)((float)((float)((float)(other->m_vertices[2].mVec128.m128_f32[2]
                                                * this->m_plane.mVec128.m128_f32[2])
                                        + (float)(other->m_vertices[2].mVec128.m128_f32[1]
                                                * this->m_plane.mVec128.m128_f32[1]))
                                + (float)(other->m_vertices[2].mVec128.m128_f32[0] * this->m_plane.mVec128.m128_f32[0]))
                        - this->m_plane.mVec128.m128_f32[3])
                - v2) <= 0.0)
      && ((float)((float)((float)((float)((float)(other->m_plane.mVec128.m128_f32[2]
                                                * this->m_vertices[0].mVec128.m128_f32[2])
                                        + (float)(other->m_plane.mVec128.m128_f32[1]
                                                * this->m_vertices[0].mVec128.m128_f32[1]))
                                + (float)(other->m_plane.mVec128.m128_f32[0] * this->m_vertices[0].mVec128.m128_f32[0]))
                        - other->m_plane.mVec128.m128_f32[3])
                - v2) <= 0.0
       || (float)((float)((float)((float)((float)(other->m_plane.mVec128.m128_f32[2]
                                                * this->m_vertices[1].mVec128.m128_f32[2])
                                        + (float)(other->m_plane.mVec128.m128_f32[1]
                                                * this->m_vertices[1].mVec128.m128_f32[1]))
                                + (float)(other->m_plane.mVec128.m128_f32[0] * this->m_vertices[1].mVec128.m128_f32[0]))
                        - other->m_plane.mVec128.m128_f32[3])
                - v2) <= 0.0
       || (float)((float)((float)((float)((float)(this->m_vertices[2].mVec128.m128_f32[2]
                                                * other->m_plane.mVec128.m128_f32[2])
                                        + (float)(this->m_vertices[2].mVec128.m128_f32[1]
                                                * other->m_plane.mVec128.m128_f32[1]))
                                + (float)(other->m_plane.mVec128.m128_f32[0] * this->m_vertices[2].mVec128.m128_f32[0]))
                        - other->m_plane.mVec128.m128_f32[3])
                - v2) <= 0.0);
}
