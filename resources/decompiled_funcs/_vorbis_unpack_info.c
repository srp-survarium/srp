int __usercall vorbis_unpack_info@<eax>(
        vostok::memory::doug_lea_mt_allocator *vi@<esi>,
        oggpack_buffer *opb@<eax>,
        bool a3@<bpl>)
{
  int *m_thread_id_const; // ebx
  unsigned int v6; // eax
  int v7; // edx
  int v8; // ebx

  m_thread_id_const = (int *)vi->m_thread_id_const;
  if ( !m_thread_id_const )
    return -129;
  v6 = oggpack_read(opb, 0x20u);
  vi->__vftable = (vostok::memory::doug_lea_mt_allocator_vtbl *)v6;
  if ( v6 )
    return -134;
  vi->m_arena_start = (void *)oggpack_read(opb, 8u);
  vi->m_arena_end = (void *)oggpack_read(opb, 0x20u);
  vi->m_arena_id = (const char *)oggpack_read(opb, 0x20u);
  *(_DWORD *)&vi->m_use_memory_monitor = oggpack_read(opb, 0x20u);
  vi->m_arena = (void *)oggpack_read(opb, 0x20u);
  *m_thread_id_const = 1 << oggpack_read(opb, 4u);
  v7 = 1 << oggpack_read(opb, 4u);
  m_thread_id_const[1] = v7;
  if ( (int)vi->m_arena_end >= 1 && (int)vi->m_arena_start >= 1 )
  {
    v8 = *m_thread_id_const;
    if ( v8 >= 64 && v7 >= v8 && v7 <= 0x2000 && oggpack_read(opb, 1u) == 1 )
      return 0;
  }
  vorbis_info_clear(a3, (vostok::memory *)opb, (bool)vi, vi);
  return -133;
}
