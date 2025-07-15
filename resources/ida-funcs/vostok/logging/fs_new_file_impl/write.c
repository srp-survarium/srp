int __thiscall vostok::logging::fs_new_file_impl::write(
        vostok::logging::fs_new_file_impl *this,
        const void *buffer,
        unsigned int size)
{
  return vostok::fs_new::device_file_system_no_watcher_proxy::write(
           (vostok::fs_new::device_file_system_no_watcher_proxy *)this,
           &this->m_device->m_device.m_device_file_system,
           this->m_file,
           buffer,
           size);
}
