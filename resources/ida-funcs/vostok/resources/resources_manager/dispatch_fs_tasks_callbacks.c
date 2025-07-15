void __userpurge vostok::resources::resources_manager::dispatch_fs_tasks_callbacks(
        vostok::resources::fs_task *ready_fs_tasks@<eax>,
        const bool finalizing_thread)
{
  vostok::resources::fs_task *m_next; // ebx
  vostok::memory::base_allocator *m_allocator; // edi
  _BYTE *v5; // [esp+Ch] [ebp-4h]

  do
  {
    m_next = ready_fs_tasks->m_next;
    if ( !finalizing_thread )
      ready_fs_tasks->call_user_callback(ready_fs_tasks);
    m_allocator = ready_fs_tasks->m_allocator;
    v5 = __RTCastToVoid((void **)&ready_fs_tasks->__vftable);
    ((void (__thiscall *)(vostok::resources::fs_task *, _DWORD))ready_fs_tasks->~vostok::resources::fs_task)(
      ready_fs_tasks,
      0);
    m_allocator->call_free(
      m_allocator,
      v5,
      "vostok::resources::resources_manager::dispatch_fs_tasks_callbacks",
      ".\\resources_manager_user_thread.cpp",
      574u);
    ready_fs_tasks = m_next;
  }
  while ( m_next );
}
