const char *__cdecl null_puts(bio_st *bp, const char *str)
{
  const char *result; // eax

  result = str;
  if ( str )
    return (const char *)strlen(str);
  return result;
}
