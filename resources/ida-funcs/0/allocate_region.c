LPVOID __cdecl allocate_region(unsigned __int64 size, void *const address)
{
  return VirtualAlloc(address, size, 0x3000u, 4u);
}
