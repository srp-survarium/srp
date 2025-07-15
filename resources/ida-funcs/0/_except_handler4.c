int __cdecl _except_handler4(
        _EXCEPTION_RECORD *ExceptionRecord,
        _EXCEPTION_REGISTRATION_RECORD *EstablisherFrame,
        _CONTEXT *ContextRecord)
{
  unsigned int Handler; // ebx
  unsigned int v4; // esi
  _EXCEPTION_REGISTRATION_RECORD *v5; // edi
  int (*v6)(void); // ecx
  unsigned int v7; // eax
  int v8; // eax
  _EXCEPTION_REGISTRATION_RECORD *v10; // eax
  _DWORD v11[2]; // [esp+Ch] [ebp-18h] BYREF
  int v12; // [esp+14h] [ebp-10h]
  int v13; // [esp+18h] [ebp-Ch]
  _EXCEPTION_DISPOSITION (__cdecl *v14)(_EXCEPTION_RECORD *, void *, _CONTEXT *, void *); // [esp+1Ch] [ebp-8h]
  char v15; // [esp+23h] [ebp-1h]

  Handler = (unsigned int)EstablisherFrame;
  v4 = __security_cookie ^ (unsigned int)EstablisherFrame[1].Next;
  v15 = 0;
  v13 = 1;
  v5 = EstablisherFrame + 2;
  if ( (ExceptionRecord->ExceptionFlags & 0x66) != 0 )
    goto $LN32_5;
  EstablisherFrame[-1].Handler = (_EXCEPTION_DISPOSITION (__cdecl *)(_EXCEPTION_RECORD *, void *, _CONTEXT *, void *))v11;
  Handler = (unsigned int)EstablisherFrame[1].Handler;
  v11[0] = ExceptionRecord;
  v11[1] = ContextRecord;
  if ( Handler != -2 )
  {
    do
    {
      v6 = *(int (**)(void))(v4 + 12 * Handler + 20);
      v12 = v4 + 12 * Handler + 16;
      v7 = *(_DWORD *)v12;
      v14 = *(_EXCEPTION_DISPOSITION (__cdecl **)(_EXCEPTION_RECORD *, void *, _CONTEXT *, void *))v12;
      if ( v6 )
      {
        v8 = _EH4_CallFilterFunc(v6);
        v15 = 1;
        if ( v8 < 0 )
          return 0;
        if ( v8 > 0 )
        {
          if ( ExceptionRecord->ExceptionCode == -529697949
            && _pDestructExceptionObject[0]
            && _IsNonwritableInCurrentImage((unsigned __int8 *)_pDestructExceptionObject) )
          {
            _pDestructExceptionObject[0](ExceptionRecord, 1);
          }
          _EH4_GlobalUnwind(EstablisherFrame);
          v10 = EstablisherFrame;
          if ( EstablisherFrame[1].Handler != (_EXCEPTION_DISPOSITION (__cdecl *)(_EXCEPTION_RECORD *, void *, _CONTEXT *, void *))Handler )
          {
            _EH4_LocalUnwind((int)EstablisherFrame, Handler, (int)v5, &__security_cookie);
            v10 = EstablisherFrame;
          }
          v10[1].Handler = v14;
          _EH4_TransferToHandler(*(int (__fastcall **)(_DWORD, _DWORD))(v12 + 8));
$LN32_5:
          if ( *(_DWORD *)(Handler + 12) != -2 )
            _EH4_LocalUnwind(Handler, 0xFFFFFFFE, (int)v5, &__security_cookie);
          return v13;
        }
        v7 = (unsigned int)v14;
      }
      Handler = v7;
    }
    while ( v7 != -2 );
  }
  return v13;
}
