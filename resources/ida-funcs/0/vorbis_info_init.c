void __cdecl vorbis_info_init(vorbis_info *vi)
{
  memset(vi, 0, sizeof(vorbis_info));
  vi->codec_setup = ogg_calloc_impl(1u, 0xE50u);
}
