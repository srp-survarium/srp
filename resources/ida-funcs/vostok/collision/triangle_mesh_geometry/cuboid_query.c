bool __thiscall vostok::collision::triangle_mesh_geometry::cuboid_query(
        vostok::collision::triangle_mesh_geometry *this,
        const vostok::collision::object *object,
        const vostok::math::cuboid *cuboid,
        vostok::buffer_vector<vostok::collision::triangle_result> *triangles)
{
  unsigned int v4; // esi
  vostok::collision::colliders::cuboid_geometry v6; // [esp+4h] [ebp-14h] BYREF

  v6.m_cuboid = cuboid;
  v6.m_geometry = this;
  v6.m_triangles = triangles;
  v6.m_object = object;
  v4 = triangles->m_end - triangles->m_begin;
  vostok::collision::colliders::cuboid_geometry::query(&v6, this->m_root);
  return v6.m_triangles->m_end - v6.m_triangles->m_begin > v4;
}
