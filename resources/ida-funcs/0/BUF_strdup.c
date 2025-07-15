char *__cdecl BUF_strdup(char *str)
{
  if ( str )
    return BUF_strndup(str, strlen(str));
  else
    return 0;
}
