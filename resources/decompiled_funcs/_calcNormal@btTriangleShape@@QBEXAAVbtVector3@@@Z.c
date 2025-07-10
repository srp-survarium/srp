void __usercall btTriangleShape::calcNormal(btTriangleShape *this@<eax>, btVector3 *normal@<esi>)
{
  float v2; // xmm2_4
  float v3; // xmm0_4
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm1_4
  float v8; // [esp+4h] [ebp-20h]
  unsigned __int64 v9; // [esp+8h] [ebp-1Ch]
  float v10; // [esp+10h] [ebp-14h]
  unsigned __int64 v11; // [esp+14h] [ebp-10h]

  v2 = this->m_vertices1[2].mVec128.m128_f32[2] - this->m_vertices1[0].mVec128.m128_f32[2];
  v3 = this->m_vertices1[1].mVec128.m128_f32[0] - this->m_vertices1[0].mVec128.m128_f32[0];
  v4 = this->m_vertices1[1].mVec128.m128_f32[1] - this->m_vertices1[0].mVec128.m128_f32[1];
  v5 = this->m_vertices1[2].mVec128.m128_f32[0] - this->m_vertices1[0].mVec128.m128_f32[0];
  v6 = this->m_vertices1[2].mVec128.m128_f32[1] - this->m_vertices1[0].mVec128.m128_f32[1];
  v7 = this->m_vertices1[1].mVec128.m128_f32[2] - this->m_vertices1[0].mVec128.m128_f32[2];
  *((float *)&v11 + 1) = (float)(v7 * v5) - (float)(v2 * v3);
  *(float *)&v11 = (float)(v2 * v4) - (float)(v7 * v6);
  normal->mVec128.m128_u64[0] = v11;
  normal->mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)(v3 * v6) - (float)(v4 * v5));
  v9 = normal->mVec128.m128_u64[0];
  v10 = normal->mVec128.m128_f32[2];
  v8 = 1.0
     / sqrtf(
         (float)((float)(*(float *)&v9 * *(float *)&v9) + (float)(*((float *)&v9 + 1) * *((float *)&v9 + 1)))
       + (float)(v10 * v10));
  normal->mVec128.m128_f32[0] = *(float *)&v9 * v8;
  normal->mVec128.m128_f32[1] = *((float *)&v9 + 1) * v8;
  normal->mVec128.m128_f32[2] = v10 * v8;
}
