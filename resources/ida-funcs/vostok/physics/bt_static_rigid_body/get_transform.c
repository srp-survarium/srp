vostok::math::float4x4 *__userpurge vostok::physics::bt_static_rigid_body::get_transform@<eax>(
        vostok::physics::bt_static_rigid_body *this@<ecx>,
        long double a2@<esi:edi>,
        vostok::math::float4x4 *result)
{
  HIDWORD(a2) = &this->m_bt_body->m_worldTransform;
  vostok::physics::from_bullet(a2, result);
  return result;
}
