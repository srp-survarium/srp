char __userpurge vostok::render::culling::sector_double_query_preventer::is_aabb_in_sector@<al>(
        vostok::render::culling::sector_double_query_preventer *this@<ecx>,
        unsigned int sector_id@<eax>,
        const vostok::math::aabb *bbox)
{
  vostok::buffer_vector<vostok::render::vector<vostok::math::frustum> > *m_sectors_max_frustums; // edx
  vostok::math::cuboid *m_begin; // ecx
  unsigned int v5; // eax
  vostok::math::frustum *M_start; // esi
  vostok::math::frustum *M_finish; // edi

  m_sectors_max_frustums = this->m_sectors_max_frustums;
  m_begin = (vostok::math::cuboid *)m_sectors_max_frustums->m_begin;
  v5 = sector_id;
  M_start = m_sectors_max_frustums->m_begin[v5]._M_impl._M_start;
  M_finish = m_sectors_max_frustums->m_begin[v5]._M_impl._M_finish;
  if ( M_start == M_finish )
    return 0;
  while ( vostok::math::cuboid::test_inexact(m_begin, bbox) == intersection_outside )
  {
    if ( ++M_start == M_finish )
      return 0;
  }
  return 1;
}
