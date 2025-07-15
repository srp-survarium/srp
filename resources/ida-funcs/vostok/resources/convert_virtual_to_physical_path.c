bool __usercall vostok::resources::convert_virtual_to_physical_path@<al>(
        vostok::fs_new::native_path_string *out_path@<edi>,
        const vostok::fs_new::virtual_path_string *path@<eax>)
{
  vostok::fs_new::native_path_string *v3; // eax
  vostok::fs_new::path_string_impl v5; // [esp+4h] [ebp-114h] BYREF

  if ( (unsigned int)(path->m_string.m_end - path->m_string.m_begin) <= 1
    || vostok::fs_new::path_string_impl::operator[](&path->vostok::fs_new::path_string_impl, 0) != 64 )
  {
    return vostok::vfs::virtual_file_system::convert_virtual_to_physical_path(
             (vostok::vfs::virtual_file_system *)((char *)&loc_20600
                                                + (unsigned int)vostok::resources::g_resources_manager.m_variable),
             out_path,
             path,
             "sources");
  }
  v3 = vostok::fs_new::native_path_string::convert((const char *)path->m_string.m_begin + 1, &v5);
  vostok::fs_new::virtual_path_string::operator=(
    (vostok::fs_new::virtual_path_string *)out_path,
    (vostok::fs_new::virtual_path_string *)v3);
  return 1;
}
