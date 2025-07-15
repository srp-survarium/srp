void __thiscall vostok::vfs::mounter::merge_root_node_with_tree(
        vostok::vfs::mounter *this,
        vostok::vfs::base_node<1> *new_root_node,
        vostok::vfs::base_node<1> *top_root_node,
        bool *added_ontop)
{
  vostok::vfs::base_folder_node<1> *v4; // eax
  survarium::game_camera *v5; // ecx
  vostok::vfs::base_folder_node<1> *v6; // [esp-4h] [ebp-164h]
  vostok::vfs::vfs_iterator iterator; // [esp+144h] [ebp-1Ch] BYREF
  vostok::vfs::base_node<1> *overlapped; // [esp+154h] [ebp-Ch]
  vostok::vfs::base_node<1> *overlapper; // [esp+158h] [ebp-8h]
  unsigned int mount_id; // [esp+15Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  overlapper = 0;
  overlapped = top_root_node;
  mount_id = vostok::vfs::mount_id_of_node<1>(new_root_node);
  while ( overlapped && vostok::vfs::mount_id_of_node<1>(overlapped) > mount_id )
  {
    overlapper = overlapped;
    overlapped = overlapped->m_next_overlapped.pointer;
  }
  if ( (new_root_node->m_flags & 1) == 1 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)((new_root_node->m_flags & 1) == 1));
  if ( overlapped && (overlapped->m_flags & 1) == 1 && (new_root_node->m_flags & 1) == 1 )
  {
    v6 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(overlapped);
    v4 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(new_root_node);
    vostok::vfs::transfer_children_to_empty_folder(v4, v6);
  }
  if ( overlapper )
    overlapper->m_next_overlapped.pointer = new_root_node;
  new_root_node->m_next_overlapped.pointer = overlapped;
  v5 = !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_file_system->on_node_hides)
     ? (survarium::game_camera *)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
     : 0;
  if ( v5 && overlapped )
  {
    vostok::vfs::vfs_iterator::vfs_iterator(&iterator, overlapped, 0, &this->m_file_system->hashset, type_non_recursive);
    boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
      (boost::function1<void,vostok::ai::sensors::sensed_object const &> *)&this->m_file_system->on_node_hides,
      (const vostok::ai::sensors::sensed_object *)&iterator);
  }
  survarium::weapon_user_dead_state::finalize(v5);
  *added_ontop = overlapper == 0;
}
