void __cdecl vorbis_info_init(vorbis_info *vi)
{
  vostok::memory::doug_lea_mt_allocator *v1; // ecx
  void *v2; // edi
  vostok::memory *v3; // [esp+0h] [ebp-8h]

  vi->version = 0;
  vi->channels = 0;
  vi->rate = 0;
  vi->bitrate_upper = 0;
  vi->bitrate_nominal = 0;
  vi->bitrate_lower = 0;
  vi->bitrate_window = 0;
  vi->codec_setup = 0;
  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v3);
  v2 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v1, 0xE50u);
  memset((int)v2, 0, 0xE50u);
  vi->codec_setup = v2;
}
