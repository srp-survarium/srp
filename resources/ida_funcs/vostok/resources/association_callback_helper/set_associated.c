void __thiscall vostok::resources::association_callback_helper::set_associated(
        vostok::resources::association_callback_helper *this,
        vostok::vfs::vfs_association **association)
{
  *association = this->resource;
}
