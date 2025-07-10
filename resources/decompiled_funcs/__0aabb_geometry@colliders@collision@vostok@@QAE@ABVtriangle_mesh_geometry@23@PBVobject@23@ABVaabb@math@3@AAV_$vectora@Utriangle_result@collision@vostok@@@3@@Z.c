void __userpurge vostok::collision::colliders::aabb_geometry::aabb_geometry(
        vostok::collision::colliders::aabb_geometry *this@<esi>,
        const vostok::math::aabb *aabb@<eax>,
        vostok::vectora<vostok::collision::triangle_result> *triangles@<ecx>,
        const vostok::collision::triangle_mesh_geometry *geometry,
        const vostok::collision::object *object)
{
  float v5; // xmm2_4
  float v6; // eax
  unsigned int v7; // edi
  __int64 v8; // [esp+0h] [ebp-Ch]

  this->m_aabb = aabb;
  this->m_triangles = triangles;
  this->m_geometry = geometry;
  this->m_object = object;
  v5 = aabb->max.z + aabb->min.z;
  *(float *)&v8 = (float)(aabb->max.x + aabb->min.x) * 0.5;
  *((float *)&v8 + 1) = (float)(aabb->max.y + aabb->min.y) * 0.5;
  *(_QWORD *)&this->m_center.x = v8;
  this->m_center.z = v5 * 0.5;
  *(float *)&v8 = aabb->max.x - this->m_center.x;
  *((float *)&v8 + 1) = aabb->max.y - this->m_center.y;
  v6 = aabb->max.z - this->m_center.z;
  *(_QWORD *)&this->m_extents.x = v8;
  this->m_extents.z = v6;
  v7 = triangles->_M_impl._M_finish - triangles->_M_impl._M_start;
  vostok::collision::colliders::aabb_geometry::query(this, geometry->m_root);
  this->m_result = this->m_triangles->_M_impl._M_finish - this->m_triangles->_M_impl._M_start > v7;
}
