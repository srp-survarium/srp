void __usercall vostok::vfs::mount_result::mount_result(
        vostok::vfs::mount_result *this@<ecx>,
        const vostok::vfs::mount_result *__that@<eax>)
{
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &this->mount,
    &__that->mount);
  this->result = __that->result;
}


void __userpurge vostok::vfs::mount_result::mount_result(
        vostok::vfs::mount_result *this@<ecx>,
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *a2@<eax>,
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> mount,
        vostok::vfs::vfs_mount *result)
{
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    a2,
    &mount);
  a2[1].m_object = result;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&mount);
}
