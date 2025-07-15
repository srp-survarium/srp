vostok::fs_new::physical_path_info *__thiscall vostok::fs_new::device_file_system_proxy_base::get_physical_path_info(
        vostok::fs_new::device_file_system_proxy_base *this,
        vostok::fs_new::physical_path_info *result,
        const vostok::fs_new::native_path_string *native_physical_path)
{
  this->m_device_file_system->get_physical_path_info(this->m_device_file_system, result, native_physical_path);
  return result;
}
