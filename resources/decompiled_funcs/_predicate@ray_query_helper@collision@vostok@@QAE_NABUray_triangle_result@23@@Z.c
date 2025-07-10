int __thiscall vostok::collision::ray_query_helper::predicate(
        vostok::collision::ray_query_helper *this,
        const vostok::collision::ray_triangle_result *triangle)
{
  triangle->distance = (float)this->m_factor * triangle->distance;
  return ((int (__thiscall *)(fastdelegate::detail::GenericClass *, const vostok::collision::ray_triangle_result *))this->m_predicate->m_Closure.m_pFunction)(
           this->m_predicate->m_Closure.m_pthis,
           triangle);
}
