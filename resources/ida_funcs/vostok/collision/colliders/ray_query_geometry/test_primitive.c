void __usercall vostok::collision::colliders::ray_query_geometry::test_primitive(
        vostok::collision::colliders::ray_query_geometry *this@<eax>,
        unsigned int *triangle@<edi>)
{
  unsigned int v3; // edx
  const fastdelegate::FastDelegate<bool __cdecl(vostok::collision::ray_triangle_result const &)> *m_predicate; // eax
  stlp_std::priv::_Impl_vector<vostok::math::float3,vostok::vectora_allocator<vostok::math::float3> > *v5; // ecx
  vostok::vectora<vostok::collision::ray_triangle_result> *m_triangles; // esi
  vostok::collision::ray_triangle_result *M_finish; // eax
  const stlp_std::__true_type *v8; // [esp+0h] [ebp-14h]
  float range; // [esp+4h] [ebp-10h] BYREF
  vostok::collision::ray_triangle_result result; // [esp+8h] [ebp-Ch] BYREF

  if ( vostok::collision::colliders::ray_geometry_base::test_triangle(this, triangle, &range) )
  {
    v3 = *triangle;
    m_predicate = this->m_predicate;
    result.object = this->m_object;
    result.triangle_id = v3;
    result.distance = range;
    ((void (__thiscall *)(fastdelegate::detail::GenericClass *, vostok::collision::ray_triangle_result *))m_predicate->m_Closure.m_pFunction)(
      m_predicate->m_Closure.m_pthis,
      &result);
    m_triangles = this->m_triangles;
    M_finish = m_triangles->_M_impl._M_finish;
    if ( M_finish == m_triangles->_M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::math::float3,vostok::vectora_allocator<vostok::math::float3>>::_M_insert_overflow(
        v5,
        (unsigned __int8 **)m_triangles,
        (int)M_finish,
        (const vostok::math::float3 *)&result,
        v8,
        LODWORD(range),
        (bool)result.object);
    }
    else
    {
      if ( M_finish )
        *M_finish = result;
      ++m_triangles->_M_impl._M_finish;
    }
  }
}
