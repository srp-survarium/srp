unsigned int *vostok::threading::initialize_core_affinity()
{
  unsigned int *result; // eax
  vostok::command_line::key *v1; // ecx
  vostok::command_line::key *v2; // ecx
  char *v3; // eax
  _DWORD *v4; // eax
  char *v5; // eax
  int v6; // edx
  unsigned int v7; // ecx
  char *v8; // eax
  unsigned int i; // ecx
  const char *v10; // [esp+0h] [ebp-240h]
  unsigned int v11; // [esp+4h] [ebp-23Ch]
  vostok::buffer_string v12; // [esp+8h] [ebp-238h] BYREF
  _BYTE v13[512]; // [esp+14h] [ebp-22Ch] BYREF
  char v14; // [esp+214h] [ebp-2Ch] BYREF
  _SYSTEM_INFO SystemInfo; // [esp+21Ch] [ebp-24h] BYREF

  result = s_logical_to_physical_core_index;
  if ( !s_logical_to_physical_core_index )
  {
    if ( _InterlockedExchange(&s_logical_to_physical_core_initialize_flag, 1) )
    {
      do
        result = s_logical_to_physical_core_index;
      while ( !s_logical_to_physical_core_index );
    }
    else
    {
      vostok::threading::initialize_core_count();
      GetSystemInfo(&SystemInfo);
      v12.m_begin = v13;
      v12.m_end = v13;
      v12.m_max_end = &v14;
      v13[0] = 0;
      if ( vostok::command_line::key::is_set(v1, (int)&vostok::threading::g_debug_single_thread) )
      {
        v3 = type_info::raw_name(&unsigned int `RTTI Type Descriptor');
        v4 = vostok::memory::pthreads3_allocator::malloc_impl(
               (vostok::memory::pthreads3_allocator *)(4 * s_logical_core_count),
               (unsigned int)&vostok::memory::g_mt_allocator,
               (const char *const)(4 * s_logical_core_count),
               v3,
               v10,
               v11);
        *v4 = 0;
      }
      else if ( vostok::command_line::key::is_set_as_string(
                  v2,
                  &vostok::threading::g_core_affinity.m_string_value,
                  &v12) )
      {
        v5 = type_info::raw_name(&unsigned int `RTTI Type Descriptor');
        v4 = vostok::memory::pthreads3_allocator::malloc_impl(
               (vostok::memory::pthreads3_allocator *)(4 * s_logical_core_count),
               (unsigned int)&vostok::memory::g_mt_allocator,
               (const char *const)(4 * s_logical_core_count),
               v5,
               v10,
               v11);
        v6 = 0;
        v7 = 0;
        if ( v12.m_end != v12.m_begin )
        {
          do
          {
            if ( v12.m_begin[v7] != 48 )
            {
              v4[v6++] = v7;
              if ( v6 == s_logical_core_count )
                break;
            }
            ++v7;
          }
          while ( v7 < v12.m_end - v12.m_begin );
        }
      }
      else
      {
        v8 = type_info::raw_name(&unsigned int `RTTI Type Descriptor');
        v4 = vostok::memory::pthreads3_allocator::malloc_impl(
               (vostok::memory::pthreads3_allocator *)(4 * s_logical_core_count),
               (unsigned int)&vostok::memory::g_mt_allocator,
               (const char *const)(4 * s_logical_core_count),
               v8,
               v10,
               v11);
        for ( i = 0; i < SystemInfo.dwNumberOfProcessors; ++i )
          v4[i] = i;
      }
      return (unsigned int *)_InterlockedExchange((volatile __int32 *)&s_logical_to_physical_core_index, (__int32)v4);
    }
  }
  return result;
}
