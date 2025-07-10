BOOL __thiscall Scaleform::SysMemMapperWinAPI::UnmapPages(Scaleform::SysMemMapperWinAPI *this, void *ptr, SIZE_T size)
{
  return VirtualFree(ptr, size, 0x4000u);
}
