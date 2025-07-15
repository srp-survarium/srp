int __usercall vorbis_unpack_info@<eax>(vorbis_info *vi@<edi>, oggpack_buffer *opb@<eax>)
{
  int *codec_setup; // ebx
  unsigned int v5; // eax
  int v6; // edx
  int v7; // ebx

  codec_setup = (int *)vi->codec_setup;
  if ( !codec_setup )
    return -129;
  v5 = oggpack_read(opb, 0x20u);
  vi->version = v5;
  if ( v5 )
    return -134;
  vi->channels = oggpack_read(opb, 8u);
  vi->rate = oggpack_read(opb, 0x20u);
  vi->bitrate_upper = oggpack_read(opb, 0x20u);
  vi->bitrate_nominal = oggpack_read(opb, 0x20u);
  vi->bitrate_lower = oggpack_read(opb, 0x20u);
  *codec_setup = 1 << oggpack_read(opb, 4u);
  v6 = 1 << oggpack_read(opb, 4u);
  codec_setup[1] = v6;
  if ( vi->rate >= 1 && vi->channels >= 1 )
  {
    v7 = *codec_setup;
    if ( v7 >= 64 && v6 >= v7 && v6 <= 0x2000 && oggpack_read(opb, 1u) == 1 )
      return 0;
  }
  vorbis_info_clear(vi);
  return -133;
}
