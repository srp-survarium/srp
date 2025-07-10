vostok::render::render_output_window *__thiscall vostok::render::render_output_window::`vector deleting destructor'(
        vostok::render::render_output_window *this,
        char a2)
{
  vostok::render::res_render_output *m_object; // eax

  m_object = this->m_output.m_object;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        this->m_output.m_object);
  }
  vostok::render::renderer_context_targets::~renderer_context_targets((vostok::render::renderer_context_targets *)this);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
