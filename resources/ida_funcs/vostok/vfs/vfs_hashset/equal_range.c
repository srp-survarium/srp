stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> *__thiscall vostok::vfs::vfs_hashset::equal_range(
        vostok::vfs::vfs_hashset *this,
        stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> *result,
        const char *path,
        unsigned int hash,
        vostok::vfs::lock_type_enum lock_type)
{
  vostok::threading::lock_type_enum v5; // eax
  vostok::threading::reader_writer_lock *v6; // ecx
  vostok::vfs::vfs_iterator *v7; // eax
  vostok::vfs::base_node<1> *v8; // eax
  vostok::threading::lock_type_enum v9; // eax
  vostok::threading::reader_writer_lock *v10; // ecx
  vostok::vfs::base_node<1> *node; // [esp+18h] [ebp-3Ch]
  vostok::threading::reader_writer_lock *hashset_lock; // [esp+20h] [ebp-34h]
  vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1> >,vostok::detail::null_equal<vostok::vfs::base_node<1> >,vostok::threading::single_threading_policy>::iterator v15; // [esp+34h] [ebp-20h] BYREF
  vostok::threading::reader_writer_lock *lock; // [esp+40h] [ebp-14h]
  vostok::vfs::overlapped_node_initializer begin; // [esp+44h] [ebp-10h] BYREF

  lock = &this->m_hashlocks[hash % 0x20];
  v5 = vostok::vfs::to_threading_lock_type(lock_type);
  vostok::threading::reader_writer_lock::lock(v6, (unsigned int *)&lock->m_readers_writers_counter.readers_count, v5);
  memset(&begin, 0, sizeof(begin));
  v7 = (vostok::vfs::vfs_iterator *)vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1>>,vostok::detail::null_equal<vostok::vfs::base_node<1>>,vostok::threading::single_threading_policy>::find(
                                      &this->m_hashset,
                                      &v15,
                                      hash);
  v8 = vostok::mutable_buffer::size(v7);
  begin.node = vostok::vfs::vfs_hashset::skip_nodes_with_wrong_path(v8, path);
  vostok::vfs::vfs_hashset::check_consistency(this, begin.node, path);
  if ( begin.node )
  {
    begin.hashset_lock = lock;
  }
  else
  {
    v9 = vostok::vfs::to_threading_lock_type(lock_type);
    vostok::threading::reader_writer_lock::unlock(v10, &lock->m_readers_writers_counter, v9);
  }
  node = begin.node;
  hashset_lock = begin.hashset_lock;
  result->first.path = path;
  result->first.node = node;
  result->first.lock_type = lock_type;
  result->first.hashset_lock = hashset_lock;
  result->second.path = 0;
  result->second.node = 0;
  result->second.lock_type = lock_type_uninitialized;
  result->second.hashset_lock = 0;
  return result;
}


stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> *__thiscall vostok::vfs::vfs_hashset::equal_range(
        vostok::vfs::vfs_hashset *this,
        stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> *result,
        const char *path,
        vostok::vfs::lock_type_enum lock_type)
{
  const char *v4; // eax
  unsigned int v6; // [esp-8h] [ebp-124h]
  vostok::fs_new::path_string_impl v8; // [esp+4h] [ebp-118h] BYREF
  unsigned int hash; // [esp+118h] [ebp-4h]

  vostok::fs_new::path_string_impl::path_string_impl(&v8, 47, &path);
  v6 = vostok::fs_new::path_string_impl::length(&v8);
  v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v8);
  hash = vostok::fs_new::path_crc32(v4, v6, 0);
  vostok::vfs::vfs_hashset::equal_range(this, result, path, hash, lock_type);
  return result;
}
