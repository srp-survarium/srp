_EXCEPTION_DISPOSITION __cdecl _except_handler4(
        _EXCEPTION_RECORD *ExceptionRecord,
        _EXCEPTION_REGISTRATION_RECORD *EstablisherFrame,
        _CONTEXT *ContextRecord)
{
  _EXCEPTION_DISPOSITION (__cdecl *Handler)(_EXCEPTION_RECORD *, void *, _CONTEXT *, void *); // ebx
  unsigned int v4; // esi
  _EXCEPTION_REGISTRATION_RECORD *v5; // edi
  int v6; // ecx
  unsigned int v7; // eax
  int v8; // eax
  _EXCEPTION_REGISTRATION_RECORD *v10; // eax
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+Ch] [ebp-18h] BYREF
  _EH4_SCOPETABLE_RECORD *ScopeTableRecord; // [esp+14h] [ebp-10h]
  _EXCEPTION_DISPOSITION Disposition; // [esp+18h] [ebp-Ch]
  unsigned int EnclosingLevel; // [esp+1Ch] [ebp-8h]
  unsigned __int8 Revalidate; // [esp+23h] [ebp-1h]

  Handler = (_EXCEPTION_DISPOSITION (__cdecl *)(_EXCEPTION_RECORD *, void *, _CONTEXT *, void *))EstablisherFrame;
  v4 = __security_cookie ^ (unsigned int)EstablisherFrame[1].Next;
  Revalidate = 0;
  Disposition = ExceptionContinueSearch;
  v5 = EstablisherFrame + 2;
  if ( (ExceptionRecord->ExceptionFlags & 0x66) != 0 )
    goto $LN32_1;
  EstablisherFrame[-1].Handler = (_EXCEPTION_DISPOSITION (__cdecl *)(_EXCEPTION_RECORD *, void *, _CONTEXT *, void *))&ExceptionPointers;
  Handler = EstablisherFrame[1].Handler;
  ExceptionPointers.ExceptionRecord = ExceptionRecord;
  ExceptionPointers.ContextRecord = ContextRecord;
  if ( Handler != (_EXCEPTION_DISPOSITION (__cdecl *)(_EXCEPTION_RECORD *, void *, _CONTEXT *, void *))-2 )
  {
    do
    {
      v6 = *(_DWORD *)(v4 + 12 * (_DWORD)Handler + 20);
      ScopeTableRecord = (_EH4_SCOPETABLE_RECORD *)(v4 + 12 * (_DWORD)Handler + 16);
      v7 = ScopeTableRecord->EnclosingLevel;
      EnclosingLevel = ScopeTableRecord->EnclosingLevel;
      if ( v6 )
      {
        v8 = _EH4_CallFilterFunc(v6, v5);
        Revalidate = 1;
        if ( v8 < 0 )
          return 0;
        if ( v8 > 0 )
        {
          if ( ExceptionRecord->ExceptionCode == -529697949
            && _pDestructExceptionObject
            && _IsNonwritableInCurrentImage((unsigned __int8 *)&_pDestructExceptionObject) )
          {
            _pDestructExceptionObject(ExceptionRecord, 1);
          }
          _EH4_GlobalUnwind(EstablisherFrame);
          v10 = EstablisherFrame;
          if ( EstablisherFrame[1].Handler != Handler )
          {
            _EH4_LocalUnwind(v5, &__security_cookie);
            v10 = EstablisherFrame;
          }
          v10[1].Handler = (_EXCEPTION_DISPOSITION (__cdecl *)(_EXCEPTION_RECORD *, void *, _CONTEXT *, void *))EnclosingLevel;
          _EH4_TransferToHandler(ScopeTableRecord->HandlerFunc, v5);
$LN32_1:
          if ( *((_DWORD *)Handler + 3) != -2 )
            _EH4_LocalUnwind(v5, &__security_cookie);
          return Disposition;
        }
        v7 = EnclosingLevel;
      }
      Handler = (_EXCEPTION_DISPOSITION (__cdecl *)(_EXCEPTION_RECORD *, void *, _CONTEXT *, void *))v7;
    }
    while ( v7 != -2 );
  }
  return Disposition;
}
