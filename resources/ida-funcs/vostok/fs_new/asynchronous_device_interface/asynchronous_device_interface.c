void __userpurge vostok::fs_new::asynchronous_device_interface::asynchronous_device_interface(
        vostok::fs_new::asynchronous_device_interface *this@<ecx>,
        HANDLE *a2@<edi>,
        vostok::fs_new::device_file_system_interface *device,
        vostok::fs_new::watcher_enabled_bool watcher_enabled)
{
  vostok::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query> *v4; // ecx
  vostok::threading::event_tasks_unaware *v5; // ecx

  vostok::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query>::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query>(
    &this->m_queries,
    a2);
  vostok::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query>::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query>(
    v4,
    a2 + 22);
  a2[45] = (HANDLE)-1;
  a2[44] = 0;
  vostok::threading::event_tasks_unaware::event_tasks_unaware(v5, a2 + 46);
  a2[48] = HANDLE_FLAG_INHERIT;
  a2[49] = device;
}
