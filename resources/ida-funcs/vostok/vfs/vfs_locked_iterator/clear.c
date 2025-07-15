void __usercall vostok::vfs::vfs_locked_iterator::clear(vostok::vfs::vfs_locked_iterator *this@<ecx>, int a2@<esi>)
{
  vostok::vfs::vfs_locked_iterator::unlock_and_decref_if_needed(this, a2);
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
}
