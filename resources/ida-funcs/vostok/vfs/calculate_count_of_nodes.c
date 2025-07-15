unsigned int __cdecl vostok::vfs::calculate_count_of_nodes<1>(
        const vostok::vfs::base_node<1> *node,
        bool skip_erased_node,
        bool recurse_on_link_nodes)
{
  vostok::vfs::base_node<1> *it_child; // [esp+Ch] [ebp-10h]
  const vostok::vfs::base_node<1> *target; // [esp+10h] [ebp-Ch]
  unsigned int out_count; // [esp+18h] [ebp-4h]

  if ( skip_erased_node && (node->m_flags & 0x800) == 0x800 )
    return 0;
  if ( (node->m_flags & 0x300) != 0 )
  {
    target = vostok::vfs::find_referenced_link_node(node);
    if ( recurse_on_link_nodes )
      return vostok::vfs::calculate_count_of_nodes<1>(target, skip_erased_node, recurse_on_link_nodes) + 1;
    else
      return 1;
  }
  else if ( (node->m_flags & 1) == 1 )
  {
    out_count = 1;
    for ( it_child = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node)->m_first_child.pointer;
          it_child;
          it_child = it_child->m_next.pointer )
    {
      out_count += vostok::vfs::calculate_count_of_nodes<1>(it_child, skip_erased_node, recurse_on_link_nodes);
    }
    return out_count;
  }
  else
  {
    return 1;
  }
}
