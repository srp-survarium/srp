vostok::fs_new::physical_path_info *__userpurge vostok::fs_new::device_file_system_proxy_base::get_physical_path_info@<eax>(
        vostok::fs_new::device_file_system_proxy_base *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::fs_new::physical_path_info *result,
        const vostok::fs_new::native_path_string *native_physical_path)
{
  (*(void (__thiscall **)(_DWORD, vostok::fs_new::physical_path_info *, const vostok::fs_new::native_path_string *))(*(_DWORD *)*a2 + 40))(
    *a2,
    result,
    native_physical_path);
  return result;
}
