__int64 __cdecl boost::date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl,5,1000000,6,int>::to_tick_count(
        int hours,
        int minutes,
        int seconds,
        __int64 fs)
{
  __int64 v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+10h] [ebp-Ch]
  int v7; // [esp+14h] [ebp-8h]
  int v8; // [esp+18h] [ebp-4h]

  if ( hours >= 0 && minutes >= 0 && seconds >= 0 && fs >= 0 )
    return fs + (seconds + 60LL * minutes + 3600LL * hours) * (unsigned int)&off_F4240;
  if ( hours >= 0 )
    v8 = hours;
  else
    v8 = -hours;
  if ( minutes >= 0 )
    v7 = minutes;
  else
    v7 = -minutes;
  if ( seconds >= 0 )
    v6 = seconds;
  else
    v6 = -seconds;
  if ( fs < 0 )
    v5 = -fs;
  else
    v5 = fs;
  return -(v5 + (v6 + 60LL * v7 + 3600LL * v8) * (unsigned int)&off_F4240);
}
