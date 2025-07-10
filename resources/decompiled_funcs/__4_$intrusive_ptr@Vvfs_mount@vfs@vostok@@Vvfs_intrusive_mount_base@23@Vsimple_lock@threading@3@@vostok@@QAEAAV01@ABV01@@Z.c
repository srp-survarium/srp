vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *__usercall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this@<edi>,
        const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *object@<esi>)
{
  vostok::vfs::vfs_mount *m_object; // eax
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v4; // [esp+0h] [ebp-4h] BYREF

  m_object = 0;
  v4.m_object = 0;
  if ( object->m_object )
  {
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v4);
    m_object = object->m_object;
    v4.m_object = m_object;
    if ( m_object )
    {
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      m_object = v4.m_object;
    }
  }
  v4.m_object = this->m_object;
  this->m_object = m_object;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v4);
  return this;
}
