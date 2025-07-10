int __cdecl vds_shared_init(vorbis_dsp_state *v, vorbis_info *vi)
{
  _DWORD *codec_setup; // edi
  int v4; // esi
  vostok::memory::doug_lea_mt_allocator *v5; // ecx
  void *v6; // ebx
  int v7; // eax
  vostok::memory::doug_lea_mt_allocator *v8; // ecx
  unsigned int j; // eax
  _DWORD *v10; // eax
  vostok::memory::doug_lea_mt_allocator *v11; // ecx
  _DWORD *v12; // eax
  vostok::memory::doug_lea_mt_allocator *v13; // ecx
  vostok::memory::doug_lea_mt_allocator_vtbl *v14; // eax
  vostok::memory::doug_lea_mt_allocator *v15; // ecx
  _DWORD *v16; // eax
  int v17; // ecx
  unsigned int v18; // eax
  int v19; // eax
  int v20; // ecx
  unsigned int k; // eax
  void *v22; // eax
  vostok::memory::doug_lea_mt_allocator *v23; // ecx
  bool v24; // cc
  static_codebook **v25; // esi
  vostok::memory::doug_lea_mt_allocator *v26; // ecx
  unsigned int v27; // esi
  float **v28; // eax
  vostok::memory::doug_lea_mt_allocator *v29; // ecx
  vorbis_dsp_state *v30; // esi
  unsigned int v31; // eax
  vostok::memory::doug_lea_mt_allocator *v32; // ecx
  int pcm_storage; // esi
  unsigned int v34; // esi
  vostok::memory::doug_lea_mt_allocator *v35; // ecx
  int v36; // eax
  int v37; // esi
  unsigned int v38; // esi
  vostok::memory::doug_lea_mt_allocator *v39; // ecx
  int v40; // esi
  unsigned int v41; // esi
  void **v42; // esi
  void **v43; // esi
  static_codebook **v44; // ebx
  vostok::memory *v45; // [esp+0h] [ebp-18h]
  char *v46; // [esp+0h] [ebp-18h]
  char *v47; // [esp+0h] [ebp-18h]
  char *v48; // [esp+0h] [ebp-18h]
  char *v49; // [esp+0h] [ebp-18h]
  char *v50; // [esp+0h] [ebp-18h]
  volatile int *v51; // [esp+4h] [ebp-14h]
  vostok::memory::inplace_constructor v52; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  float *id; // [esp+Ch] [ebp-Ch]
  int ia; // [esp+Ch] [ebp-Ch]
  int ib; // [esp+Ch] [ebp-Ch]
  int ic; // [esp+Ch] [ebp-Ch]
  vostok::memory::doug_lea_mt_allocator **v58; // [esp+10h] [ebp-8h]
  vostok::memory::doug_lea_mt_allocator **v59; // [esp+10h] [ebp-8h]
  vostok::memory::doug_lea_mt_allocator **pointer; // [esp+14h] [ebp-4h]
  vostok::memory::doug_lea_mt_allocator **pointera; // [esp+14h] [ebp-4h]
  vostok::memory::doug_lea_mt_allocator **pointerb; // [esp+14h] [ebp-4h]
  vostok::memory::doug_lea_mt_allocator **pointerc; // [esp+14h] [ebp-4h]

  codec_setup = vi->codec_setup;
  if ( !codec_setup )
    return 1;
  v4 = codec_setup[914];
  memset((int)v, 0, sizeof(vorbis_dsp_state));
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v45);
  v6 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v5, 0x88u);
  memset((int)v6, 0, 0x88u);
  v->backend_state = v6;
  v->vi = vi;
  v7 = codec_setup[2];
  v8 = 0;
  if ( v7 )
  {
    for ( j = v7 - 1; j; j >>= 1 )
      v8 = (vostok::memory::doug_lea_mt_allocator *)((char *)v8 + 1);
  }
  *((_DWORD *)v6 + 11) = v8;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v45);
  v10 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v8, 4u);
  *v10 = 0;
  *((_DWORD *)v6 + 3) = v10;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v45);
  v12 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v11, 4u);
  *v12 = 0;
  *((_DWORD *)v6 + 4) = v12;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v45);
  v14 = (vostok::memory::doug_lea_mt_allocator_vtbl *)vostok::memory::doug_lea_mt_allocator::malloc_impl(v13, 0x14u);
  v14->~vostok::memory::doug_lea_mt_allocator = 0;
  v14->initialize = 0;
  v14->total_size = 0;
  v14->allocated_size = 0;
  v14->call_malloc = 0;
  v15 = (vostok::memory::doug_lea_mt_allocator *)*((_DWORD *)v6 + 3);
  v15->__vftable = v14;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v45);
  v16 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v15, 0x14u);
  *v16 = 0;
  v16[1] = 0;
  v16[2] = 0;
  v16[3] = 0;
  v16[4] = 0;
  **((_DWORD **)v6 + 4) = v16;
  mdct_init(**((mdct_lookup ***)v6 + 3), (int)*codec_setup >> v4);
  mdct_init(**((mdct_lookup ***)v6 + 4), (int)codec_setup[1] >> v4);
  v17 = 0;
  if ( *codec_setup )
  {
    v18 = *codec_setup - 1;
    if ( *codec_setup != 1 )
    {
      do
      {
        ++v17;
        v18 >>= 1;
      }
      while ( v18 );
    }
  }
  *((_DWORD *)v6 + 1) = v17 - 6;
  v19 = codec_setup[1];
  v20 = 0;
  if ( v19 )
  {
    for ( k = v19 - 1; k; k >>= 1 )
      ++v20;
  }
  *((_DWORD *)v6 + 2) = v20 - 6;
  if ( codec_setup[712]
    || (v22 = calloc(codec_setup[6], 0x38u), v24 = codec_setup[6] <= 0, codec_setup[712] = v22, i = 0, v24) )
  {
LABEL_29:
    v26 = (vostok::memory::doug_lea_mt_allocator *)vi;
    v->pcm_storage = codec_setup[1];
    v27 = 4 * vi->channels;
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      vostok::debug::preinitialize(v45);
      if ( !vostok::core::g_log_callback )
      {
        vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
        vostok::debug::set_log_callback(vostok::core::debug_log_callback);
      }
      LOBYTE(pointer) = 0;
      vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
        pointer,
        (char (*)[112])v46,
        v51,
        v52);
    }
    v28 = (float **)vostok::memory::doug_lea_mt_allocator::malloc_impl(v26, v27);
    v30 = v;
    v->pcm = v28;
    v31 = 4 * vi->channels;
    v59 = (vostok::memory::doug_lea_mt_allocator **)v31;
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      vostok::debug::preinitialize(v45);
      if ( !vostok::core::g_log_callback )
      {
        vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
        vostok::debug::set_log_callback(vostok::core::debug_log_callback);
      }
      LOBYTE(pointer) = 0;
      vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
        pointer,
        (char (*)[112])v47,
        v51,
        v52);
      v31 = (unsigned int)v59;
    }
    v->pcmret = (float **)vostok::memory::doug_lea_mt_allocator::malloc_impl(v29, v31);
    for ( pointera = 0;
          (int)pointera < vi->channels;
          pointera = (vostok::memory::doug_lea_mt_allocator **)((char *)pointera + 1) )
    {
      pcm_storage = v30->pcm_storage;
      if ( !vostok::memory::g_crt_allocator.__vftable )
      {
        vostok::debug::preinitialize(v45);
        if ( !vostok::core::g_log_callback )
        {
          vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
          vostok::debug::set_log_callback(vostok::core::debug_log_callback);
        }
        LOBYTE(v59) = 0;
        vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
          v59,
          (char (*)[112])v48,
          v51,
          v52);
      }
      v34 = 4 * pcm_storage;
      id = (float *)vostok::memory::doug_lea_mt_allocator::malloc_impl(v32, v34);
      memset((int)id, 0, v34);
      v32 = (vostok::memory::doug_lea_mt_allocator *)id;
      v30 = v;
      v->pcm[(_DWORD)pointera] = id;
    }
    v35 = 0;
    v30->lW = 0;
    v30->W = 0;
    v36 = codec_setup[1] / 2;
    v30->centerW = v36;
    v30->pcm_current = v36;
    v37 = codec_setup[4];
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      vostok::debug::preinitialize(v45);
      if ( !vostok::core::g_log_callback )
      {
        vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
        vostok::debug::set_log_callback(vostok::core::debug_log_callback);
      }
      LOBYTE(pointera) = 0;
      vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
        pointera,
        (char (*)[112])v49,
        v51,
        v52);
    }
    v38 = 4 * v37;
    pointerb = (vostok::memory::doug_lea_mt_allocator **)vostok::memory::doug_lea_mt_allocator::malloc_impl(v35, v38);
    memset((int)pointerb, 0, v38);
    v39 = (vostok::memory::doug_lea_mt_allocator *)pointerb;
    *((_DWORD *)v6 + 12) = pointerb;
    v40 = codec_setup[5];
    if ( !vostok::memory::g_crt_allocator.__vftable )
    {
      vostok::debug::preinitialize(v45);
      if ( !vostok::core::g_log_callback )
      {
        vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
        vostok::debug::set_log_callback(vostok::core::debug_log_callback);
      }
      LOBYTE(pointerb) = 0;
      vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
        pointerb,
        (char (*)[112])v50,
        v51,
        v52);
    }
    v41 = 4 * v40;
    pointerc = (vostok::memory::doug_lea_mt_allocator **)vostok::memory::doug_lea_mt_allocator::malloc_impl(v39, v41);
    memset((int)pointerc, 0, v41);
    *((_DWORD *)v6 + 13) = pointerc;
    ia = 0;
    if ( (int)codec_setup[4] > 0 )
    {
      v42 = (void **)(codec_setup + 264);
      do
      {
        *(void **)((char *)v42 + *((_DWORD *)v6 + 12) - (_DWORD)codec_setup - 1056) = _floor_P[(_DWORD)*(v42 - 64)]->look(
                                                                                        v,
                                                                                        *v42);
        ++v42;
        ++ia;
      }
      while ( ia < codec_setup[4] );
    }
    ib = 0;
    if ( (int)codec_setup[5] > 0 )
    {
      v43 = (void **)(codec_setup + 392);
      do
      {
        *(void **)((char *)v43 + *((_DWORD *)v6 + 13) - (_DWORD)codec_setup - 1568) = _residue_P[(_DWORD)*(v43 - 64)]->look(
                                                                                        v,
                                                                                        *v43);
        ++v43;
        ++ib;
      }
      while ( ib < codec_setup[5] );
    }
    return 0;
  }
  else
  {
    pointer = 0;
    v25 = (static_codebook **)(codec_setup + 456);
    v58 = (vostok::memory::doug_lea_mt_allocator **)(codec_setup + 456);
    while ( *v25 && !vorbis_book_init_decode((codebook *)((char *)pointer + codec_setup[712]), *v25) )
    {
      vorbis_staticbook_destroy(*v25, v23);
      pointer += 14;
      *v58 = 0;
      v23 = (vostok::memory::doug_lea_mt_allocator *)(v58 + 1);
      v24 = ++i < codec_setup[6];
      ++v58;
      if ( !v24 )
        goto LABEL_29;
      v25 = (static_codebook **)v58;
    }
    ic = 0;
    if ( (int)codec_setup[6] > 0 )
    {
      v44 = (static_codebook **)(codec_setup + 456);
      do
      {
        if ( *v44 )
        {
          vorbis_staticbook_destroy(*v44, v23);
          *v44 = 0;
        }
        ++v44;
        ++ic;
      }
      while ( ic < codec_setup[6] );
    }
    vorbis_dsp_clear((vostok::memory::doug_lea_mt_allocator *)v);
    return -1;
  }
}
