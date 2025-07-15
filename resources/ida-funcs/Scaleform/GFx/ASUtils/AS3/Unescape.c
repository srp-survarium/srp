char __cdecl Scaleform::GFx::ASUtils::AS3::Unescape(
        char *psrc,
        char *length,
        Scaleform::String *unescapedStr,
        bool useUtf8)
{
  Scaleform::GFx::ASUtils::AS3::Formatter v5; // [esp+0h] [ebp-208h] BYREF

  v5.Endp = &v5.Buf[511];
  v5.pBuf = (char *)&v5;
  return Scaleform::GFx::ASUtils::AS3::Formatter::Unescape(&v5, psrc, length, unescapedStr, useUtf8);
}
