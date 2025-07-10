int __cdecl vorbis_info_blocksize(vorbis_info *vi, int zo)
{
  _DWORD *codec_setup; // eax

  codec_setup = vi->codec_setup;
  if ( codec_setup )
    return codec_setup[zo];
  else
    return -1;
}
