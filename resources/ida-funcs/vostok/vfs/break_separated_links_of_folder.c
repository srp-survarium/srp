void __cdecl vostok::vfs::break_separated_links_of_folder(
        vostok::vfs::base_node<1> *overlapper,
        unsigned int separator_mount_id)
{
  survarium::game_camera *pointer; // ecx
  vostok::vfs::base_node<1> *child_overlapped; // [esp+10h] [ebp-Ch]
  vostok::vfs::base_node<1> *it_child; // [esp+14h] [ebp-8h]

  pointer = (survarium::game_camera *)vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(overlapper);
  for ( it_child = (vostok::vfs::base_node<1> *)pointer->__vftable;
        it_child;
        it_child = (vostok::vfs::base_node<1> *)pointer )
  {
    survarium::weapon_user_dead_state::finalize(pointer);
    child_overlapped = it_child->m_next_overlapped.pointer;
    if ( child_overlapped && vostok::vfs::mount_id_of_node<1>(child_overlapped) < separator_mount_id )
      it_child->m_next_overlapped.pointer = 0;
    if ( (it_child->m_flags & 1) == 1 )
      vostok::vfs::break_separated_links_of_folder(it_child, separator_mount_id);
    pointer = (survarium::game_camera *)it_child->m_next.pointer;
  }
}
