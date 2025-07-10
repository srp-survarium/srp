vostok::math::aabb *__thiscall vostok::collision::collision_object::update_aabb(
        vostok::collision::collision_object *this,
        vostok::math::aabb *result,
        const vostok::math::float4x4 *local_to_world)
{
  this->m_geometry_instance->set_matrix(this->m_geometry_instance, local_to_world);
  this->m_geometry_instance->get_aabb(this->m_geometry_instance, result);
  return result;
}
