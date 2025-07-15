int __userpurge vostok::fs_new::device_file_system_proxy_base::read@<eax>(
        vostok::fs_new::device_file_system_proxy_base *this@<ecx>,
        _DWORD *a2@<eax>,
        void **file,
        void *data,
        unsigned __int64 size)
{
  return (*(int (__thiscall **)(_DWORD, void **, void *, _DWORD, _DWORD))(*(_DWORD *)*a2 + 20))(
           *a2,
           file,
           data,
           size,
           HIDWORD(size));
}
