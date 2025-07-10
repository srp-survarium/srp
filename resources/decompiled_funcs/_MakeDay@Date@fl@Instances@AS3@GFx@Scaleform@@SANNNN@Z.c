double __cdecl Scaleform::GFx::AS3::Instances::fl::Date::MakeDay(long double year, long double month, long double date)
{
  long double v5; // st7
  double v6; // st7
  double v7; // st7
  double yeara; // [esp+10h] [ebp+4h]
  long double daysinMontha; // [esp+18h] [ebp+Ch]
  long double daysinMonthb; // [esp+18h] [ebp+Ch]
  double daysinMonth; // [esp+18h] [ebp+Ch]
  double datea; // [esp+20h] [ebp+14h]

  daysinMontha = year + month + date;
  if ( (HIDWORD(daysinMontha) & 0x7FF00000) == 0x7FF00000 )
    return Scaleform::GFx::NumberUtil::NaN();
  daysinMonthb = (double)(int)month;
  datea = (double)(int)date;
  yeara = floor(daysinMonthb / 12.0) + (double)(int)year;
  v5 = fmod(daysinMonthb, 12.0);
  daysinMonth = v5;
  if ( v5 < 0.0 )
    daysinMonth = v5 + 12.0;
  v6 = Scaleform::GFx::AS3::Instances::fl::Date::DayFromYear(yeara);
  v7 = floor(v6);
  if ( (int)daysinMonth )
    return v7
         + (double)*((int *)&Scaleform::GFx::AS3::fl::DateTI.Implements
                   + 12 * Scaleform::GFx::AS3::Instances::fl::Date::IsLeapYear((int)yeara)
                   + (int)daysinMonth)
         + datea
         - 1.0;
  else
    return v7 + (double)0 + datea - 1.0;
}
