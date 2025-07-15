Scaleform::GFx::AS3::Object *__thiscall Scaleform::GFx::AS3::Object::`vector deleting destructor'(
        Scaleform::GFx::AS3::Object *this,
        char a2)
{
  Scaleform::GFx::AS3::Object::~Object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
