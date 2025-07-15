vostok::math::aabb *__thiscall vostok::collision::cylinder_geometry_instance::get_aabb(
        vostok::collision::cylinder_geometry_instance *this,
        vostok::math::aabb *result)
{
  *result = *vostok::math::aabb::modify(
               (vostok::math::aabb *)&this->m_matrix,
               (const vostok::math::float4x4 *)0xBF800000);
  return result;
}
