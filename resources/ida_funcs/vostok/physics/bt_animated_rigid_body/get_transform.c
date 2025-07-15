vostok::math::float4x4 *__thiscall vostok::physics::bt_animated_rigid_body::get_transform(
        vostok::physics::bt_animated_rigid_body *this,
        vostok::math::float4x4 *result)
{
  vostok::physics::from_bullet(&this->m_bt_body->m_worldTransform, (btMatrix3x3 *)this, result);
  return result;
}
