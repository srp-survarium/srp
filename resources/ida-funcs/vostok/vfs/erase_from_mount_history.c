void __usercall vostok::vfs::erase_from_mount_history(
        vostok::vfs::vfs_mount *item@<esi>,
        vostok::vfs::virtual_file_system *file_system@<edi>,
        vostok::threading::simple_lock *a3@<ecx>)
{
  vostok::vfs::vfs_mount *prev_mount_history; // eax
  vostok::vfs::vfs_mount *next_mount_history; // ecx
  vostok::threading::simple_lock::mutex_raii v5; // [esp+4h] [ebp-8h] BYREF

  if ( file_system->mount_history.m_first )
  {
    v5.lock = &file_system->mount_history.m_policy;
    vostok::threading::simple_lock::lock(a3, (int)&file_system->mount_history.m_policy);
    prev_mount_history = item->prev_mount_history;
    next_mount_history = item->next_mount_history;
    v5.locked = 1;
    item->prev_mount_history = 0;
    item->next_mount_history = 0;
    if ( prev_mount_history )
      prev_mount_history->next_mount_history = next_mount_history;
    else
      file_system->mount_history.m_first = next_mount_history;
    if ( next_mount_history )
      next_mount_history->prev_mount_history = prev_mount_history;
    else
      file_system->mount_history.m_last = prev_mount_history;
    item->prev_mount_history = 0;
    item->next_mount_history = 0;
    vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v5);
  }
}
