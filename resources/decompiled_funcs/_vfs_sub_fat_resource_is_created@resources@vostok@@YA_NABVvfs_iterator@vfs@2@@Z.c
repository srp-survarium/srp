bool __usercall vostok::resources::vfs_sub_fat_resource_is_created@<al>(vostok::vfs::vfs_iterator *it@<esi>)
{
  vostok::vfs::base_node<1> *v1; // eax
  bool result; // al

  result = 1;
  if ( vostok::mutable_buffer::size(it) )
  {
    v1 = vostok::mutable_buffer::size(it);
    if ( !v1 || !vostok::vfs::base_node<1>::get_mount_root_user_data(v1) )
      return 0;
  }
  return result;
}
