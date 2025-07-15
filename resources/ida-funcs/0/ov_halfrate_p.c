int __cdecl ov_halfrate_p(OggVorbis_File *vf)
{
  if ( vf->vi )
    return vorbis_synthesis_halfrate_p(vf->vi);
  else
    return -131;
}
