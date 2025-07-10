void __thiscall Scaleform::Render::DICommandQueue::popCommandSet(
        Scaleform::Render::DICommandQueue *this,
        Scaleform::Render::DICommandSet *cmdSet,
        Scaleform::Render::DICommandSetType type)
{
  Scaleform::Mutex *p_CommandSetMutex; // ebx
  Scaleform::Render::DICommandQueue *pNext; // edx
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v6; // ecx
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *p_QueueList; // eax
  Scaleform::Render::DIQueuePage *pPrev; // edi
  Scaleform::Render::DICommandQueue *v9; // edx
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v10; // ecx
  Scaleform::Render::DIQueuePage *v11; // edi
  Scaleform::Render::DICommandQueue *v12; // edx
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *Queues; // ecx
  Scaleform::Render::DIQueuePage *v14; // esi

  p_CommandSetMutex = &this->CommandSetMutex;
  Scaleform::Mutex::DoLock(&this->CommandSetMutex);
  pNext = (Scaleform::Render::DICommandQueue *)this->Queues[2].Root.pNext;
  v6 = &this->Queues[2];
  p_QueueList = &cmdSet->QueueList;
  if ( pNext != (Scaleform::Render::DICommandQueue *)&this->Queues[2] )
  {
    pPrev = v6->Root.pPrev;
    v6->Root.pPrev = (Scaleform::Render::DIQueuePage *)v6;
    this->Queues[2].Root.pNext = (Scaleform::Render::DIQueuePage *)&this->Queues[2];
    pPrev->pNext = (Scaleform::Render::DIQueuePage *)p_QueueList;
    pNext->__vftable = (Scaleform::Render::DICommandQueue_vtbl *)p_QueueList->Root.pPrev;
    p_QueueList->Root.pPrev->pNext = (Scaleform::Render::DIQueuePage *)pNext;
    p_QueueList->Root.pPrev = pPrev;
  }
  if ( type == DICommand_All )
  {
    v9 = (Scaleform::Render::DICommandQueue *)this->Queues[1].Root.pNext;
    v10 = &this->Queues[1];
    if ( v9 != (Scaleform::Render::DICommandQueue *)&this->Queues[1] )
    {
      v11 = v10->Root.pPrev;
      v10->Root.pPrev = (Scaleform::Render::DIQueuePage *)v10;
      this->Queues[1].Root.pNext = (Scaleform::Render::DIQueuePage *)&this->Queues[1];
      v11->pNext = (Scaleform::Render::DIQueuePage *)p_QueueList;
      v9->__vftable = (Scaleform::Render::DICommandQueue_vtbl *)p_QueueList->Root.pPrev;
      p_QueueList->Root.pPrev->pNext = (Scaleform::Render::DIQueuePage *)v9;
      p_QueueList->Root.pPrev = v11;
    }
    v12 = (Scaleform::Render::DICommandQueue *)this->Queues[0].Root.pNext;
    Queues = this->Queues;
    if ( v12 != (Scaleform::Render::DICommandQueue *)this->Queues )
    {
      v14 = Queues->Root.pPrev;
      Queues->Root.pPrev = (Scaleform::Render::DIQueuePage *)Queues;
      Queues->Root.pNext = (Scaleform::Render::DIQueuePage *)Queues;
      v14->pNext = (Scaleform::Render::DIQueuePage *)p_QueueList;
      v12->__vftable = (Scaleform::Render::DICommandQueue_vtbl *)p_QueueList->Root.pPrev;
      p_QueueList->Root.pPrev->pNext = (Scaleform::Render::DIQueuePage *)v12;
      p_QueueList->Root.pPrev = v14;
    }
  }
  Scaleform::Mutex::Unlock(p_CommandSetMutex);
}
