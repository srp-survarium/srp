void __cdecl Scaleform::ScanFilePath(const char *url, const char **pfilename, const char **pext)
{
  const char *v3; // edi
  const char *v4; // esi
  unsigned int v5; // eax

  v3 = url;
  v4 = 0;
  v5 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&url);
  if ( v5 )
  {
    do
    {
      if ( v5 == 47 || v5 == 92 )
      {
        v3 = url;
        v4 = 0;
      }
      else if ( v5 == 46 )
      {
        v4 = url - 1;
      }
      v5 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&url);
    }
    while ( v5 );
    --url;
  }
  else
  {
    --url;
  }
  if ( pfilename )
    *pfilename = v3;
  if ( pext )
    *pext = v4;
}
