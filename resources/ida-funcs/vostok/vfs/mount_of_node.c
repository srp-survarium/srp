vostok::vfs::vfs_mount *__usercall vostok::vfs::mount_of_node<1>@<eax>(vostok::vfs::base_node<1> *node@<eax>)
{
  if ( (node->m_flags & 0x400) == 0x400 )
    return 0;
  else
    return vostok::vfs::base_node<1>::get_mount_root((vostok::vfs::base_node<1> *)0x400, (int)node)->mount.pointer;
}
