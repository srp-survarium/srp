Scaleform::Render::Text::DocView::DocumentText *__thiscall Scaleform::Render::Text::DocView::DocumentText::`scalar deleting destructor'(
        Scaleform::Render::Text::DocView::DocumentText *this,
        char a2)
{
  Scaleform::Render::Text::StyledText::~StyledText(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
