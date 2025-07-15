wchar_t __cdecl _putwch_nolock(wchar_t ch)
{
  UINT ConsoleOutputCP; // eax
  DWORD v3; // eax
  unsigned int NumberOfCharsWritten; // [esp+4h] [ebp-10h] BYREF
  char MultiByteStr[8]; // [esp+8h] [ebp-Ch] BYREF

  if ( !use_w )
    goto LABEL_10;
  if ( _confh == (HANDLE)-2 )
    __initconout();
  if ( _confh == (HANDLE)-1 )
    return -1;
  if ( !WriteConsoleW(_confh, &ch, 1u, &NumberOfCharsWritten, 0) )
  {
    if ( use_w != 2 || GetLastError() != 120 )
      return -1;
    use_w = 0;
LABEL_10:
    ConsoleOutputCP = GetConsoleOutputCP();
    v3 = WideCharToMultiByte(ConsoleOutputCP, 0, &ch, 1, MultiByteStr, 5, 0, 0);
    if ( _confh != (HANDLE)-1 && WriteConsoleA(_confh, MultiByteStr, v3, &NumberOfCharsWritten, 0) )
      return ch;
    return -1;
  }
  use_w = 1;
  return ch;
}
