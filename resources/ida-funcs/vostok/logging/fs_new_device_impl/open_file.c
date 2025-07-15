void __thiscall vostok::logging::fs_new_device_impl::open_file(
        vostok::logging::fs_new_device_impl *this,
        char *path,
        vostok::logging::base_fs_device::file_mode_enum file_mode,
        vostok::logging::base_fs_device::file_access_enum file_access)
{
  vostok::fs_new::file_access::access_enum v4; // ebx
  vostok::logging::fs_new_file_impl *v6; // edi
  const vostok::fs_new::native_path_string *v7; // eax
  vostok::logging::base_fs_file *v8; // eax
  vostok::fs_new::native_path_string result; // [esp+Ch] [ebp-114h] BYREF
  vostok::fs_new::file_mode::mode_enum v10; // [esp+12Ch] [ebp+Ch]

  v4 = read_write;
  if ( file_mode )
  {
    if ( file_mode == open_existing_mode )
      v10 = open_existing;
    else
      v10 = append_or_create;
  }
  else
  {
    v10 = create_always;
  }
  if ( file_access )
  {
    if ( file_access == read_access )
      v4 = read;
  }
  else
  {
    v4 = write;
  }
  v6 = (vostok::logging::fs_new_file_impl *)this->m_allocator->allocate(this->m_allocator, 276u);
  if ( v6 )
  {
    v7 = vostok::fs_new::native_path_string::convert(&result, path);
    vostok::logging::fs_new_file_impl::fs_new_file_impl(v6, &this->m_device, v7, v10, v4);
    if ( !v8[68].__vftable )
      this->close_file(this, v8);
  }
}
