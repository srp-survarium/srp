vostok::fs_new::native_path_string *__thiscall vostok::vfs::vfs_iterator::get_physical_path(
        vostok::vfs::vfs_iterator *this,
        vostok::fs_new::native_path_string *result)
{
  vostok::vfs::get_node_physical_path<vostok::vfs::base_node,1>(result, this->m_node);
  return result;
}
