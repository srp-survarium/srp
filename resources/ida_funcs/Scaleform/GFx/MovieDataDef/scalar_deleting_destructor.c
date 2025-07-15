Scaleform::GFx::MovieDataDef *__thiscall Scaleform::GFx::MovieDataDef::`scalar deleting destructor'(
        Scaleform::GFx::MovieDataDef *this,
        char a2)
{
  Scaleform::GFx::MovieDataDef::~MovieDataDef(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
