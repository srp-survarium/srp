void __thiscall vostok::vfs::fixup_node::fixup_soft_link_node(vostok::vfs::fixup_node *this)
{
  survarium::game_camera *v1; // ecx
  vostok::vfs::soft_link_node<1> *soft_link; // [esp+Ch] [ebp-8h]
  unsigned int relative_path_offs; // [esp+10h] [ebp-4h]

  soft_link = (vostok::vfs::soft_link_node<1> *)vostok::vfs::node_cast<vostok::vfs::soft_link_node,vostok::vfs::base_node,1>(this->node);
  relative_path_offs = (unsigned int)soft_link->relative_path.pointer;
  survarium::weapon_user_dead_state::finalize(v1);
  soft_link->relative_path.pointer = &this->buffer_origin[relative_path_offs];
}
