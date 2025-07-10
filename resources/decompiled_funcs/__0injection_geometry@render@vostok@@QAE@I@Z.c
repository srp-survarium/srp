void __usercall vostok::render::injection_geometry::injection_geometry(
        vostok::render::injection_geometry *this@<edi>,
        unsigned int rsm_size@<eax>)
{
  unsigned int v3; // eax
  unsigned int v4; // ebp
  float *v5; // eax
  double v6; // st7
  unsigned int v7; // ecx
  double v8; // st6
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v10; // ecx
  vostok::render::res_declaration *m_object; // eax
  bool v12; // zf
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v14; // ecx
  vostok::render::res_state *v15; // ebp
  survarium::options_tab *v16; // ebx
  ID3D11RasterizerState *m_rasterizer_state; // eax
  vostok::render::grass_render_model *v18; // esi
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::math::float2 *vertices_begin; // [esp+Ch] [ebp-10h]
  float v21; // [esp+14h] [ebp-8h]
  float v22; // [esp+18h] [ebp-4h]

  v3 = rsm_size * rsm_size;
  v4 = 0;
  this->m_vertext_declaration.m_object = 0;
  this->m_vertex_buffer.m_object = 0;
  this->m_num_points = v3;
  this->m_stride = 8;
  v5 = (float *)vostok::memory::doug_lea_allocator::malloc_impl(
                  (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                  8 * v3);
  vertices_begin = (vostok::math::float2 *)v5;
  if ( rsm_size )
  {
    v6 = 1.0 / (double)rsm_size;
    do
    {
      v7 = 0;
      do
      {
        v8 = (double)v7 * v6;
        v21 = (double)v4 * v6;
        *v5 = v21;
        ++v7;
        v5 += 2;
        v22 = v8;
        *(v5 - 1) = v22;
      }
      while ( v7 < rsm_size );
      ++v4;
    }
    while ( v4 < rsm_size );
  }
  declaration = vostok::render::resource_manager::create_declaration(
                  1u,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  (stlp_std::forward_iterator_tag *)injection_geometry_vertex_layout);
  v10 = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    v10 = declaration;
  }
  m_object = this->m_vertext_declaration.m_object;
  this->m_vertext_declaration.m_object = v10;
  if ( m_object )
  {
    v12 = m_object->m_reference_count-- == 1;
    if ( v12 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  buffer = vostok::render::resource_manager::create_buffer(
             this->m_num_points * this->m_stride,
             (bool)this,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             vertices_begin,
             enum_buffer_type_vertex,
             0,
             0);
  v14 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v14 = buffer;
  }
  v15 = (vostok::render::res_state *)this->m_vertex_buffer.m_object;
  this->m_vertex_buffer.m_object = v14;
  if ( v15 )
  {
    v12 = v15->m_reference_count-- == 1;
    if ( v12 )
    {
      v16 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
             (vostok::render::vector<vostok::render::res_state *> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game,
             v15) )
      {
        v16[2].m_options = (survarium::options_item_base **)((char *)v16[2].m_options
                                                           - (unsigned int)v15->m_depth_stencil_state);
        m_rasterizer_state = v15->m_rasterizer_state;
        v18 = vostok::render::g_allocator.m_object;
        if ( m_rasterizer_state )
        {
          m_rasterizer_state->Release(v15->m_rasterizer_state);
          v15->m_rasterizer_state = 0;
        }
        BYTE2(v18->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v18->m_reconstruction_info_actuality_tick), v15);
      }
    }
  }
  if ( vertices_begin )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, vertices_begin);
  }
}
