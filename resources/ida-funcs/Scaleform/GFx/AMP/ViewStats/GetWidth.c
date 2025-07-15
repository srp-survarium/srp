double __thiscall Scaleform::GFx::AMP::ViewStats::GetWidth(Scaleform::GFx::AMP::ViewStats *this)
{
  Scaleform::Lock *p_ViewLock; // edi
  float Width; // [esp+8h] [ebp-4h]

  p_ViewLock = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  Width = this->Width;
  LeaveCriticalSection(&p_ViewLock->cs);
  return Width;
}
