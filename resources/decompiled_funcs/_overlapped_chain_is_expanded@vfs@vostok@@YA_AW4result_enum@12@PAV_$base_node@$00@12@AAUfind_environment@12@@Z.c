int __cdecl vostok::vfs::overlapped_chain_is_expanded(
        vostok::vfs::base_node<1> *topmost_node,
        vostok::vfs::find_environment *env)
{
  vostok::vfs::traverse_enum traverse_type; // [esp+Ch] [ebp-8h]
  vostok::vfs::base_node<1> *it_node; // [esp+10h] [ebp-4h]

  for ( it_node = topmost_node; it_node; it_node = it_node->m_next_overlapped.pointer )
  {
    if ( (it_node->m_flags & 0x80) == 0x80 )
      return 2;
    traverse_type = traverse_branch;
    if ( vostok::strings::equal(env->path_to_find, env->partial_path) )
      traverse_type = (topmost_node != env->node) + 1;
    if ( vostok::vfs::need_physical_mount_or_async(
           it_node,
           (vostok::vfs::find_enum)env->find_flags.m_flags,
           traverse_type) )
    {
      return 2;
    }
  }
  return 1;
}
