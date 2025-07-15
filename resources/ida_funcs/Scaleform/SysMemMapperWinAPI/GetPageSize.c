unsigned int __thiscall Scaleform::SysMemMapperWinAPI::GetPageSize(Scaleform::SysMemMapperWinAPI *this)
{
  _SYSTEM_INFO info; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(&info);
  return info.dwPageSize;
}
