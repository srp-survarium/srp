void __cdecl vorbis_dsp_clear(vostok::memory::doug_lea_mt_allocator *v)
{
  vostok::memory::doug_lea_mt_allocator *v1; // ecx
  vorbis_info *m_arena_start; // ebx
  _DWORD *codec_setup; // ebp
  char *v4; // edi
  vostok::memory::doug_lea_mt_allocator *v5; // ecx
  envelope_lookup *v6; // esi
  mdct_lookup **v7; // eax
  vostok::memory::doug_lea_mt_allocator *v8; // ecx
  void *v9; // esi
  vostok::memory::doug_lea_mt_allocator *v10; // ecx
  void *v11; // esi
  mdct_lookup **v12; // eax
  vostok::memory::doug_lea_mt_allocator *v13; // ecx
  vostok::memory::doug_lea_mt_allocator_vtbl *v14; // esi
  vostok::memory::doug_lea_mt_allocator *v15; // ecx
  void *v16; // esi
  int v17; // esi
  _DWORD *v18; // ebx
  void *v19; // esi
  int v20; // esi
  _DWORD *v21; // ebx
  void *v22; // esi
  int v23; // esi
  int v24; // ebx
  void *v25; // esi
  _DWORD *v26; // esi
  vostok::memory::doug_lea_mt_allocator *v27; // ecx
  vostok::memory::doug_lea_mt_allocator *v28; // ecx
  int i; // esi
  void **v30; // eax
  void *v31; // ebp
  void *m_arena_end; // esi
  vostok::memory::doug_lea_mt_allocator *v33; // ecx
  float **m_arena_id; // esi
  void *v35; // esi
  void *v36; // esi
  void *v37; // esi
  vostok::memory *v38; // [esp+0h] [ebp-18h]
  vorbis_info *vi; // [esp+14h] [ebp-4h]

  v1 = v;
  if ( v )
  {
    m_arena_start = (vorbis_info *)v->m_arena_start;
    vi = m_arena_start;
    if ( m_arena_start )
      codec_setup = m_arena_start->codec_setup;
    else
      codec_setup = 0;
    v4 = *(char **)&v->m_is_tasks_aware;
    if ( v4 )
    {
      if ( *(_DWORD *)v4 )
      {
        _ve_envelope_clear(*(envelope_lookup **)v4);
        v6 = *(envelope_lookup **)v4;
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v38);
        vostok::memory::doug_lea_mt_allocator::free_impl(v5, v6);
      }
      v7 = (mdct_lookup **)*((_DWORD *)v4 + 3);
      if ( v7 )
      {
        mdct_clear(*v7, v1);
        v9 = (void *)**((_DWORD **)v4 + 3);
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v38);
        vostok::memory::doug_lea_mt_allocator::free_impl(v8, v9);
        v11 = (void *)*((_DWORD *)v4 + 3);
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v38);
        vostok::memory::doug_lea_mt_allocator::free_impl(v10, v11);
      }
      v12 = (mdct_lookup **)*((_DWORD *)v4 + 4);
      if ( v12 )
      {
        mdct_clear(*v12, v1);
        v13 = (vostok::memory::doug_lea_mt_allocator *)*((_DWORD *)v4 + 4);
        v14 = v13->__vftable;
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v38);
        vostok::memory::doug_lea_mt_allocator::free_impl(v13, v14);
        v16 = (void *)*((_DWORD *)v4 + 4);
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v38);
        vostok::memory::doug_lea_mt_allocator::free_impl(v15, v16);
      }
      if ( *((_DWORD *)v4 + 12) )
      {
        if ( codec_setup )
        {
          v17 = 0;
          if ( (int)codec_setup[4] > 0 )
          {
            v18 = codec_setup + 200;
            do
              _floor_P[*v18++]->free_look(*(void **)(*((_DWORD *)v4 + 12) + 4 * v17++));
            while ( v17 < codec_setup[4] );
            m_arena_start = vi;
          }
        }
        v19 = (void *)*((_DWORD *)v4 + 12);
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v38);
        vostok::memory::doug_lea_mt_allocator::free_impl(v1, v19);
      }
      if ( *((_DWORD *)v4 + 13) )
      {
        if ( codec_setup )
        {
          v20 = 0;
          if ( (int)codec_setup[5] > 0 )
          {
            v21 = codec_setup + 328;
            do
              _residue_P[*v21++]->free_look(*(void **)(*((_DWORD *)v4 + 13) + 4 * v20++));
            while ( v20 < codec_setup[5] );
            m_arena_start = vi;
          }
        }
        v22 = (void *)*((_DWORD *)v4 + 13);
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v38);
        vostok::memory::doug_lea_mt_allocator::free_impl(v1, v22);
      }
      if ( *((_DWORD *)v4 + 14) )
      {
        if ( codec_setup )
        {
          v23 = 0;
          if ( (int)codec_setup[7] > 0 )
          {
            v24 = 0;
            do
            {
              _vp_psy_clear((vostok::memory::doug_lea_mt_allocator **)(v24 + *((_DWORD *)v4 + 14)));
              ++v23;
              v24 += 52;
            }
            while ( v23 < codec_setup[7] );
            m_arena_start = vi;
          }
        }
        v25 = (void *)*((_DWORD *)v4 + 14);
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v38);
        vostok::memory::doug_lea_mt_allocator::free_impl(v1, v25);
      }
      v26 = (_DWORD *)*((_DWORD *)v4 + 15);
      if ( v26 )
      {
        *v26 = 0;
        v26[1] = 0;
        v26[2] = 0;
        v26[3] = 0;
        v26[4] = 0;
        v26[5] = 0;
        v26[6] = 0;
        v26[7] = 0;
        v26[8] = 0;
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v38);
        vostok::memory::doug_lea_mt_allocator::free_impl(v1, v26);
      }
      memset((int)(v4 + 80), 0, 0x30u);
      drft_clear((drft_lookup *)(v4 + 20), v27);
      drft_clear((drft_lookup *)(v4 + 32), v28);
      v1 = v;
    }
    if ( v1->m_arena_end )
    {
      if ( m_arena_start )
      {
        for ( i = 0; i < m_arena_start->channels; ++i )
        {
          v30 = (void **)((char *)v1->m_arena_end + 4 * i);
          if ( *v30 )
          {
            v31 = *v30;
            if ( !vostok::memory::g_crt_allocator.__vftable )
              vostok::memory::initialize_crt_allocator(v38);
            vostok::memory::doug_lea_mt_allocator::free_impl(v1, v31);
            v1 = v;
          }
        }
      }
      m_arena_end = v1->m_arena_end;
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v38);
      vostok::memory::doug_lea_mt_allocator::free_impl(v1, m_arena_end);
      m_arena_id = (float **)v->m_arena_id;
      if ( m_arena_id )
      {
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v38);
        vostok::memory::doug_lea_mt_allocator::free_impl(v33, m_arena_id);
        v1 = v;
      }
      else
      {
        v1 = v;
      }
    }
    if ( v4 )
    {
      v35 = (void *)*((_DWORD *)v4 + 16);
      if ( v35 )
      {
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v38);
        vostok::memory::doug_lea_mt_allocator::free_impl(v1, v35);
      }
      v36 = (void *)*((_DWORD *)v4 + 17);
      if ( v36 )
      {
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v38);
        vostok::memory::doug_lea_mt_allocator::free_impl(v1, v36);
      }
      v37 = (void *)*((_DWORD *)v4 + 18);
      if ( v37 )
      {
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v38);
        vostok::memory::doug_lea_mt_allocator::free_impl(v1, v37);
      }
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v38);
      vostok::memory::doug_lea_mt_allocator::free_impl(v1, v4);
      v1 = v;
    }
    memset((int)v1, 0, sizeof(vostok::memory::doug_lea_mt_allocator));
  }
}
