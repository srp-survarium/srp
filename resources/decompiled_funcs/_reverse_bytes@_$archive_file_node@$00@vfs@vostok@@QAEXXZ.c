void __thiscall vostok::vfs::archive_file_node<1>::reverse_bytes(vostok::vfs::archive_file_node<1> *this)
{
  vostok::vfs::reverse_bytes<vostok::vfs::vfs_reader_writer_lock>((vostok::vfs::vfs_reader_writer_lock *)this);
  vostok::vfs::reverse_bytes<vostok::platform_pointer_selector<char,1>::helper>((vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *)&this->pos_in_db);
  vostok::vfs::reverse_bytes<vostok::vfs::vfs_reader_writer_lock>((vostok::vfs::vfs_reader_writer_lock *)&this->hash);
  vostok::vfs::base_node<1>::reverse_bytes(&this->base);
}
