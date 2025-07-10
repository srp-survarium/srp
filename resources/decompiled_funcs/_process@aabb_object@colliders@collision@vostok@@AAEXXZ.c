void __usercall vostok::collision::colliders::aabb_object::process(
        vostok::collision::colliders::aabb_object *this@<ecx>,
        bool a2@<bpl>,
        vostok::collision::colliders::aabb_object *a3@<edi>)
{
  vostok::vectora<vostok::collision::object const *> *m_objects; // eax
  unsigned int v4; // esi
  vostok::vectora<vostok::collision::object const *> *v5; // ecx
  unsigned int v6; // eax

  m_objects = a3->m_objects;
  if ( m_objects )
    v4 = m_objects->_M_impl._M_finish - m_objects->_M_impl._M_start;
  else
    v4 = a3->m_triangles->_M_impl._M_finish - a3->m_triangles->_M_impl._M_start;
  vostok::collision::colliders::aabb_object::query(
    a3,
    a2,
    (const stlp_std::__true_type *)a3,
    v4,
    a3->m_tree->m_root,
    COERCE_FLOAT((int)&a3->m_tree->m_aabb_center),
    a3->m_tree->m_aabb_extents);
  v5 = a3->m_objects;
  if ( v5 )
    v6 = v5->_M_impl._M_finish - v5->_M_impl._M_start;
  else
    v6 = a3->m_triangles->_M_impl._M_finish - a3->m_triangles->_M_impl._M_start;
  a3->m_result = v6 > v4;
}
