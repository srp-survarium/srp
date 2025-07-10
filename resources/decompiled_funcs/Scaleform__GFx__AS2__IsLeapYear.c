BOOL __fastcall Scaleform::GFx::AS2::IsLeapYear(int y)
{
  return !(y % 4) && (y % 100 || !(y % 400));
}
