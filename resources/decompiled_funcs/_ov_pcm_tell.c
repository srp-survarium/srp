__int64 __cdecl ov_pcm_tell(OggVorbis_File *vf)
{
  if ( vf->ready_state >= 2 )
    return vf->pcm_offset;
  else
    return -131;
}
