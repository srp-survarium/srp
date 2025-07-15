void __thiscall Scaleform::GFx::AMP::ViewStats::CollectGcStats(
        Scaleform::GFx::AMP::ViewStats *this,
        Scaleform::GFx::AMP::ProfileFrame *frameProfile)
{
  Scaleform::Lock *p_ViewLock; // edi

  p_ViewLock = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  frameProfile->GcRootsNumber += this->RootsNumber;
  frameProfile->GcFreedRootsNumber += this->FreedRootsNumber;
  LeaveCriticalSection(&p_ViewLock->cs);
}
