void __thiscall Scaleform::GFx::AS2::IMEManager::IMEManager(Scaleform::GFx::AS2::IMEManager *this)
{
  this->__vftable = (Scaleform::GFx::AS2::IMEManager_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AS2::IMEManager_vtbl *)&Scaleform::GFx::ASIMEManager::`vftable';
  Scaleform::String::String(&this->CandidateSwfPath);
  Scaleform::String::String(&this->CandidateSwfErrorMsg);
  this->pLangContext.pObjectInterface = 0;
  this->pLangContext.Type = VT_Undefined;
  this->pStatusContext.pObjectInterface = 0;
  this->pStatusContext.Type = VT_Undefined;
  this->CustomFuncCandList.pObject = 0;
  this->CustomFuncLanguageBar.pObject = 0;
  this->pMovie = 0;
  this->pTextField = 0;
  this->pLangContext2 = 0;
  this->pStatusContext2 = 0;
  this->__vftable = (Scaleform::GFx::AS2::IMEManager_vtbl *)&Scaleform::GFx::AS2::IMEManager::`vftable';
  Scaleform::String::String(&this->CandListPath);
  this->pTextField = 0;
  this->pMovie = 0;
  this->UnsupportedIMEWindowsFlag = 3;
}
