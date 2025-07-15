Scaleform::Render::Text::LineBuffer::Line *__thiscall Scaleform::Render::Text::LineBuffer::InsertNewLine(
        Scaleform::Render::Text::LineBuffer *this,
        unsigned int lineIdx,
        unsigned int glyphCount,
        unsigned int formatDataElementsCount,
        Scaleform::Render::Text::LineBuffer::Line *lineType)
{
  Scaleform::Render::Text::LineBuffer::Line *result; // eax
  Scaleform::Render::Text::LineBuffer::Line *v7; // esi

  result = Scaleform::Render::Text::LineBuffer::TextLineAllocator::AllocLine(
             &this->LineAllocator,
             (((lineType != 0 ? 38 : 26) + 8 * glyphCount + 7) & 0xFFFFFFFC) + 4 * formatDataElementsCount,
             (Scaleform::Render::Text::LineBuffer::LineType)lineType);
  v7 = result;
  lineType = result;
  if ( result )
  {
    if ( (result->MemSize & 0x80000000) == 0 )
      result->Data32.GlyphsCount = glyphCount;
    else
      result->Data8.GlyphsCount = glyphCount;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::BundleEntry *,Scaleform::AllocatorLH<Scaleform::Render::BundleEntry *,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      &this->Lines,
      lineIdx,
      &lineType);
    return v7;
  }
  return result;
}
