Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::InteractiveObject::`vector deleting destructor'(
        Scaleform::GFx::InteractiveObject *this,
        char a2)
{
  Scaleform::GFx::InteractiveObject::~InteractiveObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
