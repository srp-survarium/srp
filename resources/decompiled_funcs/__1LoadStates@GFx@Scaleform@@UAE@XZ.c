void __thiscall Scaleform::GFx::LoadStates::~LoadStates(Scaleform::GFx::LoadStates *this)
{
  volatile LONG *v2; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::ResourceWeakLib *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx
  Scaleform::RefCountVImpl *v7; // ecx
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::RefCountVImpl *v9; // ecx
  Scaleform::RefCountVImpl *v10; // ecx
  Scaleform::RefCountVImpl *v11; // ecx
  Scaleform::RefCountVImpl *v12; // ecx
  Scaleform::RefCountVImpl *v13; // ecx
  Scaleform::RefCountVImpl *v14; // ecx
  Scaleform::RefCountVImpl *v15; // ecx

  this->__vftable = (Scaleform::GFx::LoadStates_vtbl *)&Scaleform::GFx::LoadStates::`vftable';
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy>(&this->SubstituteFontMovieDefs.Data);
  v2 = (volatile LONG *)(this->RelativePath.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  pObject = (Scaleform::RefCountVImpl *)this->pLoaderImpl.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = this->pWeakResourceLib.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
  v5 = (Scaleform::RefCountVImpl *)this->pAS3Support.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = (Scaleform::RefCountVImpl *)this->pAS2Support.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v7 = (Scaleform::RefCountVImpl *)this->pAudioState.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v8 = (Scaleform::RefCountVImpl *)this->pVideoPlayerState.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  v9 = (Scaleform::RefCountVImpl *)this->pZlibSupport.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v10 = (Scaleform::RefCountVImpl *)this->pImageFileHandlerRegistry.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  v11 = (Scaleform::RefCountVImpl *)this->pTaskManager.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  v12 = (Scaleform::RefCountVImpl *)this->pProgressHandler.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  v13 = (Scaleform::RefCountVImpl *)this->pParseControl.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  v14 = (Scaleform::RefCountVImpl *)this->pLog.pObject;
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  v15 = (Scaleform::RefCountVImpl *)this->pBindStates.pObject;
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
