int __usercall vorbis_block_clear@<eax>(
        vostok::memory::doug_lea_mt_allocator *a1@<ecx>,
        vostok::debug *a2@<ebx>,
        vorbis_block *vb)
{
  vorbis_block *v3; // edi
  vorbis_block_internal *internal; // ebp
  vostok::memory::doug_lea_mt_allocator *v5; // ecx
  void *localstore; // esi
  int v7; // edi
  oggpack_buffer **packetblob; // ebp
  oggpack_buffer *v9; // esi
  unsigned __int8 *buffer; // ebx
  oggpack_buffer *v11; // esi
  vostok::memory *v13; // [esp-4h] [ebp-14h]
  vostok::memory *v14; // [esp+0h] [ebp-10h]
  vorbis_block_internal *vbi; // [esp+Ch] [ebp-4h]

  v3 = vb;
  internal = (vorbis_block_internal *)vb->internal;
  vbi = internal;
  _vorbis_block_ripcord(vb, a1, a2);
  localstore = vb->localstore;
  if ( localstore )
  {
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v14);
    vostok::memory::doug_lea_mt_allocator::free_impl(v5, localstore);
  }
  if ( internal )
  {
    v7 = 0;
    packetblob = internal->packetblob;
    v13 = a2;
    do
    {
      v9 = *packetblob;
      buffer = (*packetblob)->buffer;
      if ( buffer )
      {
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v13);
        vostok::memory::doug_lea_mt_allocator::free_impl(v5, buffer);
      }
      v9->endbyte = 0;
      v9->endbit = 0;
      v9->buffer = 0;
      v9->ptr = 0;
      v9->storage = 0;
      if ( v7 != 7 )
      {
        v11 = *packetblob;
        if ( !vostok::memory::g_crt_allocator.__vftable )
          vostok::memory::initialize_crt_allocator(v13);
        vostok::memory::doug_lea_mt_allocator::free_impl(v5, v11);
      }
      ++v7;
      ++packetblob;
    }
    while ( v7 < 15 );
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v14);
    vostok::memory::doug_lea_mt_allocator::free_impl(v5, vbi);
    v3 = vb;
  }
  memset((int)v3, 0, sizeof(vorbis_block));
  return 0;
}
