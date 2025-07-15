char __userpurge vostok::render::culling::sector_double_query_preventer::is_possible_points_for_frustum@<al>(
        vostok::render::culling::sector_double_query_preventer *this@<ecx>,
        unsigned int sector_id@<eax>,
        const vostok::math::float3 (*vertices)[4])
{
  vostok::fixed_vector<vostok::math::frustum,1024> *v3; // eax
  const vostok::math::cuboid *m_begin; // esi
  vostok::math::frustum *m_end; // edi
  const vostok::math::float3 *i; // ebx
  int v8; // [esp+Ch] [ebp-4h]

  v3 = &this->m_sectors_max_frustums->m_begin[sector_id];
  m_begin = v3->m_begin;
  m_end = v3->m_end;
  while ( m_begin != m_end )
  {
    v8 = 0;
    for ( i = (const vostok::math::float3 *)vertices; vostok::math::is_point_inside_cuboid(i, m_begin); ++i )
    {
      if ( (unsigned int)++v8 >= 4 )
        return 0;
    }
    ++m_begin;
  }
  return 1;
}
