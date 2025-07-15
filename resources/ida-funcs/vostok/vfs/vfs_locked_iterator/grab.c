void __usercall vostok::vfs::vfs_locked_iterator::grab(
        vostok::vfs::vfs_locked_iterator *this@<edi>,
        const vostok::vfs::vfs_locked_iterator *other@<esi>,
        vostok::vfs::vfs_locked_iterator *a3@<ecx>)
{
  vostok::vfs::vfs_locked_iterator::unlock_and_decref_if_needed(a3, (int)this);
  *this = *other;
  other->m_node = 0;
}
