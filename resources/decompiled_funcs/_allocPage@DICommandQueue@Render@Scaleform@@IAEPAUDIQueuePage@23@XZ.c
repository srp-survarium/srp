Scaleform::Render::DIQueuePage *__thiscall Scaleform::Render::DICommandQueue::allocPage(
        Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Render::DIQueuePage *result; // eax
  int v3; // [esp+4h] [ebp-4h] BYREF

  if ( (Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *)this->Queues[3].Root.pNext == &this->Queues[3] )
  {
    v3 = 2;
    result = (Scaleform::Render::DIQueuePage *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 512,
                                                 &v3);
    if ( !result )
      return 0;
    result->Offset = 0;
    result->CaptureFrameId = 0;
  }
  else
  {
    result = this->Queues[3].Root.pNext;
    result->pPrev->pNext = result->pNext;
    result->pNext->Scaleform::ListNode<Scaleform::Render::DIQueuePage>::$DED4EEDCED8B039708BE169F5A3A1451::pPrev = result->pPrev;
    --this->FreePageCount;
  }
  if ( result )
  {
    result->pPrev = this->Queues[0].Root.pPrev;
    result->pNext = (Scaleform::Render::DIQueuePage *)this->Queues;
    this->Queues[0].Root.pPrev->pNext = result;
    this->Queues[0].Root.pPrev = result;
  }
  return result;
}
