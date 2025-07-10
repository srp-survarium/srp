void __cdecl vostok::threading::initialize_core_affinity()
{
  int v0; // ebx
  _DWORD *v1; // esi
  unsigned int v2; // edi
  _DWORD *v3; // eax
  unsigned int dwNumberOfProcessors; // ecx
  unsigned int i; // eax
  _SYSTEM_INFO SystemInfo; // [esp+10h] [ebp-234h] BYREF
  vostok::fixed_string<512> core_affinity; // [esp+34h] [ebp-210h] BYREF
  char v8; // [esp+240h] [ebp-4h] BYREF

  if ( !s_logical_to_physical_core_index )
  {
    v0 = 0;
    if ( _InterlockedExchange(&s_logical_to_physical_core_initialize_flag, 1) )
    {
      while ( !s_logical_to_physical_core_index )
        ;
    }
    else
    {
      vostok::threading::initialize_core_count();
      GetSystemInfo(&SystemInfo);
      core_affinity.m_begin = core_affinity.m_buffer;
      core_affinity.m_end = core_affinity.m_buffer;
      core_affinity.m_max_end = &v8;
      core_affinity.m_buffer[0] = 0;
      if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
      {
        vostok::threading::g_debug_single_thread.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      }
      if ( vostok::threading::g_debug_single_thread.m_type == type_recursive )
      {
        if ( vostok::command_line::key::is_set_as_string(
               &vostok::threading::g_core_affinity,
               (vostok::command_line::key *)&core_affinity) )
        {
          v2 = 0;
          v1 = pt3malloc((char *)(4 * s_logical_core_count));
          if ( core_affinity.m_end != core_affinity.m_begin )
          {
            do
            {
              if ( *vostok::buffer_string::operator[](&core_affinity, v2) != 48 )
              {
                v1[v0++] = v2;
                if ( v0 == s_logical_core_count )
                  break;
              }
              ++v2;
            }
            while ( v2 < core_affinity.m_end - core_affinity.m_begin );
          }
        }
        else
        {
          v3 = pt3malloc((char *)(4 * s_logical_core_count));
          dwNumberOfProcessors = SystemInfo.dwNumberOfProcessors;
          v1 = v3;
          for ( i = 0; i < dwNumberOfProcessors; ++i )
            v1[i] = i;
        }
      }
      else
      {
        v1 = pt3malloc((char *)(4 * s_logical_core_count));
        *v1 = 0;
      }
      _InterlockedExchange((volatile __int32 *)&s_logical_to_physical_core_index, (__int32)v1);
    }
  }
}
