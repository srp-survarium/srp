_DWORD *__cdecl _SEH_prolog(int a1, int a2)
{
  void *v4; // esp
  _DWORD v6[2]; // [esp-8h] [ebp-8h] BYREF
  int v7; // [esp+4h] [ebp+4h]

  v6[1] = _except_handler3;
  v6[0] = NtCurrentTeb()->NtTib.ExceptionList;
  v4 = alloca(a2);
  v7 = -1;
  return v6;
}
