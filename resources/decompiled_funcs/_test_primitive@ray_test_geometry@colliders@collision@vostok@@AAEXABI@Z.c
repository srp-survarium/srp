void __usercall vostok::collision::colliders::ray_test_geometry::test_primitive(
        vostok::collision::colliders::ray_test_geometry *this@<eax>,
        unsigned int *triangle@<edi>)
{
  const fastdelegate::FastDelegate<bool __cdecl(vostok::collision::ray_triangle_result const &)> *m_predicate; // eax
  float range; // [esp+4h] [ebp-10h] BYREF
  _DWORD v5[3]; // [esp+8h] [ebp-Ch] BYREF

  if ( vostok::collision::colliders::ray_geometry_base::test_triangle(this, triangle, &range) )
  {
    m_predicate = this->m_predicate;
    v5[1] = *triangle;
    v5[0] = 0;
    *(float *)&v5[2] = range;
    this->m_result = ((int (__thiscall *)(fastdelegate::detail::GenericClass *, _DWORD *))m_predicate->m_Closure.m_pFunction)(
                       m_predicate->m_Closure.m_pthis,
                       v5);
  }
}
