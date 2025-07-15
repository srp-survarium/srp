void __thiscall Scaleform::Render::DrawableImageContext::RemoveCaptureNotify(
        Scaleform::Render::DrawableImageContext *this,
        Scaleform::Render::DICommandQueue *notify)
{
  Scaleform::Lock *p_TreeRootKillListLock; // esi

  p_TreeRootKillListLock = &this->TreeRootKillListLock;
  EnterCriticalSection(&this->TreeRootKillListLock.cs);
  if ( notify->pNext )
  {
    notify->pPrev->pNext = notify->pNext;
    notify->pNext->pPrev = notify->pPrev;
    notify->pPrev = 0;
    notify->pNext = 0;
  }
  LeaveCriticalSection(&p_TreeRootKillListLock->cs);
}
