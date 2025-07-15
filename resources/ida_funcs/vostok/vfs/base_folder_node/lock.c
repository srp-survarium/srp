bool __thiscall vostok::vfs::base_folder_node<1>::lock(
        vostok::vfs::base_folder_node<1> *this,
        vostok::vfs::lock_type_enum lock_type,
        vostok::vfs::lock_operation_enum lock_operation)
{
  return vostok::vfs::vfs_reader_writer_lock::lock(&this->m_readers_writers_counters, lock_type, lock_operation);
}
