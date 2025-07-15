char __usercall try_to_allocate_arenas_as_a_single_block@<al>(
        vostok::buffer_vector<vostok::memory::platform::region> *arenas@<eax>,
        vostok::buffer_vector<vostok::memory::platform::region> *resource_arenas)
{
  vostok::memory::platform::region *m_begin; // eax
  unsigned __int64 v4; // kr00_8
  vostok::memory::platform::region *i; // eax
  unsigned __int64 v6; // kr08_8
  unsigned int v7; // eax
  unsigned __int64 v8; // kr10_8
  unsigned int v9; // eax
  unsigned __int64 v10; // rax
  char *region; // eax
  vostok::memory::platform::region *v13; // ecx
  vostok::memory::platform::region *m_end; // esi
  vostok::memory::platform::region *v15; // ecx
  vostok::memory::platform::region *v16; // edx
  unsigned __int64 v17; // [esp-18h] [ebp-2Ch]

  m_begin = arenas->m_begin;
  v4 = 0;
  while ( m_begin != arenas->m_end )
  {
    v4 += m_begin->size;
    ++m_begin;
  }
  for ( i = resource_arenas->m_begin; i != resource_arenas->m_end; ++i )
  {
    v6 = i->size + v4;
    v4 = v6;
  }
  v7 = allocation_granularity();
  v8 = vostok::math::align_up<unsigned __int64>(v4, v7);
  v9 = allocation_granularity();
  HIDWORD(v17) = v9 == 0;
  LODWORD(v17) = -v9;
  v10 = vostok::math::min(v8, v17);
  region = (char *)allocate_region(v10, 0);
  if ( !region )
    return 0;
  s_single_block_arena_size = v4;
  v13 = arenas->m_begin;
  m_end = arenas->m_end;
  s_single_block_arena = region;
  while ( v13 != m_end )
  {
    if ( v13->size )
    {
      v13->address = region;
      region += LODWORD(v13->size);
    }
    ++v13;
  }
  v15 = resource_arenas->m_begin;
  v16 = resource_arenas->m_end;
  while ( v15 != v16 )
  {
    v15->address = region;
    region += LODWORD(v15->size);
    ++v15;
  }
  return 1;
}
