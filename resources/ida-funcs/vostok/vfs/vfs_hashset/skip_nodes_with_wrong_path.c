vostok::vfs::base_node<1> *__usercall vostok::vfs::vfs_hashset::skip_nodes_with_wrong_path@<eax>(
        vostok::vfs::base_node<1> *node@<eax>,
        const char *path)
{
  vostok::fs_new::virtual_path_string out_string; // [esp+4h] [ebp-A0h] BYREF

  while ( node )
  {
    out_string.m_string.m_begin = out_string.m_string.m_buffer;
    out_string.m_string.m_end = out_string.m_string.m_buffer;
    out_string.m_string.m_max_end = &out_string.m_separator;
    out_string.m_string.m_buffer[0] = 0;
    out_string.m_separator = 47;
    vostok::vfs::base_node<1>::get_full_path(node, &out_string);
    if ( !vostok::detail::strcmp_s(out_string.m_string.m_begin, path) )
      break;
    node = node->m_hashset_next.pointer;
  }
  return node;
}
