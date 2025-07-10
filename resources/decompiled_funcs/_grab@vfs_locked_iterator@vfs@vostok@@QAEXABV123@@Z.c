void __thiscall vostok::vfs::vfs_locked_iterator::grab(
        vostok::vfs::vfs_locked_iterator *this,
        const vostok::vfs::vfs_locked_iterator *other)
{
  vostok::vfs::vfs_locked_iterator::unlock_and_decref_if_needed(this);
  *this = *other;
  other->m_node = 0;
}
