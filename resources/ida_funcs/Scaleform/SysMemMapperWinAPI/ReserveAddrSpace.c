LPVOID __thiscall Scaleform::SysMemMapperWinAPI::ReserveAddrSpace(Scaleform::SysMemMapperWinAPI *this, SIZE_T size)
{
  return VirtualAlloc(0, size, 0x2000u, 4u);
}
