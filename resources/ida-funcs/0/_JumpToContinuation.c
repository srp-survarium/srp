void __stdcall _JumpToContinuation(void (__stdcall *target)(_DWORD, EHRegistrationNode *), EHRegistrationNode *pRN)
{
  target(target, pRN);
}
