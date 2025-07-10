void __usercall vostok::render::culling::sector_double_query_preventer::~sector_double_query_preventer(
        vostok::render::culling::sector_double_query_preventer *this@<ecx>,
        vostok::render::culling::sector_double_query_preventer *a2@<edi>)
{
  vostok::render::vector<vostok::math::frustum> **p_m_begin; // esi
  vostok::render::grass_render_model *m_object; // ecx
  vostok::render::grass_render_model *v4; // ebp
  vostok::render::vector<vostok::math::frustum> **v5; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *m_buffer_for_frustum_vectors; // eax
  void *v8; // esi
  vostok::render::vector<vostok::math::frustum> **m_sectors_max_rects; // esi
  vostok::render::grass_render_model *v10; // ebp
  vostok::render::vector<vostok::math::frustum> **v11; // eax
  void *v12; // esi
  void *m_buffer_for_rect_vectors; // eax
  void *v14; // esi
  vostok::render::culling::sector_double_query_preventer::frustum_image *M_start; // eax
  void *v16; // esi

  vostok::render::culling::sector_double_query_preventer::clear(this, a2);
  p_m_begin = &a2->m_sectors_max_frustums->m_begin;
  m_object = vostok::render::g_allocator.m_object;
  v4 = vostok::render::g_allocator.m_object;
  if ( p_m_begin )
  {
    vostok::buffer_vector<vostok::render::vector<vostok::math::frustum>>::destroy(*p_m_begin, p_m_begin + 1);
    p_m_begin[1] = *p_m_begin;
    v5 = p_m_begin;
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(v4->m_reconstruction_info_actuality_tick);
    BYTE2(v4->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v5);
    a2->m_sectors_max_frustums = 0;
    m_object = vostok::render::g_allocator.m_object;
  }
  m_buffer_for_frustum_vectors = a2->m_buffer_for_frustum_vectors;
  if ( a2->m_buffer_for_frustum_vectors )
  {
    v8 = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v8, m_buffer_for_frustum_vectors);
    a2->m_buffer_for_frustum_vectors = 0;
    m_object = vostok::render::g_allocator.m_object;
  }
  m_sectors_max_rects = (vostok::render::vector<vostok::math::frustum> **)a2->m_sectors_max_rects;
  v10 = m_object;
  if ( m_sectors_max_rects )
  {
    vostok::buffer_vector<vostok::render::vector<vostok::math::frustum>>::destroy(
      *m_sectors_max_rects,
      m_sectors_max_rects + 1);
    m_sectors_max_rects[1] = *m_sectors_max_rects;
    v11 = m_sectors_max_rects;
    v12 = (void *)HIDWORD(v10->m_reconstruction_info_actuality_tick);
    BYTE2(v10->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v12, v11);
    a2->m_sectors_max_rects = 0;
    m_object = vostok::render::g_allocator.m_object;
  }
  m_buffer_for_rect_vectors = a2->m_buffer_for_rect_vectors;
  if ( m_buffer_for_rect_vectors )
  {
    v14 = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v14, m_buffer_for_rect_vectors);
    a2->m_buffer_for_rect_vectors = 0;
    m_object = vostok::render::g_allocator.m_object;
  }
  M_start = a2->m_frustum_images._M_impl._M_start;
  if ( M_start )
  {
    v16 = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v16, M_start);
  }
}
