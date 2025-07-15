_tiddata *__cdecl _getptd_noexit()
{
  DWORD LastError; // eax
  DWORD v1; // edi
  int (__stdcall *v2)(unsigned int); // eax
  _tiddata *v3; // esi
  unsigned __int8 *v4; // eax
  int (__stdcall *v5)(unsigned int, unsigned __int8 *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v8; // [esp-8h] [ebp-10h]
  unsigned int v9; // [esp-4h] [ebp-Ch]
  unsigned __int8 *v10; // [esp-4h] [ebp-Ch]

  LastError = GetLastError();
  v9 = __flsindex;
  v1 = LastError;
  v2 = (int (__stdcall *)(unsigned int))__set_flsgetvalue();
  v3 = (_tiddata *)v2(v9);
  if ( !v3 )
  {
    v4 = _calloc_crt(1u, 0x214u);
    v3 = (_tiddata *)v4;
    if ( v4 )
    {
      v10 = v4;
      v8 = __flsindex;
      v5 = (int (__stdcall *)(unsigned int, unsigned __int8 *))_decode_pointer(gpFlsSetValue);
      if ( v5(v8, v10) )
      {
        _initptd(v3, 0);
        CurrentThreadId = GetCurrentThreadId();
        v3->_thandle = -1;
        v3->_tid = CurrentThreadId;
      }
      else
      {
        free(v3);
        v3 = 0;
      }
    }
  }
  SetLastError(v1);
  return v3;
}
