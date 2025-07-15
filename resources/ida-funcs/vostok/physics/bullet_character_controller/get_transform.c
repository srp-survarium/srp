btTransform *__thiscall vostok::physics::bullet_character_controller::get_transform(
        vostok::physics::bullet_character_controller *this,
        btTransform *result)
{
  _BYTE v3[16]; // [esp+10h] [ebp-10h] BYREF

  *result = this->m_ghost_object.m_worldTransform;
  result->m_origin = (btVector3)vostok::physics::capsule_center_to_bottom_position(
                                  &result->m_origin,
                                  &this->m_shape,
                                  (int)v3)->mVec128;
  return result;
}
