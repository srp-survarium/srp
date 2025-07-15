void __thiscall vostok::fs_new::asynchronous_device_interface::process_queries(
        vostok::fs_new::asynchronous_device_interface *this)
{
  vostok::fs_new::asynchronous_device_interface::process_queries(
    this,
    (vostok::fs_new::asynchronous_device_interface *)&this->m_high_priority_queries);
  vostok::fs_new::asynchronous_device_interface::process_queries(this, this);
}
