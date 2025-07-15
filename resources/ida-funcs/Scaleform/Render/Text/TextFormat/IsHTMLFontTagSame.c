BOOL __thiscall Scaleform::Render::Text::TextFormat::IsHTMLFontTagSame(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::Render::Text::TextFormat *fmt)
{
  double v4; // st7
  BOOL result; // eax
  float v6; // [esp+Ch] [ebp+4h]
  float v7; // [esp+Ch] [ebp+4h]
  float LetterSpacing; // [esp+Ch] [ebp+4h]

  result = 0;
  if ( ((this->PresentMask & 4) != 0
     && (fmt->PresentMask & 4) != 0
     && !Scaleform::String::CompareNoCase(
           (char *)((this->FontList.HeapTypeBits & 0xFFFFFFFC) + 8),
           (char *)((fmt->FontList.HeapTypeBits & 0xFFFFFFFC) + 8))
     || (this->PresentMask & 0x800) != 0
     && (fmt->PresentMask & 0x800) != 0
     && this->pFontHandle.pObject == fmt->pFontHandle.pObject)
    && ((this->ColorV ^ fmt->ColorV) & 0xFFFFFF) == 0
    && HIBYTE(this->ColorV) == HIBYTE(fmt->ColorV) )
  {
    v6 = (double)this->FontSize * 0.05000000074505806;
    v4 = v6;
    v7 = 0.05000000074505806 * (double)fmt->FontSize;
    if ( v7 == v4 && ((this->FormatFlags ^ fmt->FormatFlags) & 8) == 0 )
    {
      LetterSpacing = Scaleform::Render::Text::TextFormat::GetLetterSpacing(this);
      if ( LetterSpacing == Scaleform::Render::Text::TextFormat::GetLetterSpacing(fmt) )
        return 1;
    }
  }
  return result;
}
