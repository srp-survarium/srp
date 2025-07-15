vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *__thiscall vostok::vfs::vfs_mount::make_pointer_possibly_increase_destroy_count(
        vostok::vfs::vfs_mount *this,
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *result)
{
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> out_result; // [esp+14h] [ebp-4h] BYREF

  if ( vostok::vfs::vfs_mount::change_reference_count_change_may_destroy_this(this, 1) == 1 )
    vostok::threading::interlocked_increment((vostok::resources::unmanaged_intrusive_base *)&this->m_destroy_count);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &out_result,
    this);
  vostok::vfs::vfs_mount::change_reference_count_change_may_destroy_this(this, -1);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    result,
    &out_result);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&out_result);
  return result;
}
