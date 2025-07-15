char **__usercall copy_environ@<eax>(char **oldenviron@<eax>)
{
  char **result; // eax
  char **v3; // ecx
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // [esp+4h] [ebp-4h]

  result = 0;
  v3 = oldenviron;
  if ( oldenviron )
  {
    if ( *oldenviron )
    {
      do
      {
        ++v3;
        result = (char **)((char *)result + 1);
      }
      while ( *v3 );
    }
    v4 = _calloc_crt((unsigned int)result + 1, 4u);
    v5 = v4;
    if ( !v4 )
      _amsg_exit(9);
    while ( *oldenviron )
    {
      *(_DWORD *)v4 = _strdup(*oldenviron);
      v4 += 4;
      ++oldenviron;
    }
    *(_DWORD *)v4 = 0;
    return (char **)v5;
  }
  return result;
}
