Scaleform::GFx::ConstShapeWithStyles *__thiscall Scaleform::GFx::ConstShapeWithStyles::`vector deleting destructor'(
        Scaleform::GFx::ConstShapeWithStyles *this,
        char a2)
{
  Scaleform::GFx::ConstShapeWithStyles::~ConstShapeWithStyles(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
