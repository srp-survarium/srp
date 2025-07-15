void __userpurge vostok::vfs::vfs_hashset::replace(
        vostok::vfs::vfs_hashset *this@<ecx>,
        vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1> >,vostok::detail::null_equal<vostok::vfs::base_node<1> >,vostok::threading::single_threading_policy> *a2@<eax>,
        __int16 hash,
        vostok::vfs::base_node<1> *with_node,
        vostok::vfs::base_node<1> *what_node,
        vostok::vfs::base_node<1> *mount_id)
{
  vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1> >,vostok::detail::null_equal<vostok::vfs::base_node<1> >,vostok::threading::single_threading_policy> *v6; // esi
  volatile signed __int64 *v7; // edi
  vostok::threading::reader_writer_lock *v8; // ecx

  v6 = a2;
  v7 = (volatile signed __int64 *)((char *)a2 + 8 * (hash & 0x1F));
  vostok::threading::reader_writer_lock::lock_write_impl(this->m_hashlocks, v7);
  v6 = (vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1> >,vostok::detail::null_equal<vostok::vfs::base_node<1> >,vostok::threading::single_threading_policy> *)((char *)v6 + 256);
  vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1>>,vostok::detail::null_equal<vostok::vfs::base_node<1>>,vostok::threading::single_threading_policy>::erase(
    v6,
    hash,
    what_node);
  what_node = mount_id;
  vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1>>,vostok::detail::null_equal<vostok::vfs::base_node<1>>,vostok::threading::single_threading_policy>::insert<vostok::vfs::should_overlap_predicate>(
    hash,
    v6,
    with_node,
    (const vostok::vfs::should_overlap_predicate *)&what_node);
  vostok::threading::reader_writer_lock::unlock(v8, v7, lock_type_write);
}
