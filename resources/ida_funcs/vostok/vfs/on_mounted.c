void __cdecl vostok::vfs::on_mounted(
        vostok::vfs::mount_result result,
        vostok::vfs::mount_result *out_result,
        bool *finished)
{
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
    &out_result->mount,
    &result.mount);
  out_result->result = result.result;
  *finished = 1;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&result.mount);
}
