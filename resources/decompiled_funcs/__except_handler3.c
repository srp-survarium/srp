int __cdecl _except_handler3(_EXCEPTION_RECORD *pExcept, _EH3_EXCEPTION_REGISTRATION *pRN, int a3)
{
  _EH3_EXCEPTION_REGISTRATION *v3; // ebp
  _EH3_EXCEPTION_REGISTRATION *v4; // ebx
  DWORD TryLevel; // esi
  PSCOPETABLE_ENTRY ScopeTable; // edi
  int (__fastcall *FilterFunc)(_DWORD, _DWORD); // eax
  int v8; // eax
  PSCOPETABLE_ENTRY v9; // edi
  int v10; // ecx
  _DWORD v12[2]; // [esp+10h] [ebp-8h] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  v3 = (_EH3_EXCEPTION_REGISTRATION *)&savedregs;
  v4 = pRN;
  if ( (pExcept->ExceptionFlags & 6) != 0 )
  {
    _local_unwind2((int)pRN, 0xFFFFFFFF);
    return 1;
  }
  else
  {
    v12[0] = pExcept;
    v12[1] = a3;
    pRN[-1].TryLevel = (DWORD)v12;
    TryLevel = pRN->TryLevel;
    ScopeTable = pRN->ScopeTable;
    if ( _ValidateEH3RN(pRN) <= 0 )
    {
      pExcept->ExceptionFlags |= 8u;
    }
    else
    {
      while ( TryLevel != -1 )
      {
        FilterFunc = (int (__fastcall *)(_DWORD, _DWORD))ScopeTable[TryLevel].FilterFunc;
        if ( FilterFunc )
        {
          v8 = FilterFunc(0, 0);
          v4 = (_EH3_EXCEPTION_REGISTRATION *)v3->TryLevel;
          if ( v8 )
          {
            if ( v8 < 0 )
              return 0;
            CallDestructExceptionObject((_EXCEPTION_RECORD *)v3->ScopeTable, 1);
            v9 = v4->ScopeTable;
            _global_unwind2(v4);
            v3 = v4 + 1;
            _local_unwind2((int)v4, TryLevel);
            _NLG_Notify((unsigned int)v9[TryLevel].HandlerFunc, (unsigned int)&v4[1], 1u);
            v4->TryLevel = *(&v9->EnclosingLevel + v10);
            v4 = 0;
            TryLevel = 0;
            (*((void (__fastcall **)(_DWORD, _DWORD))&v9->HandlerFunc + v10))(0, 0);
          }
        }
        ScopeTable = v4->ScopeTable;
        TryLevel = ScopeTable[TryLevel].EnclosingLevel;
      }
    }
    return 1;
  }
}
