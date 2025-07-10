BOOL __thiscall vostok::vfs::vfs_iterator::operator!=(
        vostok::vfs::vfs_iterator *this,
        const vostok::vfs::vfs_iterator *it)
{
  return !vostok::vfs::vfs_iterator::operator==(this, it);
}
