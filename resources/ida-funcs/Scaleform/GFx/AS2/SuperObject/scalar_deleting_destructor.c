Scaleform::GFx::AS2::SuperObject *__thiscall Scaleform::GFx::AS2::SuperObject::`scalar deleting destructor'(
        Scaleform::GFx::AS2::SuperObject *this,
        char a2)
{
  Scaleform::GFx::AS2::SuperObject::~SuperObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
