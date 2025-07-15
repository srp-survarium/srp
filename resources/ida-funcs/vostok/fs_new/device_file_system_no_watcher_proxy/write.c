int __userpurge vostok::fs_new::device_file_system_no_watcher_proxy::write@<eax>(
        vostok::fs_new::device_file_system_no_watcher_proxy *this@<ecx>,
        _DWORD *a2@<eax>,
        void **file,
        const void *data,
        unsigned __int64 size)
{
  return (*(int (__thiscall **)(_DWORD, void **, const void *, _DWORD, _DWORD))(*(_DWORD *)*a2 + 16))(
           *a2,
           file,
           data,
           size,
           HIDWORD(size));
}
