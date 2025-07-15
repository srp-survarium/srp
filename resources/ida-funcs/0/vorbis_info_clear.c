void __usercall vorbis_info_clear(
        bool a1@<bpl>,
        vostok::memory *a2@<edi>,
        bool a3@<sil>,
        vostok::memory::doug_lea_mt_allocator *vi)
{
  vostok::memory::doug_lea_mt_allocator *v4; // ecx
  _DWORD *m_thread_id_const; // ebx
  int v6; // esi
  void **v7; // ebp
  void *v8; // edi
  int v9; // ebp
  void **v10; // esi
  int v11; // ebp
  void **v12; // esi
  int v13; // ebp
  void **v14; // esi
  int v15; // ebp
  int v16; // eax
  void *v17; // edi
  int v18; // ebp
  void *v19; // edi
  vostok::memory::doug_lea_mt_allocator *v20; // ecx
  vostok::memory *v21; // [esp-Ch] [ebp-18h]
  bool v22; // [esp-Ch] [ebp-18h]
  bool v23; // [esp-8h] [ebp-14h]
  bool v24; // [esp-4h] [ebp-10h]
  bool v25; // [esp+0h] [ebp-Ch]
  static_codebook **v26; // [esp+4h] [ebp-8h]
  vostok::memory::doug_lea_mt_allocator *v27; // [esp+8h] [ebp-4h]
  void **v28; // [esp+8h] [ebp-4h]

  v4 = vi;
  m_thread_id_const = (_DWORD *)vi->m_thread_id_const;
  if ( m_thread_id_const )
  {
    v24 = a1;
    v23 = a3;
    v6 = 0;
    v21 = a2;
    if ( (int)m_thread_id_const[2] > 0 )
    {
      v7 = (void **)(m_thread_id_const + 8);
      do
      {
        v8 = *v7;
        if ( *v7 )
        {
          if ( !vostok::memory::g_crt_allocator.__vftable )
            vostok::memory::initialize_crt_allocator(v21);
          vostok::memory::doug_lea_mt_allocator::free_impl(v4, v8);
        }
        ++v6;
        ++v7;
      }
      while ( v6 < m_thread_id_const[2] );
    }
    v9 = 0;
    if ( (int)m_thread_id_const[3] > 0 )
    {
      v10 = (void **)(m_thread_id_const + 136);
      do
      {
        if ( *v10 )
          _mapping_P[(_DWORD)*(v10 - 64)]->free_info(*v10);
        ++v9;
        ++v10;
      }
      while ( v9 < m_thread_id_const[3] );
    }
    v11 = 0;
    if ( (int)m_thread_id_const[4] > 0 )
    {
      v12 = (void **)(m_thread_id_const + 264);
      do
      {
        if ( *v12 )
          _floor_P[(_DWORD)*(v12 - 64)]->free_info(*v12);
        ++v11;
        ++v12;
      }
      while ( v11 < m_thread_id_const[4] );
    }
    v13 = 0;
    if ( (int)m_thread_id_const[5] > 0 )
    {
      v14 = (void **)(m_thread_id_const + 392);
      do
      {
        if ( *v14 )
          _residue_P[(_DWORD)*(v14 - 64)]->free_info(*v14);
        ++v13;
        ++v14;
      }
      while ( v13 < m_thread_id_const[5] );
    }
    v15 = 0;
    if ( (int)m_thread_id_const[6] > 0 )
    {
      v4 = (vostok::memory::doug_lea_mt_allocator *)(m_thread_id_const + 456);
      v27 = 0;
      v26 = (static_codebook **)(m_thread_id_const + 456);
      do
      {
        if ( *v26 )
          vorbis_staticbook_destroy(*v26, v4);
        v16 = m_thread_id_const[712];
        if ( v16 )
          vorbis_book_clear((codebook *)((char *)v27 + v16), v27);
        ++v26;
        v27 = (vostok::memory::doug_lea_mt_allocator *)((char *)v27 + 56);
        ++v15;
      }
      while ( v15 < m_thread_id_const[6] );
    }
    v17 = (void *)m_thread_id_const[712];
    if ( v17 )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
      {
        vostok::debug::preinitialize(v21);
        if ( !vostok::core::g_log_callback )
        {
          vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
          vostok::debug::set_log_callback(vostok::core::debug_log_callback);
        }
        if ( !vostok::memory::g_crt_allocator.__vftable )
        {
          if ( _InterlockedExchange((volatile __int32 *)&s_crt_allocator_creation, 1) )
          {
            while ( !vostok::memory::g_crt_allocator.__vftable )
              ;
          }
          else
          {
            vostok::memory::doug_lea_mt_allocator::doug_lea_mt_allocator(v4, (const bool)v21, v23, v24, v25);
            (*(void (__thiscall **)(char *, unsigned __int8 *, unsigned __int8 *, _DWORD, const char *))(*(_DWORD *)s_crt_allocator_buffer + 4))(
              s_crt_allocator_buffer,
              vostok::memory::s_CRT_arena,
              &vostok::memory::s_CRT_arena[55905848],
              0,
              "CRT allocator");
            v4 = &vostok::memory::g_crt_allocator;
            _InterlockedExchange((volatile __int32 *)&vostok::memory::g_crt_allocator, (__int32)s_crt_allocator_buffer);
          }
        }
      }
      vostok::memory::doug_lea_mt_allocator::free_impl(v4, v17);
    }
    v18 = 0;
    if ( (int)m_thread_id_const[7] > 0 )
    {
      v28 = (void **)(m_thread_id_const + 713);
      do
      {
        v19 = *v28;
        if ( *v28 )
        {
          memset((int)v19, 0, 0x208u);
          if ( !vostok::memory::g_crt_allocator.__vftable )
          {
            vostok::debug::preinitialize(v21);
            if ( !vostok::core::g_log_callback )
            {
              vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
              vostok::debug::set_log_callback(vostok::core::debug_log_callback);
            }
            if ( !vostok::memory::g_crt_allocator.__vftable )
            {
              v20 = &s_crt_allocator_creation;
              if ( _InterlockedExchange((volatile __int32 *)&s_crt_allocator_creation, 1) )
              {
                while ( !vostok::memory::g_crt_allocator.__vftable )
                  ;
              }
              else
              {
                vostok::memory::doug_lea_mt_allocator::doug_lea_mt_allocator(
                  &s_crt_allocator_creation,
                  (const bool)v21,
                  v23,
                  v24,
                  v25);
                (*(void (__thiscall **)(char *, unsigned __int8 *, unsigned __int8 *, _DWORD, const char *))(*(_DWORD *)s_crt_allocator_buffer + 4))(
                  s_crt_allocator_buffer,
                  vostok::memory::s_CRT_arena,
                  &vostok::memory::s_CRT_arena[55905848],
                  0,
                  "CRT allocator");
                v20 = (vostok::memory::doug_lea_mt_allocator *)_InterlockedExchange(
                                                                 (volatile __int32 *)&vostok::memory::g_crt_allocator,
                                                                 (__int32)s_crt_allocator_buffer);
              }
            }
          }
          vostok::memory::doug_lea_mt_allocator::free_impl(v20, v19);
        }
        ++v28;
        ++v18;
      }
      while ( v18 < m_thread_id_const[7] );
    }
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      vostok::debug::preinitialize(v21);
      if ( !vostok::core::g_log_callback )
      {
        vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
        vostok::debug::set_log_callback(vostok::core::debug_log_callback);
      }
      if ( !vostok::memory::g_crt_allocator.__vftable )
      {
        v4 = &s_crt_allocator_creation;
        if ( _InterlockedExchange((volatile __int32 *)&s_crt_allocator_creation, 1) )
        {
          while ( !vostok::memory::g_crt_allocator.__vftable )
            ;
        }
        else
        {
          vostok::memory::doug_lea_mt_allocator::doug_lea_mt_allocator(&s_crt_allocator_creation, v22, v23, v24, v25);
          (*(void (__thiscall **)(char *, unsigned __int8 *, unsigned __int8 *, _DWORD, const char *))(*(_DWORD *)s_crt_allocator_buffer + 4))(
            s_crt_allocator_buffer,
            vostok::memory::s_CRT_arena,
            &vostok::memory::s_CRT_arena[55905848],
            0,
            "CRT allocator");
          v4 = (vostok::memory::doug_lea_mt_allocator *)_InterlockedExchange(
                                                          (volatile __int32 *)&vostok::memory::g_crt_allocator,
                                                          (__int32)s_crt_allocator_buffer);
        }
      }
    }
    vostok::memory::doug_lea_mt_allocator::free_impl(v4, m_thread_id_const);
    v4 = vi;
  }
  v4->__vftable = 0;
  v4->m_arena_start = 0;
  v4->m_arena_end = 0;
  v4->m_arena_id = 0;
  *(_DWORD *)&v4->m_use_memory_monitor = 0;
  v4->m_arena = 0;
  v4->m_user_thread_logging_name = 0;
  v4->m_thread_id_const = thread_id_const_false;
}
