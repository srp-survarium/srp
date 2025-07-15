void __cdecl Scaleform::GFx::ASUtils::AS3::EncodeURIComponent(
        char *psrc,
        int length,
        Scaleform::String *escapedStr,
        bool useUtf8)
{
  Scaleform::GFx::ASUtils::AS3::Formatter v4; // [esp+0h] [ebp-208h] BYREF

  v4.Endp = &v4.Buf[511];
  v4.pBuf = (char *)&v4;
  Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMask(
    &v4,
    psrc,
    length,
    escapedStr,
    unescaped_mask_URIComponent,
    useUtf8);
}
