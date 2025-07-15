void __userpurge vostok::vfs::vfs_hashset::erase(
        vostok::vfs::vfs_hashset *this@<ecx>,
        int a2@<eax>,
        __int16 hash,
        vostok::vfs::base_node<1> *node)
{
  volatile signed __int64 *v5; // edi
  vostok::threading::reader_writer_lock *v6; // ecx

  v5 = (volatile signed __int64 *)(a2 + 8 * (hash & 0x1F));
  vostok::threading::reader_writer_lock::lock_write_impl(this->m_hashlocks, v5);
  vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1>>,vostok::detail::null_equal<vostok::vfs::base_node<1>>,vostok::threading::single_threading_policy>::erase(
    (vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1> >,vostok::detail::null_equal<vostok::vfs::base_node<1> >,vostok::threading::single_threading_policy> *)(a2 + 256),
    hash,
    node);
  vostok::threading::reader_writer_lock::unlock(v6, v5, lock_type_write);
}
