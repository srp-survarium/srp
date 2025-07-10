FARPROC __thiscall set_low_fragmentation_heap(void *this)
{
  FARPROC result; // eax
  HMODULE LibraryA; // eax
  void (__stdcall *v3)(_DWORD, _DWORD, _DWORD, _DWORD); // esi
  HANDLE ProcessHeap; // eax
  void *heap_handle; // eax
  unsigned int HeapFragValue; // [esp+10h] [ebp-4h] BYREF

  HeapFragValue = (unsigned int)this;
  result = (FARPROC)vostok::debug::is_debugger_present();
  if ( !(_BYTE)result )
  {
    LibraryA = LoadLibraryA("kernel32.dll");
    result = GetProcAddress(LibraryA, "HeapSetInformation");
    v3 = (void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))result;
    if ( result )
    {
      HeapFragValue = 2;
      ProcessHeap = GetProcessHeap();
      v3(ProcessHeap, 0, &HeapFragValue, 4);
      heap_handle = _get_heap_handle();
      return (FARPROC)((int (__stdcall *)(void *, _DWORD, unsigned int *, int))v3)(heap_handle, 0, &HeapFragValue, 4);
    }
  }
  return result;
}
