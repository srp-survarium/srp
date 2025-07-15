char __thiscall vostok::core::core_debug_engine::create_folder_r(
        vostok::core::core_debug_engine *this,
        char *path,
        bool create_last)
{
  char *m_variable; // esi
  const vostok::fs_new::native_path_string *v4; // eax
  vostok::fs_new::native_path_string result; // [esp+4h] [ebp-114h] BYREF

  m_variable = (char *)s_core_synchronous_device.m_variable;
  v4 = vostok::fs_new::native_path_string::convert(&result, path);
  return vostok::fs_new::create_folder_r(
           m_variable,
           (const vostok::fs_new::synchronous_device_interface *)m_variable,
           v4,
           create_last);
}
