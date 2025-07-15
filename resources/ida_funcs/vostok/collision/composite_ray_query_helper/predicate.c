int __thiscall vostok::collision::composite_ray_query_helper::predicate(
        vostok::collision::composite_ray_query_helper *this,
        const vostok::collision::ray_triangle_result *triangle)
{
  float m_min_distance; // xmm0_4

  m_min_distance = (float)this->m_factor * triangle->distance;
  triangle->distance = m_min_distance;
  if ( m_min_distance > this->m_min_distance )
    m_min_distance = this->m_min_distance;
  this->m_min_distance = m_min_distance;
  return ((int (__thiscall *)(fastdelegate::detail::GenericClass *, const vostok::collision::ray_triangle_result *))this->m_predicate->m_Closure.m_pFunction)(
           this->m_predicate->m_Closure.m_pthis,
           triangle);
}
