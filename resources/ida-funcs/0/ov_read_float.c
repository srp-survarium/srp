int __usercall ov_read_float@<eax>(
        __int128 a1@<xmm0>,
        OggVorbis_File *vf,
        float ***pcm_channels,
        int length,
        int *bitstream)
{
  int v6; // [esp+0h] [ebp-10h]
  char v7; // [esp+4h] [ebp-Ch]
  int n; // [esp+8h] [ebp-8h]
  float **pcm; // [esp+Ch] [ebp-4h] BYREF

  if ( vf->ready_state < 2 )
    return -131;
  while ( 1 )
  {
    if ( vf->ready_state == 4 )
    {
      n = vorbis_synthesis_pcmout(&vf->vd, &pcm);
      if ( n )
        break;
    }
    v6 = fetch_and_process_packet(a1, vf, 0, 1, 1);
    if ( v6 == -2 )
      return 0;
    if ( v6 <= 0 )
      return v6;
  }
  v7 = vorbis_synthesis_halfrate_p(vf->vi);
  if ( pcm_channels )
    *pcm_channels = pcm;
  if ( n > length )
    n = length;
  vorbis_synthesis_read(&vf->vd, n);
  vf->pcm_offset += n << v7;
  if ( bitstream )
    *bitstream = vf->current_link;
  return n;
}
