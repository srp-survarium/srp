void __thiscall vostok::vfs::fixup_node::fixup_external_subfat_node(vostok::vfs::fixup_node *this)
{
  survarium::game_camera *v1; // ecx
  vostok::vfs::external_subfat_node<1> *external_subfat; // [esp+Ch] [ebp-8h]
  survarium::game_camera *relative_path_offs; // [esp+10h] [ebp-4h]

  external_subfat = vostok::vfs::node_cast<vostok::vfs::external_subfat_node,vostok::vfs::base_node,1>(this->node);
  survarium::weapon_user_dead_state::finalize(v1);
  relative_path_offs = (survarium::game_camera *)external_subfat->relative_path_to_external.pointer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)external_subfat->relative_path_to_external.pointer);
  external_subfat->relative_path_to_external.pointer = (char *)relative_path_offs + (unsigned int)this->buffer_origin;
}
