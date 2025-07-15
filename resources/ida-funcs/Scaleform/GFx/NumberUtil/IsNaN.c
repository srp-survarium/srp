BOOL __stdcall Scaleform::GFx::NumberUtil::IsNaN(long double v)
{
  return (HIDWORD(v) & 0x7FF00000) == 0x7FF00000 && (unsigned int)&loc_FFFFF & HIDWORD(v) | LODWORD(v);
}
