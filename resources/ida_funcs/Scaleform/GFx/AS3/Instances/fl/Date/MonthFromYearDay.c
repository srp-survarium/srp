int __cdecl Scaleform::GFx::AS3::Instances::fl::Date::MonthFromYearDay(int year, int dayWithinYear)
{
  BOOL IsLeapYear; // ecx
  int result; // eax
  const int *i; // ecx

  IsLeapYear = Scaleform::GFx::AS3::Instances::fl::Date::IsLeapYear(year);
  result = 0;
  for ( i = &Scaleform::GFx::AS3::Instances::fl::Date::Months[IsLeapYear][1]; *(i - 1) <= dayWithinYear; i += 6 )
  {
    if ( *i > dayWithinYear )
      return ++result;
    if ( i[1] > dayWithinYear )
    {
      result += 2;
      return result;
    }
    if ( i[2] > dayWithinYear )
    {
      result += 3;
      return result;
    }
    if ( i[3] > dayWithinYear )
    {
      result += 4;
      return result;
    }
    if ( i[4] > dayWithinYear )
    {
      result += 5;
      return result;
    }
    result += 6;
    if ( result >= 12 )
      return result;
  }
  return result;
}
