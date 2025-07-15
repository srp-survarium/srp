void __thiscall vostok::render::culling::sector_double_query_preventer::clear(
        vostok::render::culling::sector_double_query_preventer *this)
{
  vostok::buffer_vector<vostok::fixed_vector<vostok::math::frustum,1024> > *m_sectors_max_frustums; // eax
  vostok::fixed_vector<vostok::math::frustum,1024> *m_end; // edx
  vostok::fixed_vector<vostok::math::frustum,1024> *i; // eax
  vostok::buffer_vector<vostok::fixed_vector<vostok::render::culling::aab_rect,1024> > *m_sectors_max_rects; // eax
  vostok::fixed_vector<vostok::render::culling::aab_rect,1024> *v5; // ecx
  vostok::fixed_vector<vostok::render::culling::aab_rect,1024> *j; // eax

  m_sectors_max_frustums = this->m_sectors_max_frustums;
  m_end = m_sectors_max_frustums->m_end;
  for ( i = m_sectors_max_frustums->m_begin;
        i != m_end;
        i = (vostok::fixed_vector<vostok::math::frustum,1024> *)((char *)i + (_DWORD)&loc_1E00A + 2) )
  {
    i->m_end = i->m_begin;
  }
  m_sectors_max_rects = this->m_sectors_max_rects;
  v5 = m_sectors_max_rects->m_end;
  for ( j = m_sectors_max_rects->m_begin; j != v5; ++j )
    j->m_end = j->m_begin;
}
