void __usercall vostok::collision::colliders::ray_query_geometry::test_primitive(
        vostok::collision::colliders::ray_query_geometry *this@<esi>,
        unsigned int *triangle@<edi>)
{
  const fastdelegate::FastDelegate<bool __cdecl(vostok::collision::ray_triangle_result const &)> *m_predicate; // eax
  vostok::buffer_vector<vostok::collision::ray_triangle_result> *v3; // ecx
  _DWORD v4[3]; // [esp+0h] [ebp-10h] BYREF
  float range; // [esp+Ch] [ebp-4h] BYREF

  if ( vostok::collision::colliders::ray_geometry_base::test_triangle(this, triangle, &range) )
  {
    v4[0] = this->m_object;
    v4[1] = *triangle;
    m_predicate = this->m_predicate;
    *(float *)&v4[2] = range;
    ((void (__thiscall *)(fastdelegate::detail::GenericClass *, _DWORD *))m_predicate->m_Closure.m_pFunction)(
      m_predicate->m_Closure.m_pthis,
      v4);
    vostok::buffer_vector<vostok::collision::ray_triangle_result>::push_back(
      v3,
      (const vostok::collision::ray_triangle_result *)this->m_triangles,
      v4);
  }
}
