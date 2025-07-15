void __userpurge vostok::vfs::vfs_hashset::insert(
        vostok::vfs::vfs_hashset *this@<ecx>,
        int a2@<eax>,
        __int16 hash,
        vostok::vfs::base_node<1> *node,
        vostok::vfs::should_overlap_predicate mount_id)
{
  volatile signed __int64 *v6; // edi
  vostok::threading::reader_writer_lock *v7; // ecx

  v6 = (volatile signed __int64 *)(a2 + 8 * (hash & 0x1F));
  vostok::threading::reader_writer_lock::lock_write_impl(this->m_hashlocks, v6);
  vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1>>,vostok::detail::null_equal<vostok::vfs::base_node<1>>,vostok::threading::single_threading_policy>::insert<vostok::vfs::should_overlap_predicate>(
    hash,
    (vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1> >,vostok::detail::null_equal<vostok::vfs::base_node<1> >,vostok::threading::single_threading_policy> *)(a2 + 256),
    node,
    &mount_id);
  vostok::threading::reader_writer_lock::unlock(v7, v6, lock_type_write);
}
