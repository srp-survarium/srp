BOOL __stdcall CH_ReadProcessMemory(
        void *__formal,
        unsigned __int64 lpBaseAddress,
        void *lpBuffer,
        SIZE_T nSize,
        unsigned int *lpNumberOfBytesRead)
{
  HANDLE CurrentProcess; // eax

  CurrentProcess = GetCurrentProcess();
  return ReadProcessMemory(CurrentProcess, (LPCVOID)lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead);
}
