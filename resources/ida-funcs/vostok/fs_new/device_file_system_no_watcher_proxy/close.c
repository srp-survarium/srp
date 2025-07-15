void __thiscall vostok::fs_new::device_file_system_no_watcher_proxy::close(
        vostok::fs_new::device_file_system_no_watcher_proxy *this,
        void **file)
{
  this->m_device_file_system->close(this->m_device_file_system, file);
}
