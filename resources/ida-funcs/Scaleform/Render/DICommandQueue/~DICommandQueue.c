void __thiscall Scaleform::Render::DICommandQueue::~DICommandQueue(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Render::DrawableImageContext *pObject; // ecx
  Scaleform::Waitable::HandlerArray **p_pHandlers; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::Render::DIQueuePage *pNext; // eax
  Scaleform::RefCountVImpl *v6; // ecx
  Scaleform::Render::DrawableImage *v7; // ecx
  Scaleform::Render::DrawableImage *v8; // ecx
  Scaleform::RefCountVImpl *v9; // ecx

  pObject = this->pDIContext.pObject;
  this->__vftable = (Scaleform::Render::DICommandQueue_vtbl *)&Scaleform::Render::DICommandQueue::`vftable';
  this->RefCount = 2;
  Scaleform::Render::DrawableImageContext::RemoveCaptureNotify(pObject, this);
  if ( this == (Scaleform::Render::DICommandQueue *)-44 )
    p_pHandlers = 0;
  else
    p_pHandlers = &this->CommandSetMutex.pHandlers;
  this->ImageList.Root.pPrev = (Scaleform::Render::DrawableImage *)p_pHandlers;
  this->ImageList.Root.pNext = (Scaleform::Render::DrawableImage *)p_pHandlers;
  v4 = (Scaleform::RefCountVImpl *)this->pDIContext.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->pDIContext.pObject = 0;
  while ( (Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *)this->Queues[3].Root.pNext != &this->Queues[3] )
  {
    pNext = this->Queues[3].Root.pNext;
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->Scaleform::ListNode<Scaleform::Render::DIQueuePage>::$635FA6BA164E16D24CB31804A66DEDAF::pPrev = pNext->pPrev;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pNext);
  }
  this->RefCount = 0;
  v6 = (Scaleform::RefCountVImpl *)this->ExecuteCmd.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  Scaleform::Lock::~Lock(&this->QueueLock);
  v7 = this->pGPUModifiedImageList.pObject;
  if ( v7 )
    v7->Release(v7);
  v8 = this->pCPUModifiedImageList.pObject;
  if ( v8 )
    v8->Release(v8);
  v9 = (Scaleform::RefCountVImpl *)this->pDIContext.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  Scaleform::WaitCondition::~WaitCondition(&this->CommandSetWC);
  Scaleform::Mutex::~Mutex(&this->CommandSetMutex);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
