void __userpurge vostok::physics::bullet_character_controller::set_desired_walk_vector(
        const btVector3 *walk_vector@<eax>,
        vostok::physics::bullet_character_controller *this)
{
  btVector3 v2; // [esp+Ch] [ebp-10h] BYREF

  this->m_has_updates = 0;
  this->m_walk_vector = (btVector3)walk_vector->mVec128;
  if ( this->m_walk_vector.mVec128.m128_f32[0] != 0.0
    || this->m_walk_vector.mVec128.m128_f32[1] != 0.0
    || this->m_walk_vector.mVec128.m128_f32[2] != 0.0 )
  {
    this->m_normalizedDirection = (btVector3)vostok::physics::getNormalizedVector(&this->m_walk_vector, &v2)->mVec128;
  }
  this->m_walk_vector_applied = 0;
}
