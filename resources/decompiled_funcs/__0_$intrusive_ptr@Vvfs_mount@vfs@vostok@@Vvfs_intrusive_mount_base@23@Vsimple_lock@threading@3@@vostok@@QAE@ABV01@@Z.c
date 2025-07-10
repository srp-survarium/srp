void __usercall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *other@<edi>)
{
  vostok::vfs::vfs_mount *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}
