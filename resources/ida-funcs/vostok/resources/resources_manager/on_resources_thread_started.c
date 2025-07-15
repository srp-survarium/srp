void __usercall vostok::resources::resources_manager::on_resources_thread_started(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::resources_manager *a2@<esi>)
{
  DWORD CurrentThreadId; // eax
  DWORD v3; // eax
  vostok::resources::game_resources_manager *v4; // ecx
  LARGE_INTEGER v5; // rax
  vostok::resources::resources_manager *v6; // ecx
  LARGE_INTEGER PerformanceCount; // [esp+8h] [ebp-8h] BYREF

  _InterlockedExchange((volatile __int32 *)((char *)&dword_203CC + (_DWORD)a2), GetCurrentThreadId());
  CurrentThreadId = GetCurrentThreadId();
  if ( vostok::memory::g_resources_helper_allocator.m_user_thread_id != CurrentThreadId )
  {
    _InterlockedExchange(
      (volatile __int32 *)&vostok::memory::g_resources_helper_allocator.m_user_thread_id,
      CurrentThreadId);
    if ( vostok::memory::g_resources_helper_allocator.m_thread_id_const )
      vostok::memory::g_resources_helper_allocator.m_user_thread_id_called = 1;
  }
  vostok::memory::g_resources_helper_allocator.m_user_thread_logging_name = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !vostok::memory::g_resources_helper_allocator.m_user_thread_logging_name )
    vostok::memory::g_resources_helper_allocator.m_user_thread_logging_name = "undefined";
  v3 = GetCurrentThreadId();
  if ( vostok::memory::g_resources_unmanaged_allocator.m_user_thread_id != v3 )
  {
    _InterlockedExchange((volatile __int32 *)&vostok::memory::g_resources_unmanaged_allocator.m_user_thread_id, v3);
    if ( vostok::memory::g_resources_unmanaged_allocator.m_thread_id_const )
      vostok::memory::g_resources_unmanaged_allocator.m_user_thread_id_called = 1;
  }
  vostok::memory::g_resources_unmanaged_allocator.m_user_thread_logging_name = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !vostok::memory::g_resources_unmanaged_allocator.m_user_thread_logging_name )
    vostok::memory::g_resources_unmanaged_allocator.m_user_thread_logging_name = "undefined";
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    v5.QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    v5 = PerformanceCount;
  }
  *(_DWORD *)((char *)&loc_20218 + (_DWORD)a2) = v5.LowPart;
  *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20218 + 4) = v5.HighPart;
  *(_DWORD *)((char *)nullsub_153 + (_DWORD)a2) = 0;
  *(_DWORD *)((char *)&loc_20214 + (_DWORD)a2) = 0;
  vostok::resources::initialize_game_resources_manager(v4);
  if ( a2->m_do_mount_mounts_path )
  {
    *(_DWORD *)((char *)btConvexConcaveCollisionAlgorithm::CreateFunc::CreateCollisionAlgorithm + (_DWORD)a2) = GetCurrentThreadId();
    vostok::resources::resources_manager::do_mount_mounts_path(v6, a2);
    a2->m_do_mount_mounts_path = 0;
  }
}
