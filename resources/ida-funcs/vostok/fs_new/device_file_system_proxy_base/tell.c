int __thiscall vostok::fs_new::device_file_system_proxy_base::tell(
        vostok::fs_new::device_file_system_proxy_base *this,
        void **file)
{
  return this->m_device_file_system->tell(this->m_device_file_system, file);
}
