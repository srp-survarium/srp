void __userpurge vostok::collision::colliders::cuboid_geometry::cuboid_geometry(
        vostok::collision::colliders::cuboid_geometry *this@<esi>,
        const vostok::collision::triangle_mesh_geometry *geometry@<ecx>,
        vostok::vectora<vostok::collision::triangle_result> *triangles@<eax>,
        const vostok::collision::object *object,
        const vostok::math::cuboid *cuboid)
{
  unsigned int v5; // edi

  this->m_cuboid = cuboid;
  this->m_geometry = geometry;
  this->m_triangles = triangles;
  this->m_object = object;
  v5 = triangles->_M_impl._M_finish - triangles->_M_impl._M_start;
  vostok::collision::colliders::cuboid_geometry::query(this, geometry->m_root);
  this->m_result = this->m_triangles->_M_impl._M_finish - this->m_triangles->_M_impl._M_start > v5;
}
