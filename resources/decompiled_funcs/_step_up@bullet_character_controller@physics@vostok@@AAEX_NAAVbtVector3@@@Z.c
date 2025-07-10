void __usercall vostok::physics::bullet_character_controller::step_up(
        vostok::physics::bullet_character_controller *this@<eax>,
        btVector3 *pos_up_correction@<ecx>)
{
  float y; // xmm2_4
  float x; // xmm4_4
  float v4; // xmm1_4
  btVector3 v5; // [esp+0h] [ebp-10h]

  y = this->m_current_shape_dim.y;
  x = this->m_current_shape_dim.x;
  if ( (float)((float)(y - x) - s_step_height) >= 0.0 )
    v4 = (float)(this->m_current_shape_dim.y - x) - s_step_height;
  else
    v4 = 0.0;
  v5.mVec128.m128_f32[0] = x * 0.5;
  v5.mVec128.m128_f32[2] = x * 0.5;
  v5.mVec128.m128_f32[1] = (float)((float)(x + v4) - x) * 0.5;
  v5.mVec128.m128_i32[3] = 0;
  this->m_shape.m_implicitShapeDimensions = (btVector3)v5.mVec128;
  pos_up_correction->mVec128.m128_i32[2] = 0;
  pos_up_correction->mVec128.m128_i32[0] = 0;
  pos_up_correction->mVec128.m128_i32[3] = 0;
  pos_up_correction->mVec128.m128_f32[1] = (float)(y - (float)(x + v4)) * 0.5;
  this->m_current_pos.mVec128.m128_f32[0] = this->m_current_pos.mVec128.m128_f32[0];
  this->m_current_pos.mVec128.m128_f32[1] = pos_up_correction->mVec128.m128_f32[1]
                                          + this->m_current_pos.mVec128.m128_f32[1];
  this->m_current_pos.mVec128.m128_f32[2] = this->m_current_pos.mVec128.m128_f32[2]
                                          + pos_up_correction->mVec128.m128_f32[2];
  this->m_current_step_offset = pos_up_correction->mVec128.m128_f32[1];
}
