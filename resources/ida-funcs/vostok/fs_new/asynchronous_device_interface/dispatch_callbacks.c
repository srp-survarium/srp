void __thiscall vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(
        vostok::fs_new::asynchronous_device_interface *this)
{
  vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(this, &this->m_high_priority_queries);
  vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(this, &this->m_queries);
}
