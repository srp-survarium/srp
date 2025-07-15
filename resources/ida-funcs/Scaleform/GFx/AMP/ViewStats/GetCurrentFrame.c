unsigned int __thiscall Scaleform::GFx::AMP::ViewStats::GetCurrentFrame(Scaleform::GFx::AMP::ViewStats *this)
{
  Scaleform::Lock *p_ViewLock; // edi
  unsigned int CurrentFrame; // esi

  p_ViewLock = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  CurrentFrame = this->CurrentFrame;
  LeaveCriticalSection(&p_ViewLock->cs);
  return CurrentFrame;
}
