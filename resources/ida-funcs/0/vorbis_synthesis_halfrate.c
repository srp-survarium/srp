int __cdecl vorbis_synthesis_halfrate(vorbis_info *vi, int flag)
{
  int *codec_setup; // eax

  codec_setup = (int *)vi->codec_setup;
  if ( *codec_setup <= 64 && flag )
    return -1;
  codec_setup[914] = flag != 0;
  return 0;
}
