int __userpurge vostok::fs_new::device_file_system_proxy_base::seek@<eax>(
        vostok::fs_new::device_file_system_proxy_base *this@<ecx>,
        _DWORD *a2@<eax>,
        void **file,
        unsigned __int64 offset,
        vostok::fs_new::seek_file_enum origin)
{
  return (*(int (__thiscall **)(_DWORD, void **, _DWORD, _DWORD, vostok::fs_new::seek_file_enum))(*(_DWORD *)*a2 + 24))(
           *a2,
           file,
           offset,
           HIDWORD(offset),
           origin);
}
