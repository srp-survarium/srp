vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        const vostok::render::untyped_buffer **a2@<esi>)
{
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  const vostok::render::untyped_buffer *v3; // edi

  v2 = 0;
  if ( this )
  {
    ++this->m_object;
    v2 = this;
  }
  v3 = *a2;
  *a2 = (const vostok::render::untyped_buffer *)v2;
  if ( v3 )
  {
    if ( v3->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v3);
  }
  return (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2;
}
