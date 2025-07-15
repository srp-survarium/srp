void __userpurge vostok::render::culling::sector_double_query_preventer::sector_double_query_preventer(
        unsigned int sectors_count@<eax>,
        vostok::render::culling::sector_double_query_preventer *this,
        const vostok::render::culling::spatial_sector *sectors)
{
  unsigned int v5; // esi
  vostok::buffer_vector<vostok::render::vector<vostok::math::frustum> > *v6; // eax
  int v7; // ebp
  vostok::render::vector<vostok::math::frustum> *m_buffer_for_frustum_vectors; // ecx
  vostok::buffer_vector<vostok::render::vector<vostok::render::culling::aab_rect> > *v9; // eax
  vostok::render::vector<vostok::math::frustum> *m_buffer_for_rect_vectors; // ecx
  vostok::render::vector<vostok::math::frustum> *v11; // ecx
  unsigned int *p_m_portals_count; // esi
  stlp_std::priv::_Impl_vector<vostok::render::culling::aab_rect,vostok::render::std_allocator<vostok::render::culling::aab_rect> > *v13; // ecx
  vostok::render::culling::sector_double_query_preventer *thisa; // [esp+18h] [ebp+4h]

  v5 = 12 * sectors_count;
  this->m_buffer_for_frustum_vectors = vostok::memory::doug_lea_allocator::malloc_impl(
                                         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                         12 * sectors_count);
  v6 = (vostok::buffer_vector<vostok::render::vector<vostok::math::frustum> > *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                                  (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                                                  8u);
  v7 = 0;
  if ( v6 )
  {
    m_buffer_for_frustum_vectors = (vostok::render::vector<vostok::math::frustum> *)this->m_buffer_for_frustum_vectors;
    v6->m_begin = (vostok::render::vector<vostok::math::frustum> *)this->m_buffer_for_frustum_vectors;
    v6->m_end = m_buffer_for_frustum_vectors;
  }
  else
  {
    v6 = 0;
  }
  this->m_sectors_max_frustums = v6;
  this->m_buffer_for_rect_vectors = vostok::memory::doug_lea_allocator::malloc_impl(
                                      (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                      v5);
  v9 = (vostok::buffer_vector<vostok::render::vector<vostok::render::culling::aab_rect> > *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                                                              8u);
  if ( v9 )
  {
    m_buffer_for_rect_vectors = (vostok::render::vector<vostok::math::frustum> *)this->m_buffer_for_rect_vectors;
    v9->m_begin = (vostok::render::vector<vostok::render::culling::aab_rect> *)m_buffer_for_rect_vectors;
    v9->m_end = (vostok::render::vector<vostok::render::culling::aab_rect> *)m_buffer_for_rect_vectors;
  }
  else
  {
    v9 = 0;
  }
  this->m_sectors_max_rects = v9;
  this->m_frustum_images._M_impl._M_start = 0;
  this->m_frustum_images._M_impl._M_finish = 0;
  this->m_frustum_images._M_impl._M_end_of_storage._M_data = 0;
  vostok::buffer_vector<vostok::render::vector<vostok::math::frustum>>::resize(
    this->m_sectors_max_frustums,
    sectors_count,
    m_buffer_for_rect_vectors);
  vostok::buffer_vector<vostok::render::vector<vostok::math::frustum>>::resize(
    (vostok::buffer_vector<vostok::render::vector<vostok::math::frustum> > *)this->m_sectors_max_rects,
    sectors_count,
    v11);
  if ( sectors_count )
  {
    p_m_portals_count = &sectors->m_portals_count;
    thisa = (vostok::render::culling::sector_double_query_preventer *)sectors_count;
    do
    {
      stlp_std::priv::_Impl_vector<vostok::math::frustum,vostok::render::std_allocator<vostok::math::frustum>>::reserve(
        (stlp_std::priv::_Impl_vector<vostok::math::frustum,vostok::render::std_allocator<vostok::math::frustum> > *)this->m_sectors_max_frustums,
        (int)&this->m_sectors_max_frustums->m_begin[v7],
        2 * *p_m_portals_count);
      stlp_std::priv::_Impl_vector<vostok::render::culling::aab_rect,vostok::render::std_allocator<vostok::render::culling::aab_rect>>::reserve(
        v13,
        &this->m_sectors_max_rects->m_begin[v7]._M_impl._M_start,
        2 * *p_m_portals_count);
      p_m_portals_count += 8;
      ++v7;
      thisa = (vostok::render::culling::sector_double_query_preventer *)((char *)thisa - 1);
    }
    while ( thisa );
  }
}
