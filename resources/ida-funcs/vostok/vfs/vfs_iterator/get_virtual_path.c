vostok::fs_new::virtual_path_string *__thiscall vostok::vfs::vfs_iterator::get_virtual_path(
        vostok::vfs::vfs_iterator *this,
        vostok::fs_new::virtual_path_string *result)
{
  vostok::fs_new::virtual_path_string path; // [esp+30h] [ebp-118h] BYREF

  vostok::fs_new::virtual_path_string::virtual_path_string(&path);
  vostok::vfs::base_node<1>::get_full_path(this->m_node, (vostok::fs_new::native_path_string *)&path);
  vostok::fs_new::virtual_path_string::virtual_path_string(result, &path);
  return result;
}
