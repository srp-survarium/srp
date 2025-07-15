void __thiscall Scaleform::GFx::DrawTextManagerImpl::~DrawTextManagerImpl(Scaleform::GFx::DrawTextManagerImpl *this)
{
  Scaleform::Render::ContextImpl::RTHandle::HandleData *pObject; // ecx
  Scaleform::Render::TreeRoot *v3; // ecx
  bool v4; // zf
  Scaleform::RefCountVImpl *v5; // ecx
  volatile LONG *v6; // edi
  Scaleform::RefCountVImpl *v7; // ecx
  Scaleform::GFx::FontManagerStates *v8; // ecx
  Scaleform::RefCountVImpl *v9; // ecx
  Scaleform::Render::Text::Allocator *v10; // ecx
  Scaleform::GFx::MovieDef *v11; // ecx
  Scaleform::RefCountVImpl *v12; // ecx
  Scaleform::Render::TreeRoot *v13; // ecx

  pObject = this->DispHandle.pData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  this->DispHandle.pData.pObject = 0;
  v3 = this->pRootNode.pObject;
  if ( this->pRootNode.pObject )
  {
    v4 = v3->RefCount-- == 1;
    if ( v4 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v3);
  }
  this->pRootNode.pObject = 0;
  Scaleform::Render::ContextImpl::Context::Shutdown(&this->RenderContext, 1);
  Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&this->DispHandle);
  Scaleform::Render::ContextImpl::Context::~Context(&this->RenderContext);
  v5 = (Scaleform::RefCountVImpl *)this->pLoaderImpl.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = (volatile LONG *)(this->DefaultTextParams.FontName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v6 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
  v7 = (Scaleform::RefCountVImpl *)this->pWeakLib.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v8 = this->pFontStates.pObject;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
  v9 = (Scaleform::RefCountVImpl *)this->pFontManager.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v10 = this->pTextAllocator.pObject;
  if ( v10 )
    Scaleform::RefCountNTSImpl::Release(v10);
  v11 = this->pMovieDef.pObject;
  if ( v11 )
    Scaleform::GFx::Resource::Release(v11);
  v12 = (Scaleform::RefCountVImpl *)this->pStateBag.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  v13 = this->pRootNode.pObject;
  if ( this->pRootNode.pObject )
  {
    v4 = v13->RefCount-- == 1;
    if ( v4 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v13);
  }
}
