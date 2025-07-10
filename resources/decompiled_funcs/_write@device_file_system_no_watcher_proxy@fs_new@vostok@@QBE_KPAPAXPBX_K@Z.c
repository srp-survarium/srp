int __thiscall vostok::fs_new::device_file_system_no_watcher_proxy::write(
        vostok::fs_new::device_file_system_no_watcher_proxy *this,
        void **file,
        const void *data,
        unsigned __int64 size)
{
  return ((int (__thiscall *)(vostok::fs_new::device_file_system_interface *, void **, const void *, _DWORD, _DWORD))this->m_device_file_system->write)(
           this->m_device_file_system,
           file,
           data,
           size,
           HIDWORD(size));
}
