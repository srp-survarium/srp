vostok::math::aabb *__thiscall vostok::collision::triangle_mesh_geometry::get_aabb(
        vostok::collision::triangle_mesh_geometry *this,
        vostok::math::aabb *result)
{
  vostok::math::aabb *v2; // eax

  v2 = result;
  qmemcpy(result, &this->m_bounding_aabb, sizeof(vostok::math::aabb));
  return v2;
}
