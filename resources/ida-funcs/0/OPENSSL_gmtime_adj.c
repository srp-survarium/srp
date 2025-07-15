int __cdecl OPENSSL_gmtime_adj(tm *tm, int off_day, int offset_sec)
{
  int v3; // ebp
  tm *v4; // esi
  int v5; // ebx
  int v6; // ecx
  tm *v7; // ecx
  int result; // eax
  tm *tm_mday; // [esp-4h] [ebp-14h]

  v3 = off_day + offset_sec / 86400;
  v4 = tm;
  v5 = tm->tm_sec + 60 * (tm->tm_min + 60 * tm->tm_hour) + offset_sec % 86400;
  if ( v5 < (int) __thiscall vostok::sound::world::`vcall'{12,{flat}} )
  {
    if ( v5 < 0 )
    {
      --v3;
      v5 += (int) __thiscall vostok::sound::world::`vcall'{12,{flat}};
    }
  }
  else
  {
    ++v3;
    v5 -= (int) __thiscall vostok::sound::world::`vcall'{12,{flat}};
  }
  v6 = tm->tm_mon + 1;
  tm_mday = (tm *)tm->tm_mday;
  offset_sec = tm->tm_year + 1900;
  off_day = v6;
  tm = tm_mday;
  if ( v3 + date_to_julian(offset_sec, v6, (int)tm_mday) < 0 )
    return 0;
  julian_to_date(&offset_sec, &off_day, (int *)&tm);
  if ( (unsigned int)(offset_sec - 1900) > 0x1FA3 )
    return 0;
  v4->tm_year = offset_sec - 1900;
  v4->tm_mon = off_day - 1;
  v7 = tm;
  v4->tm_hour = v5 / 3600;
  v4->tm_mday = (int)v7;
  result = 1;
  v4->tm_min = v5 / 60 % 60;
  v4->tm_sec = v5 % 60;
  return result;
}
