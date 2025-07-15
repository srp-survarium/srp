Scaleform::GFx::AS2::ArrayObject *__thiscall Scaleform::GFx::AS2::ArrayObject::`vector deleting destructor'(
        Scaleform::GFx::AS2::ArrayObject *this,
        char a2)
{
  Scaleform::GFx::AS2::ArrayObject::~ArrayObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


void *__thiscall Scaleform::GFx::AS2::ArrayObject::`vector deleting destructor'(char *this, unsigned int a2)
{
  return Scaleform::GFx::AS2::ArrayObject::`vector deleting destructor'(
           (Scaleform::GFx::AS2::ArrayObject *)(this - 16),
           a2);
}
