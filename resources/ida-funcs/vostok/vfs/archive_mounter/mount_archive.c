void __thiscall vostok::vfs::archive_mounter::mount_archive(
        vostok::vfs::archive_mounter *this,
        vostok::vfs::mount_result *result)
{
  vostok::vfs::vfs_mount *m_object; // eax
  vostok::vfs::archive_mounter *v3; // ecx
  vostok::fs_new::synchronous_device_interface *v4; // ecx
  vostok::fs_new::synchronous_device_interface *v5; // ecx
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v6; // ecx
  vostok::vfs::mount_result *v7; // ecx
  vostok::vfs::mounter *v8; // eax
  vostok::vfs::mounter *v9; // ecx
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v10; // [esp-Ch] [ebp-28h] BYREF
  vostok::vfs::vfs_mount *v11; // [esp-8h] [ebp-24h]
  int v12; // [esp-4h] [ebp-20h]
  vostok::fs_new::synchronous_device_interface device; // [esp+Ch] [ebp-10h] BYREF

  m_object = result[151].mount.m_object;
  if ( m_object )
  {
    vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
      (vostok::fs_new::synchronous_device_interface *)this,
      (int)&device,
      (vostok::fs_new::asynchronous_device_query_vtbl *)m_object,
      (vostok::memory::base_allocator *)result[152].mount.m_object);
    if ( device.m_out_of_memory )
    {
      vostok::vfs::mounter::finish_with_out_of_memory(v3, (int)result);
      vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(v4, (int *)&device);
      return;
    }
    vostok::vfs::archive_mounter::mount_archive_impl(v3, (int)result, &device);
    vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(v5, (int *)&device);
  }
  else
  {
    vostok::vfs::archive_mounter::mount_archive_impl(
      this,
      (int)result,
      (vostok::fs_new::synchronous_device_interface *)result[151].result);
  }
  if ( result[8].result == result_out_of_memory )
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
      v6,
      (int *)&result[8],
      0);
  v12 = 0;
  v11 = (vostok::vfs::vfs_mount *)result[8].result;
  v10.m_object = (vostok::vfs::vfs_mount *)v6;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &v10,
    &result[8].mount);
  vostok::vfs::mount_result::mount_result(
    v7,
    (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&device.m_device,
    v10,
    v11);
  vostok::vfs::mounter::finish(v9, result, v8, v12);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&device.m_device);
}
