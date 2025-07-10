vostok::render::res_geometry *__userpurge vostok::render::resource_manager::create_geometry@<eax>(
        stlp_std::forward_iterator_tag *decl@<eax>,
        vostok::render::resource_manager *this,
        unsigned int decl_size,
        unsigned int vertex_stride,
        vostok::render::untyped_buffer *vb,
        vostok::render::untyped_buffer *ib)
{
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v7; // esi
  vostok::render::res_geometry *geometry; // edi

  declaration = vostok::render::resource_manager::create_declaration(
                  decl_size,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  decl);
  v7 = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    v7 = declaration;
  }
  geometry = vostok::render::resource_manager::create_geometry(v7, vb, this, vertex_stride, ib);
  if ( v7 )
  {
    if ( v7->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v7);
  }
  return geometry;
}
