void __thiscall vostok::vfs::base_folder_node<1>::unlock(
        vostok::vfs::base_folder_node<1> *this,
        vostok::vfs::lock_type_enum lock_type)
{
  vostok::vfs::vfs_reader_writer_lock::unlock(&this->m_readers_writers_counters, lock_type);
}
