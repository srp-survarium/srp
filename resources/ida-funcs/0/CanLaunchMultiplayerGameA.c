int __cdecl CanLaunchMultiplayerGameA(char *strGameExeFullPath)
{
  wchar_t WideCharStr[260]; // [esp+0h] [ebp-208h] BYREF

  memset(WideCharStr, 0, sizeof(WideCharStr));
  MultiByteToWideChar(0, 0, strGameExeFullPath, 260, WideCharStr, 260);
  return CanLaunchMultiplayerGameW(WideCharStr);
}
