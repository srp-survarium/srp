void __thiscall Scaleform::Render::DICommandQueue::ExecuteNextCapture(
        Scaleform::Render::DICommandQueue *this,
        Scaleform::Render::ContextImpl::RenderNotify *pnotify)
{
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // ecx
  Scaleform::Render::DICommandQueue *pNext; // ecx
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v5; // eax
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v6; // edi
  Scaleform::Render::DIQueuePage *pPrev; // edx
  Scaleform::Render::DIQueuePage *v8; // eax
  Scaleform::Render::DIQueuePage *v9; // ecx
  Scaleform::Render::DICommandContext context; // [esp+10h] [ebp-24h] BYREF
  Scaleform::Render::DICommandSet v11; // [esp+18h] [ebp-1Ch] BYREF
  int v12; // [esp+24h] [ebp-10h] BYREF
  Scaleform::Render::HAL *v13; // [esp+28h] [ebp-Ch]
  Scaleform::Render::Renderer2D *v14; // [esp+2Ch] [ebp-8h]
  int v15; // [esp+30h] [ebp-4h]

  if ( !this->pRTCommandQueue && pnotify )
    this->pRTCommandQueue = pnotify->pRTCommandQueue;
  pRTCommandQueue = this->pRTCommandQueue;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  if ( pRTCommandQueue )
  {
    pRTCommandQueue->GetRenderInterfaces(pRTCommandQueue, (Scaleform::Render::Interfaces *)&v12);
    context.pR2D = v14;
    context.pHAL = v13;
  }
  v11.pQueue = this;
  v11.QueueList.Root.pPrev = (Scaleform::Render::DIQueuePage *)&v11.QueueList;
  v11.QueueList.Root.pNext = (Scaleform::Render::DIQueuePage *)&v11.QueueList;
  Scaleform::Mutex::DoLock(&this->CommandSetMutex);
  EnterCriticalSection(&this->QueueLock.cs);
  pNext = (Scaleform::Render::DICommandQueue *)this->Queues[1].Root.pNext;
  v5 = &this->Queues[1];
  v6 = &this->Queues[2];
  if ( pNext != (Scaleform::Render::DICommandQueue *)&this->Queues[1] )
  {
    pPrev = v5->Root.pPrev;
    v5->Root.pPrev = (Scaleform::Render::DIQueuePage *)v5;
    this->Queues[1].Root.pNext = (Scaleform::Render::DIQueuePage *)&this->Queues[1];
    pPrev->pNext = (Scaleform::Render::DIQueuePage *)v6;
    pNext->__vftable = (Scaleform::Render::DICommandQueue_vtbl *)v6->Root.pPrev;
    v6->Root.pPrev->pNext = (Scaleform::Render::DIQueuePage *)pNext;
    v6->Root.pPrev = pPrev;
  }
  Scaleform::Mutex::DoLock(&this->CommandSetMutex);
  v8 = this->Queues[2].Root.pNext;
  if ( v8 != (Scaleform::Render::DIQueuePage *)v6 )
  {
    v9 = v6->Root.pPrev;
    v6->Root.pPrev = (Scaleform::Render::DIQueuePage *)v6;
    this->Queues[2].Root.pNext = (Scaleform::Render::DIQueuePage *)&this->Queues[2];
    v9->pNext = (Scaleform::Render::DIQueuePage *)&v11.QueueList;
    v8->pPrev = v11.QueueList.Root.pPrev;
    v11.QueueList.Root.pPrev->pNext = v8;
    v11.QueueList.Root.pPrev = v9;
  }
  Scaleform::Mutex::Unlock(&this->CommandSetMutex);
  this->pRTCommands = &v11;
  LeaveCriticalSection(&this->QueueLock.cs);
  Scaleform::Mutex::Unlock(&this->CommandSetMutex);
  Scaleform::Render::DICommandSet::ExecuteCommandsRT(&v11, &context);
  Scaleform::Mutex::DoLock(&this->CommandSetMutex);
  this->pRTCommands = 0;
  Scaleform::WaitCondition::NotifyAll(&this->CommandSetWC);
  Scaleform::Mutex::Unlock(&this->CommandSetMutex);
}
