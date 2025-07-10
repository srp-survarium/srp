int __thiscall vostok::fs_new::device_file_system_proxy_base::read(
        vostok::fs_new::device_file_system_proxy_base *this,
        void **file,
        void *data,
        unsigned __int64 size)
{
  return ((int (__thiscall *)(vostok::fs_new::device_file_system_interface *, void **, void *, _DWORD, _DWORD))this->m_device_file_system->read)(
           this->m_device_file_system,
           file,
           data,
           size,
           HIDWORD(size));
}
