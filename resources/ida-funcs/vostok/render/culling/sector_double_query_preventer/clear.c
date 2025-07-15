void __thiscall vostok::render::culling::sector_double_query_preventer::clear(
        vostok::render::culling::sector_double_query_preventer *this,
        vostok::render::culling::sector_double_query_preventer *thisa)
{
  vostok::buffer_vector<vostok::render::vector<vostok::math::frustum> > *m_sectors_max_frustums; // eax
  vostok::render::vector<vostok::math::frustum> *m_end; // ebx
  vostok::render::vector<vostok::math::frustum> *i; // esi
  vostok::buffer_vector<vostok::render::vector<vostok::render::culling::aab_rect> > *m_sectors_max_rects; // eax
  vostok::render::vector<vostok::render::culling::aab_rect> *v6; // ebx
  vostok::render::vector<vostok::render::culling::aab_rect> *j; // esi

  m_sectors_max_frustums = thisa->m_sectors_max_frustums;
  m_end = m_sectors_max_frustums->m_end;
  for ( i = m_sectors_max_frustums->m_begin; i != m_end; ++i )
  {
    if ( i->_M_impl._M_start != i->_M_impl._M_finish )
      i->_M_impl._M_finish = i->_M_impl._M_start;
  }
  m_sectors_max_rects = thisa->m_sectors_max_rects;
  v6 = m_sectors_max_rects->m_end;
  for ( j = m_sectors_max_rects->m_begin; j != v6; ++j )
  {
    if ( j->_M_impl._M_start != j->_M_impl._M_finish )
      j->_M_impl._M_finish = j->_M_impl._M_start;
  }
}
