int __cdecl ov_halfrate(OggVorbis_File *vf, int flag)
{
  __int64 pos; // [esp+4h] [ebp-10h]
  int i; // [esp+10h] [ebp-4h]

  if ( !vf->vi )
    return -131;
  if ( vf->ready_state > 3 )
  {
    vorbis_dsp_clear(&vf->vd);
    vorbis_block_clear(&vf->vb);
    vf->ready_state = 3;
    if ( vf->pcm_offset >= 0 )
    {
      pos = vf->pcm_offset;
      vf->pcm_offset = -1;
      ov_pcm_seek(vf, pos);
    }
  }
  for ( i = 0; ; ++i )
  {
    if ( i >= vf->links )
      return 0;
    if ( vorbis_synthesis_halfrate(&vf->vi[i], flag) )
      break;
  }
  if ( flag )
    ov_halfrate(vf, 0);
  return -131;
}
