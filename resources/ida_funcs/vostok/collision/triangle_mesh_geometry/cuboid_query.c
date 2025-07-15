bool __thiscall vostok::collision::triangle_mesh_geometry::cuboid_query(
        vostok::collision::triangle_mesh_geometry *this,
        const vostok::collision::object *object,
        const vostok::math::cuboid *cuboid,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  unsigned int v4; // esi
  vostok::collision::colliders::cuboid_geometry v6; // [esp+4h] [ebp-14h] BYREF

  v6.m_cuboid = cuboid;
  v6.m_geometry = this;
  v6.m_triangles = triangles;
  v6.m_object = object;
  v4 = triangles->_M_impl._M_finish - triangles->_M_impl._M_start;
  vostok::collision::colliders::cuboid_geometry::query(&v6, this->m_root);
  return v6.m_triangles->_M_impl._M_finish - v6.m_triangles->_M_impl._M_start > v4;
}
