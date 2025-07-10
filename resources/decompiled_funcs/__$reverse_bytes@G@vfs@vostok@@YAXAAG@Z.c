void __cdecl vostok::vfs::reverse_bytes<unsigned short>(char *res)
{
  char *__i2; // [esp+0h] [ebp-24h]
  char *__i1; // [esp+4h] [ebp-20h]

  __i2 = res + 2;
  for ( __i1 = res; __i1 < __i2; ++__i1 )
    stlp_std::iter_swap<char *,char *>(__i1, --__i2);
}
