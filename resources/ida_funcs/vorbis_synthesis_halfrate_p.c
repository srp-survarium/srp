int __cdecl vorbis_synthesis_halfrate_p(vorbis_info *vi)
{
  return *((_DWORD *)vi->codec_setup + 914);
}
