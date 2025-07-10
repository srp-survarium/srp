void __cdecl Scaleform::GFx::ASUtils::AS3::EncodeURI(
        const char *psrc,
        unsigned int length,
        Scaleform::String *escapedStr,
        bool useUtf8)
{
  Scaleform::GFx::ASUtils::AS3::Formatter f; // [esp+0h] [ebp-208h] BYREF

  f.Endp = &f.Buf[511];
  f.pBuf = (char *)&f;
  Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMask(&f, psrc, length, escapedStr, unescaped_mask_URI, useUtf8);
}
