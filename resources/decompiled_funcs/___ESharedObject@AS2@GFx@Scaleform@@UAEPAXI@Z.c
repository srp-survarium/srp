Scaleform::GFx::AS2::SharedObject *__thiscall Scaleform::GFx::AS2::SharedObject::`vector deleting destructor'(
        Scaleform::GFx::AS2::SharedObject *this,
        char a2)
{
  Scaleform::GFx::AS2::SharedObject::~SharedObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
