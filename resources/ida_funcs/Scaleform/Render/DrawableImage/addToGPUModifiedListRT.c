void __thiscall Scaleform::Render::DrawableImage::addToGPUModifiedListRT(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Lock *p_QueueLock; // ebx
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommandQueue *v5; // edi
  Scaleform::Render::DrawableImage *v6; // ecx
  Scaleform::Render::DrawableImage **p_pObject; // edi
  Scaleform::Render::DrawableImage *v8; // ecx
  Scaleform::Ptr<Scaleform::Render::DrawableImage> *p_pGPUModifiedImageList; // edi

  p_QueueLock = &this->pQueue.pObject->QueueLock;
  EnterCriticalSection(&p_QueueLock->cs);
  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  if ( (this->DrawableImageState & 0x10) == 0 )
  {
    this->DrawableImageState |= 0x10u;
    v5 = this->pQueue.pObject;
    v6 = v5->pGPUModifiedImageList.pObject;
    p_pObject = &v5->pGPUModifiedImageList.pObject;
    if ( v6 )
      v6->AddRef(v6);
    v8 = this->pGPUModifiedNext.pObject;
    if ( v8 )
      v8->Release(v8);
    this->pGPUModifiedNext.pObject = *p_pObject;
    p_pGPUModifiedImageList = &this->pQueue.pObject->pGPUModifiedImageList;
    this->AddRef(this);
    if ( p_pGPUModifiedImageList->pObject )
      p_pGPUModifiedImageList->pObject->Release(p_pGPUModifiedImageList->pObject);
    p_pGPUModifiedImageList->pObject = this;
  }
  LeaveCriticalSection(&p_QueueLock->cs);
}
