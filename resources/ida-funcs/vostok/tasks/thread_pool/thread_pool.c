void __userpurge vostok::tasks::thread_pool::thread_pool(
        vostok::tasks::thread_pool *this@<ecx>,
        _DWORD *max_task_threads,
        unsigned int max_user_threads,
        unsigned int min_permanent_working_threads,
        vostok::tasks::execute_while_wait_for_children_enum execute_while_wait_for_children,
        vostok::tasks::do_logging_bool do_logging)
{
  _DWORD *v6; // ebx
  vostok::threading::event_tasks_unaware *v7; // ecx
  vostok::threading::event_tasks_unaware *v8; // ecx
  vostok::threading::event_tasks_unaware *v9; // ecx
  vostok::threading::event_tasks_unaware *v10; // ecx
  vostok::timing::timer *v11; // ecx
  vostok::threading::event_tasks_unaware *v12; // ecx
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  vostok::memory::pthreads3_allocator *v16; // ecx
  char *v17; // eax
  void *v18; // ecx
  unsigned int v19; // eax
  vostok::memory::pthreads3_allocator *v20; // ecx
  char *v21; // edi
  void *v22; // ecx
  unsigned int v23; // eax
  vostok::command_line::key *v24; // ecx
  vostok::buffer_vector<vostok::tasks::thread_tls> *v25; // ecx
  vostok::buffer_vector<vostok::tasks::thread_tls> *v26; // ecx
  unsigned int v27; // edi
  void *v28; // ecx
  void *v29; // ecx
  _DWORD *v30; // eax
  _RTL_CRITICAL_SECTION *v31; // [esp-4h] [ebp-18h]
  const char *v32; // [esp+0h] [ebp-14h]
  const char *v33; // [esp+0h] [ebp-14h]
  const char *v34; // [esp+0h] [ebp-14h]
  const char *v35; // [esp+0h] [ebp-14h]
  unsigned int v36; // [esp+4h] [ebp-10h]
  unsigned int v37; // [esp+4h] [ebp-10h]
  unsigned int v38; // [esp+4h] [ebp-10h]
  unsigned int v39; // [esp+Ch] [ebp-8h]
  char *v40; // [esp+Ch] [ebp-8h]
  unsigned int out_value; // [esp+10h] [ebp-4h] BYREF

  v6 = max_task_threads;
  v31 = (_RTL_CRITICAL_SECTION *)(max_task_threads + 2);
  *max_task_threads = 1;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware((vostok::threading::mutex_tasks_unaware *)this, v31);
  vostok::threading::event_tasks_unaware::event_tasks_unaware(v7, (HANDLE *)v6 + 8);
  vostok::threading::event_tasks_unaware::event_tasks_unaware(v8, (HANDLE *)v6 + 10);
  vostok::threading::event_tasks_unaware::event_tasks_unaware(v9, (HANDLE *)v6 + 12);
  vostok::threading::event_tasks_unaware::event_tasks_unaware(v10, (HANDLE *)v6 + 14);
  vostok::timing::timer::timer(v11, (LARGE_INTEGER *)v6 + 8);
  v6[22] = 0;
  vostok::threading::event_tasks_unaware::event_tasks_unaware(v12, (HANDLE *)v6 + 24);
  v6[26] = 0;
  v6[27] = 0;
  v6[28] = 0;
  v13 = type_info::raw_name(&vostok::tasks::thread_tls `RTTI Type Descriptor');
  v39 = 360 * max_user_threads;
  v14 = vostok::memory::pthreads3_allocator::malloc_impl(
          (vostok::memory::pthreads3_allocator *)(360 * max_user_threads),
          (int)&vostok::memory::g_mt_allocator,
          (const char *const)(360 * max_user_threads),
          v13,
          v32,
          v36);
  v6[31] = &v14[v39];
  v6[29] = v14;
  v6[30] = v14;
  v15 = type_info::raw_name(&vostok::tasks::thread_tls `RTTI Type Descriptor');
  v17 = vostok::memory::pthreads3_allocator::malloc_impl(
          v16,
          (int)&vostok::memory::g_mt_allocator,
          (const char *const)0xB400,
          v15,
          v33,
          v37);
  v6[32] = v17;
  v6[33] = v17;
  v6[34] = v17 + 46080;
  v40 = type_info::raw_name(&long `RTTI Type Descriptor');
  v19 = vostok::threading::core_count(v18);
  v21 = vostok::memory::pthreads3_allocator::malloc_impl(
          v20,
          (int)&vostok::memory::g_mt_allocator,
          (const char *const)(4 * v19),
          v40,
          v34,
          v38);
  v6[37] = &v21[4 * vostok::threading::core_count(v22)];
  v23 = min_permanent_working_threads;
  v6[35] = v21;
  v6[36] = v21;
  v6[38] = v23;
  v6[39] = 0;
  v6[40] = 0;
  v6[41] = 0;
  *((_BYTE *)v6 + 168) = 0;
  v6[43] = 0;
  out_value = 0;
  if ( vostok::command_line::key::is_set_as_number<unsigned int>(v24, (int)&s_spin_count_key, &out_value) )
  {
    v25 = &s_spin_count;
    _InterlockedExchange((volatile __int32 *)&s_spin_count, out_value);
  }
  vostok::buffer_vector<vostok::tasks::thread_tls>::resize(v25, v6 + 29, max_user_threads);
  vostok::buffer_vector<vostok::tasks::thread_tls>::resize(v26, v6 + 32, 0x80u);
  v6[27] = TlsAlloc();
  ResetEvent((HANDLE)v6[8]);
  v27 = 0;
  if ( vostok::threading::core_count(v28) )
  {
    do
    {
      if ( v6[36] >= v6[37]
        && !`vostok::buffer_vector<long volatile>::push_back'::`11'::debug_macro_helper_ignore_always )
      {
        HIBYTE(max_task_threads) = 0;
        vostok::debug::on_error(
          (bool *)&max_task_threads + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<long volatile >::push_back",
          (const char *)0x12E,
          "buffer overflow",
          v35);
        if ( vostok::debug::is_debugger_present() || HIBYTE(max_task_threads) )
          __debugbreak();
      }
      v30 = (_DWORD *)v6[36];
      if ( v30 )
        *v30 = 0;
      v6[36] += 4;
      ++v27;
    }
    while ( v27 < vostok::threading::core_count(v29) );
  }
  v6[23] = 0;
}
