Scaleform::GFx::AS2::AsFunctionObject *__thiscall Scaleform::GFx::AS2::AsFunctionObject::`scalar deleting destructor'(
        Scaleform::GFx::AS2::AsFunctionObject *this,
        char a2)
{
  Scaleform::GFx::AS2::AsFunctionObject::~AsFunctionObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
