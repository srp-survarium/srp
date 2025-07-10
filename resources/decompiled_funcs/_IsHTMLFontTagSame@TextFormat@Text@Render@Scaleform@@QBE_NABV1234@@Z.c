BOOL __thiscall Scaleform::Render::Text::TextFormat::IsHTMLFontTagSame(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::Render::Text::TextFormat *fmt)
{
  double v4; // st7
  BOOL result; // eax
  float fmta; // [esp+Ch] [ebp+4h]
  float fmtb; // [esp+Ch] [ebp+4h]
  float fmtc; // [esp+Ch] [ebp+4h]

  result = 0;
  if ( ((this->PresentMask & 4) != 0
     && (fmt->PresentMask & 4) != 0
     && !Scaleform::String::CompareNoCase(
           (const char *)((this->FontList.HeapTypeBits & 0xFFFFFFFC) + 8),
           (const char *)((fmt->FontList.HeapTypeBits & 0xFFFFFFFC) + 8))
     || (this->PresentMask & 0x800) != 0
     && (fmt->PresentMask & 0x800) != 0
     && this->pFontHandle.pObject == fmt->pFontHandle.pObject)
    && ((unsigned int)&vostok::memory::s_CRT_arena[5574199] & (this->ColorV ^ fmt->ColorV)) == 0
    && HIBYTE(this->ColorV) == HIBYTE(fmt->ColorV) )
  {
    fmta = (double)this->FontSize * 0.05000000074505806;
    v4 = fmta;
    fmtb = 0.05000000074505806 * (double)fmt->FontSize;
    if ( fmtb == v4 && ((this->FormatFlags ^ fmt->FormatFlags) & 8) == 0 )
    {
      fmtc = Scaleform::Render::Text::TextFormat::GetLetterSpacing(this);
      if ( fmtc == Scaleform::Render::Text::TextFormat::GetLetterSpacing(fmt) )
        return 1;
    }
  }
  return result;
}
