vorbis_info *__cdecl ov_info(OggVorbis_File *vf, int link)
{
  if ( !vf->seekable )
    return vf->vi;
  if ( link >= 0 )
  {
    if ( link < vf->links )
      return &vf->vi[link];
    else
      return 0;
  }
  else if ( vf->ready_state < 3 )
  {
    return vf->vi;
  }
  else
  {
    return &vf->vi[vf->current_link];
  }
}
