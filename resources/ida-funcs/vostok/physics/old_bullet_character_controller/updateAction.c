void __userpurge vostok::physics::old_bullet_character_controller::updateAction(
        vostok::physics::old_bullet_character_controller *this@<ecx>,
        float a2@<xmm0>,
        btCollisionWorld *__formal,
        const btVector3 *deltaTime)
{
  int i; // esi
  btVector3 v6; // [esp+18h] [ebp-10h] BYREF

  v6.mVec128 = (__m128)this->m_ghost_object.m_worldTransform.m_origin;
  for ( i = 0; i <= 2; ++i )
  {
    vostok::physics::old_bullet_character_controller::recover_from_penetration(this, (int)this, i);
    if ( a2 <= 0.050000001 )
      break;
  }
  this->m_current_pos.mVec128.m128_i32[0] = this->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_i32[0];
  this->m_current_pos.mVec128.m128_i32[1] = this->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_i32[1];
  this->m_current_pos.mVec128.m128_i32[2] = this->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_i32[2];
  this->m_current_pos.mVec128.m128_i32[3] = this->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_i32[3];
  vostok::physics::old_bullet_character_controller::player_step(this, this, deltaTime, &v6);
  this->m_walk_vector.mVec128.m128_i32[0] = 0;
  this->m_walk_vector.mVec128.m128_i32[1] = 0;
  this->m_walk_vector.mVec128.m128_i32[2] = 0;
  this->m_walk_vector.mVec128.m128_i32[3] = 0;
  this->m_air_control_vector.mVec128.m128_i32[0] = 0;
  this->m_air_control_vector.mVec128.m128_i32[1] = 0;
  this->m_air_control_vector.mVec128.m128_i32[2] = 0;
  this->m_air_control_vector.mVec128.m128_i32[3] = 0;
}
