__int64 __cdecl ov_raw_tell(OggVorbis_File *vf)
{
  if ( vf->ready_state >= 2 )
    return vf->offset;
  else
    return -131;
}
