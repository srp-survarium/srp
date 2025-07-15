vostok::resources::vfs_sub_fat_resource *__thiscall vostok::resources::get_node_sub_fat(
        vostok::vfs::base_node<1> *const node)
{
  if ( node )
    return (vostok::resources::vfs_sub_fat_resource *)vostok::vfs::base_node<1>::get_mount_root_user_data(node);
  else
    return 0;
}
