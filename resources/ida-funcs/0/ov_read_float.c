int __cdecl ov_read_float(OggVorbis_File *vf, float ***pcm_channels, int length, int *bitstream)
{
  int ret; // [esp+0h] [ebp-10h]
  char hs; // [esp+4h] [ebp-Ch]
  int samples; // [esp+8h] [ebp-8h]
  float **pcm; // [esp+Ch] [ebp-4h] BYREF

  if ( vf->ready_state < 2 )
    return -131;
  while ( 1 )
  {
    if ( vf->ready_state == 4 )
    {
      samples = vorbis_synthesis_pcmout(&vf->vd, &pcm);
      if ( samples )
        break;
    }
    ret = fetch_and_process_packet(vf, 0, 1, 1);
    if ( ret == -2 )
      return 0;
    if ( ret <= 0 )
      return ret;
  }
  hs = vorbis_synthesis_halfrate_p(vf->vi);
  if ( pcm_channels )
    *pcm_channels = pcm;
  if ( samples > length )
    samples = length;
  vorbis_synthesis_read(&vf->vd, samples);
  vf->pcm_offset += samples << hs;
  if ( bitstream )
    *bitstream = vf->current_link;
  return samples;
}
