char __cdecl Scaleform::GFx::ASUtils::AS3::Unescape(
        const char *psrc,
        const char *length,
        Scaleform::String *unescapedStr,
        bool useUtf8)
{
  Scaleform::GFx::ASUtils::AS3::Formatter f; // [esp+0h] [ebp-208h] BYREF

  f.Endp = &f.Buf[511];
  f.pBuf = (char *)&f;
  return Scaleform::GFx::ASUtils::AS3::Formatter::Unescape(&f, (int)psrc, length, unescapedStr, useUtf8);
}
