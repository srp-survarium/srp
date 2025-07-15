void __cdecl vostok::vfs::free_node(
        vostok::vfs::virtual_file_system *file_system,
        vostok::vfs::base_node<1> *node,
        vostok::vfs::base_node<1> **root_write_lock,
        unsigned int hash,
        vostok::memory::base_allocator *allocator)
{
  vostok::vfs::free_node_impl(file_system, node, root_write_lock, hash, allocator, erase_from_hashset_true);
}
