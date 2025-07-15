unsigned int __usercall vostok::vfs::mount_id_of_node<1>@<eax>(vostok::vfs::base_node<1> *node@<eax>)
{
  if ( (node->m_flags & 0x400) == 0x400 )
    return vostok::vfs::node_cast<vostok::vfs::mount_helper_node,vostok::vfs::base_node,1>(node)->mount_id;
  else
    return vostok::vfs::base_node<1>::get_mount_root((vostok::vfs::base_node<1> *)0x400, (int)node)->mount_id;
}
