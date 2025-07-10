void __thiscall vostok::vfs::vfs_hashset::erase(
        vostok::vfs::vfs_hashset *this,
        unsigned int hash,
        vostok::vfs::base_node<1> *node)
{
  vostok::threading::reader_writer_lock *v3; // ecx
  vostok::threading::reader_writer_lock *v5; // [esp+4h] [ebp-10h]
  vostok::threading::reader_writer_lock::mutex_raii raii; // [esp+8h] [ebp-Ch] BYREF

  v5 = &this->m_hashlocks[hash % 0x20];
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&raii);
  raii.lock = v5;
  raii.lock_type = lock_type_write;
  vostok::threading::reader_writer_lock::lock(
    v3,
    (unsigned int *)&v5->m_readers_writers_counter.readers_count,
    lock_type_write);
  raii.locked = 1;
  vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1>>,vostok::detail::null_equal<vostok::vfs::base_node<1>>,vostok::threading::single_threading_policy>::erase(
    &this->m_hashset,
    hash,
    node);
  vostok::threading::reader_writer_lock::mutex_raii::~mutex_raii(&raii);
}
