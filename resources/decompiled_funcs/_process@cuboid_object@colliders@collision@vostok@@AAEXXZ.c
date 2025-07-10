void __usercall vostok::collision::colliders::cuboid_object::process(
        vostok::collision::colliders::cuboid_object *this@<ecx>,
        bool a2@<bl>,
        vostok::collision::colliders::cuboid_object *a3@<edi>)
{
  vostok::vectora<vostok::collision::object const *> *m_objects; // eax
  unsigned int v4; // esi
  vostok::vectora<vostok::collision::triangle_result> *m_triangles; // eax
  vostok::vectora<vostok::collision::object const *> *v6; // ecx
  vostok::vectora<vostok::collision::triangle_result> *v7; // ecx

  m_objects = a3->m_objects;
  if ( m_objects )
  {
    v4 = m_objects->_M_impl._M_finish - m_objects->_M_impl._M_start;
  }
  else
  {
    m_triangles = a3->m_triangles;
    if ( m_triangles )
      v4 = m_triangles->_M_impl._M_finish - m_triangles->_M_impl._M_start;
    else
      v4 = 0;
  }
  vostok::collision::colliders::cuboid_object::query(
    a3,
    a2,
    (const stlp_std::__true_type *)a3,
    v4,
    a3->m_tree->m_root,
    &a3->m_tree->m_aabb_center,
    a3->m_tree->m_aabb_extents);
  v6 = a3->m_objects;
  if ( v6 )
  {
    a3->m_result = v6->_M_impl._M_finish - v6->_M_impl._M_start > v4;
  }
  else
  {
    v7 = a3->m_triangles;
    if ( v7 )
      a3->m_result = v7->_M_impl._M_finish - v7->_M_impl._M_start > v4;
    else
      a3->m_result = 0;
  }
}
