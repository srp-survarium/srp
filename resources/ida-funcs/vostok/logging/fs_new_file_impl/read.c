int __thiscall vostok::logging::fs_new_file_impl::read(
        vostok::logging::fs_new_file_impl *this,
        void *buffer,
        unsigned int size)
{
  return vostok::fs_new::device_file_system_proxy_base::read(
           (vostok::fs_new::device_file_system_proxy_base *)this,
           &this->m_device->m_device.m_device_file_system,
           this->m_file,
           buffer,
           size);
}
