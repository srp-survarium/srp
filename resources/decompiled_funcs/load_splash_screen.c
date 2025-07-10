char __usercall load_splash_screen@<al>(
        void *const file_handle@<edi>,
        unsigned __int8 *const buffer,
        unsigned int buffer_size)
{
  HANDLE EventA; // esi
  BOOL OverlappedResult; // eax
  void *overlapped_16; // [esp+28h] [ebp-24h]
  unsigned int NumberOfBytesTransferred; // [esp+34h] [ebp-18h] BYREF
  _OVERLAPPED Overlapped; // [esp+38h] [ebp-14h] BYREF

  EventA = CreateEventA(0, 0, 0, 0);
  Overlapped.Offset = 0;
  Overlapped.OffsetHigh = 0;
  Overlapped.hEvent = EventA;
  if ( !ReadFile(file_handle, buffer, buffer_size, 0, &Overlapped) && GetLastError() != 997 )
  {
    overlapped_16 = EventA;
LABEL_4:
    CloseHandle(overlapped_16);
    return 0;
  }
  WaitForSingleObject(EventA, 0xFFFFFFFF);
  OverlappedResult = GetOverlappedResult(file_handle, &Overlapped, &NumberOfBytesTransferred, 0);
  overlapped_16 = EventA;
  if ( !OverlappedResult )
    goto LABEL_4;
  CloseHandle(EventA);
  return 1;
}
