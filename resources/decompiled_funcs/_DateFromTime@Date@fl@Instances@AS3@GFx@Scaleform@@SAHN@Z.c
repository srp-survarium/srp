int __cdecl Scaleform::GFx::AS3::Instances::fl::Date::DateFromTime(double time)
{
  int v1; // esi
  int v2; // ebx
  int v3; // esi
  long double year; // [esp+14h] [ebp-8h]
  double timea; // [esp+20h] [ebp+4h]

  year = Scaleform::GFx::AS3::Instances::fl::Date::YearFromTime(time);
  timea = floor(time / 86400000.0);
  v1 = (int)(timea - Scaleform::GFx::AS3::Instances::fl::Date::DayFromYear(year));
  v2 = Scaleform::GFx::AS3::Instances::fl::Date::MonthFromYearDay((int)year, v1);
  v3 = v1 + 1;
  if ( v2 > 0 )
    v3 -= *((_DWORD *)&Scaleform::GFx::AS3::fl::DateTI.Implements
          + 12 * Scaleform::GFx::AS3::Instances::fl::Date::IsLeapYear((int)year)
          + v2);
  return v3;
}
