BOOL __stdcall Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(long double v)
{
  return *(_QWORD *)&v == 0x7FF0000000000000LL;
}
