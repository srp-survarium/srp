void __thiscall vostok::vfs::fixup_node::fixup_node(
        vostok::vfs::fixup_node *this,
        vostok::vfs::base_node<1> *const node,
        char *const buffer_origin,
        vostok::vfs::mount_root_node_base<1> *mount_root)
{
  survarium::game_camera *v4; // ecx

  this->node = node;
  this->buffer_origin = buffer_origin;
  this->mount_root = mount_root;
  if ( (node->m_flags & 0x100) == 0x100 )
  {
    vostok::vfs::fixup_node::fixup_soft_link_node(this);
  }
  else if ( (node->m_flags & 0x200) == 0x200 )
  {
    vostok::vfs::fixup_node::fixup_hard_link_node(this);
  }
  else if ( (node->m_flags & 8) == 8 )
  {
    vostok::vfs::fixup_node::fixup_folder_mount_root(this);
  }
  else if ( (node->m_flags & 1) == 1 )
  {
    vostok::vfs::fixup_node::fixup_folder_node(this);
  }
  else if ( (node->m_flags & 0x1000) == 0x1000 )
  {
    vostok::vfs::fixup_node::fixup_external_subfat_node(this);
  }
  else if ( (node->m_flags & 0x40) == 0x40 )
  {
    vostok::vfs::fixup_node::fixup_inlined_node(this);
  }
  else if ( (node->m_flags & 0x800) == 0x800 )
  {
    vostok::vfs::node_cast<vostok::vfs::erased_node,vostok::vfs::base_node,1>(this->node);
    survarium::weapon_user_dead_state::finalize(v4);
  }
  vostok::vfs::fixup_node::fixup_base_node(this);
}
