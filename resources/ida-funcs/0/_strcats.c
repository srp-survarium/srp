void _strcats(char *outstr, unsigned int sizeInBytes, int n, ...)
{
  int v3; // edi
  const char **p_n; // esi

  v3 = n;
  if ( n > 0 )
  {
    p_n = (const char **)&n;
    do
    {
      if ( strcat_s(v3, outstr, sizeInBytes, *++p_n) )
        _invoke_watson(0, v3, (int)p_n);
      --v3;
    }
    while ( v3 );
  }
}
