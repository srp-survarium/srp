void __thiscall Scaleform::GFx::ASIMEManager::~ASIMEManager(Scaleform::GFx::ASIMEManager *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx
  Scaleform::GFx::Value *p_pStatusContext; // esi
  Scaleform::GFx::Value *p_pLangContext; // esi
  volatile LONG *v6; // esi
  volatile LONG *v7; // esi

  this->__vftable = (Scaleform::GFx::ASIMEManager_vtbl *)&Scaleform::GFx::ASIMEManager::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->CustomFuncLanguageBar.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v3 = (Scaleform::RefCountVImpl *)this->CustomFuncCandList.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  p_pStatusContext = &this->pStatusContext;
  if ( (this->pStatusContext.Type & 0x40) != 0 )
  {
    p_pStatusContext->pObjectInterface->ObjectRelease(
      p_pStatusContext->pObjectInterface,
      &this->pStatusContext,
      this->pStatusContext.mValue.pStringManaged);
    p_pStatusContext->pObjectInterface = 0;
  }
  this->pStatusContext.Type = VT_Undefined;
  p_pLangContext = &this->pLangContext;
  if ( (this->pLangContext.Type & 0x40) != 0 )
  {
    p_pLangContext->pObjectInterface->ObjectRelease(
      p_pLangContext->pObjectInterface,
      &this->pLangContext,
      this->pLangContext.mValue.pStringManaged);
    p_pLangContext->pObjectInterface = 0;
  }
  this->pLangContext.Type = VT_Undefined;
  v6 = (volatile LONG *)(this->CandidateSwfErrorMsg.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v6 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
  v7 = (volatile LONG *)(this->CandidateSwfPath.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v7 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v7);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
