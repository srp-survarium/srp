Scaleform::GFx::StaticTextCharacter *__thiscall Scaleform::GFx::StaticTextCharacter::`scalar deleting destructor'(
        Scaleform::GFx::StaticTextCharacter *this,
        char a2)
{
  Scaleform::GFx::StaticTextCharacter::~StaticTextCharacter(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
