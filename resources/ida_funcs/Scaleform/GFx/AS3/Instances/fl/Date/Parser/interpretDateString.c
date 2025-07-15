int __cdecl Scaleform::GFx::AS3::Instances::fl::Date::Parser::interpretDateString(
        const char *str,
        int length,
        int *index)
{
  int i; // ecx
  const char *v5; // eax
  int v6; // ecx
  const char *v7; // eax

  if ( length == 2 )
  {
    if ( str[1] == 77 )
    {
      if ( *str == 65 )
        return 5;
      if ( *str == 80 )
        return 6;
    }
    return 0;
  }
  if ( length != 3 )
    return 0;
  if ( *str == 71 && str[1] == 77 && str[2] == 84 )
    return 3;
  if ( *str == 85 && str[1] == 84 && str[2] == 67 )
    return 4;
  for ( i = 0; i < 7; ++i )
  {
    v5 = Scaleform::GFx::AS3::Instances::fl::Date::DayNames[i];
    if ( *v5 == *str && v5[1] == str[1] && v5[2] == str[2] )
    {
      *index = i;
      return 2;
    }
  }
  v6 = 0;
  while ( 1 )
  {
    v7 = Scaleform::GFx::AS3::Instances::fl::Date::MonthNames[v6];
    if ( *v7 == *str && v7[1] == str[1] && v7[2] == str[2] )
      break;
    if ( ++v6 >= 12 )
      return 0;
  }
  *index = v6;
  return 1;
}
