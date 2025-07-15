vostok::fs_new::native_path_string *__userpurge vostok::vfs::vfs_iterator::get_physical_path@<eax>(
        vostok::vfs::vfs_iterator *this@<ecx>,
        int a2@<eax>,
        vostok::fs_new::native_path_string *result)
{
  vostok::vfs::get_node_physical_path<vostok::vfs::base_node,1>(
    *(vostok::vfs::base_node<1> **)(a2 + 4),
    (vostok::vfs::base_node<1> *)this,
    result);
  return result;
}
