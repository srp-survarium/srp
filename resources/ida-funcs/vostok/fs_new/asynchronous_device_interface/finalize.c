void __thiscall vostok::fs_new::asynchronous_device_interface::finalize(
        vostok::fs_new::asynchronous_device_interface *this)
{
  if ( this->m_device_mode )
  {
    vostok::fs_new::asynchronous_device_interface::process_queries(this);
    vostok::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query>::consumer_finalize(&this->m_queries);
    vostok::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query>::consumer_finalize(&this->m_high_priority_queries);
  }
}
