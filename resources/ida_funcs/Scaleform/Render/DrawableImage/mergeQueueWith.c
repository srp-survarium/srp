char __thiscall Scaleform::Render::DrawableImage::mergeQueueWith(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *other)
{
  Scaleform::Lock *p_QueueLock; // edi
  Scaleform::Render::Texture *volatile pObject; // ebp
  Scaleform::Render::Image *RefCount; // edi
  Scaleform::Render::ImageUpdateSync *v7; // ecx
  volatile int v8; // ecx
  Scaleform::Render::Image *i; // eax
  Scaleform::Render::ImageUpdateSync *v10; // ecx
  Scaleform::Render::ImageUpdateSync *pUpdateSync; // ecx
  Scaleform::GFx::Resource *v12; // ecx
  Scaleform::RefCountVImpl *v13; // ecx
  Scaleform::Render::DICommandQueue *v14; // eax
  Scaleform::Render::Image_vtbl *pPrev; // ecx

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
      pObject = (Scaleform::Render::Texture *volatile)other->pQueue.pObject;
      RefCount = (Scaleform::Render::Image *)pObject[1].RefCount;
      if ( other == RefCount )
      {
        v7 = (Scaleform::Render::ImageUpdateSync *)other->pCPUModifiedNext.pObject;
        if ( v7 )
          ((void (__thiscall *)(Scaleform::Render::ImageUpdateSync *))v7->UpdateImage)(v7);
        v8 = pObject[1].RefCount;
        if ( v8 )
          (*(void (__thiscall **)(volatile int))(*(_DWORD *)v8 + 8))(v8);
        pObject[1].RefCount = (volatile int)other->pCPUModifiedNext.pObject;
      }
      else
      {
        for ( i = (Scaleform::Render::Image *)RefCount[4].pUpdateSync;
              other != i;
              i = (Scaleform::Render::Image *)i[4].pUpdateSync )
        {
          RefCount = i;
        }
        v10 = (Scaleform::Render::ImageUpdateSync *)other->pCPUModifiedNext.pObject;
        if ( v10 )
          ((void (__thiscall *)(Scaleform::Render::ImageUpdateSync *))v10->UpdateImage)(v10);
        pUpdateSync = RefCount[4].pUpdateSync;
        if ( pUpdateSync )
          ((void (__thiscall *)(Scaleform::Render::ImageUpdateSync *))pUpdateSync->UpdateImage)(pUpdateSync);
        RefCount[4].pUpdateSync = (Scaleform::Render::ImageUpdateSync *)other->pCPUModifiedNext.pObject;
      }
    }
    p_QueueLock = &this->pQueue.pObject->QueueLock;
    EnterCriticalSection(&p_QueueLock->cs);
    v12 = (Scaleform::GFx::Resource *)this->pQueue.pObject;
    if ( v12 )
      Scaleform::RefCountImpl::AddRef(v12);
    v13 = (Scaleform::RefCountVImpl *)other->pQueue.pObject;
    if ( v13 )
      Scaleform::RefCountImpl::Release(v13);
    other->pQueue.pObject = this->pQueue.pObject;
    v14 = this->pQueue.pObject;
    pPrev = (Scaleform::Render::Image_vtbl *)v14->ImageList.Root.pPrev;
    v14 = (Scaleform::Render::DICommandQueue *)((char *)v14 + 44);
    other->pPrev = (Scaleform::Render::DrawableImage *)pPrev;
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
