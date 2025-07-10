void *__thiscall vostok::vfs::base_node<1>::get_mount_root_user_data(vostok::vfs::base_node<1> *this)
{
  vostok::vfs::mount_root_node_base<1> *pointer; // [esp+0h] [ebp-14h]

  if ( (this->m_flags & 8) == 8 )
    pointer = vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(this);
  else
    pointer = this->m_mount_root.pointer;
  if ( !pointer )
    return 0;
  if ( pointer->mount.pointer )
    return pointer->mount.pointer->user_data;
  return 0;
}
