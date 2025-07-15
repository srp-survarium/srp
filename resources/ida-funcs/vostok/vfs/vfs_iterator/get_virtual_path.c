vostok::fs_new::virtual_path_string *__thiscall vostok::vfs::vfs_iterator::get_virtual_path(
        vostok::vfs::vfs_iterator *this,
        vostok::fs_new::virtual_path_string *result,
        vostok::fs_new::virtual_path_string *a3)
{
  vostok::fs_new::virtual_path_string::virtual_path_string((vostok::fs_new::virtual_path_string *)this, (int)a3);
  vostok::vfs::base_node<1>::get_full_path((vostok::vfs::base_node<1> *)result->m_string.m_end, a3);
  return a3;
}
