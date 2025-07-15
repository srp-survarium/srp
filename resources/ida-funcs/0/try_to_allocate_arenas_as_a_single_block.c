char __cdecl try_to_allocate_arenas_as_a_single_block(
        vostok::buffer_vector<vostok::memory::platform::region> *arenas,
        vostok::buffer_vector<vostok::memory::platform::region> *resource_arenas)
{
  vostok::memory::platform::region *m_begin; // eax
  vostok::memory::platform::region *m_end; // ecx
  unsigned int v4; // esi
  unsigned int v5; // edi
  unsigned __int64 v6; // kr00_8
  vostok::memory::platform::region *v7; // eax
  vostok::memory::platform::region *v8; // ecx
  unsigned __int64 v9; // kr08_8
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // kr10_8
  int v12; // ecx
  char *v13; // eax
  vostok::memory::platform::region *v15; // ecx
  vostok::memory::platform::region *v16; // edx
  vostok::memory::platform::region *v17; // ecx
  vostok::memory::platform::region *v18; // edx
  unsigned __int64 pure_total_size; // [esp+14h] [ebp-30h]
  _SYSTEM_INFO SystemInfo; // [esp+20h] [ebp-24h] BYREF

  m_begin = arenas->m_begin;
  m_end = arenas->m_end;
  v4 = 0;
  v5 = 0;
  if ( arenas->m_begin != m_end )
  {
    do
    {
      v6 = m_begin->size + __PAIR64__(v5, v4);
      v5 = HIDWORD(v6);
      v4 = v6;
      ++m_begin;
    }
    while ( m_begin != m_end );
  }
  v7 = resource_arenas->m_begin;
  v8 = resource_arenas->m_end;
  if ( resource_arenas->m_begin != v8 )
  {
    do
    {
      v9 = v7->size + __PAIR64__(v5, v4);
      v5 = HIDWORD(v9);
      v4 = v9;
      ++v7;
    }
    while ( v7 != v8 );
  }
  pure_total_size = __PAIR64__(v5, v4);
  GetSystemInfo(&SystemInfo);
  v10 = __PAIR64__(v5, v4) % SystemInfo.dwAllocationGranularity;
  if ( v10 )
  {
    v11 = SystemInfo.dwAllocationGranularity - v10 + __PAIR64__(v5, v4);
    v5 = HIDWORD(v11);
    v4 = v11;
  }
  GetSystemInfo(&SystemInfo);
  v12 = (__PAIR64__(v5, SystemInfo.dwAllocationGranularity) == 0 || v5 == (SystemInfo.dwAllocationGranularity == 0))
     && (!__PAIR64__(v5, SystemInfo.dwAllocationGranularity) || v4 < -SystemInfo.dwAllocationGranularity);
  v13 = (char *)VirtualAlloc(
                  0,
                  (-v12 & (v4 + SystemInfo.dwAllocationGranularity)) - SystemInfo.dwAllocationGranularity,
                  0x3000u,
                  4u);
  if ( !v13 )
    return 0;
  *(_QWORD *)&s_crt_allocator_creation.m_arena_id = pure_total_size;
  v15 = arenas->m_begin;
  v16 = arenas->m_end;
  for ( s_crt_allocator_creation.m_arena_start = v13; v15 != v16; ++v15 )
  {
    if ( v15->size )
    {
      v15->address = v13;
      v13 += LODWORD(v15->size);
    }
  }
  v17 = resource_arenas->m_begin;
  v18 = resource_arenas->m_end;
  if ( resource_arenas->m_begin != v18 )
  {
    do
    {
      v17->address = v13;
      v13 += LODWORD(v17->size);
      ++v17;
    }
    while ( v17 != v18 );
  }
  return 1;
}
