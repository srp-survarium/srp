__int64 __usercall boost::date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl,5,1000000,6,int>::to_tick_count@<edx:eax>(
        int hours@<eax>,
        int minutes,
        int seconds,
        __int64 fs)
{
  int v4; // ebx
  __int64 v5; // rdi

  v4 = minutes;
  v5 = fs;
  if ( hours < 0 )
  {
    hours = -hours;
  }
  else
  {
    if ( minutes < 0 )
    {
LABEL_8:
      v4 = -minutes;
      goto LABEL_9;
    }
    if ( seconds >= 0 && fs >= 0 )
      return fs + (seconds + 60 * (minutes + 60LL * hours)) * (unsigned int)&loc_F4240;
  }
  if ( minutes < 0 )
    goto LABEL_8;
LABEL_9:
  if ( seconds < 0 )
    seconds = -seconds;
  if ( fs < 0 )
  {
    LODWORD(v5) = -(int)fs;
    HIDWORD(v5) = (unsigned __int64)-v5 >> 32;
  }
  return -v5 - (seconds + 60 * (v4 + 60LL * hours)) * (unsigned int)&loc_F4240;
}
