vostok::math::aabb *__thiscall vostok::collision::box_geometry_instance::get_aabb(
        vostok::collision::box_geometry_instance *this,
        vostok::math::aabb *result)
{
  *result = *vostok::math::aabb::modify((vostok::math::aabb *)&this->m_matrix, clear_value);
  return result;
}
