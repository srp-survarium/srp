unsigned int __cdecl Scaleform::Render::Text::LineBuffer::CalcLineSize(
        unsigned int glyphCount,
        unsigned int formatDataElementsCount,
        Scaleform::Render::Text::LineBuffer::LineType lineType)
{
  return (((lineType != Line8 ? 38 : 26) + 8 * glyphCount + 7) & 0xFFFFFFFC) + 4 * formatDataElementsCount;
}
