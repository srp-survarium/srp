char *__cdecl getStringHelper(char *buf, char *end, char *str, int len)
{
  int v4; // esi
  char *v5; // ecx
  int v6; // edx

  v4 = len;
  if ( len > end - buf )
    v4 = end - buf;
  if ( v4 )
  {
    v5 = buf;
    v6 = v4;
    do
    {
      *v5 = v5[str - buf];
      ++v5;
      --v6;
    }
    while ( v6 );
  }
  return &buf[v4];
}
