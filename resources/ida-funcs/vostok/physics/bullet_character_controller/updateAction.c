void __thiscall vostok::physics::bullet_character_controller::updateAction(
        vostok::physics::bullet_character_controller *this,
        btCollisionWorld *__formal,
        float deltaTime)
{
  vostok::physics::bullet_character_controller::player_step(this, this, deltaTime);
  this->m_walk_vector.mVec128.m128_i32[0] = 0;
  this->m_walk_vector.mVec128.m128_i32[1] = 0;
  this->m_walk_vector.mVec128.m128_i32[2] = 0;
  this->m_walk_vector.mVec128.m128_i32[3] = 0;
  this->m_air_control_vector.mVec128.m128_i32[0] = 0;
  this->m_air_control_vector.mVec128.m128_i32[1] = 0;
  this->m_air_control_vector.mVec128.m128_i32[2] = 0;
  this->m_air_control_vector.mVec128.m128_i32[3] = 0;
}
