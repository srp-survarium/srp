int __cdecl make_decode_ready(OggVorbis_File *vf)
{
  if ( vf->ready_state > 3 )
    return 0;
  if ( vf->ready_state < 3 )
    return -129;
  if ( vf->seekable )
  {
    if ( vorbis_synthesis_init(&vf->vd, &vf->vi[vf->current_link]) )
      return -137;
  }
  else if ( vorbis_synthesis_init(&vf->vd, vf->vi) )
  {
    return -137;
  }
  vorbis_block_init(&vf->vd, &vf->vb);
  vf->ready_state = 4;
  vf->bittrack = 0.0;
  vf->samptrack = 0.0;
  return 0;
}
