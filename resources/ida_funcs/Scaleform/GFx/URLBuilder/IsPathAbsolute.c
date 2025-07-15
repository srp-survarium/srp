char __cdecl Scaleform::GFx::URLBuilder::IsPathAbsolute(const char *putf8str)
{
  unsigned int v1; // eax
  unsigned int v2; // eax

  if ( !putf8str || !*putf8str )
    return 1;
  v1 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8str);
  if ( !v1 )
    --putf8str;
  if ( v1 == 47 || v1 == 92 )
    return 1;
  if ( v1 )
  {
    do
    {
      if ( v1 == 58 )
      {
        v2 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8str);
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
      else if ( v1 == 47 || v1 == 92 )
      {
        return 0;
      }
      v1 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8str);
    }
    while ( v1 );
    --putf8str;
  }
  return 0;
}
