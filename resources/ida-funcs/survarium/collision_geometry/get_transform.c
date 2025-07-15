vostok::math::float4x4 *__userpurge survarium::collision_geometry::get_transform@<eax>(
        survarium::collision_geometry *this@<ecx>,
        long double a2@<esi:edi>,
        vostok::math::float4x4 *result)
{
  HIDWORD(a2) = &this->m_ghost_object->m_bt_object->m_worldTransform;
  vostok::physics::from_bullet(a2, result);
  return result;
}
