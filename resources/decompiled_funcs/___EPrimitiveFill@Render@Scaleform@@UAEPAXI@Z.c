Scaleform::Render::PrimitiveFill *__thiscall Scaleform::Render::PrimitiveFill::`vector deleting destructor'(
        Scaleform::Render::PrimitiveFill *this,
        char a2)
{
  Scaleform::Render::PrimitiveFill::~PrimitiveFill(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
