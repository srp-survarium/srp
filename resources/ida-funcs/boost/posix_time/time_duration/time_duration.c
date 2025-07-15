void __usercall boost::posix_time::time_duration::time_duration(
        boost::posix_time::time_duration *this@<ecx>,
        _DWORD *a2@<eax>)
{
  char *v2; // ecx
  char *v3; // ecx
  char *v4; // ecx

  if ( this )
  {
    v2 = (char *)&this[-1].ticks_.value_ + 7;
    if ( v2 )
    {
      v3 = v2 - 1;
      if ( !v3 )
      {
        *a2 = -1;
        a2[1] = 0x7FFFFFFF;
        return;
      }
      v4 = v3 - 1;
      if ( v4 )
      {
        a2[1] = 0x7FFFFFFF;
        if ( v4 == (char *)1 )
        {
          *a2 = -3;
          return;
        }
        goto LABEL_12;
      }
      *a2 = 1;
    }
    else
    {
      *a2 = 0;
    }
    a2[1] = 0x80000000;
    return;
  }
  a2[1] = 0x7FFFFFFF;
LABEL_12:
  *a2 = -2;
}
