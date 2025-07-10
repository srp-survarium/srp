vostok::render::resource_manager **__usercall vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::render::resource_manager **a2@<esi>)
{
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  vostok::render::resource_manager *v3; // ecx
  vostok::render::resource_manager *v4; // eax

  v2 = 0;
  if ( this )
  {
    ++this->m_object;
    v2 = this;
  }
  v3 = (vostok::render::resource_manager *)v2;
  v4 = *a2;
  *a2 = v3;
  if ( v4 )
  {
    if ( v4->sh_created-- == 1 )
      vostok::render::resource_manager::release(
        v3,
        (const vostok::render::render_target *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  return a2;
}
