bool __cdecl vostok::fs_new::create_folder_r(
        const vostok::fs_new::synchronous_device_interface *device,
        const char *path,
        bool create_last)
{
  vostok::fs_new::native_path_string *v3; // eax
  vostok::fs_new::path_string_impl v5; // [esp+140h] [ebp-114h] BYREF

  v3 = vostok::fs_new::native_path_string::convert(path, &v5);
  return vostok::fs_new::create_folder_r(device, v3, create_last);
}
