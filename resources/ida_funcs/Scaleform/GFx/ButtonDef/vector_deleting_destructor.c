Scaleform::GFx::ButtonDef *__thiscall Scaleform::GFx::ButtonDef::`vector deleting destructor'(
        Scaleform::GFx::ButtonDef *this,
        char a2)
{
  Scaleform::GFx::ButtonDef::~ButtonDef(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
