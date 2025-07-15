bool __thiscall vostok::collision::helper::predicate(
        vostok::collision::helper *this,
        const vostok::collision::ray_triangle_result *triangle)
{
  float distance; // xmm0_4

  distance = triangle->distance;
  if ( distance <= *this->m_distance )
  {
    *this->m_distance = distance;
    *this->m_result = 1;
  }
  return 0;
}
