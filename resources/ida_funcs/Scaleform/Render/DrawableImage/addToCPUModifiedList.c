void __thiscall Scaleform::Render::DrawableImage::addToCPUModifiedList(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Lock *p_QueueLock; // ebx
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommandQueue *v5; // edi
  Scaleform::Render::DrawableImage *v6; // ecx
  Scaleform::Render::DrawableImage **p_pObject; // edi
  Scaleform::Render::DrawableImage *v8; // ecx
  Scaleform::Ptr<Scaleform::Render::DrawableImage> *p_pCPUModifiedImageList; // edi

  p_QueueLock = &this->pQueue.pObject->QueueLock;
  EnterCriticalSection(&p_QueueLock->cs);
  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  if ( (this->DrawableImageState & 8) == 0 )
  {
    this->DrawableImageState |= 8u;
    v5 = this->pQueue.pObject;
    v6 = v5->pCPUModifiedImageList.pObject;
    p_pObject = &v5->pCPUModifiedImageList.pObject;
    if ( v6 )
      v6->AddRef(v6);
    v8 = this->pCPUModifiedNext.pObject;
    if ( v8 )
      v8->Release(v8);
    this->pCPUModifiedNext.pObject = *p_pObject;
    p_pCPUModifiedImageList = &this->pQueue.pObject->pCPUModifiedImageList;
    this->AddRef(this);
    if ( p_pCPUModifiedImageList->pObject )
      p_pCPUModifiedImageList->pObject->Release(p_pCPUModifiedImageList->pObject);
    p_pCPUModifiedImageList->pObject = this;
  }
  LeaveCriticalSection(&p_QueueLock->cs);
}
