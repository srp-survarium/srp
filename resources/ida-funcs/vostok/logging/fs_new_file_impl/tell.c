int __thiscall vostok::logging::fs_new_file_impl::tell(vostok::logging::fs_new_file_impl *this)
{
  return this->m_device->m_device.m_device_file_system->tell(
           this->m_device->m_device.m_device_file_system,
           this->m_file);
}
