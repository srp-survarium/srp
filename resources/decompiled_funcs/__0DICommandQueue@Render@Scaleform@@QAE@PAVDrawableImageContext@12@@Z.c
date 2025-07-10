void __thiscall Scaleform::Render::DICommandQueue::DICommandQueue(
        Scaleform::Render::DICommandQueue *this,
        Scaleform::GFx::Resource *dicontext)
{
  Scaleform::Waitable::HandlerArray **p_pHandlers; // ecx
  Scaleform::Render::DICommandQueue::ExecuteCommand *v4; // eax
  Scaleform::Render::DICommandQueue::ExecuteCommand *v5; // edi
  Scaleform::Render::DrawableImageContext *pObject; // ecx

  this->__vftable = (Scaleform::Render::DICommandQueue_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::DICommandQueue_vtbl *)&Scaleform::Render::DICommandQueue::`vftable';
  Scaleform::Mutex::Mutex(&this->CommandSetMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&this->CommandSetWC);
  this->pRTCommands = 0;
  if ( this == (Scaleform::Render::DICommandQueue *)-44 )
    p_pHandlers = 0;
  else
    p_pHandlers = &this->CommandSetMutex.pHandlers;
  this->ImageList.Root.pPrev = (Scaleform::Render::DrawableImage *)p_pHandlers;
  this->ImageList.Root.pNext = (Scaleform::Render::DrawableImage *)p_pHandlers;
  if ( dicontext )
    Scaleform::RefCountImpl::AddRef(dicontext);
  this->pDIContext.pObject = (Scaleform::Render::DrawableImageContext *)dicontext;
  this->pCPUModifiedImageList.pObject = 0;
  this->pGPUModifiedImageList.pObject = 0;
  this->pRTCommandQueue = (Scaleform::Render::ThreadCommandQueue *)dicontext[2].pLib;
  Scaleform::Lock::Lock(&this->QueueLock, 0);
  v4 = (Scaleform::Render::DICommandQueue::ExecuteCommand *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                              Scaleform::Memory::pGlobalHeap,
                                                              56,
                                                              0);
  v5 = v4;
  if ( v4 )
  {
    v4->__vftable = (Scaleform::Render::DICommandQueue::ExecuteCommand_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v4->RefCount = 1;
    v4->__vftable = (Scaleform::Render::DICommandQueue::ExecuteCommand_vtbl *)&Scaleform::Render::DICommandQueue::ExecuteCommand::`vftable';
    v4->pQueue = this;
    Scaleform::Event::Event(&v4->ExecuteDone, 0, 0);
  }
  else
  {
    v5 = 0;
  }
  this->ExecuteCmd.pObject = v5;
  this->Queues[1].Root.pPrev = (Scaleform::Render::DIQueuePage *)&this->Queues[1];
  this->Queues[1].Root.pNext = (Scaleform::Render::DIQueuePage *)&this->Queues[1];
  this->Queues[2].Root.pPrev = (Scaleform::Render::DIQueuePage *)&this->Queues[2];
  this->Queues[2].Root.pNext = (Scaleform::Render::DIQueuePage *)&this->Queues[2];
  this->Queues[0].Root.pPrev = (Scaleform::Render::DIQueuePage *)this->Queues;
  this->Queues[0].Root.pNext = (Scaleform::Render::DIQueuePage *)this->Queues;
  this->Queues[3].Root.pPrev = (Scaleform::Render::DIQueuePage *)&this->Queues[3];
  this->Queues[3].Root.pNext = (Scaleform::Render::DIQueuePage *)&this->Queues[3];
  pObject = this->pDIContext.pObject;
  this->CaptureFrameId = 0;
  this->FreePageCount = 0;
  this->AllocPageCount = 0;
  Scaleform::Render::DrawableImageContext::AddCaptureNotify(pObject, this);
}
