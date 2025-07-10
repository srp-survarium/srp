void __usercall vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<esi>,
        const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object@<edi>)
{
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v4; // eax

  m_object = this->m_object;
  if ( this->m_object != object->m_object )
  {
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const vostok::render::render_target *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    }
    v4 = object->m_object;
    this->m_object = object->m_object;
    if ( v4 )
      ++v4->m_reference_count;
  }
}
