unsigned int __thiscall Scaleform::GFx::AMP::ViewStats::GetFrameCount(Scaleform::GFx::AMP::ViewStats *this)
{
  Scaleform::Lock *p_ViewLock; // edi
  unsigned int FrameCount; // esi

  p_ViewLock = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  FrameCount = this->FrameCount;
  LeaveCriticalSection(&p_ViewLock->cs);
  return FrameCount;
}
