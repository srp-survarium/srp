void __cdecl Scaleform::ScanFilePath(char *url, const char **pfilename, const char **pext)
{
  const char *v3; // edi
  const char *v4; // esi
  unsigned int Char_Advance0; // eax

  v3 = url;
  v4 = 0;
  Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&url);
  if ( Char_Advance0 )
  {
    do
    {
      if ( Char_Advance0 == 47 || Char_Advance0 == 92 )
      {
        v3 = url;
        v4 = 0;
      }
      else if ( Char_Advance0 == 46 )
      {
        v4 = url - 1;
      }
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&url);
    }
    while ( Char_Advance0 );
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
