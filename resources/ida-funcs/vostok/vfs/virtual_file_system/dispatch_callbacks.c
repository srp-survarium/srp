void __usercall vostok::vfs::virtual_file_system::dispatch_callbacks(
        vostok::vfs::virtual_file_system *this@<ecx>,
        vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy> *a2@<edi>)
{
  vostok::vfs::dispatch_ready_referers_list();
  if ( *(_DWORD *)(&a2->gap0 + (_DWORD)&loc_2015E + 2) == -1
    || *(_DWORD *)(&a2->gap0 + (_DWORD)&loc_2015E + 2) == GetCurrentThreadId() )
  {
    vostok::vfs::dispatch_scheduled_to_unmount(
      (vostok::threading::simple_lock *)(&a2->gap0 + (_DWORD)&loc_20144 + 4),
      a2);
  }
}
