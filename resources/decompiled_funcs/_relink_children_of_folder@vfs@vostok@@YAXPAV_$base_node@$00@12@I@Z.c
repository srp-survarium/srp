void __cdecl vostok::vfs::relink_children_of_folder(
        vostok::vfs::base_node<1> *overlapper,
        unsigned int separator_mount_id)
{
  survarium::game_camera *v2; // ecx
  vostok::vfs::base_folder_node<1> *v3; // ecx
  int v4; // [esp-Ch] [ebp-8Ch] BYREF
  unsigned __int64 v5; // [esp+0h] [ebp-80h]
  int *v6; // [esp+34h] [ebp-4Ch]
  vostok::vfs::base_node<1> *v7; // [esp+38h] [ebp-48h]
  vostok::vfs::base_node<1> *pointer; // [esp+3Ch] [ebp-44h]
  unsigned __int64 max_storage; // [esp+40h] [ebp-40h]
  char v10; // [esp+53h] [ebp-2Dh]
  vostok::vfs::base_node<1> *next_child; // [esp+54h] [ebp-2Ch]
  vostok::vfs::base_node<1> *it_child; // [esp+58h] [ebp-28h]
  vostok::vfs::base_node<1> *it_node; // [esp+5Ch] [ebp-24h]
  vostok::vfs::base_folder_node<1> *overlapper_folder; // [esp+60h] [ebp-20h]
  vostok::vfs::base_folder_node<1> *overlapped_folder; // [esp+64h] [ebp-1Ch]
  vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> new_children; // [esp+68h] [ebp-18h] BYREF

  overlapper_folder = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(overlapper);
  overlapped_folder = 0;
  for ( it_node = overlapper; it_node; it_node = pointer )
  {
    if ( vostok::vfs::mount_id_of_node<1>(it_node) < separator_mount_id )
    {
      overlapped_folder = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(it_node);
      break;
    }
    pointer = it_node->m_next_overlapped.pointer;
  }
  vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>(&new_children);
  for ( it_child = overlapper_folder->m_first_child.pointer; it_child; it_child = next_child )
  {
    v7 = it_child->m_next.pointer;
    next_child = v7;
    if ( vostok::vfs::mount_id_of_node<1>(it_child) >= separator_mount_id )
    {
      v6 = &v4;
      vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        &new_children,
        (vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper)(unsigned int)it_child,
        0);
      if ( (it_child->m_flags & 1) == 1 )
        vostok::vfs::relink_children_of_folder(it_child, separator_mount_id);
    }
    else
    {
      v10 = 0;
      survarium::weapon_user_dead_state::finalize(v2);
      vostok::vfs::base_folder_node<1>::prepend_child(overlapped_folder, it_child);
    }
  }
  max_storage = new_children.m_first.max_storage;
  v5 = new_children.m_first.max_storage;
  v3 = overlapper_folder;
  overlapper_folder->m_first_child.pointer = new_children.m_first.pointer;
  HIDWORD(v3->m_first_child.max_storage) = HIDWORD(v5);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v3);
}
