HRESULT __usercall GetVideoMemoryViaDirectDraw@<eax>(unsigned __int64 *pdwAvailableVidMem@<edi>, HMONITOR__ *hMonitor)
{
  HMODULE LibraryA; // esi
  FARPROC ProcAddress; // eax
  FARPROC v4; // eax
  int v5; // eax
  bool bGotMemory; // [esp+39h] [ebp-235h]
  IDirectDraw7 *pDDraw7; // [esp+3Ah] [ebp-234h] BYREF
  IDirectDraw *pDDraw; // [esp+3Eh] [ebp-230h] BYREF
  unsigned int temp; // [esp+42h] [ebp-22Ch] BYREF
  _DDSCAPS2 ddscaps; // [esp+46h] [ebp-228h] BYREF
  DDRAW_MATCH match; // [esp+56h] [ebp-218h] BYREF

  pDDraw = 0;
  bGotMemory = 0;
  *pdwAvailableVidMem = 0;
  LibraryA = LoadLibraryA(&stru_95DC74.m_buffer[52]);
  if ( !LibraryA )
    return -2147467259;
  memset((int)&match, 0, sizeof(match));
  match.hMonitor = hMonitor;
  ProcAddress = GetProcAddress(LibraryA, &stru_95DC74.m_buffer[64]);
  if ( ProcAddress )
    ((void (__stdcall *)(int (__stdcall *)(_GUID *, char *, char *, _BYTE *, HMONITOR__ *), DDRAW_MATCH *, int))ProcAddress)(
      DDEnumCallbackEx,
      &match,
      1);
  v4 = GetProcAddress(LibraryA, &stru_95DC74.m_buffer[252]);
  if ( v4 )
  {
    ((void (__stdcall *)(DDRAW_MATCH *, IDirectDraw **, _DWORD))v4)(&match, &pDDraw, 0);
    if ( pDDraw->QueryInterface(pDDraw, &IID_IDirectDraw7, (void **)&pDDraw7) >= 0 )
    {
      memset(&ddscaps.dwCaps2, 0, 12);
      ddscaps.dwCaps = 268451840;
      v5 = pDDraw7->GetAvailableVidMem(pDDraw7, &ddscaps, &temp, 0);
      *pdwAvailableVidMem = temp;
      if ( v5 >= 0 )
        bGotMemory = 1;
      pDDraw7->Release(pDDraw7);
    }
  }
  FreeLibrary(LibraryA);
  if ( bGotMemory )
    return 0;
  else
    return -2147467259;
}
