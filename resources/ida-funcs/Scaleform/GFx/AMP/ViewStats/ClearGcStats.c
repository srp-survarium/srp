void __thiscall Scaleform::GFx::AMP::ViewStats::ClearGcStats(Scaleform::GFx::AMP::ViewStats *this)
{
  Scaleform::Lock *p_ViewLock; // edi

  p_ViewLock = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  this->RootsNumber = 0;
  this->FreedRootsNumber = 0;
  LeaveCriticalSection(&p_ViewLock->cs);
}
