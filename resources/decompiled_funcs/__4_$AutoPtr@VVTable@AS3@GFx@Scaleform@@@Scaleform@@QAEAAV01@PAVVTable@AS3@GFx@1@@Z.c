Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable> *__thiscall Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable>::operator=(
        Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable> *this,
        Scaleform::GFx::AS3::VTable *p)
{
  Scaleform::GFx::AS3::VTable *pObject; // esi

  pObject = this->pObject;
  if ( this->pObject != p )
  {
    if ( pObject && this->Owner )
    {
      this->Owner = 0;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
        pObject->VTMethods.Data.Data,
        pObject->VTMethods.Data.Size);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject->VTMethods.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
    this->pObject = p;
  }
  this->Owner = p != 0;
  return this;
}
