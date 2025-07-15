int __cdecl ov_bitrate(__int64 vf)
{
  double v2; // st7
  double v3; // [esp+10h] [ebp-28h]
  __int64 v4; // [esp+28h] [ebp-10h]
  int i; // [esp+30h] [ebp-8h]
  float v6; // [esp+34h] [ebp-4h]

  if ( *(int *)(vf + 88) < 2 )
    return -131;
  if ( SHIDWORD(vf) >= *(_DWORD *)(vf + 52) )
    return -131;
  if ( !*(_DWORD *)(vf + 4) && HIDWORD(vf) )
    return ov_bitrate((unsigned int)vf);
  if ( vf >= 0 )
  {
    if ( *(_DWORD *)(vf + 4) )
    {
      v3 = (double)(8LL
                  * (*(_QWORD *)(*(_DWORD *)(vf + 56) + 8 * HIDWORD(vf) + 8)
                   - *(_QWORD *)(*(_DWORD *)(vf + 60) + 8 * HIDWORD(vf))));
      v2 = ov_time_total((OggVorbis_File *)vf, SHIDWORD(vf));
      return (int)floor(v3 / v2 + 0.5);
    }
    else if ( *(int *)(*(_DWORD *)(vf + 72) + 32 * HIDWORD(vf) + 16) <= 0 )
    {
      if ( *(int *)(*(_DWORD *)(vf + 72) + 32 * HIDWORD(vf) + 12) <= 0 )
      {
        return -1;
      }
      else if ( *(int *)(*(_DWORD *)(vf + 72) + 32 * HIDWORD(vf) + 20) <= 0 )
      {
        return *(_DWORD *)(*(_DWORD *)(vf + 72) + 32 * HIDWORD(vf) + 12);
      }
      else
      {
        return (*(_DWORD *)(*(_DWORD *)(vf + 72) + 32 * HIDWORD(vf) + 20)
              + *(_DWORD *)(*(_DWORD *)(vf + 72) + 32 * HIDWORD(vf) + 12))
             / 2;
      }
    }
    else
    {
      return *(_DWORD *)(*(_DWORD *)(vf + 72) + 32 * HIDWORD(vf) + 16);
    }
  }
  else
  {
    v4 = 0;
    for ( i = 0; i < *(_DWORD *)(vf + 52); ++i )
      v4 += 8LL * (*(_QWORD *)(*(_DWORD *)(vf + 56) + 8 * i + 8) - *(_QWORD *)(*(_DWORD *)(vf + 60) + 8 * i));
    v6 = (double)v4 / ov_time_total((OggVorbis_File *)vf, -1);
    return (int)floor(v6 + 0.5);
  }
}
