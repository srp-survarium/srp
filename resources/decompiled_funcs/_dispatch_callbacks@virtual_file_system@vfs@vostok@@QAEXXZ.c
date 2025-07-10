void __thiscall vostok::vfs::virtual_file_system::dispatch_callbacks(vostok::vfs::virtual_file_system *this)
{
  vostok::vfs::dispatch_ready_referers_list();
  if ( *(_DWORD *)((char *)&loc_20160 + (_DWORD)this) == -1
    || *(_DWORD *)((char *)&loc_20160 + (_DWORD)this) == vostok::threading::current_thread_id() )
  {
    vostok::vfs::dispatch_scheduled_to_unmount(
      (vostok::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *)(&this->mount_history.gap0 + (_DWORD)&loc_20146 + 2),
      &this->mount_history);
  }
}
