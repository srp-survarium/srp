vostok::resources::vfs_sub_fat_resource *__usercall vostok::resources::get_node_sub_fat@<eax>(
        vostok::vfs::base_node<1> *const node@<eax>,
        vostok::vfs::base_node<1> *a2@<ecx>)
{
  vostok::vfs::mount_root_node_base<1> *mount_root; // eax
  vostok::vfs::vfs_mount *pointer; // eax

  if ( node
    && (mount_root = vostok::vfs::base_node<1>::get_mount_root(a2, (int)node)) != 0
    && (pointer = mount_root->mount.pointer) != 0 )
  {
    return (vostok::resources::vfs_sub_fat_resource *)pointer->user_data;
  }
  else
  {
    return 0;
  }
}
