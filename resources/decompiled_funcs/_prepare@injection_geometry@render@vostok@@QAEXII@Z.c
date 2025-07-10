void __usercall vostok::render::injection_geometry::prepare(
        vostok::render::injection_geometry *this@<ecx>,
        int a2@<eax>)
{
  float *v3; // eax
  unsigned int i; // edi
  unsigned int v5; // ecx
  double v6; // st6
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v8; // ecx
  vostok::render::res_declaration *v9; // eax
  bool v10; // zf
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v12; // ecx
  vostok::render::res_state *v13; // edi
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::math::float2 *vertices_begin; // [esp+14h] [ebp-10h]
  float v16; // [esp+1Ch] [ebp-8h]
  float v17; // [esp+20h] [ebp-4h]

  if ( *(_DWORD *)(a2 + 16) != 128 || *(_DWORD *)(a2 + 20) != 128 )
  {
    *(_DWORD *)(a2 + 8) = 0x4000;
    *(_DWORD *)(a2 + 16) = 128;
    *(_DWORD *)(a2 + 20) = 128;
    v3 = (float *)vostok::memory::doug_lea_allocator::malloc_impl(
                    (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                    (unsigned int)&loc_20000);
    vertices_begin = (vostok::math::float2 *)v3;
    for ( i = 0; i < 0x80; ++i )
    {
      v5 = 0;
      do
      {
        v6 = (double)v5 * 0.0078125;
        v16 = (double)i * 0.0078125;
        *v3 = v16;
        ++v5;
        v3 += 2;
        v17 = v6;
        *(v3 - 1) = v17;
      }
      while ( v5 < 0x80 );
    }
    declaration = vostok::render::resource_manager::create_declaration(
                    1u,
                    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                    (stlp_std::forward_iterator_tag *)injection_geometry_vertex_layout);
    v8 = 0;
    if ( declaration )
    {
      ++declaration->m_reference_count;
      v8 = declaration;
    }
    v9 = *(vostok::render::res_declaration **)a2;
    *(_DWORD *)a2 = v8;
    if ( v9 )
    {
      v10 = v9->m_reference_count-- == 1;
      if ( v10 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v9);
    }
    buffer = vostok::render::resource_manager::create_buffer(
               *(_DWORD *)(a2 + 8) * *(_DWORD *)(a2 + 12),
               i,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               vertices_begin,
               enum_buffer_type_vertex,
               0,
               0);
    v12 = 0;
    if ( buffer )
    {
      ++buffer->m_reference_count;
      v12 = buffer;
    }
    v13 = *(vostok::render::res_state **)(a2 + 4);
    *(_DWORD *)(a2 + 4) = v12;
    if ( v13 )
    {
      v10 = v13->m_reference_count-- == 1;
      if ( v10 )
        vostok::render::resource_manager::release(
          v13,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    }
    if ( vertices_begin )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, vertices_begin);
    }
  }
}
