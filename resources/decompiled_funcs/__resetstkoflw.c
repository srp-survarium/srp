BOOL __cdecl _resetstkoflw()
{
  void *v0; // esp
  unsigned int dwPageSize; // edi
  int v2; // esi
  HMODULE ModuleHandleW; // eax
  BOOL (__stdcall *SetThreadStackGuarantee)(PULONG); // eax
  SIZE_T v5; // ebx
  char *v6; // esi
  _BYTE v8[16]; // [esp-4h] [ebp-64h] BYREF
  _SYSTEM_INFO SystemInfo; // [esp+Ch] [ebp-54h] BYREF
  _MEMORY_BASIC_INFORMATION Buffer; // [esp+30h] [ebp-30h] BYREF
  unsigned int flOldProtect; // [esp+4Ch] [ebp-14h] BYREF
  char *AllocationBase; // [esp+50h] [ebp-10h]
  LPCVOID lpAddress; // [esp+54h] [ebp-Ch]
  int v14; // [esp+58h] [ebp-8h] BYREF

  v0 = alloca(4);
  lpAddress = v8;
  if ( !VirtualQuery(v8, &Buffer, 0x1Cu) )
    return 0;
  AllocationBase = (char *)Buffer.AllocationBase;
  GetSystemInfo(&SystemInfo);
  dwPageSize = SystemInfo.dwPageSize;
  v2 = 0;
  ModuleHandleW = GetModuleHandleW(L"kernel32.dll");
  if ( ModuleHandleW )
  {
    SetThreadStackGuarantee = (BOOL (__stdcall *)(PULONG))GetProcAddress(ModuleHandleW, "SetThreadStackGuarantee");
    if ( SetThreadStackGuarantee )
    {
      v14 = 0;
      if ( ((int (__cdecl *)(int *))SetThreadStackGuarantee)(&v14) == 1 )
      {
        if ( v14 )
          v2 = v14;
      }
    }
  }
  v5 = ~(dwPageSize - 1) & (v2 + dwPageSize - 1);
  if ( v5 )
    v5 += dwPageSize;
  if ( v5 < 2 * dwPageSize )
    v5 = 2 * dwPageSize;
  v6 = (char *)(((unsigned int)lpAddress & ~(dwPageSize - 1)) - v5);
  return v6 >= &AllocationBase[dwPageSize]
      && VirtualAlloc(v6, v5, 0x1000u, 4u)
      && VirtualProtect(v6, v5, 0x104u, &flOldProtect);
}
