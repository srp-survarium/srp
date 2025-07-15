char **__usercall copy_environ@<eax>(const char **oldenviron@<eax>)
{
  char **result; // eax
  const char **v3; // ecx
  char **v4; // esi
  char **newenviron; // [esp+4h] [ebp-4h]

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
    v4 = (char **)_calloc_crt((unsigned int)result + 1, 4u);
    newenviron = v4;
    if ( !v4 )
      _amsg_exit(9);
    while ( *oldenviron )
      *v4++ = _strdup(*oldenviron++);
    *v4 = 0;
    return newenviron;
  }
  return result;
}
