vostok::math::float4x4 *__thiscall vostok::physics::bt_static_rigid_body::get_transform(
        vostok::physics::bt_static_rigid_body *this,
        vostok::math::float4x4 *result)
{
  vostok::physics::from_bullet(&this->m_bt_body->m_worldTransform);
  return result;
}
