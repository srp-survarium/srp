void __thiscall vostok::vfs::transfer_children::find_first_and_last_overlapper(
        vostok::vfs::transfer_children *this,
        vostok::vfs::base_node<1> **out_first_overlapper,
        vostok::vfs::base_node<1> **out_last_overlapper,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *path,
        unsigned int hash,
        vostok::vfs::base_node<1> *const child)
{
  const char *v6; // eax
  unsigned int v7; // eax
  vostok::vfs::base_node<1> *it_node; // [esp+8h] [ebp-50h]
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> begin_end; // [esp+Ch] [ebp-4Ch] BYREF
  vostok::vfs::base_node<1> *first_overlapper; // [esp+2Ch] [ebp-2Ch]
  vostok::vfs::base_node<1> *last_overlapper; // [esp+30h] [ebp-28h]
  vostok::vfs::overlapped_node_iterator it_end; // [esp+34h] [ebp-24h] BYREF
  unsigned int dest_start_mount_id; // [esp+44h] [ebp-14h]
  vostok::vfs::overlapped_node_iterator it; // [esp+48h] [ebp-10h] BYREF

  v6 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(path);
  vostok::vfs::vfs_hashset::equal_range(this->m_hashset, &begin_end, v6, hash, lock_type_read);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &begin_end.first);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it_end, &begin_end.second);
  dest_start_mount_id = vostok::vfs::mount_id_of_node<1>(this->m_dest_start);
  first_overlapper = 0;
  last_overlapper = 0;
  while ( (it.node != 0) != (it_end.node != 0) )
  {
    it_node = it.node;
    if ( it.node == child )
      break;
    v7 = vostok::vfs::mount_id_of_node<1>(it.node);
    if ( v7 <= dest_start_mount_id )
    {
      if ( !first_overlapper )
        first_overlapper = it_node;
      if ( (it_node->m_flags & 1) != 1 )
        first_overlapper = 0;
      last_overlapper = it_node;
    }
    vostok::vfs::overlapped_node_iterator::operator++(&it);
  }
  *out_first_overlapper = first_overlapper;
  *out_last_overlapper = last_overlapper;
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
}
