void __thiscall vostok::resources::resources_manager::dispatch_devices(vostok::resources::resources_manager *this)
{
  vostok::fs_new::asynchronous_device_interface *v2; // ecx

  vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(
    (vostok::fs_new::asynchronous_device_interface *)this,
    *(vostok::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query> **)((char *)&this->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_205FF + 1));
  vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(
    v2,
    *(vostok::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query> **)((char *)&this->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20603 + 1));
}
