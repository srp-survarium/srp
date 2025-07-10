void __thiscall Scaleform::Render::DrawableImageContext::AddCaptureNotify(
        Scaleform::Render::DrawableImageContext *this,
        Scaleform::Render::DICommandQueue *notify)
{
  Scaleform::Lock *p_TreeRootKillListLock; // edi

  p_TreeRootKillListLock = &this->TreeRootKillListLock;
  EnterCriticalSection(&this->TreeRootKillListLock.cs);
  notify->pPrev = this->QueueList.Root.pPrev;
  notify->pNext = (Scaleform::Render::DICommandQueue *)&this->TreeRootKillList.Data.Size;
  this->QueueList.Root.pPrev->pNext = notify;
  this->QueueList.Root.pPrev = notify;
  LeaveCriticalSection(&p_TreeRootKillListLock->cs);
}
