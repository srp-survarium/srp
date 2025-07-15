char __thiscall vostok::logging::fs_new_device_impl::create_folder_r(
        vostok::logging::fs_new_device_impl *this,
        char *path,
        vostok::logging::base_fs_device::create_last_enum create_last)
{
  const vostok::fs_new::native_path_string *v4; // eax
  vostok::fs_new::native_path_string result; // [esp+4h] [ebp-114h] BYREF

  v4 = vostok::fs_new::native_path_string::convert(&result, path);
  return vostok::fs_new::create_folder_r((char *)&this->m_device, &this->m_device, v4, create_last == create_last);
}
