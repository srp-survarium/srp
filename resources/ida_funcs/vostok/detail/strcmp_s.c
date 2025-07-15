int __cdecl vostok::detail::strcmp_s(const char *s1, const char *s2)
{
  const char *v2; // eax
  const char *v4; // ecx
  bool v5; // cf
  unsigned __int8 v6; // dl

  v2 = s1;
  if ( s1 )
  {
    v4 = s2;
    if ( s2 )
    {
      while ( 1 )
      {
        v5 = *v2 < (unsigned int)*v4;
        if ( *v2 != *v4 )
          break;
        if ( !*v2 )
          return 0;
        v6 = v2[1];
        v5 = v6 < (unsigned int)v4[1];
        if ( v6 != v4[1] )
          break;
        v2 += 2;
        v4 += 2;
        if ( !v6 )
          return 0;
      }
      return -v5 - (v5 - 1);
    }
    else
    {
      return *s1 != 0;
    }
  }
  else if ( s2 )
  {
    return -(*s2 != 0);
  }
  else
  {
    return 0;
  }
}
