Scaleform::Render::Text::HTMLImageTagDesc *__thiscall Scaleform::Render::Text::HTMLImageTagDesc::`scalar deleting destructor'(
        Scaleform::Render::Text::HTMLImageTagDesc *this,
        char a2)
{
  Scaleform::Render::Text::HTMLImageTagDesc::~HTMLImageTagDesc(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
