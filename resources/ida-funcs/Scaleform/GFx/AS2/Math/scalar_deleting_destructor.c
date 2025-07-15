Scaleform::GFx::AS2::GASIme *__thiscall Scaleform::GFx::AS2::Math::`scalar deleting destructor'(
        Scaleform::GFx::AS2::GASIme *this,
        char a2)
{
  Scaleform::GFx::AS2::Object::~Object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
