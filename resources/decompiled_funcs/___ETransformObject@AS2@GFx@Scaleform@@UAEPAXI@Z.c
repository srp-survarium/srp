Scaleform::GFx::AS2::TransformObject *__thiscall Scaleform::GFx::AS2::TransformObject::`vector deleting destructor'(
        Scaleform::GFx::AS2::TransformObject *this,
        char a2)
{
  Scaleform::GFx::AS2::TransformObject::~TransformObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
