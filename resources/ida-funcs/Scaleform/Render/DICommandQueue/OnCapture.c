void __thiscall Scaleform::Render::DICommandQueue::OnCapture(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Mutex *p_CommandSetMutex; // edi
  Scaleform::Lock *p_QueueLock; // ebx
  Scaleform::Render::DICommandQueue *pNext; // edx
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *Queues; // eax
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v6; // ecx
  Scaleform::Render::DIQueuePage *pPrev; // esi

  p_CommandSetMutex = &this->CommandSetMutex;
  Scaleform::Mutex::DoLock(&this->CommandSetMutex);
  while ( this->pRTCommands )
    Scaleform::WaitCondition::Wait(&this->CommandSetWC, p_CommandSetMutex, 0xFFFFFFFF);
  p_QueueLock = &this->QueueLock;
  EnterCriticalSection(&this->QueueLock.cs);
  pNext = (Scaleform::Render::DICommandQueue *)this->Queues[0].Root.pNext;
  Queues = this->Queues;
  v6 = &this->Queues[1];
  if ( pNext != (Scaleform::Render::DICommandQueue *)this->Queues )
  {
    pPrev = Queues->Root.pPrev;
    Queues->Root.pPrev = (Scaleform::Render::DIQueuePage *)Queues;
    Queues->Root.pNext = (Scaleform::Render::DIQueuePage *)Queues;
    pPrev->pNext = (Scaleform::Render::DIQueuePage *)v6;
    pNext->__vftable = (Scaleform::Render::DICommandQueue_vtbl *)v6->Root.pPrev;
    v6->Root.pPrev->pNext = (Scaleform::Render::DIQueuePage *)pNext;
    v6->Root.pPrev = pPrev;
  }
  LeaveCriticalSection(&p_QueueLock->cs);
  Scaleform::Mutex::Unlock(p_CommandSetMutex);
}
