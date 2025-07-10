void __thiscall vostok::vfs::mount_result::mount_result(
        vostok::vfs::mount_result *this,
        const vostok::vfs::mount_result *__that)
{
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &this->mount,
    &__that->mount);
  this->result = __that->result;
}
