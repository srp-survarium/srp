void __thiscall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this,
        vostok::vfs::vfs_mount *object)
{
  this->m_object = 0;
  if ( object )
  {
    this->m_object = object;
    _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}
