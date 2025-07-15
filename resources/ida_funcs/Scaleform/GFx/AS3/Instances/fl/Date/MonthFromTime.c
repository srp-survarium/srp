int __cdecl Scaleform::GFx::AS3::Instances::fl::Date::MonthFromTime(double time)
{
  int v1; // eax
  double year; // [esp+8h] [ebp-8h]
  double timea; // [esp+14h] [ebp+4h]

  year = Scaleform::GFx::AS3::Instances::fl::Date::YearFromTime(time);
  timea = floor(time / 86400000.0);
  v1 = (int)(timea - Scaleform::GFx::AS3::Instances::fl::Date::DayFromYear(year));
  return Scaleform::GFx::AS3::Instances::fl::Date::MonthFromYearDay((int)year, v1);
}
