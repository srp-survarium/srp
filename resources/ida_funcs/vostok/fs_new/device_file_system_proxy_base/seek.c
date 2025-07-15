int __thiscall vostok::fs_new::device_file_system_proxy_base::seek(
        vostok::fs_new::device_file_system_proxy_base *this,
        void **file,
        unsigned __int64 offset,
        vostok::fs_new::seek_file_enum origin)
{
  return ((int (__thiscall *)(vostok::fs_new::device_file_system_interface *, void **, _DWORD, _DWORD, vostok::fs_new::seek_file_enum))this->m_device_file_system->seek)(
           this->m_device_file_system,
           file,
           offset,
           HIDWORD(offset),
           origin);
}
