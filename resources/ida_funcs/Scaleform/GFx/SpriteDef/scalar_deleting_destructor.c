Scaleform::GFx::SpriteDef *__thiscall Scaleform::GFx::SpriteDef::`scalar deleting destructor'(
        Scaleform::GFx::SpriteDef *this,
        char a2)
{
  Scaleform::GFx::SpriteDef::~SpriteDef(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
