int __usercall vorbis_block_init@<eax>(vostok::memory *a1@<edi>, vorbis_dsp_state *v, vorbis_block *vb)
{
  vorbis_block *v3; // esi
  vostok::memory::doug_lea_mt_allocator *v4; // ecx
  void *v5; // ebp
  vostok::memory::doug_lea_mt_allocator *v6; // ecx
  int v7; // edi
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  _BYTE *v10; // eax
  vostok::memory *v12; // [esp-8h] [ebp-Ch]
  vostok::memory *v13; // [esp+0h] [ebp-4h]

  v3 = vb;
  memset((int)vb, 0, sizeof(vorbis_block));
  vb->vd = v;
  vb->localalloc = 0;
  vb->localstore = 0;
  if ( v->analysisp )
  {
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v13);
    v12 = a1;
    v5 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v4, 0x48u);
    memset((int)v5, 0, 0x48u);
    vb->internal = v5;
    *((float *)v5 + 1) = -9999.0;
    v7 = 0;
    while ( 1 )
    {
      if ( v7 == 7 )
      {
        *((_DWORD *)v5 + 10) = &v3->opb;
      }
      else
      {
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v12);
        v8 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v6, 0x14u);
        v6 = 0;
        *v8 = 0;
        v8[1] = 0;
        v8[2] = 0;
        v8[3] = 0;
        v8[4] = 0;
        *((_DWORD *)v5 + v7 + 3) = v8;
      }
      v9 = (_DWORD *)*((_DWORD *)v5 + v7 + 3);
      *v9 = 0;
      v9[1] = 0;
      v9[2] = 0;
      v9[3] = 0;
      v9[4] = 0;
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v12);
      v10 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v6, 0x100u);
      ++v7;
      v9[2] = v10;
      v9[3] = v10;
      *v10 = 0;
      v9[4] = 256;
      if ( v7 >= 15 )
        break;
      v3 = vb;
    }
  }
  return 0;
}
