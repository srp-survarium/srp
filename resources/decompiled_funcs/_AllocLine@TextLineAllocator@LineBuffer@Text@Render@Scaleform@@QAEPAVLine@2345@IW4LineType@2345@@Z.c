Scaleform::Render::Text::LineBuffer::Line *__thiscall Scaleform::Render::Text::LineBuffer::TextLineAllocator::AllocLine(
        Scaleform::Render::Text::LineBuffer::TextLineAllocator *this,
        unsigned int size,
        Scaleform::Render::Text::LineBuffer::LineType lineType)
{
  Scaleform::Render::Text::LineBuffer::Line *result; // eax
  unsigned int v4; // ecx

  result = (Scaleform::Render::Text::LineBuffer::Line *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                          Scaleform::Memory::pGlobalHeap,
                                                          this,
                                                          size,
                                                          0);
  result->MemSize ^= (size ^ result->MemSize) & 0xFFFFFFF;
  v4 = result->MemSize & 0xFFFFFFF;
  if ( lineType )
  {
    result->MemSize = v4 | 0x40000000;
    result->Data32.GlyphsCount = 0;
    result->Data32.Height = 0;
    result->Data32.Width = 0;
    result->Data32.TextLength = 0;
    result->Data32.BaseLineOffset = 0;
    result->Data32.Leading = 0;
  }
  else
  {
    result->MemSize = v4 | 0xC0000000;
    result->Data8.GlyphsCount = 0;
    result->Data8.Leading = 0;
    result->Data8.BaseLineOffset = 0;
    result->Data8.Height = 0;
    result->Data8.Width = 0;
  }
  result->Data32.OffsetX = 0;
  result->Data32.OffsetY = 0;
  result->Data32.TextPos = 0;
  return result;
}
