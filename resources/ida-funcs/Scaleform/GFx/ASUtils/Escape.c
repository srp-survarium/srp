void __cdecl Scaleform::GFx::ASUtils::Escape(char *psrc, unsigned int length, Scaleform::String *pescapedStr)
{
  Scaleform::GFx::ASUtils::EscapeWithMask(psrc, length, pescapedStr, mask);
}
