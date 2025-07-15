void __thiscall vostok::vfs::async_callbacks_data::on_lazy_mounted(
        vostok::vfs::async_callbacks_data *this,
        vostok::vfs::mount_result mount)
{
  vostok::vfs::async_callbacks_data::on_callback_may_destroy_this(this, (int)this, mount.result);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&mount.mount);
}
