BOOL __stdcall Scaleform::GFx::NumberUtil::IsNaN(long double v)
{
  return (HIDWORD(v) & 0x7FF00000) == 0x7FF00000 && HIDWORD(v) & 0xFFFFF | LODWORD(v);
}
