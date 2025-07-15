void __usercall vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(
        vostok::fs_new::asynchronous_device_interface *this@<ecx>,
        vostok::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query> *a2@<esi>)
{
  vostok::fs_new::asynchronous_device_interface *v2; // ecx

  vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(this, a2 + 1);
  vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(v2, a2);
}
