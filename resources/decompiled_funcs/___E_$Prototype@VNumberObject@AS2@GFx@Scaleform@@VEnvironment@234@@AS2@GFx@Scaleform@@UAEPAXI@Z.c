Scaleform::GFx::AS2::NumberProto *__thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment>::`vector deleting destructor'(
        Scaleform::GFx::AS2::NumberProto *this,
        char a2)
{
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment>::~Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment>(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
