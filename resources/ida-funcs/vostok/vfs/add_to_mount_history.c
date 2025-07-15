void __usercall vostok::vfs::add_to_mount_history(
        vostok::vfs::vfs_mount *new_item@<edi>,
        vostok::vfs::virtual_file_system *file_system@<esi>,
        vostok::threading::simple_lock *a3@<ecx>)
{
  vostok::vfs::vfs_mount *m_last; // eax
  bool v4; // zf
  vostok::threading::simple_lock::mutex_raii v5; // [esp+0h] [ebp-8h] BYREF

  v5.lock = &file_system->mount_history.m_policy;
  vostok::threading::simple_lock::lock(a3, (int)&file_system->mount_history.m_policy);
  m_last = file_system->mount_history.m_last;
  new_item->next_mount_history = 0;
  new_item->prev_mount_history = m_last;
  v4 = file_system->mount_history.m_first == 0;
  v5.locked = 1;
  if ( v4 )
    file_system->mount_history.m_first = new_item;
  else
    file_system->mount_history.m_last->next_mount_history = new_item;
  file_system->mount_history.m_last = new_item;
  vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v5);
}
