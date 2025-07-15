void __cdecl vostok::vfs::replace_and_free_what_node(
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *virtual_path,
        unsigned int virtual_path_hash,
        vostok::vfs::virtual_file_system *file_system,
        vostok::vfs::base_node<1> *what_node,
        vostok::vfs::base_node<1> *with_node,
        vostok::vfs::base_node<1> *overlapper,
        vostok::vfs::base_node<1> *root_write_lock,
        vostok::memory::base_allocator *allocator)
{
  vostok::vfs::exchange_nodes_impl(
    virtual_path,
    virtual_path_hash,
    exchange_nodes_insert,
    file_system,
    what_node,
    with_node,
    overlapper,
    root_write_lock,
    allocator);
}
