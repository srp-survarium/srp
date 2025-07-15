BOOL __userpurge vostok::render::sort_by_distance_predicate::operator()@<eax>(
        const vostok::render::render_surface_instance *left@<ecx>,
        const vostok::render::render_surface_instance *right@<eax>,
        vostok::render::sort_by_distance_predicate *this)
{
  float m_distance_to_viewer; // xmm0_4
  BOOL result; // eax

  if ( this->m_from_near_to_far )
  {
    m_distance_to_viewer = right->m_distance_to_viewer;
    result = 0;
    if ( m_distance_to_viewer <= left->m_distance_to_viewer )
      return result;
    return 1;
  }
  return left->m_distance_to_viewer > right->m_distance_to_viewer;
}
