void __thiscall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this,
        vostok::vfs::vfs_mount *object)
{
  vostok::vfs::vfs_mount *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object != object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::vfs::vfs_intrusive_mount_base::destroy(this->m_object, this->m_object);
    this->m_object = object;
    if ( object )
      _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}
