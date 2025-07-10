BOOL __thiscall Scaleform::SysMemMapperWinAPI::ReleaseAddrSpace(
        Scaleform::SysMemMapperWinAPI *this,
        void *ptr,
        unsigned int __formal)
{
  return VirtualFree(ptr, 0, 0x8000u);
}
