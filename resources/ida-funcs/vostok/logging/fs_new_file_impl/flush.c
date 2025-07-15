void __thiscall vostok::logging::fs_new_file_impl::flush(vostok::logging::fs_new_file_impl *this)
{
  this->m_device->m_device.m_device_file_system->flush(this->m_device->m_device.m_device_file_system, this->m_file);
}
