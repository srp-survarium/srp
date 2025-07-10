void __thiscall vostok::vfs::fat_header::reverse_bytes(vostok::vfs::fat_header *this)
{
  vostok::vfs::reverse_bytes<vostok::vfs::vfs_reader_writer_lock>((vostok::vfs::vfs_reader_writer_lock *)&this->num_nodes);
  vostok::vfs::reverse_bytes<vostok::vfs::vfs_reader_writer_lock>((vostok::vfs::vfs_reader_writer_lock *)&this->buffer_size);
}
