char __thiscall Scaleform::Render::DrawableImage::mergeQueueWith(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *other)
{
  Scaleform::Lock *p_QueueLock; // edi
  Scaleform::Render::DICommandQueue *pObject; // ebp
  Scaleform::Render::DrawableImage *v6; // edi
  Scaleform::Render::DrawableImage *v7; // ecx
  Scaleform::Render::DrawableImage *v8; // ecx
  Scaleform::Render::DrawableImage *i; // eax
  Scaleform::Render::DrawableImage *v10; // ecx
  Scaleform::Render::DrawableImage *v11; // ecx
  Scaleform::Render::DICommandQueue *v12; // ecx
  Scaleform::RefCountVImpl *v13; // ecx
  Scaleform::Render::DICommandQueue *v14; // eax
  Scaleform::Render::DrawableImage *pPrev; // ecx

  p_QueueLock = &this->pQueue.pObject->QueueLock;
  EnterCriticalSection(&p_QueueLock->cs);
  if ( other->GetImageType(other) == Type_DrawableImage && other->pQueue.pObject != this->pQueue.pObject )
  {
    if ( other->pContext.pObject != this->pContext.pObject )
    {
      LeaveCriticalSection(&p_QueueLock->cs);
      return 0;
    }
    LeaveCriticalSection(&p_QueueLock->cs);
    Scaleform::Render::DICommandQueue::ExecuteCommandsAndWait(other->pQueue.pObject);
    other->pPrev->pNext = other->pNext;
    other->pNext->pPrev = other->pPrev;
    if ( (other->DrawableImageState & 8) != 0 )
    {
      pObject = other->pQueue.pObject;
      v6 = pObject->pCPUModifiedImageList.pObject;
      if ( other == v6 )
      {
        v7 = other->pCPUModifiedNext.pObject;
        if ( v7 )
          v7->AddRef(v7);
        v8 = pObject->pCPUModifiedImageList.pObject;
        if ( v8 )
          v8->Release(v8);
        pObject->pCPUModifiedImageList.pObject = other->pCPUModifiedNext.pObject;
      }
      else
      {
        for ( i = v6->pCPUModifiedNext.pObject; other != i; i = i->pCPUModifiedNext.pObject )
          v6 = i;
        v10 = other->pCPUModifiedNext.pObject;
        if ( v10 )
          v10->AddRef(v10);
        v11 = v6->pCPUModifiedNext.pObject;
        if ( v11 )
          v11->Release(v11);
        v6->pCPUModifiedNext.pObject = other->pCPUModifiedNext.pObject;
      }
    }
    p_QueueLock = &this->pQueue.pObject->QueueLock;
    EnterCriticalSection(&p_QueueLock->cs);
    v12 = this->pQueue.pObject;
    if ( v12 )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v12);
    v13 = (Scaleform::RefCountVImpl *)other->pQueue.pObject;
    if ( v13 )
      Scaleform::RefCountImpl::Release(v13);
    other->pQueue.pObject = this->pQueue.pObject;
    v14 = this->pQueue.pObject;
    pPrev = v14->ImageList.Root.pPrev;
    v14 = (Scaleform::Render::DICommandQueue *)((char *)v14 + 44);
    other->pPrev = pPrev;
    other->pNext = (Scaleform::Render::DrawableImage *)&v14[-1].Queues[3];
    v14->__vftable[6].~Scaleform::Render::DICommandQueue = (void (__thiscall *)(struct Scaleform::Render::DICommandQueue *))other;
    v14->__vftable = (Scaleform::Render::DICommandQueue_vtbl *)other;
    if ( (other->DrawableImageState & 8) != 0 )
    {
      other->DrawableImageState &= ~8u;
      Scaleform::Render::DrawableImage::addToCPUModifiedList(other);
    }
  }
  LeaveCriticalSection(&p_QueueLock->cs);
  return 1;
}
