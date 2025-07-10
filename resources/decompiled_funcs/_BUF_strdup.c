char *__cdecl BUF_strdup(const char *str)
{
  if ( str )
    return BUF_strndup(str, strlen(str));
  else
    return 0;
}
