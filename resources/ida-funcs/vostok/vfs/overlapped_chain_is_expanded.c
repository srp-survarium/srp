int __usercall vostok::vfs::overlapped_chain_is_expanded@<eax>(
        vostok::vfs::find_environment *env@<edi>,
        vostok::vfs::base_node<1> *topmost_node)
{
  vostok::vfs::base_node<1> *i; // esi
  vostok::vfs::traverse_enum v3; // ebx

  for ( i = topmost_node; ; i = i->m_next_overlapped.pointer )
  {
    if ( !i )
      return 1;
    if ( SLOBYTE(i->m_flags) < 0 )
      break;
    v3 = traverse_branch;
    if ( !vostok::strings::compare(env->path_to_find, env->partial_path) )
    {
      LOBYTE(v3) = topmost_node != env->node;
      ++v3;
    }
    if ( vostok::vfs::need_physical_mount_or_async(i, (vostok::vfs::find_enum)env->find_flags.m_flags, v3) )
      break;
  }
  return 2;
}
