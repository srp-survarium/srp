char *__cdecl Scaleform::GFx::AS3::Instances::fl::Date::Parser::scanUnsignedInt(char *str, int *val)
{
  char *result; // eax
  char i; // cl

  result = str;
  *val = 0;
  for ( i = *str; *result >= 48; i = *result )
  {
    if ( i > 57 )
      break;
    ++result;
    *val = i + 10 * *val - 48;
  }
  return result;
}
