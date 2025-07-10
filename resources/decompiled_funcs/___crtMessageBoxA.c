int __cdecl __crtMessageBoxA(const char *lpText, const char *lpCaption, unsigned int uType)
{
  HWND__ *(__stdcall *v3)(HWND__ *); // ebx
  HMODULE LibraryA; // eax
  HMODULE v5; // edi
  int (__stdcall *MessageBoxA)(HWND, LPCSTR, LPCSTR, UINT); // eax
  HWND (__stdcall *GetActiveWindow)(); // eax
  HWND (__stdcall *GetLastActivePopup)(HWND); // eax
  BOOL (__stdcall *GetUserObjectInformationA)(HANDLE, int, PVOID, DWORD, LPDWORD); // eax
  HWINSTA (__stdcall *GetProcessWindowStation)(); // eax
  int (*v11)(void); // esi
  int (__stdcall *v12)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // eax
  int (__stdcall *v13)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // edi
  int v14; // eax
  int (*v15)(void); // eax
  int (__stdcall *v16)(HWND__ *); // eax
  int (__stdcall *v17)(HWND__ *, const char *, const char *, unsigned int); // eax
  tagUSEROBJECTFLAGS uof; // [esp+10h] [ebp-14h] BYREF
  unsigned int nDummy; // [esp+1Ch] [ebp-8h] BYREF
  HWND__ *hWndParent; // [esp+20h] [ebp-4h]

  hWndParent = 0;
  v3 = (HWND__ *(__stdcall *)(HWND__ *))_encoded_null();
  if ( !pfnMessageBox )
  {
    LibraryA = LoadLibraryA("USER32.DLL");
    v5 = LibraryA;
    if ( !LibraryA )
      return 0;
    MessageBoxA = (int (__stdcall *)(HWND, LPCSTR, LPCSTR, UINT))GetProcAddress(LibraryA, "MessageBoxA");
    if ( !MessageBoxA )
      return 0;
    pfnMessageBox = (int (__stdcall *)(HWND__ *, const char *, const char *, unsigned int))_encode_pointer(MessageBoxA);
    GetActiveWindow = (HWND (__stdcall *)())GetProcAddress(v5, "GetActiveWindow");
    pfnGetActiveWindow = (HWND__ *(__stdcall *)())_encode_pointer(GetActiveWindow);
    GetLastActivePopup = (HWND (__stdcall *)(HWND))GetProcAddress(v5, "GetLastActivePopup");
    pfnGetLastActivePopup = (HWND__ *(__stdcall *)(HWND__ *))_encode_pointer(GetLastActivePopup);
    GetUserObjectInformationA = (BOOL (__stdcall *)(HANDLE, int, PVOID, DWORD, LPDWORD))GetProcAddress(
                                                                                          v5,
                                                                                          "GetUserObjectInformationA");
    pfnGetUserObjectInformation = (int (__stdcall *)(void *, int, void *, unsigned int, unsigned int *))_encode_pointer(GetUserObjectInformationA);
    if ( pfnGetUserObjectInformation )
    {
      GetProcessWindowStation = (HWINSTA (__stdcall *)())GetProcAddress(v5, "GetProcessWindowStation");
      pfnGetProcessWindowStation = (HWINSTA__ *(__stdcall *)())_encode_pointer(GetProcessWindowStation);
    }
  }
  if ( (char *)pfnGetProcessWindowStation == (char *)v3
    || (char *)pfnGetUserObjectInformation == (char *)v3
    || (v11 = (int (*)(void))_decode_pointer(pfnGetProcessWindowStation),
        v12 = (int (__stdcall *)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *))_decode_pointer(pfnGetUserObjectInformation),
        v13 = v12,
        !v11)
    || !v12
    || (v14 = v11()) != 0 && v13(v14, 1, &uof, 12, &nDummy) && (uof.dwFlags & 1) != 0 )
  {
    if ( (char *)pfnGetActiveWindow != (char *)v3 )
    {
      v15 = (int (*)(void))_decode_pointer(pfnGetActiveWindow);
      if ( v15 )
      {
        hWndParent = (HWND__ *)v15();
        if ( hWndParent )
        {
          if ( pfnGetLastActivePopup != v3 )
          {
            v16 = (int (__stdcall *)(HWND__ *))_decode_pointer(pfnGetLastActivePopup);
            if ( v16 )
              hWndParent = (HWND__ *)v16(hWndParent);
          }
        }
      }
    }
  }
  else
  {
    uType |= (unsigned int)&loc_1FFFFE + 2;
  }
  v17 = (int (__stdcall *)(HWND__ *, const char *, const char *, unsigned int))_decode_pointer(pfnMessageBox);
  if ( v17 )
    return v17(hWndParent, lpText, lpCaption, uType);
  return 0;
}
