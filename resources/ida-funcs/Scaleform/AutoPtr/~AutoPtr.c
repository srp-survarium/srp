void __thiscall Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable>::~AutoPtr<Scaleform::GFx::AS3::VTable>(
        Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable> *this)
{
  Scaleform::GFx::AS3::VTable *pObject; // esi

  pObject = this->pObject;
  if ( this->pObject )
  {
    if ( this->Owner )
    {
      this->Owner = 0;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
        pObject->VTMethods.Data.Data,
        pObject->VTMethods.Data.Size);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject->VTMethods.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
    this->pObject = 0;
  }
  this->Owner = 0;
}
