void __usercall vostok::physics::old_bullet_character_controller::set_desired_walk_vector(
        vostok::physics::old_bullet_character_controller *this@<edx>,
        const btVector3 *walk_vector@<eax>)
{
  btVector3 *NormalizedVector; // eax
  btVector3 v3; // [esp+0h] [ebp-10h] BYREF

  this->m_has_updates = 0;
  this->m_walk_vector = (btVector3)walk_vector->mVec128;
  if ( this->m_walk_vector.mVec128.m128_f32[0] != 0.0
    || this->m_walk_vector.mVec128.m128_f32[1] != 0.0
    || this->m_walk_vector.mVec128.m128_f32[2] != 0.0 )
  {
    NormalizedVector = vostok::physics::getNormalizedVector(&this->m_walk_vector, &v3);
    this->m_normalizedDirection = (btVector3)NormalizedVector->mVec128;
  }
  this->m_walk_vector_applied = 0;
}
