void __userpurge vostok::vfs::mounter::mounter(
        vostok::vfs::mounter *this@<ecx>,
        int a2@<esi>,
        vostok::vfs::query_mount_arguments *args,
        vostok::vfs::virtual_file_system *file_system)
{
  vostok::vfs::mounter_base *v4; // ebx
  vostok::vfs::query_mount_arguments *v5; // ecx
  vostok::threading::mutex *v6; // ecx
  vostok::vfs::mounter *m_last; // eax
  vostok::vfs::mounter *v8; // eax

  *(_DWORD *)a2 = &vostok::vfs::mounter::`vftable';
  v4 = 0;
  *(_DWORD *)(a2 + 16) = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    (vostok::threading::mutex_tasks_unaware *)this,
    (_RTL_CRITICAL_SECTION *)(a2 + 24));
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 68) = 1;
  vostok::vfs::query_mount_arguments::query_mount_arguments(v5, a2 + 72, args);
  *(_DWORD *)(a2 + 1316) = file_system;
  *(_DWORD *)(a2 + 1312) = 0;
  *(_DWORD *)(a2 + 1320) = 0;
  vostok::threading::mutex::lock(v6, (_RTL_CRITICAL_SECTION *)&file_system->pending_mounts.m_policy);
  m_last = file_system->pending_mounts.m_last;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 8) = m_last;
  if ( file_system->pending_mounts.m_first )
  {
    v8 = file_system->pending_mounts.m_last;
    if ( v8 )
      v4 = &v8->vostok::vfs::mounter_base;
    v4->next = (vostok::vfs::mounter *)a2;
  }
  else
  {
    file_system->pending_mounts.m_first = (vostok::vfs::mounter *)a2;
  }
  file_system->pending_mounts.m_last = (vostok::vfs::mounter *)a2;
  LeaveCriticalSection((LPCRITICAL_SECTION)&file_system->pending_mounts.m_policy);
}
