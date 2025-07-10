void __thiscall Scaleform::Render::DICommandQueue::ExecuteCommand::Execute(
        Scaleform::Render::DICommandQueue::ExecuteCommand *this)
{
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // ecx
  Scaleform::Render::DICommandQueue *pQueue; // ecx
  Scaleform::Mutex *p_CommandSetMutex; // edi
  Scaleform::Render::DICommandContext context; // [esp+Ch] [ebp-24h] BYREF
  Scaleform::Render::DICommandSet cmdSet; // [esp+14h] [ebp-1Ch] BYREF
  int v7; // [esp+20h] [ebp-10h] BYREF
  Scaleform::Render::HAL *v8; // [esp+24h] [ebp-Ch]
  Scaleform::Render::Renderer2D *v9; // [esp+28h] [ebp-8h]
  int v10; // [esp+2Ch] [ebp-4h]

  pRTCommandQueue = this->pQueue->pRTCommandQueue;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  if ( pRTCommandQueue )
  {
    pRTCommandQueue->GetRenderInterfaces(pRTCommandQueue, (Scaleform::Render::Interfaces *)&v7);
    context.pR2D = v9;
    context.pHAL = v8;
  }
  pQueue = this->pQueue;
  cmdSet.QueueList.Root.pPrev = (Scaleform::Render::DIQueuePage *)&cmdSet.QueueList;
  cmdSet.pQueue = pQueue;
  cmdSet.QueueList.Root.pNext = (Scaleform::Render::DIQueuePage *)&cmdSet.QueueList;
  Scaleform::Render::DICommandQueue::popCommandSet(pQueue, &cmdSet, DICommand_All);
  this->pQueue->pRTCommands = &cmdSet;
  Scaleform::Render::DICommandSet::ExecuteCommandsRT(&cmdSet, &context);
  p_CommandSetMutex = &this->pQueue->CommandSetMutex;
  Scaleform::Mutex::DoLock(p_CommandSetMutex);
  this->pQueue->pRTCommands = 0;
  Scaleform::WaitCondition::NotifyAll(&this->pQueue->CommandSetWC);
  Scaleform::Mutex::Unlock(p_CommandSetMutex);
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this->pQueue);
  Scaleform::Event::SetEvent(&this->ExecuteDone);
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this);
}
