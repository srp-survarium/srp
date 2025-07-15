void __usercall vostok::render::hw_hiz_point_list::initialize(
        vostok::render::hw_hiz_point_list *this@<esi>,
        unsigned int num_points@<eax>,
        bool a3@<dil>)
{
  vostok::render::resource_manager *v3; // ecx
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v5; // ecx
  vostok::render::untyped_buffer *m_object; // edi

  v3 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  this->m_num_points = num_points;
  buffer = vostok::render::resource_manager::create_buffer(
             24 * num_points,
             a3,
             v3,
             0,
             enum_buffer_type_vertex,
             (vostok::render::untyped_buffer *)1,
             0);
  v5 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v5 = buffer;
  }
  m_object = this->m_vertex_buffer.m_object;
  this->m_vertex_buffer.m_object = v5;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
}
