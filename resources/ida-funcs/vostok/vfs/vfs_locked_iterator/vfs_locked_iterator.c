void __thiscall vostok::vfs::vfs_locked_iterator::vfs_locked_iterator(vostok::vfs::vfs_locked_iterator *this)
{
  vostok::vfs::vfs_iterator::vfs_iterator(this);
  this->mount_operation_id = 0;
}
