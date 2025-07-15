BOOL __cdecl Scaleform::Render::Text::LineBuffer::LineYOffsetComparator::Less(
        const Scaleform::Render::Text::LineBuffer::Line *p1,
        float yoffset)
{
  return Scaleform::Render::Text::LineBuffer::LineYOffsetComparator::Compare(p1, yoffset) < 0;
}
