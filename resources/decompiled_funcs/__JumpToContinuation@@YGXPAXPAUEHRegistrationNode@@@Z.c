void __stdcall _JumpToContinuation(void (__stdcall *target)(void *, EHRegistrationNode *), EHRegistrationNode *pRN)
{
  target(target, pRN);
}
