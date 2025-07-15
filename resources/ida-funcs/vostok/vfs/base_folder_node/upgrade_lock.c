void __thiscall vostok::vfs::base_folder_node<1>::upgrade_lock(
        vostok::vfs::base_folder_node<1> *this,
        vostok::vfs::lock_type_enum from_lock,
        vostok::vfs::lock_type_enum to_lock)
{
  vostok::vfs::vfs_reader_writer_lock::upgrade(
    &this->m_readers_writers_counters,
    from_lock,
    to_lock,
    lock_operation_lock);
}
