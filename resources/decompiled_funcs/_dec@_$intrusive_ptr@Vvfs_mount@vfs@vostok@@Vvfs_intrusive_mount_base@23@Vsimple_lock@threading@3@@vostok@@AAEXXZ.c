void __thiscall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::vfs::vfs_intrusive_mount_base::destroy(this->m_object, this->m_object);
  }
}
