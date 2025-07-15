void __usercall vostok::collision::colliders::ray_test_geometry::test_primitive(
        vostok::collision::colliders::ray_test_geometry *this@<esi>,
        unsigned int *triangle@<edi>)
{
  unsigned int v2; // eax
  const fastdelegate::FastDelegate<bool __cdecl(vostok::collision::ray_triangle_result const &)> *m_predicate; // eax
  _DWORD v4[3]; // [esp+0h] [ebp-10h] BYREF
  float range; // [esp+Ch] [ebp-4h] BYREF

  if ( vostok::collision::colliders::ray_geometry_base::test_triangle(this, triangle, &range) )
  {
    v2 = *triangle;
    v4[0] = 0;
    v4[1] = v2;
    m_predicate = this->m_predicate;
    *(float *)&v4[2] = range;
    this->m_result = ((int (__thiscall *)(fastdelegate::detail::GenericClass *, _DWORD *))m_predicate->m_Closure.m_pFunction)(
                       m_predicate->m_Closure.m_pthis,
                       v4);
  }
}
