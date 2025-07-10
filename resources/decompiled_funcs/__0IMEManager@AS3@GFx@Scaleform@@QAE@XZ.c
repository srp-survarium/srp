void __thiscall Scaleform::GFx::AS3::IMEManager::IMEManager(Scaleform::GFx::AS3::IMEManager *this)
{
  Scaleform::GFx::Value *p_CandListVal; // edi

  this->__vftable = (Scaleform::GFx::AS3::IMEManager_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AS3::IMEManager_vtbl *)&Scaleform::GFx::ASIMEManager::`vftable';
  Scaleform::String::String(&this->CandidateSwfPath);
  Scaleform::String::String(&this->CandidateSwfErrorMsg);
  this->pLangContext.pObjectInterface = 0;
  this->pLangContext.Type = VT_Undefined;
  this->pStatusContext.pObjectInterface = 0;
  this->pStatusContext.Type = VT_Undefined;
  this->CustomFuncCandList.pObject = 0;
  this->CustomFuncLanguageBar.pObject = 0;
  this->pLangContext2 = 0;
  this->pStatusContext2 = 0;
  this->__vftable = (Scaleform::GFx::AS3::IMEManager_vtbl *)&Scaleform::GFx::AS3::IMEManager::`vftable';
  this->CandListVal.pObjectInterface = 0;
  this->CandListVal.Type = VT_Undefined;
  p_CandListVal = &this->CandListVal;
  this->pCustomFunc.pObject = 0;
  this->UnsupportedIMEWindowsFlag = 3;
  this->pTextField = 0;
  this->pMovie = 0;
  this->CandidateListState = 0;
  if ( (this->CandListVal.Type & 0x40) != 0 )
  {
    p_CandListVal->pObjectInterface->ObjectRelease(
      p_CandListVal->pObjectInterface,
      &this->CandListVal,
      this->CandListVal.mValue.pStringManaged);
    p_CandListVal->pObjectInterface = 0;
  }
  this->CandListVal.Type = VT_Null;
}
