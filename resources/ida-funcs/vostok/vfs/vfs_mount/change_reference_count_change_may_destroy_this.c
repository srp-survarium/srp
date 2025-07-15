signed __int32 __thiscall vostok::vfs::vfs_mount::change_reference_count_change_may_destroy_this(
        vostok::vfs::vfs_mount *this,
        vostok::vfs::vfs_mount *change,
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> a3)
{
  signed __int32 v3; // eax
  signed __int32 v5; // esi

  if ( (int)a3.m_object <= 0 )
  {
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &a3,
      change);
    v5 = _InterlockedDecrement(&change->m_reference_count) - 1;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&a3);
    return v5;
  }
  else
  {
    v3 = _InterlockedExchangeAdd(&change->m_reference_count, (unsigned int)a3.m_object);
    return (signed __int32)a3.m_object + v3;
  }
}
