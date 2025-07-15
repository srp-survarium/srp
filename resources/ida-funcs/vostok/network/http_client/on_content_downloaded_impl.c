void __thiscall vostok::network::http_client::on_content_downloaded_impl(
        vostok::network::http_client *this,
        vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *content)
{
  boost::function<void __cdecl(char const *)> *p_m_on_content_downloaded; // eax
  int v4; // ecx

  p_m_on_content_downloaded = &this->m_on_content_downloaded;
  v4 = -(this->m_on_content_downloaded.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v4) != 0 )
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)v4,
      p_m_on_content_downloaded,
      content);
  this->m_busy = 0;
}
