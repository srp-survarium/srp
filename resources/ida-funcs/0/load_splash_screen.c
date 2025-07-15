char __cdecl load_splash_screen(HANDLE file_handle, unsigned __int8 *const buffer, DWORD buffer_size)
{
  vostok::threading::event_tasks_unaware *v3; // ecx
  HANDLE v4; // esi
  char v5; // bl
  unsigned int NumberOfBytesTransferred; // [esp+Ch] [ebp-24h] BYREF
  HANDLE hObject; // [esp+10h] [ebp-20h] BYREF
  _OVERLAPPED Overlapped; // [esp+1Ch] [ebp-14h] BYREF

  vostok::threading::event_tasks_unaware::event_tasks_unaware(v3, &hObject);
  v4 = hObject;
  v5 = 0;
  Overlapped.Offset = 0;
  Overlapped.OffsetHigh = 0;
  Overlapped.hEvent = hObject;
  if ( ReadFile(file_handle, buffer, buffer_size, 0, &Overlapped) || GetLastError() == 997 )
  {
    WaitForSingleObject(v4, 0xFFFFFFFF);
    if ( GetOverlappedResult(file_handle, &Overlapped, &NumberOfBytesTransferred, 0) )
      v5 = 1;
    CloseHandle(v4);
    return v5;
  }
  else
  {
    CloseHandle(v4);
    return 0;
  }
}
