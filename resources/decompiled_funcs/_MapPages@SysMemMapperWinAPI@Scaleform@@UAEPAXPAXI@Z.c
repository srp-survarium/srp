LPVOID __thiscall Scaleform::SysMemMapperWinAPI::MapPages(Scaleform::SysMemMapperWinAPI *this, void *ptr, SIZE_T size)
{
  return VirtualAlloc(ptr, size, 0x1000u, 4u);
}
