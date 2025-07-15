Scaleform::GFx::AMP::ServerState_vtbl *__thiscall Scaleform::GFx::AMP::Server::GetCurrentState(
        Scaleform::GFx::AMP::Server *this)
{
  unsigned int *p_CurrentLineNumber; // edi
  Scaleform::GFx::AMP::ServerState_vtbl *v3; // esi

  p_CurrentLineNumber = &this->CurrentState.CurrentLineNumber;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
  v3 = this->CurrentState.__vftable;
  LeaveCriticalSection((LPCRITICAL_SECTION)p_CurrentLineNumber);
  return v3;
}
