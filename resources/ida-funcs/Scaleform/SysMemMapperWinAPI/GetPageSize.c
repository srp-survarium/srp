unsigned int __thiscall Scaleform::SysMemMapperWinAPI::GetPageSize(Scaleform::SysMemMapperWinAPI *this)
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(&SystemInfo);
  return SystemInfo.dwPageSize;
}
