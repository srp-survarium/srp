void __thiscall Scaleform::GFx::LoadStates::LoadStates(Scaleform::GFx::LoadStates *this)
{
  this->__vftable = (Scaleform::GFx::LoadStates_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::LoadStates_vtbl *)&Scaleform::GFx::LoadStates::`vftable';
  this->pBindStates.pObject = 0;
  this->pLog.pObject = 0;
  this->pParseControl.pObject = 0;
  this->pProgressHandler.pObject = 0;
  this->pTaskManager.pObject = 0;
  this->pImageFileHandlerRegistry.pObject = 0;
  this->pZlibSupport.pObject = 0;
  this->pVideoPlayerState.pObject = 0;
  this->pAudioState.pObject = 0;
  this->pAS2Support.pObject = 0;
  this->pAS3Support.pObject = 0;
  this->pWeakResourceLib.pObject = 0;
  this->pLoaderImpl.pObject = 0;
  Scaleform::String::String(&this->RelativePath);
  this->ThreadedLoading = 0;
  this->SubstituteFontMovieDefs.Data.Data = 0;
  this->SubstituteFontMovieDefs.Data.Size = 0;
  this->SubstituteFontMovieDefs.Data.Policy.Capacity = 0;
}
