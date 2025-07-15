void __cdecl __noreturn longjmp(jmp_buf Buf, int Value)
{
  unsigned int *v2; // ebx
  unsigned int v3; // ebp
  void *v4; // esi
  void (__stdcall *v5)(unsigned int *); // eax
  _EXCEPTION_RECORD ExceptionRecord; // [esp+0h] [ebp-50h] BYREF

  v2 = (unsigned int *)Buf;
  ExceptionRecord.ExceptionCode = -2147483610;
  memset(&ExceptionRecord.ExceptionFlags, 0, 16);
  v3 = *Buf;
  v4 = (void *)Buf[6];
  if ( v4 != (void *)__readfsdword(0) )
  {
    RtlUnwind(v4, &lj_return, &ExceptionRecord, 0);
    v2 = (unsigned int *)Buf;
  }
  if ( v4 )
  {
    if ( _rt_probe_read4(v2 + 8) && v2[8] == 1447244336 )
    {
      v5 = (void (__stdcall *)(unsigned int *))v2[9];
      if ( v5 )
        v5(v2);
    }
    else
    {
      _local_unwind2((int)v4, v2[7]);
    }
  }
  _NLG_Notify(v2[5], v3, 0);
  ((void (*)(void))v2[5])();
}
