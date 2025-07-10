void __thiscall vostok::vfs::mounter::merge_node_with_tree(
        vostok::vfs::mounter *this,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *path,
        unsigned int hash,
        vostok::vfs::base_node<1> *node,
        vostok::vfs::base_folder_node<1> *parent)
{
  char is_ready_for_transition; // al
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  const char *v8; // eax
  vostok::vfs::base_folder_node<1> *v9; // eax
  survarium::game_camera *v10; // ecx
  survarium::game_camera *v11; // ecx
  survarium::game_camera *v12; // ecx
  survarium::game_camera *v13; // ecx
  unsigned int v14; // eax
  survarium::game_camera *v15; // ecx
  survarium::game_camera *v16; // ecx
  survarium::game_camera *v17; // ecx
  unsigned int v18; // eax
  vostok::vfs::base_node<1> *v19; // [esp-8h] [ebp-30Ch]
  unsigned int v20; // [esp-4h] [ebp-308h]
  vostok::vfs::base_folder_node<1> *v21; // [esp-4h] [ebp-308h]
  bool v22; // [esp+0h] [ebp-304h]
  vostok::vfs::base_node<1> *v24; // [esp+158h] [ebp-1ACh]
  btNullPairCache *v25; // [esp+15Ch] [ebp-1A8h] BYREF
  int v26; // [esp+164h] [ebp-1A0h]
  unsigned int v27; // [esp+168h] [ebp-19Ch]
  btNullPairCache **v28; // [esp+16Ch] [ebp-198h]
  vostok::vfs::base_folder_node<1> *pointer; // [esp+170h] [ebp-194h]
  vostok::vfs::transfer_children v30; // [esp+174h] [ebp-190h] BYREF
  char v31; // [esp+2B4h] [ebp-50h]
  char v32; // [esp+2B5h] [ebp-4Fh]
  char v33; // [esp+2B6h] [ebp-4Eh]
  char v34; // [esp+2B7h] [ebp-4Dh]
  char v35; // [esp+2B8h] [ebp-4Ch]
  char v36; // [esp+2B9h] [ebp-4Bh]
  char v37; // [esp+2BAh] [ebp-4Ah]
  char v38; // [esp+2BBh] [ebp-49h]
  char v39; // [esp+2C2h] [ebp-42h]
  char v40; // [esp+2C3h] [ebp-41h]
  vostok::vfs::base_folder_node<1> *node_folder; // [esp+2C4h] [ebp-40h]
  vostok::vfs::base_node<1> *next_overlapped; // [esp+2C8h] [ebp-3Ch]
  vostok::vfs::base_node<1> *topmost_overlapper; // [esp+2CCh] [ebp-38h]
  vostok::vfs::vfs_iterator iterator; // [esp+2D0h] [ebp-34h] BYREF
  vostok::vfs::base_folder_node<1> *folder_overlapped_by_parent; // [esp+2E0h] [ebp-24h]
  vostok::vfs::base_node<1> *overlapped_by_parent; // [esp+2E4h] [ebp-20h]
  vostok::vfs::base_folder_node<1> *overlapped_folder; // [esp+2E8h] [ebp-1Ch]
  vostok::vfs::archive_folder_mount_root_node<1> *mount_root; // [esp+2ECh] [ebp-18h]
  vostok::vfs::base_node<1> *overlapped; // [esp+2F0h] [ebp-14h] BYREF
  vostok::vfs::base_node<1> *overlapper; // [esp+2F4h] [ebp-10h] BYREF
  bool node_is_submount_root; // [esp+2FBh] [ebp-9h]
  unsigned int node_mount_id; // [esp+2FCh] [ebp-8h]
  vostok::vfs::base_folder_node<1> *parent_to_link; // [esp+300h] [ebp-4h] BYREF

  v40 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  node_mount_id = vostok::vfs::mount_id_of_node<1>(node);
  parent_to_link = 0;
  overlapped = 0;
  overlapper = 0;
  vostok::vfs::mounter::find_overlapped_and_parent_to_link(
    this,
    &parent_to_link,
    &overlapper,
    &overlapped,
    path,
    hash,
    node,
    parent);
  node_is_submount_root = 0;
  if ( (node->m_flags & 8) == 8 )
  {
    mount_root = (vostok::vfs::archive_folder_mount_root_node<1> *)vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>(node);
    v22 = mount_root && mount_root->attach_node.pointer;
    node_is_submount_root = v22;
  }
  if ( overlapped )
  {
    pointer = overlapped->m_parent.pointer;
    overlapped_folder = pointer;
    if ( pointer != parent || node_is_submount_root )
    {
      vostok::vfs::base_folder_node<1>::unlink_child(overlapped_folder, overlapped, 1);
      if ( !node_is_submount_root )
      {
        overlapped_by_parent = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(parent)->m_next_overlapped.pointer;
        v38 = 0;
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)overlapped_by_parent);
        folder_overlapped_by_parent = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(overlapped_by_parent);
        v37 = 0;
        survarium::weapon_user_dead_state::finalize(v6);
        v36 = 0;
        survarium::weapon_user_dead_state::finalize(v7);
        vostok::vfs::base_folder_node<1>::prepend_child(folder_overlapped_by_parent, overlapped);
      }
    }
    else
    {
      v39 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)pointer);
      v28 = &v25;
      v25 = (btNullPairCache *)0x4000;
      v24 = overlapped;
      v26 = 0x4000;
      is_ready_for_transition = survarium::player_logic_base_state::is_ready_for_transition((btNullPairCache *)0x4000);
      v27 = v26 << (is_ready_for_transition == 0 ? 0x10 : 0);
      _InterlockedOr((volatile signed __int32 *)&v24->m_flags, v27);
    }
  }
  vostok::vfs::base_folder_node<1>::prepend_child(parent_to_link, node);
  if ( overlapper
    && (overlapper->m_flags & 1) == 1
    && (node->m_flags & 1) != 1
    && overlapped
    && (overlapped->m_flags & 1) == 1 )
  {
    v20 = node_mount_id;
    v19 = overlapper;
    v8 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(path);
    vostok::vfs::separate_folders_by_file_node(&this->m_file_system->hashset, v8, hash, v19, v20);
  }
  if ( overlapper )
    overlapper->m_next_overlapped.pointer = node;
  if ( overlapped && (overlapped->m_flags & 1) == 1 && (node->m_flags & 1) == 1 )
  {
    v21 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(overlapped);
    v9 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node);
    vostok::vfs::transfer_children_to_empty_folder(v9, v21);
  }
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_file_system->on_node_hides)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0
    && overlapped )
  {
    vostok::vfs::vfs_iterator::vfs_iterator(&iterator, overlapped, 0, &this->m_file_system->hashset, type_non_recursive);
    boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
      (boost::function1<void,vostok::ai::sensors::sensed_object const &> *)&this->m_file_system->on_node_hides,
      (const vostok::ai::sensors::sensed_object *)&iterator);
  }
  if ( node_is_submount_root )
  {
    v35 = 0;
    survarium::weapon_user_dead_state::finalize(v10);
    v34 = 0;
    survarium::weapon_user_dead_state::finalize(v11);
    next_overlapped = overlapped->m_next_overlapped.pointer;
    node->m_next_overlapped.pointer = next_overlapped;
    if ( !overlapper && this->m_args.root_write_lock == overlapped )
    {
      node_folder = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node);
      v33 = 0;
      survarium::weapon_user_dead_state::finalize(v12);
      vostok::vfs::base_folder_node<1>::lock(node_folder, lock_type_write, lock_operation_lock);
      v32 = 0;
      survarium::weapon_user_dead_state::finalize(v13);
    }
    v14 = vostok::vfs::mount_id_of_node<1>(node);
    vostok::vfs::vfs_hashset::replace(&this->m_file_system->hashset, hash, node, overlapped, v14);
    topmost_overlapper = vostok::vfs::mounter::find_topmost_overlapper(this, path, hash, node);
    v31 = 0;
    survarium::weapon_user_dead_state::finalize(v15);
    if ( next_overlapped && (next_overlapped->m_flags & 1) == 1 )
    {
      if ( topmost_overlapper )
      {
        vostok::vfs::transfer_children::transfer_children(
          &v30,
          &this->m_file_system->hashset,
          (const vostok::fs_new::virtual_path_string *)path,
          hash,
          topmost_overlapper,
          next_overlapped);
        survarium::weapon_user_dead_state::finalize(v16);
        survarium::weapon_user_dead_state::finalize(v17);
      }
    }
  }
  else
  {
    node->m_next_overlapped.pointer = overlapped;
    v18 = vostok::vfs::mount_id_of_node<1>(node);
    vostok::vfs::vfs_hashset::insert(&this->m_file_system->hashset, hash, node, v18);
  }
}
