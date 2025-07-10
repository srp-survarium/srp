Scaleform::GFx::AS2::MouseCtorFunction *__thiscall Scaleform::GFx::AS2::MouseCtorFunction::`scalar deleting destructor'(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        char a2)
{
  Scaleform::GFx::AS2::MouseCtorFunction::~MouseCtorFunction(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
