Scaleform::GFx::AS3::IMEManager *__thiscall Scaleform::GFx::AS3::IMEManager::`vector deleting destructor'(
        Scaleform::GFx::AS3::IMEManager *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::Value *p_CandListVal; // esi

  this->__vftable = (Scaleform::GFx::AS3::IMEManager_vtbl *)&Scaleform::GFx::AS3::IMEManager::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pCustomFunc.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  p_CandListVal = &this->CandListVal;
  if ( (this->CandListVal.Type & 0x40) != 0 )
  {
    p_CandListVal->pObjectInterface->ObjectRelease(
      p_CandListVal->pObjectInterface,
      &this->CandListVal,
      this->CandListVal.mValue.pStringManaged);
    p_CandListVal->pObjectInterface = 0;
  }
  this->CandListVal.Type = VT_Undefined;
  Scaleform::GFx::ASIMEManager::~ASIMEManager(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
