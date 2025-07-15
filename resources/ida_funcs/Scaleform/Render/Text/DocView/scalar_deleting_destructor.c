Scaleform::Render::Text::DocView *__thiscall Scaleform::Render::Text::DocView::`scalar deleting destructor'(
        Scaleform::Render::Text::DocView *this,
        char a2)
{
  Scaleform::Render::Text::DocView::~DocView(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
