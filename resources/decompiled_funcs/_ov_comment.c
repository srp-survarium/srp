vorbis_comment *__cdecl ov_comment(OggVorbis_File *vf, int link)
{
  if ( !vf->seekable )
    return vf->vc;
  if ( link >= 0 )
  {
    if ( link < vf->links )
      return &vf->vc[link];
    else
      return 0;
  }
  else if ( vf->ready_state < 3 )
  {
    return vf->vc;
  }
  else
  {
    return &vf->vc[vf->current_link];
  }
}
