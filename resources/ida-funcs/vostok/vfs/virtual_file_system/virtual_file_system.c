void __usercall vostok::vfs::virtual_file_system::virtual_file_system(
        vostok::vfs::virtual_file_system *this@<ecx>,
        _DWORD *a2@<edi>)
{
  _DWORD *v2; // eax
  int i; // edx
  char *v4; // eax
  vostok::threading::mutex_tasks_unaware *v5; // ecx
  vostok::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *v6; // ecx

  a2[1] = 0;
  a2[2] = 0;
  a2[3] = 0;
  a2[4] = 0;
  v2 = a2 + 6;
  for ( i = 31; i >= 0; --i )
  {
    *v2 = 0;
    v2[1] = 0;
    *v2 = 0;
    v2[1] = 0;
    v2 += 2;
  }
  *(_DWORD *)((char *)a2 + (_DWORD)&loc_20102 + 2 + 24) = 0;
  memset((int)(a2 + 71), 0, (unsigned int)&loc_20000);
  v4 = (char *)a2 + (_DWORD)&loc_2011E + 2;
  *((_DWORD *)v4 + 1) = 0;
  *((_DWORD *)v4 + 2) = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v5,
    (_RTL_CRITICAL_SECTION *)((char *)a2 + (_DWORD)&loc_2011E + 2 + 16));
  vostok::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>(
    v6,
    (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)((char *)a2 + (_DWORD)&loc_20144 + 4));
  *(_DWORD *)((char *)a2 + (_DWORD)&loc_20165 + 3) = 0;
  *(_DWORD *)((char *)a2 + (_DWORD)&loc_20185 + 3) = 0;
  *(int *)((char *)&dword_201A8 + (_DWORD)a2) = 0;
  *(int *)((char *)&dword_201C8 + (_DWORD)a2) = 0;
}
