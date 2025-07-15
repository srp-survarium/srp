BOOL __stdcall Scaleform::GFx::NumberUtil::IsNaNOrInfinity(long double v)
{
  return (HIDWORD(v) & 0x7FF00000) == 2146435072;
}
