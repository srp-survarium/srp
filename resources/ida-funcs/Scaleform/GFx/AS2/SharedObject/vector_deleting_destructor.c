Scaleform::GFx::AS2::SharedObject *__thiscall Scaleform::GFx::AS2::SharedObject::`vector deleting destructor'(
        Scaleform::GFx::AS2::SharedObject *this,
        char a2)
{
  Scaleform::GFx::AS2::SharedObject::~SharedObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


Scaleform::GFx::AS2::SharedObject *__thiscall Scaleform::GFx::AS2::SharedObject::`vector deleting destructor'(
        char *this,
        char a2)
{
  return Scaleform::GFx::AS2::SharedObject::`vector deleting destructor'(
           (Scaleform::GFx::AS2::SharedObject *)(this - 16),
           a2);
}
