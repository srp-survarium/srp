char __userpurge vostok::render::culling::sector_double_query_preventer::is_possible_ss_aab_rect@<al>(
        const vostok::render::culling::aab_rect *rect@<edx>,
        unsigned int sector_id@<eax>,
        vostok::render::culling::sector_double_query_preventer *this)
{
  vostok::render::vector<vostok::render::culling::aab_rect> *v3; // eax
  vostok::render::culling::aab_rect *M_finish; // ecx
  float *p_x; // eax
  float x; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float y; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm2_4

  v3 = &this->m_sectors_max_rects->m_begin[sector_id];
  M_finish = v3->_M_impl._M_finish;
  p_x = &v3->_M_impl._M_start->min.x;
  if ( p_x == (float *)M_finish )
    return 1;
  x = rect->min.x;
  while ( 1 )
  {
    if ( x >= *p_x || fabs(*p_x - x) < 0.0000099999997 )
    {
      v7 = p_x[2];
      v8 = rect->max.x;
      if ( v7 >= v8 || fabs(v7 - v8) < 0.0000099999997 )
      {
        v9 = p_x[1];
        y = rect->min.y;
        if ( y >= v9 || fabs(v9 - y) < 0.0000099999997 )
        {
          v11 = p_x[3];
          v12 = rect->max.y;
          if ( v11 >= v12 || fabs(v11 - v12) < 0.0000099999997 )
            break;
        }
      }
    }
    p_x += 4;
    if ( p_x == (float *)M_finish )
      return 1;
  }
  return 0;
}
