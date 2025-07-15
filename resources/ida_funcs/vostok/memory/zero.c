void __cdecl vostok::memory::zero(void *destination, unsigned int size_in_bytes)
{
  memset((int)destination, 0, size_in_bytes);
}


void __cdecl vostok::memory::zero<char,14>(char (*destination)[14])
{
  vostok::memory::zero(destination, 0xEu);
}


void __cdecl vostok::memory::zero<unsigned short,64>(unsigned __int16 (*destination)[64])
{
  vostok::memory::zero(destination, 0x80u);
}


void __cdecl vostok::memory::zero<vostok::vfs::base_node<1> *,32768>(vostok::vfs::base_node<1> *(*destination)[32768])
{
  vostok::memory::zero(destination, (unsigned int)&loc_20000);
}
