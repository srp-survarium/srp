void __cdecl vostok::vfs::mounter::remove_marked_to_unlink_from_parent(vostok::vfs::base_folder_node<1> *parent)
{
  char is_ready_for_transition; // al
  unsigned __int16 *p_m_flags; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  int v6; // [esp-Ch] [ebp-A8h] BYREF
  vostok::vfs::base_folder_node<1> *v7; // [esp+0h] [ebp-9Ch]
  unsigned __int64 v8; // [esp+4h] [ebp-98h]
  btNullPairCache v9; // [esp+Ch] [ebp-90h] BYREF
  int *v10; // [esp+4Ch] [ebp-50h]
  survarium::game_camera *v11; // [esp+50h] [ebp-4Ch]
  vostok::vfs::base_node<1> *v12; // [esp+54h] [ebp-48h]
  vostok::vfs::base_node<1> *pointer; // [esp+58h] [ebp-44h]
  unsigned __int64 max_storage; // [esp+5Ch] [ebp-40h]
  char v15; // [esp+65h] [ebp-37h]
  char v16; // [esp+66h] [ebp-36h]
  char v17; // [esp+67h] [ebp-35h]
  char v18; // [esp+73h] [ebp-29h]
  vostok::vfs::base_node<1> *next_child; // [esp+74h] [ebp-28h]
  vostok::vfs::base_node<1> *child; // [esp+78h] [ebp-24h]
  vostok::vfs::base_node<1> *overlapped; // [esp+7Ch] [ebp-20h]
  vostok::vfs::base_folder_node<1> *old_parent; // [esp+80h] [ebp-1Ch]
  vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> new_children; // [esp+84h] [ebp-18h] BYREF

  v12 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(parent);
  pointer = v12->m_next_overlapped.pointer;
  overlapped = pointer;
  if ( !pointer || (overlapped->m_flags & 0x300) != 0 )
    v7 = 0;
  else
    v7 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(overlapped);
  old_parent = v7;
  vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>(&new_children);
  for ( child = parent->m_first_child.pointer; child; child = next_child )
  {
    v11 = (survarium::game_camera *)child->m_next.pointer;
    next_child = (vostok::vfs::base_node<1> *)v11;
    v18 = 0;
    survarium::weapon_user_dead_state::finalize(v11);
    if ( (child->m_flags & 0x4000) == 0x4000 )
    {
      v9.m_overlappingPairArray.m_data = (btBroadphasePair *)&v9;
      v9.__vftable = (btNullPairCache_vtbl *)0x4000;
      v9.m_overlappingPairArray.m_size = 0x4000;
      is_ready_for_transition = survarium::player_logic_base_state::is_ready_for_transition(&v9);
      v9.m_overlappingPairArray.m_capacity = v9.m_overlappingPairArray.m_size << (is_ready_for_transition == 0 ? 0x10 : 0);
      p_m_flags = &child->m_flags;
      _InterlockedAnd((volatile signed __int32 *)&child->m_flags, ~v9.m_overlappingPairArray.m_capacity);
      v17 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)p_m_flags);
      v16 = 0;
      survarium::weapon_user_dead_state::finalize(v3);
      v15 = 0;
      survarium::weapon_user_dead_state::finalize(v4);
      vostok::vfs::base_folder_node<1>::prepend_child(old_parent, child);
    }
    else
    {
      v10 = &v6;
      vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        &new_children,
        (vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper)(unsigned int)child,
        0);
    }
  }
  max_storage = new_children.m_first.max_storage;
  v8 = new_children.m_first.max_storage;
  parent->m_first_child.pointer = new_children.m_first.pointer;
  v5 = (survarium::game_camera *)HIDWORD(v8);
  HIDWORD(parent->m_first_child.max_storage) = HIDWORD(v8);
  survarium::weapon_user_dead_state::finalize(v5);
}
