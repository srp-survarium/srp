double __thiscall Scaleform::GFx::AMP::ViewStats::GetHeight(Scaleform::GFx::AMP::ViewStats *this)
{
  Scaleform::Lock *p_ViewLock; // edi
  float Height; // [esp+8h] [ebp-4h]

  p_ViewLock = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  Height = this->Height;
  LeaveCriticalSection(&p_ViewLock->cs);
  return Height;
}
