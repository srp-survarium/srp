HMODULE __cdecl _crt_waiting_on_module_handle(const wchar_t *szModuleName)
{
  DWORD v1; // edi
  HMODULE result; // eax

  v1 = 1000;
  do
  {
    Sleep(v1);
    result = GetModuleHandleW(szModuleName);
    v1 += 1000;
  }
  while ( v1 <= 0xEA60 && !result );
  return result;
}
