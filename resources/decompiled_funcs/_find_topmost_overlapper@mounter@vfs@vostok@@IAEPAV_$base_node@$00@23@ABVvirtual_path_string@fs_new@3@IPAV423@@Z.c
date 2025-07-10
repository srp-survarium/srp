vostok::vfs::base_node<1> *__thiscall vostok::vfs::mounter::find_topmost_overlapper(
        vostok::vfs::mounter *this,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *path,
        unsigned int hash,
        vostok::vfs::base_node<1> *node)
{
  const char *v4; // eax
  vostok::vfs::base_node<1> *v7; // [esp+8h] [ebp-4Ch]
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> begin_end; // [esp+10h] [ebp-44h] BYREF
  vostok::vfs::base_node<1> *overlapper; // [esp+30h] [ebp-24h]
  vostok::vfs::overlapped_node_iterator it_end; // [esp+34h] [ebp-20h] BYREF
  vostok::vfs::overlapped_node_iterator it; // [esp+44h] [ebp-10h] BYREF

  v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(path);
  vostok::vfs::vfs_hashset::equal_range(&this->m_file_system->hashset, &begin_end, v4, hash, lock_type_write);
  overlapper = 0;
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &begin_end.first);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it_end, &begin_end.second);
  while ( (it.node != 0) != (it_end.node != 0) )
  {
    if ( (it.node->m_flags & 1) == 1 )
    {
      if ( !overlapper )
        overlapper = it.node;
    }
    else
    {
      overlapper = 0;
    }
    if ( it.node == node )
      break;
    vostok::vfs::overlapped_node_iterator::operator++(&it);
  }
  v7 = overlapper;
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
  return v7;
}
