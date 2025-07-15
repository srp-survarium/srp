Scaleform::GFx::LoadStates *__thiscall Scaleform::GFx::LoadStates::`vector deleting destructor'(
        Scaleform::GFx::LoadStates *this,
        char a2)
{
  Scaleform::GFx::LoadStates::~LoadStates(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
