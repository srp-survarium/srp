unsigned int __stdcall vostok::memory::helper_thread_proc(void *__formal)
{
  unsigned __int64 QuadPart; // rax
  _RTL_CRITICAL_SECTION *v2; // esi
  unsigned __int64 v3; // rax
  vostok::memory::tester_pinned_resource *m_end; // ebx
  vostok::memory::tester_pinned_resource *m_begin; // edi
  unsigned int v6; // ebp
  int v7; // esi
  int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  int v11; // edx
  unsigned int v12; // ecx
  vostok::memory::tester_pinned_resource *v13; // eax
  unsigned int v14; // ecx
  vostok::memory::tester_pinned_resource *const *v16; // [esp+0h] [ebp-1D528h]
  unsigned int v17; // [esp+14h] [ebp-1D514h]
  vostok::buffer_vector<vostok::memory::tester_pinned_resource> v18; // [esp+18h] [ebp-1D510h] BYREF
  LARGE_INTEGER PerformanceCount; // [esp+20h] [ebp-1D508h] BYREF
  __int64 v20; // [esp+2Ch] [ebp-1D4FCh]
  vostok::timing::timer v21; // [esp+38h] [ebp-1D4F0h] BYREF
  LPCRITICAL_SECTION v22; // [esp+50h] [ebp-1D4D8h]
  vostok::math::randoms_table<30000,4294967295,1> v23; // [esp+58h] [ebp-1D4D0h] BYREF

  vostok::math::randoms_table<30000,4294967295,1>::randoms_table<30000,4294967295,1>(&v23);
  vostok::timing::timer::timer(&v21);
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    QuadPart = PerformanceCount.QuadPart;
  }
  v21.m_start_time = QuadPart;
  v21.m_current_time = 0;
  if ( s_helper_process_state == 1 )
  {
    do
    {
      v2 = s_mutex;
      v22 = s_mutex;
      vostok::threading::mutex::lock((vostok::threading::mutex *)s_mutex);
      v3 = 1000 * vostok::timing::timer::get_elapsed_ticks(&v21);
      m_end = vostok::memory::s_pinned.m_end;
      m_begin = vostok::memory::s_pinned.m_begin;
      v17 = v3 / vostok::timing::g_qpc_per_second.QuadPart;
      v6 = 0;
      if ( vostok::memory::s_pinned.m_end - vostok::memory::s_pinned.m_begin )
      {
        v7 = 0;
        do
        {
          if ( v17 >= m_begin[v7].unpin_time )
          {
            v8 = (int)(m_begin[v7].pin_ptr - 52);
            _InterlockedExchangeAdd((volatile signed __int32 *)(v8 + 44), 0xFFFFFFFF);
            if ( *(_DWORD *)(v8 + 16) && !*(_DWORD *)(v8 + 44) )
            {
              _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)(v8 + 16) + 40), 1u);
              *(_DWORD *)(v8 + 16) = 0;
            }
            v18.m_begin = &vostok::memory::s_pinned.m_begin[v7];
            v18.m_end = &vostok::memory::s_pinned.m_begin[v7 + 1];
            vostok::buffer_vector<vostok::memory::tester_pinned_resource>::erase(&v18.m_end, &v18, v16);
            m_end = vostok::memory::s_pinned.m_end;
            m_begin = vostok::memory::s_pinned.m_begin;
            --v6;
            --v7;
          }
          ++v6;
          ++v7;
        }
        while ( v6 < m_end - m_begin );
        v2 = v22;
      }
      v9 = vostok::memory::s_resources.m_end - vostok::memory::s_resources.m_begin;
      if ( v9 && (unsigned int)(m_end - m_begin) < 0xA )
      {
        v10 = v23.m_randoms.m_begin[v23.m_index++];
        if ( v23.m_index == 30000 )
          v23.m_index = 0;
        LODWORD(v20) = vostok::memory::s_resources.m_begin[v10 % v9];
        v11 = *(_DWORD *)(v20 + 212);
        _InterlockedExchangeAdd((volatile signed __int32 *)(v11 + 44), 1u);
        v12 = v23.m_randoms.m_begin[v23.m_index];
        HIDWORD(v20) = v11 + 52;
        if ( ++v23.m_index == 30000 )
          v23.m_index = 0;
        v13 = vostok::memory::s_pinned.m_end;
        v14 = v17 + v12 % 0xA;
        if ( vostok::memory::s_pinned.m_end )
        {
          *(_QWORD *)vostok::memory::s_pinned.m_end = v20;
          v13->unpin_time = v14;
        }
        ++vostok::memory::s_pinned.m_end;
      }
      LeaveCriticalSection(v2);
    }
    while ( s_helper_process_state == 1 );
    s_helper_process_state = 0;
    return 0;
  }
  else
  {
    s_helper_process_state = 0;
    return 0;
  }
}
