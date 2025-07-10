unsigned int __thiscall vostok::memory::reader_wrapper<vostok::memory::reader>::r<unsigned int>(
        vostok::memory::reader_wrapper<vostok::memory::reader> *this)
{
  unsigned int *v1; // edx
  unsigned int result; // eax

  v1 = *(unsigned int **)&this[4];
  result = *v1;
  *(_DWORD *)&this[4] = v1 + 1;
  return result;
}
