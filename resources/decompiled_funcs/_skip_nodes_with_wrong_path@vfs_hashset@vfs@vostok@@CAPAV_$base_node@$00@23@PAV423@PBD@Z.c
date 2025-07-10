vostok::vfs::base_node<1> *__cdecl vostok::vfs::vfs_hashset::skip_nodes_with_wrong_path(
        vostok::vfs::base_node<1> *node,
        const char *path)
{
  vostok::fs_new::virtual_path_string full_path; // [esp+10h] [ebp-118h] BYREF

  while ( node )
  {
    vostok::fs_new::virtual_path_string::virtual_path_string(&full_path);
    vostok::vfs::base_node<1>::get_full_path(node, (vostok::fs_new::native_path_string *)&full_path);
    if ( vostok::operator==(&full_path.m_string, path) )
      break;
    node = node->m_hashset_next.pointer;
  }
  return node;
}
