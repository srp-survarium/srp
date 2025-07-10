PVOID __cdecl _decode_pointer(void *codedptr)
{
  int (__stdcall *Value)(unsigned int); // eax
  int v2; // eax
  PVOID (__stdcall *DecodePointer)(PVOID); // eax
  HMODULE ModuleHandleW; // eax
  unsigned int v6; // [esp-4h] [ebp-8h]

  if ( TlsGetValue(__getvalueindex)
    && __flsindex != -1
    && (v6 = __flsindex, Value = (int (__stdcall *)(unsigned int))TlsGetValue(__getvalueindex), (v2 = Value(v6)) != 0) )
  {
    DecodePointer = *(PVOID (__stdcall **)(PVOID))(v2 + 508);
  }
  else
  {
    ModuleHandleW = GetModuleHandleW(L"KERNEL32.DLL");
    if ( !ModuleHandleW )
    {
      ModuleHandleW = _crt_waiting_on_module_handle(L"KERNEL32.DLL");
      if ( !ModuleHandleW )
        return codedptr;
    }
    DecodePointer = (PVOID (__stdcall *)(PVOID))GetProcAddress(ModuleHandleW, "DecodePointer");
  }
  if ( DecodePointer )
    return DecodePointer(codedptr);
  return codedptr;
}
