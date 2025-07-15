BOOL __thiscall Scaleform::GFx::AMP::Server::IsFunctionAggregation(Scaleform::GFx::AMP::Server *this)
{
  unsigned int *p_CurrentLineNumber; // edi
  bool v3; // bl

  p_CurrentLineNumber = &this->CurrentState.CurrentLineNumber;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
  v3 = ((int)this->CurrentState.__vftable & 0x40) != 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)p_CurrentLineNumber);
  return !v3;
}
