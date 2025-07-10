vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *__usercall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this@<esi>,
        vostok::vfs::vfs_mount *object@<eax>,
        vostok::vfs::vfs_mount *a3@<ecx>)
{
  vostok::vfs::vfs_mount **v3; // eax
  vostok::vfs::vfs_mount *v4; // ecx
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v6; // [esp+0h] [ebp-4h] BYREF

  v6.m_object = a3;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &v6,
    object);
  v4 = *v3;
  *v3 = this->m_object;
  this->m_object = v4;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v6);
  return this;
}
