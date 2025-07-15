// positive sp value has been detected, the output may be wrong!
void __stdcall _CallMemberFunction1(void *pthis, void *pmfn, void *pthat, int val2)
{
  __int32 v4; // [esp-8h] [ebp-8h]
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  ((void (__stdcall *)(void *, void *))_InterlockedExchange((volatile __int32 *)&retaddr, v4))(pthis, pmfn);
}
