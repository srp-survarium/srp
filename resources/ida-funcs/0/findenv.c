int __usercall findenv@<eax>(unsigned int len@<edi>, const char *name)
{
  const unsigned __int8 **i; // esi
  unsigned __int8 v3; // al

  for ( i = (const unsigned __int8 **)_environ; ; ++i )
  {
    if ( !*i )
      return -(((char *)i - (char *)_environ) >> 2);
    if ( !_mbsnbicoll(len, (unsigned int)i, (const unsigned __int8 *)name, *i, len) )
    {
      v3 = (*i)[len];
      if ( v3 == 61 || !v3 )
        break;
    }
  }
  return ((char *)i - (char *)_environ) >> 2;
}
