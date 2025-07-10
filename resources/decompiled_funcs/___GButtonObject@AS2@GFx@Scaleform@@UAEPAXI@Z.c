Scaleform::GFx::AS2::ColorObject *__thiscall Scaleform::GFx::AS2::ButtonObject::`scalar deleting destructor'(
        Scaleform::GFx::AS2::ColorObject *this,
        char a2)
{
  Scaleform::WeakPtrProxy *pObject; // eax

  pObject = this->pCharacter.pProxy.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
  }
  Scaleform::GFx::AS2::Object::~Object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
