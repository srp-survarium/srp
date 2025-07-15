void __thiscall vostok::vfs::archive_inline_compressed_file_node<1>::reverse_bytes(
        vostok::vfs::archive_inline_compressed_file_node<1> *this)
{
  vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *res; // [esp+28h] [ebp-B8h]

  vostok::vfs::reverse_bytes<vostok::vfs::vfs_reader_writer_lock>((vostok::vfs::vfs_reader_writer_lock *)this);
  vostok::vfs::reverse_bytes<vostok::platform_pointer_selector<char,1>::helper>((vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *)&this->pos_in_db);
  vostok::vfs::reverse_bytes<vostok::vfs::vfs_reader_writer_lock>((vostok::vfs::vfs_reader_writer_lock *)&this->hash);
  if ( this )
  {
    res = (vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *)&this->vostok::vfs::archive_inline_file_node_base<1>;
    vostok::vfs::reverse_bytes<vostok::platform_pointer_selector<char,1>::helper>((vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *)&this->vostok::vfs::archive_inline_file_node_base<1>);
  }
  else
  {
    res = 0;
    vostok::vfs::reverse_bytes<vostok::platform_pointer_selector<char,1>::helper>(0);
  }
  vostok::vfs::reverse_bytes<vostok::vfs::vfs_reader_writer_lock>((vostok::vfs::vfs_reader_writer_lock *)&res[1]);
  vostok::vfs::reverse_bytes<vostok::vfs::vfs_reader_writer_lock>((vostok::vfs::vfs_reader_writer_lock *)&this->uncompressed_size);
  vostok::vfs::base_node<1>::reverse_bytes(&this->base);
}
