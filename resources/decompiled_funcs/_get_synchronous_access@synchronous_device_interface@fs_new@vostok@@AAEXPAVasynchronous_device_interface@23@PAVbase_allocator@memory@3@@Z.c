void __thiscall vostok::fs_new::synchronous_device_interface::get_synchronous_access(
        vostok::fs_new::synchronous_device_interface *this,
        vostok::fs_new::asynchronous_device_interface *adi,
        vostok::memory::base_allocator *allocator)
{
  vostok::fs_new::asynchronous_device_interface::get_synchronous_access(adi, this, allocator);
  if ( this->m_synchronize_query )
    vostok::fs_new::synchronize_device_query::wait_synchronization(this->m_synchronize_query);
}
