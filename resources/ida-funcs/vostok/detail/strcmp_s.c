const char *__usercall vostok::detail::strcmp_s@<eax>(const char *s1@<eax>, const char *s2@<ecx>)
{
  if ( s1 )
  {
    if ( s2 )
      return (const char *)vostok::strings::compare(s1, s2);
    else
      return (const char *)(*s1 != 0);
  }
  else if ( s2 )
  {
    LOBYTE(s1) = *s2 == 0;
    --s1;
  }
  return s1;
}
