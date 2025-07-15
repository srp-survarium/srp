vostok::math::aabb *__thiscall vostok::collision::triangle_mesh_geometry_instance::get_aabb(
        vostok::collision::triangle_mesh_geometry_instance *this,
        vostok::math::aabb *result)
{
  vostok::math::float4x4 *p_m_matrix; // esi
  const vostok::math::float4x4 *v4; // [esp+0h] [ebp-1Ch]
  _BYTE v5[24]; // [esp+4h] [ebp-18h] BYREF

  p_m_matrix = &this->m_matrix;
  this->m_triangle_mesh->get_aabb((vostok::collision::geometry *)this->m_triangle_mesh, (vostok::math::aabb *)v5);
  *result = *vostok::math::aabb::modify((vostok::math::aabb *)p_m_matrix, v4);
  return result;
}
