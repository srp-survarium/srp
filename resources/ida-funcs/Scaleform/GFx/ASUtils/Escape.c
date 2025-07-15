void __cdecl Scaleform::GFx::ASUtils::Escape(const char *psrc, unsigned int length, Scaleform::String *pescapedStr)
{
  Scaleform::GFx::ASUtils::EscapeWithMask(psrc, length, pescapedStr, mask);
}
