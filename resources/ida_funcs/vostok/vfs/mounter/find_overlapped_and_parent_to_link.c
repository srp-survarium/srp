void __thiscall vostok::vfs::mounter::find_overlapped_and_parent_to_link(
        vostok::vfs::mounter *this,
        vostok::vfs::base_folder_node<1> **out_parent_to_link,
        vostok::vfs::base_node<1> **out_overlapper,
        vostok::vfs::base_node<1> **out_overlapped,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *path,
        unsigned int hash,
        vostok::vfs::base_node<1> *node,
        vostok::vfs::base_folder_node<1> *parent)
{
  const char *v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  survarium::game_camera *v11; // ecx
  vostok::vfs::base_node<1> *overlapper_parent; // [esp+14h] [ebp-64h]
  vostok::vfs::base_node<1> *parent_to_link_node; // [esp+18h] [ebp-60h]
  vostok::vfs::base_node<1> *parent_of_it_node; // [esp+1Ch] [ebp-5Ch]
  vostok::vfs::base_node<1> *it_node; // [esp+20h] [ebp-58h]
  vostok::vfs::base_node<1> *overlapped; // [esp+24h] [ebp-54h]
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> begin_end; // [esp+28h] [ebp-50h] BYREF
  vostok::vfs::base_node<1> *overlapper; // [esp+48h] [ebp-30h] BYREF
  vostok::vfs::base_node<1> *candidate_for_link; // [esp+4Ch] [ebp-2Ch]
  unsigned int node_mount_id; // [esp+50h] [ebp-28h]
  vostok::vfs::overlapped_node_iterator it_end; // [esp+54h] [ebp-24h] BYREF
  vostok::vfs::base_folder_node<1> *parent_to_link; // [esp+64h] [ebp-14h]
  vostok::vfs::overlapped_node_iterator it; // [esp+68h] [ebp-10h] BYREF

  v8 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(path);
  vostok::vfs::vfs_hashset::equal_range(&this->m_file_system->hashset, &begin_end, v8, hash, lock_type_write);
  node_mount_id = vostok::vfs::mount_id_of_node<1>(node);
  parent_to_link = 0;
  candidate_for_link = 0;
  overlapped = 0;
  overlapper = 0;
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &begin_end.first);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it_end, &begin_end.second);
  while ( (it.node != 0) != (it_end.node != 0) )
  {
    it_node = it.node;
    parent_of_it_node = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(it.node->m_parent.pointer);
    v9 = vostok::vfs::mount_id_of_node<1>(it_node);
    if ( v9 <= node_mount_id )
    {
      v10 = vostok::vfs::mount_id_of_node<1>(parent_of_it_node);
      if ( v10 >= node_mount_id )
      {
        parent_to_link = it_node->m_parent.pointer;
        overlapped = it_node;
      }
      break;
    }
    candidate_for_link = parent_of_it_node;
    overlapper = it_node;
    vostok::vfs::overlapped_node_iterator::operator++(&it);
  }
  vostok::vfs::overlapped_node_iterator::clear(&it);
  if ( !parent_to_link )
    parent_to_link = vostok::vfs::mounter::find_parent_to_link(this, &overlapper, candidate_for_link, parent, path);
  survarium::weapon_user_dead_state::finalize(v11);
  if ( overlapper )
  {
    overlapper_parent = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(overlapper->m_parent.pointer);
    parent_to_link_node = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(parent_to_link);
    if ( !vostok::vfs::folders_connected_by_overlap(overlapper_parent, parent_to_link_node) )
      overlapper = 0;
  }
  *out_overlapper = overlapper;
  *out_overlapped = overlapped;
  *out_parent_to_link = parent_to_link;
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
}
