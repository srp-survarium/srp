Scaleform::GFx::DrawingContext *__thiscall Scaleform::GFx::DrawingContext::`vector deleting destructor'(
        Scaleform::GFx::DrawingContext *this,
        char a2)
{
  Scaleform::GFx::DrawingContext::~DrawingContext(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
