void __usercall vostok::collision::colliders::aabb_geometry::test_primitive(
        vostok::collision::colliders::aabb_geometry *this@<ecx>,
        float triangle_id@<eax>)
{
  const vostok::collision::object *m_object; // ecx
  float v5; // edx
  vostok::vectora<vostok::collision::triangle_result> *m_triangles; // esi
  float *M_finish; // eax
  const stlp_std::__true_type *v8; // [esp+0h] [ebp-10h]
  unsigned int v9; // [esp+4h] [ebp-Ch]
  vostok::collision::ray_object_result __x; // [esp+8h] [ebp-8h] BYREF

  if ( vostok::collision::colliders::aabb_geometry::test_triangle(this, LODWORD(triangle_id)) )
  {
    m_object = this->m_object;
    v5 = triangle_id;
    m_triangles = this->m_triangles;
    M_finish = (float *)m_triangles->_M_impl._M_finish;
    __x.object = m_object;
    __x.distance = v5;
    if ( M_finish == (float *)m_triangles->_M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)&__x,
        (unsigned __int8 **)m_triangles,
        (int)M_finish,
        &__x,
        v8,
        v9,
        (bool)__x.object);
    }
    else
    {
      if ( M_finish )
      {
        *(_DWORD *)M_finish = m_object;
        M_finish[1] = v5;
      }
      ++m_triangles->_M_impl._M_finish;
    }
  }
}
