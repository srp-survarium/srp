char __thiscall Scaleform::GFx::AMP::Server::IsPaused(Scaleform::GFx::AMP::Server *this)
{
  unsigned int *p_CurrentLineNumber; // edi
  char v3; // bl

  p_CurrentLineNumber = &this->CurrentState.CurrentLineNumber;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
  v3 = (int)this->CurrentState.__vftable & 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)p_CurrentLineNumber);
  return v3;
}
