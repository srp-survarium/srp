BOOL __stdcall Scaleform::GFx::NumberUtil::IsNEGATIVE_INFINITY(long double v)
{
  return *(_QWORD *)&v == 0xFFF0000000000000uLL;
}
