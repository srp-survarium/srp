void __cdecl vostok::vfs::find_link_target_path<1>(
        const vostok::vfs::base_node<1> *node,
        vostok::fs_new::native_path_string *out_path)
{
  survarium::game_camera *v2; // ecx
  vostok::vfs::soft_link_node<1> *v3; // eax
  const vostok::vfs::hard_link_node<1> *v4; // [esp+0h] [ebp-Ch]

  survarium::weapon_user_dead_state::finalize(v2);
  if ( (node->m_flags & 0x200) == 0x200 )
  {
    v4 = vostok::vfs::node_cast<vostok::vfs::soft_link_node,vostok::vfs::base_node,1>(node);
    vostok::vfs::base_node<1>::get_full_path(v4->referenced.pointer, out_path);
  }
  else
  {
    v3 = (vostok::vfs::soft_link_node<1> *)vostok::vfs::node_cast<vostok::vfs::soft_link_node,vostok::vfs::base_node,1>(node);
    vostok::vfs::soft_link_node<1>::absolute_path_to_referenced(v3, (vostok::fs_new::virtual_path_string *)out_path);
  }
}
