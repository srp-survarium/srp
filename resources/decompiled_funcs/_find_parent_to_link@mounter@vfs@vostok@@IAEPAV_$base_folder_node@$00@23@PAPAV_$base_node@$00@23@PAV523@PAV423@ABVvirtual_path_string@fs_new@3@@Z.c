vostok::vfs::base_folder_node<1> *__thiscall vostok::vfs::mounter::find_parent_to_link(
        vostok::vfs::mounter *this,
        vostok::vfs::base_node<1> **in_out_overlapper,
        vostok::vfs::base_node<1> *candidate_for_link,
        vostok::vfs::base_folder_node<1> *parent,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *path)
{
  char *v6; // eax
  const char *v7; // eax
  vostok::vfs::base_node<1> *node; // ecx
  BOOL v9; // ecx
  survarium::game_camera *v10; // ecx
  survarium::game_camera *v11; // ecx
  vostok::vfs::base_folder_node<1> *v13; // [esp+14h] [ebp-17Ch]
  vostok::vfs::base_node<1> *v14; // [esp+1Ch] [ebp-174h]
  unsigned int overlapper_mount_id; // [esp+24h] [ebp-16Ch]
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> begin_end; // [esp+28h] [ebp-168h] BYREF
  vostok::fs_new::virtual_path_string parent_path; // [esp+48h] [ebp-148h] BYREF
  vostok::vfs::base_node<1> *prev_node; // [esp+160h] [ebp-30h]
  vostok::vfs::base_folder_node<1> *out_result; // [esp+164h] [ebp-2Ch]
  bool reached_file; // [esp+16Bh] [ebp-25h]
  vostok::vfs::overlapped_node_iterator it_end; // [esp+16Ch] [ebp-24h] BYREF
  bool found_candidate; // [esp+17Fh] [ebp-11h]
  vostok::vfs::overlapped_node_iterator it; // [esp+180h] [ebp-10h] BYREF
  vostok::vfs::base_node<1> *candidate_for_linka; // [esp+19Ch] [ebp+Ch]

  if ( candidate_for_link
    && vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(candidate_for_link) == parent )
  {
    return parent;
  }
  vostok::fs_new::virtual_path_string::virtual_path_string(&parent_path);
  v6 = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(path);
  vostok::fs_new::get_path_without_last_item<vostok::fs_new::virtual_path_string>(&parent_path, v6);
  v7 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&parent_path);
  vostok::vfs::vfs_hashset::equal_range(&this->m_file_system->hashset, &begin_end, v7, lock_type_write);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &begin_end.first);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it_end, &begin_end.second);
  found_candidate = 0;
  while ( 1 )
  {
    node = (vostok::vfs::base_node<1> *)(it.node != 0);
    if ( node == (vostok::vfs::base_node<1> *)(it_end.node != 0) )
      break;
    if ( !candidate_for_link || (node = it.node, it.node == candidate_for_link) )
    {
      found_candidate = 1;
      break;
    }
    vostok::vfs::overlapped_node_iterator::operator++(&it);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)node);
  if ( *in_out_overlapper )
  {
    found_candidate = 0;
    overlapper_mount_id = vostok::vfs::mount_id_of_node<1>(*in_out_overlapper);
    while ( 1 )
    {
      v9 = it_end.node != 0;
      if ( (it.node != 0) == v9 )
        break;
      if ( vostok::vfs::mount_id_of_node<1>(it.node) == overlapper_mount_id )
      {
        found_candidate = 1;
        vostok::vfs::overlapped_node_iterator::operator++(&it);
        survarium::weapon_user_dead_state::finalize(v10);
        break;
      }
      vostok::vfs::overlapped_node_iterator::operator++(&it);
    }
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v9);
  }
  reached_file = 0;
  candidate_for_linka = it.node;
  prev_node = 0;
  while ( (it.node != 0) != (it_end.node != 0) )
  {
    v14 = it.node;
    if ( prev_node && !prev_node->m_next_overlapped.pointer )
    {
      *in_out_overlapper = 0;
      candidate_for_linka = v14;
    }
    if ( reached_file )
    {
      candidate_for_linka = v14;
      reached_file = 0;
    }
    if ( v14 == vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(parent) )
      break;
    if ( (v14->m_flags & 1) != 1 )
    {
      reached_file = 1;
      *in_out_overlapper = 0;
    }
    prev_node = it.node;
    vostok::vfs::overlapped_node_iterator::operator++(&it);
  }
  out_result = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(candidate_for_linka);
  survarium::weapon_user_dead_state::finalize(v11);
  v13 = out_result;
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
  return v13;
}
