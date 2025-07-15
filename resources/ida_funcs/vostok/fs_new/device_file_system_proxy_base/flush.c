void __thiscall vostok::fs_new::device_file_system_proxy_base::flush(
        vostok::fs_new::device_file_system_proxy_base *this,
        void **file)
{
  this->m_device_file_system->flush(this->m_device_file_system, file);
}
