int __cdecl ov_serialnumber(OggVorbis_File *vf, int i)
{
  if ( i >= vf->links )
    return ov_serialnumber(vf, vf->links - 1);
  if ( !vf->seekable && i >= 0 )
    return ov_serialnumber(vf, -1);
  if ( i >= 0 )
    return vf->serialnos[i];
  return vf->current_serialno;
}
