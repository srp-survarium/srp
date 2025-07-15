int __cdecl _mtinit()
{
  HMODULE ModuleHandleW; // eax
  HMODULE v1; // edi
  BOOL (__stdcall *FlsFree)(DWORD); // eax
  DWORD v3; // eax
  int (__stdcall *v4)(_DWORD); // eax
  unsigned __int8 *v5; // eax
  _tiddata *v6; // esi
  int (__stdcall *v7)(unsigned int, unsigned __int8 *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v10; // [esp-8h] [ebp-10h]
  unsigned __int8 *v11; // [esp-4h] [ebp-Ch]

  ModuleHandleW = GetModuleHandleW(L"KERNEL32.DLL");
  if ( !ModuleHandleW )
    ModuleHandleW = _crt_waiting_on_module_handle(L"KERNEL32.DLL");
  v1 = ModuleHandleW;
  if ( ModuleHandleW )
  {
    gpFlsAlloc = (unsigned int (__stdcall *)(void (__stdcall *)(void *)))GetProcAddress(ModuleHandleW, "FlsAlloc");
    gpFlsGetValue = (void *(__stdcall *)(unsigned int))GetProcAddress(v1, "FlsGetValue");
    gpFlsSetValue = (int (__stdcall *)(unsigned int, void *))GetProcAddress(v1, "FlsSetValue");
    FlsFree = (BOOL (__stdcall *)(DWORD))GetProcAddress(v1, "FlsFree");
    gpFlsFree = FlsFree;
    if ( !gpFlsAlloc || !gpFlsGetValue || !gpFlsSetValue || !FlsFree )
    {
      gpFlsGetValue = TlsGetValue;
      gpFlsAlloc = __crtTlsAlloc;
      gpFlsSetValue = TlsSetValue;
      gpFlsFree = TlsFree;
    }
    v3 = TlsAlloc();
    __getvalueindex = v3;
    if ( v3 == -1 || !TlsSetValue(v3, gpFlsGetValue) )
      return 0;
    _init_pointers();
    gpFlsAlloc = (unsigned int (__stdcall *)(void (__stdcall *)(void *)))_encode_pointer(gpFlsAlloc);
    gpFlsGetValue = (void *(__stdcall *)(unsigned int))_encode_pointer(gpFlsGetValue);
    gpFlsSetValue = (int (__stdcall *)(unsigned int, void *))_encode_pointer(gpFlsSetValue);
    gpFlsFree = (int (__stdcall *)(unsigned int))_encode_pointer(gpFlsFree);
    if ( _mtinitlocks() )
    {
      v4 = (int (__stdcall *)(_DWORD))_decode_pointer(gpFlsAlloc);
      __flsindex = v4(_freefls);
      if ( __flsindex != -1 )
      {
        v5 = _calloc_crt(1u, 0x214u);
        v6 = (_tiddata *)v5;
        if ( v5 )
        {
          v11 = v5;
          v10 = __flsindex;
          v7 = (int (__stdcall *)(unsigned int, unsigned __int8 *))_decode_pointer(gpFlsSetValue);
          if ( v7(v10, v11) )
          {
            _initptd(v6, 0);
            CurrentThreadId = GetCurrentThreadId();
            v6->_thandle = -1;
            v6->_tid = CurrentThreadId;
            return 1;
          }
        }
      }
    }
  }
  _mtterm();
  return 0;
}
