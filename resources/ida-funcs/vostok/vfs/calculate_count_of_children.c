unsigned int __cdecl vostok::vfs::calculate_count_of_children<1>(
        const vostok::vfs::base_node<1> *node,
        bool count_erased)
{
  survarium::game_camera *v2; // ecx
  vostok::vfs::base_node<1> *it_child; // [esp+Ch] [ebp-Ch]
  unsigned int out_count; // [esp+14h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize(v2);
  if ( (node->m_flags & 1) != 1 )
    return 0;
  out_count = 0;
  for ( it_child = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node)->m_first_child.pointer;
        it_child;
        it_child = it_child->m_next.pointer )
  {
    if ( (it_child->m_flags & 0x800) != 0x800 || count_erased )
      ++out_count;
  }
  return out_count;
}
