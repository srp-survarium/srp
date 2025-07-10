BOOL __thiscall Scaleform::Render::Text::TextFormat::IsFontSame(
        Scaleform::Render::Text::TextFormat *this,
        const Scaleform::Render::Text::TextFormat *fmt)
{
  unsigned __int8 FormatFlags; // cl
  BOOL result; // eax

  result = 0;
  if ( (this->PresentMask & 4) != 0
    && (fmt->PresentMask & 4) != 0
    && !Scaleform::String::CompareNoCase(
          (const char *)((this->FontList.HeapTypeBits & 0xFFFFFFFC) + 8),
          (const char *)((fmt->FontList.HeapTypeBits & 0xFFFFFFFC) + 8))
    || (this->PresentMask & 0x800) != 0
    && (fmt->PresentMask & 0x800) != 0
    && this->pFontHandle.pObject == fmt->pFontHandle.pObject )
  {
    FormatFlags = fmt->FormatFlags;
    if ( ((FormatFlags ^ this->FormatFlags) & 1) == 0 && ((FormatFlags ^ this->FormatFlags) & 2) == 0 )
      return 1;
  }
  return result;
}
