void __cdecl vostok::vfs::on_mounted(
        vostok::vfs::mount_result result,
        vostok::vfs::mount_result *out_result,
        bool *finished)
{
  vostok::vfs::mount_result *v3; // esi

  v3 = out_result;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
    &result.mount,
    &out_result->mount);
  v3->result = result.result;
  *finished = 1;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&result.mount);
}
