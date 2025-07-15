void __usercall vostok::fs_new::asynchronous_device_interface::push_query(
        vostok::fs_new::asynchronous_device_interface *this@<esi>,
        vostok::fs_new::asynchronous_device_query *query@<eax>)
{
  vostok::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query>::producer_push_to_process(
    &this->m_queries,
    query);
  SetEvent(*(HANDLE *)this->m_wakeup_event.m_event.m_event);
}
