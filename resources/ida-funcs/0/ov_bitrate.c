int __cdecl ov_bitrate(OggVorbis_File *vf, int i)
{
  long double v3; // st7
  double v4; // [esp+10h] [ebp-28h]
  __int64 bits; // [esp+28h] [ebp-10h]
  int j; // [esp+30h] [ebp-8h]
  float br; // [esp+34h] [ebp-4h]

  if ( vf->ready_state < 2 )
    return -131;
  if ( i >= vf->links )
    return -131;
  if ( !vf->seekable && i )
    return ov_bitrate(vf, 0);
  if ( i >= 0 )
  {
    if ( vf->seekable )
    {
      v4 = (double)(8 * (vf->offsets[i + 1] - vf->dataoffsets[i]));
      v3 = ov_time_total(vf, i);
      return (int)floor(v4 / v3 + 0.5);
    }
    else if ( vf->vi[i].bitrate_nominal <= 0 )
    {
      if ( vf->vi[i].bitrate_upper <= 0 )
      {
        return -1;
      }
      else if ( vf->vi[i].bitrate_lower <= 0 )
      {
        return vf->vi[i].bitrate_upper;
      }
      else
      {
        return (vf->vi[i].bitrate_lower + vf->vi[i].bitrate_upper) / 2;
      }
    }
    else
    {
      return vf->vi[i].bitrate_nominal;
    }
  }
  else
  {
    bits = 0;
    for ( j = 0; j < vf->links; ++j )
      bits += 8 * (vf->offsets[j + 1] - vf->dataoffsets[j]);
    br = (double)bits / ov_time_total(vf, -1);
    return (int)floor(br + 0.5);
  }
}
