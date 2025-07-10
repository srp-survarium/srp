char __userpurge vostok::render::culling::sector_double_query_preventer::is_possible_points_for_frustum@<al>(
        vostok::render::culling::sector_double_query_preventer *this@<ecx>,
        unsigned int sector_id@<eax>,
        const vostok::math::float3 (*vertices)[4])
{
  vostok::buffer_vector<vostok::render::vector<vostok::math::frustum> > *m_sectors_max_frustums; // edx
  unsigned int v4; // eax
  const vostok::math::cuboid *M_start; // ebx
  vostok::math::frustum *i; // ebp
  const vostok::math::float3 *v7; // edi
  unsigned int v8; // esi

  m_sectors_max_frustums = this->m_sectors_max_frustums;
  v4 = sector_id;
  M_start = m_sectors_max_frustums->m_begin[v4]._M_impl._M_start;
  for ( i = m_sectors_max_frustums->m_begin[v4]._M_impl._M_finish; M_start != i; ++M_start )
  {
    v7 = (const vostok::math::float3 *)vertices;
    v8 = 0;
    while ( vostok::math::is_point_inside_cuboid(v7, M_start) )
    {
      ++v8;
      ++v7;
      if ( v8 >= 4 )
        return 0;
    }
  }
  return 1;
}
