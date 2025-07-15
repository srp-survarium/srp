int __thiscall vostok::fs_new::device_file_system_proxy_base::erase(
        vostok::fs_new::device_file_system_proxy_base *this,
        const vostok::fs_new::native_path_string *absolute_physical_path)
{
  return ((int (__thiscall *)(vostok::fs_new::device_file_system_interface *, const vostok::fs_new::native_path_string *))this->m_device_file_system->erase)(
           this->m_device_file_system,
           absolute_physical_path);
}
