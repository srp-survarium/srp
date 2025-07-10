void __userpurge vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        vostok::render::untyped_buffer *object@<esi>,
        vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::untyped_buffer *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object != object )
  {
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          this->m_object);
    }
    this->m_object = object;
    if ( object )
      ++object->m_reference_count;
  }
}
