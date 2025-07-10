Scaleform::Render::ComplexPrimitiveBundle *__thiscall Scaleform::Render::ComplexPrimitiveBundle::`vector deleting destructor'(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        char a2)
{
  Scaleform::Render::ComplexPrimitiveBundle::~ComplexPrimitiveBundle(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
