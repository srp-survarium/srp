void __usercall vostok::collision::colliders::cuboid_geometry::add_triangle(
        vostok::collision::colliders::cuboid_geometry *this@<eax>,
        unsigned int triangle_id@<edx>)
{
  const vostok::collision::object *m_object; // ecx
  vostok::vectora<vostok::collision::triangle_result> *m_triangles; // esi
  vostok::collision::triangle_result *M_finish; // eax
  const stlp_std::__true_type *v5; // [esp+0h] [ebp-14h]
  unsigned int v6; // [esp+4h] [ebp-10h]
  _BYTE __x[12]; // [esp+8h] [ebp-Ch] BYREF

  m_object = this->m_object;
  m_triangles = this->m_triangles;
  M_finish = m_triangles->_M_impl._M_finish;
  *(_DWORD *)__x = m_object;
  *(_DWORD *)&__x[4] = triangle_id;
  if ( M_finish == m_triangles->_M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)__x,
      (unsigned __int8 **)m_triangles,
      (int)M_finish,
      (const vostok::collision::ray_object_result *)__x,
      v5,
      v6,
      __x[0]);
  }
  else
  {
    if ( M_finish )
    {
      M_finish->object = m_object;
      M_finish->triangle_id = triangle_id;
    }
    ++m_triangles->_M_impl._M_finish;
  }
}
