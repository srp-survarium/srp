BOOL __fastcall vostok::physics::old_bullet_character_controller::sweep_test_key::operator==(
        vostok::physics::old_bullet_character_controller::sweep_test_key *this,
        float *a2)
{
  return a2[3] == this->m_start.mVec128.m128_f32[3]
      && a2[2] == this->m_start.mVec128.m128_f32[2]
      && a2[1] == this->m_start.mVec128.m128_f32[1]
      && *a2 == this->m_start.mVec128.m128_f32[0]
      && a2[7] == this->m_finish.mVec128.m128_f32[3]
      && a2[6] == this->m_finish.mVec128.m128_f32[2]
      && a2[5] == this->m_finish.mVec128.m128_f32[1]
      && a2[4] == this->m_finish.mVec128.m128_f32[0]
      && a2[11] == this->m_up_vector.mVec128.m128_f32[3]
      && a2[10] == this->m_up_vector.mVec128.m128_f32[2]
      && a2[9] == this->m_up_vector.mVec128.m128_f32[1]
      && a2[8] == this->m_up_vector.mVec128.m128_f32[0]
      && a2[16] == this->m_max_slope_angle_cos
      && a2[17] == this->m_capsule_height;
}
