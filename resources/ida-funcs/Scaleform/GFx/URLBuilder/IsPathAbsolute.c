char __cdecl Scaleform::GFx::URLBuilder::IsPathAbsolute(char *putf8str)
{
  unsigned int Char_Advance0; // eax
  unsigned int v2; // eax

  if ( !putf8str || !*putf8str )
    return 1;
  Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8str);
  if ( !Char_Advance0 )
    --putf8str;
  if ( Char_Advance0 == 47 || Char_Advance0 == 92 )
    return 1;
  if ( Char_Advance0 )
  {
    do
    {
      if ( Char_Advance0 == 58 )
      {
        v2 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8str);
        if ( v2 )
        {
          if ( v2 == 47 || v2 == 92 )
            return 1;
        }
        else
        {
          --putf8str;
        }
      }
      else if ( Char_Advance0 == 47 || Char_Advance0 == 92 )
      {
        return 0;
      }
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8str);
    }
    while ( Char_Advance0 );
    --putf8str;
  }
  return 0;
}
