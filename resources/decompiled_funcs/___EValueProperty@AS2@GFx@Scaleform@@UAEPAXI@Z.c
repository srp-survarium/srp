Scaleform::GFx::AS2::ValueProperty *__thiscall Scaleform::GFx::AS2::ValueProperty::`vector deleting destructor'(
        Scaleform::GFx::AS2::ValueProperty *this,
        char a2)
{
  Scaleform::GFx::AS2::ValueProperty::~ValueProperty(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
