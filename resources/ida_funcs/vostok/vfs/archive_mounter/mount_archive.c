void __thiscall vostok::vfs::archive_mounter::mount_archive(vostok::vfs::archive_mounter *this)
{
  vostok::vfs::result_enum m_result; // [esp+14h] [ebp-30h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> other; // [esp+18h] [ebp-2Ch] BYREF
  bool m_out_of_memory; // [esp+2Bh] [ebp-19h]
  vostok::vfs::mount_result v5; // [esp+30h] [ebp-14h] BYREF
  vostok::fs_new::synchronous_device_interface device; // [esp+38h] [ebp-Ch] BYREF

  if ( this->m_args.asynchronous_device )
  {
    vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
      &device,
      this->m_args.asynchronous_device,
      this->m_args.allocator);
    m_out_of_memory = device.m_out_of_memory;
    if ( device.m_out_of_memory )
    {
      vostok::vfs::mounter::finish_with_out_of_memory(this);
      vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&device);
      return;
    }
    vostok::vfs::archive_mounter::mount_archive_impl(this, &device);
    vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&device);
  }
  else
  {
    vostok::vfs::archive_mounter::mount_archive_impl(this, this->m_args.synchronous_device);
  }
  if ( this->m_result == result_success )
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
      &this->m_mount_ptr,
      0,
      (vostok::vfs::vfs_mount *)this);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &other,
    &this->m_mount_ptr);
  m_result = this->m_result;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &v5.mount,
    &other);
  v5.result = m_result;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&other);
  vostok::vfs::mounter::finish(this, &v5, 0);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v5.mount);
}
