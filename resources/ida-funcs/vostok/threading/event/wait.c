int __userpurge vostok::threading::event::wait@<eax>(
        vostok::threading::event *this@<ecx>,
        HANDLE *a2@<eax>,
        DWORD max_wait_time_ms)
{
  DWORD v4; // eax
  void *v5; // ecx
  int v7; // ebx
  DWORD v8; // eax
  void *v9; // ecx
  DWORD v10; // eax
  void *v11; // ecx
  int v12; // esi

  if ( !max_wait_time_ms )
  {
    v4 = WaitForSingleObject(*a2, 0);
    if ( v4 )
      return vostok::threading::event_tasks_unaware::wait(v5, v4);
    return 1;
  }
  v7 = 0;
  if ( s_spin_count.m_begin )
  {
    do
    {
      v8 = WaitForSingleObject(*a2, 0);
      if ( !v8 || vostok::threading::event_tasks_unaware::wait(v9, v8) == 1 )
        return 1;
    }
    while ( (vostok::tasks::thread_tls *)++v7 < s_spin_count.m_begin );
  }
  vostok::tasks::on_current_thread_locks();
  v10 = WaitForSingleObject(*a2, max_wait_time_ms);
  if ( v10 )
    v12 = vostok::threading::event_tasks_unaware::wait(v11, v10);
  else
    v12 = 1;
  vostok::tasks::on_current_thread_unlocks();
  return v12;
}
