double __cdecl Scaleform::GFx::AS3::Instances::fl::Date::DayFromYear(long double year)
{
  long double v2; // [esp+8h] [ebp-8h]
  long double v3; // [esp+8h] [ebp-8h]

  v2 = floor((year - 1969.0) * 0.25) + (year - 1970.0) * 365.0;
  v3 = v2 - floor((year - 1901.0) / 100.0);
  return floor((year - 1601.0) / 400.0) + v3;
}
