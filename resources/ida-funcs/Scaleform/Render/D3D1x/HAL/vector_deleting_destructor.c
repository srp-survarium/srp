Scaleform::Render::D3D1x::HAL *__thiscall Scaleform::Render::D3D1x::HAL::`vector deleting destructor'(
        Scaleform::Render::D3D1x::HAL *this,
        char a2)
{
  Scaleform::Render::D3D1x::HAL::~HAL(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
