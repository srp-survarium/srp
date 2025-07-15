void __thiscall vostok::vfs::vfs_hashset::replace(
        vostok::vfs::vfs_hashset *this,
        unsigned int hash,
        vostok::vfs::base_node<1> *with_node,
        vostok::vfs::base_node<1> *what_node,
        unsigned int mount_id)
{
  vostok::threading::reader_writer_lock *v5; // ecx
  vostok::threading::reader_writer_lock *v7; // [esp+4h] [ebp-14h]
  vostok::vfs::should_overlap_predicate should_overlap_predicate; // [esp+8h] [ebp-10h] BYREF
  vostok::threading::reader_writer_lock::mutex_raii raii; // [esp+Ch] [ebp-Ch] BYREF

  v7 = &this->m_hashlocks[hash % 0x20];
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&raii);
  raii.lock = v7;
  raii.lock_type = lock_type_write;
  vostok::threading::reader_writer_lock::lock(
    v5,
    (unsigned int *)&v7->m_readers_writers_counter.readers_count,
    lock_type_write);
  raii.locked = 1;
  vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1>>,vostok::detail::null_equal<vostok::vfs::base_node<1>>,vostok::threading::single_threading_policy>::erase(
    &this->m_hashset,
    hash,
    what_node);
  should_overlap_predicate.mount_id = mount_id;
  vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1>>,vostok::detail::null_equal<vostok::vfs::base_node<1>>,vostok::threading::single_threading_policy>::insert<vostok::vfs::should_overlap_predicate>(
    &this->m_hashset,
    hash,
    with_node,
    &should_overlap_predicate);
  vostok::threading::reader_writer_lock::mutex_raii::~mutex_raii(&raii);
}
