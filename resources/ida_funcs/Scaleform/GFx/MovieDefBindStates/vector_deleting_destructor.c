Scaleform::GFx::MovieDefBindStates *__thiscall Scaleform::GFx::MovieDefBindStates::`vector deleting destructor'(
        Scaleform::GFx::MovieDefBindStates *this,
        char a2)
{
  Scaleform::GFx::MovieDefBindStates::~MovieDefBindStates(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
