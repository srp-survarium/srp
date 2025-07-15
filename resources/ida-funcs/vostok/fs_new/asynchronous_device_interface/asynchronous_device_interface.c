void __thiscall vostok::fs_new::asynchronous_device_interface::asynchronous_device_interface(
        vostok::fs_new::asynchronous_device_interface *this,
        vostok::fs_new::device_file_system_interface *device,
        vostok::fs_new::watcher_enabled_bool watcher_enabled)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query>::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query>(&this->m_queries);
  vostok::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query>::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query>(&this->m_high_priority_queries);
  this->m_processing_queries = 0;
  this->m_synchronous_thread_id = -1;
  vostok::threading::event::event(&this->m_wakeup_event, 0);
  this->m_device_mode = device_mode_asynchronous;
  this->m_device.m_device_file_system = device;
}
