int __thiscall Scaleform::GFx::AMP::Server::GetProfileLevel(Scaleform::GFx::AMP::Server *this)
{
  unsigned int *p_CurrentLineNumber; // edi
  volatile int RefCount; // esi

  p_CurrentLineNumber = &this->CurrentState.CurrentLineNumber;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
  RefCount = this->CurrentState.RefCount;
  LeaveCriticalSection((LPCRITICAL_SECTION)p_CurrentLineNumber);
  return RefCount;
}
