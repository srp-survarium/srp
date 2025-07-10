Scaleform::Render::Text::Paragraph *__thiscall Scaleform::Render::Text::StyledText::CopyStyledText(
        Scaleform::Render::Text::StyledText *this,
        unsigned int startPos,
        Scaleform::Render::Text::Paragraph *endPos)
{
  Scaleform::Render::Text::Allocator *Allocator; // esi
  Scaleform::Render::Text::StyledText *v5; // eax
  Scaleform::Render::Text::Paragraph *v6; // eax
  Scaleform::Render::Text::Paragraph *v7; // esi

  Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this);
  v5 = (Scaleform::Render::Text::StyledText *)Allocator->pHeap->Alloc(Allocator->pHeap, 36u, 0);
  if ( v5 )
  {
    Scaleform::Render::Text::StyledText::StyledText(v5, Allocator);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  Scaleform::Render::Text::StyledText::CopyStyledText(this, v7, startPos, endPos);
  return v7;
}
