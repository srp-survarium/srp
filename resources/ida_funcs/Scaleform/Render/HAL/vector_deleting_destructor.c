Scaleform::Render::HAL *__thiscall Scaleform::Render::HAL::`vector deleting destructor'(
        Scaleform::Render::HAL *this,
        char a2)
{
  Scaleform::Render::HAL::~HAL(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
