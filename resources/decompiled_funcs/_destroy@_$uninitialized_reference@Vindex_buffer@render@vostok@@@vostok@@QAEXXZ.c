void __usercall vostok::uninitialized_reference<vostok::render::index_buffer>::destroy(
        vostok::uninitialized_reference<vostok::render::index_buffer> *this@<ecx>,
        int a2@<esi>)
{
  const vostok::render::untyped_buffer **v2; // eax
  const vostok::render::untyped_buffer *v3; // ecx

  v2 = *(const vostok::render::untyped_buffer ***)(a2 + 20);
  v3 = *v2;
  if ( *v2 )
  {
    if ( v3->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *v2);
  }
  *(_DWORD *)(a2 + 24) = 0;
}
