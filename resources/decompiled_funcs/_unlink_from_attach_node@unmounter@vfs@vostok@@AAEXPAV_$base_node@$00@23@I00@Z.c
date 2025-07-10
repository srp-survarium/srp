void __thiscall vostok::vfs::unmounter::unlink_from_attach_node(
        vostok::vfs::unmounter *this,
        vostok::vfs::base_node<1> *mount_root,
        unsigned int hash,
        vostok::vfs::base_node<1> *overlapper,
        vostok::vfs::base_node<1> *attach_node)
{
  vostok::vfs::replace_and_free_what_node(
    &this->m_args->virtual_path,
    hash,
    this->m_file_system,
    mount_root,
    attach_node,
    overlapper,
    this->m_args->root_write_lock,
    this->m_args->allocator);
}
