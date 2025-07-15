BOOL __fastcall character_step_down_sweep_test_callback::is_side_contact(
        const btVector3 *hit_point,
        const btVector3 *hit_normal,
        character_step_down_sweep_test_callback *this)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm5_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float m_capsule_radius2; // xmm0_4
  float v12; // xmm2_4
  bool v13; // cl
  bool v14; // al

  v3 = hit_point->mVec128.m128_f32[0] - this->m_center.mVec128.m128_f32[0];
  v4 = hit_point->mVec128.m128_f32[1] - this->m_center.mVec128.m128_f32[1];
  v5 = hit_point->mVec128.m128_f32[2] - this->m_center.mVec128.m128_f32[2];
  v6 = (float)((float)(this->m_up_vector.mVec128.m128_f32[0] * v3) + (float)(this->m_up_vector.mVec128.m128_f32[1] * v4))
     + (float)(this->m_up_vector.mVec128.m128_f32[2] * v5);
  v7 = this->m_up_vector.mVec128.m128_f32[2] * v6;
  v8 = v3 - (float)(this->m_up_vector.mVec128.m128_f32[0] * v6);
  v9 = (float)(v4 - (float)(this->m_up_vector.mVec128.m128_f32[1] * v6))
     * (float)(v4 - (float)(this->m_up_vector.mVec128.m128_f32[1] * v6));
  v10 = v8 * v8;
  m_capsule_radius2 = this->m_capsule_radius2;
  v12 = (float)((float)((float)(v5 - v7) * (float)(v5 - v7)) + v9) + v10;
  v13 = m_capsule_radius2 > v12 && fabs(v12 - m_capsule_radius2) >= 0.0000099999997;
  v14 = fabs(
          (float)((float)(this->m_up_vector.mVec128.m128_f32[2] * hit_normal->mVec128.m128_f32[2])
                + (float)(this->m_up_vector.mVec128.m128_f32[1] * hit_normal->mVec128.m128_f32[1]))
        + (float)(this->m_up_vector.mVec128.m128_f32[0] * hit_normal->mVec128.m128_f32[0])) < 0.001;
  return !v13 && v14;
}
