vostok::vfs::physical_folder_mount_root_node<1> *__usercall vostok::vfs::base_node<1>::get_mount_root@<eax>(
        vostok::vfs::base_node<1> *this@<ecx>,
        int a2@<eax>)
{
  if ( (*(_BYTE *)(a2 + 48) & 8) != 0 )
    return vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>((vostok::vfs::base_node<1> *)a2);
  else
    return *(vostok::vfs::physical_folder_mount_root_node<1> **)a2;
}
