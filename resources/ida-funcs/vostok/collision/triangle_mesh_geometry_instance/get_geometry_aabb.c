vostok::math::aabb *__thiscall vostok::collision::triangle_mesh_geometry_instance::get_geometry_aabb(
        vostok::collision::triangle_mesh_geometry_instance *this,
        vostok::math::aabb *result)
{
  this->m_triangle_mesh->get_aabb((vostok::collision::geometry *)this->m_triangle_mesh, result);
  return result;
}
