BOOL __cdecl Scaleform::Render::Text::StyledText::ParagraphComparator::Less(
        const Scaleform::Render::Text::Paragraph *pp1,
        unsigned int index)
{
  unsigned int StartIndex; // eax

  StartIndex = pp1->StartIndex;
  return (index < StartIndex || index >= StartIndex + pp1->Text.Size) && (int)(StartIndex - index) < 0;
}
