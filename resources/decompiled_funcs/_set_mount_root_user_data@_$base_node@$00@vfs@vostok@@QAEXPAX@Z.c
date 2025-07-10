void __thiscall vostok::vfs::base_node<1>::set_mount_root_user_data(vostok::vfs::base_node<1> *this, void *data)
{
  vostok::vfs::mount_root_node_base<1> *pointer; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  vostok::vfs::mount_root_node_base<1> *v5; // [esp+0h] [ebp-18h]

  if ( (this->m_flags & 8) == 8 )
  {
    v5 = vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(this);
  }
  else
  {
    pointer = this->m_mount_root.pointer;
    v5 = this->m_mount_root.pointer;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)pointer);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
  v5->mount.pointer->user_data = data;
}
