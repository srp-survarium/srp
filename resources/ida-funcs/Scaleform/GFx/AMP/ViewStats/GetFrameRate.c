double __thiscall Scaleform::GFx::AMP::ViewStats::GetFrameRate(Scaleform::GFx::AMP::ViewStats *this)
{
  Scaleform::Lock *p_ViewLock; // edi
  float FrameRate; // [esp+8h] [ebp-4h]

  p_ViewLock = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  FrameRate = this->FrameRate;
  LeaveCriticalSection(&p_ViewLock->cs);
  return FrameRate;
}
