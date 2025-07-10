PVOID __cdecl _encode_pointer(void *ptr)
{
  int (__stdcall *Value)(unsigned int); // eax
  int v2; // eax
  PVOID (__stdcall *EncodePointer)(PVOID); // eax
  HMODULE ModuleHandleW; // eax
  unsigned int v6; // [esp-4h] [ebp-8h]

  if ( TlsGetValue(__getvalueindex)
    && __flsindex != -1
    && (v6 = __flsindex, Value = (int (__stdcall *)(unsigned int))TlsGetValue(__getvalueindex), (v2 = Value(v6)) != 0) )
  {
    EncodePointer = *(PVOID (__stdcall **)(PVOID))(v2 + 504);
  }
  else
  {
    ModuleHandleW = GetModuleHandleW(L"KERNEL32.DLL");
    if ( !ModuleHandleW )
    {
      ModuleHandleW = _crt_waiting_on_module_handle(L"KERNEL32.DLL");
      if ( !ModuleHandleW )
        return ptr;
    }
    EncodePointer = (PVOID (__stdcall *)(PVOID))GetProcAddress(ModuleHandleW, "EncodePointer");
  }
  if ( EncodePointer )
    return EncodePointer(ptr);
  return ptr;
}
