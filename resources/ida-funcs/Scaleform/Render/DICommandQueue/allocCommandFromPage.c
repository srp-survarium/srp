unsigned __int8 *__thiscall Scaleform::Render::DICommandQueue::allocCommandFromPage(
        Scaleform::Render::DICommandQueue *this,
        unsigned int size,
        Scaleform::Lock *locked)
{
  Scaleform::Render::DIQueuePage *pPrev; // eax
  unsigned int Offset; // ecx

  pPrev = this->Queues[0].Root.pPrev;
  if ( pPrev == (Scaleform::Render::DIQueuePage *)this->Queues || size > 496 - pPrev->Offset )
  {
    if ( !this->FreePageCount && this->AllocPageCount >= 0x10 )
    {
      LeaveCriticalSection(&locked->cs);
      Scaleform::Render::DICommandQueue::ExecuteCommandsAndWait(this);
      EnterCriticalSection(&locked->cs);
    }
    pPrev = Scaleform::Render::DICommandQueue::allocPage(this);
  }
  if ( !pPrev )
    return 0;
  Offset = pPrev->Offset;
  if ( size > 496 - Offset )
    return 0;
  pPrev->Offset = size + Offset;
  return &pPrev->Buffer[Offset];
}
