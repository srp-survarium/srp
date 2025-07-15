const char *__cdecl Scaleform::GFx::AS3::Instances::fl::Date::Parser::skipWhitespace(const char *str)
{
  const char *result; // eax
  char i; // cl
  char v3; // cl

  result = str;
  for ( i = *str; i; i = *++result )
  {
    if ( i > 32 && i != 44 )
    {
      if ( i != 45 )
        break;
      v3 = result[1];
      if ( v3 >= 48 && v3 <= 57 )
        break;
    }
  }
  return result;
}
