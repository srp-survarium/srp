BOOL __cdecl Scaleform::GFx::AS3::Instances::fl::Date::IsLeapYear(int y)
{
  return !(y % 4) && (y % 100 || !(y % 400));
}
