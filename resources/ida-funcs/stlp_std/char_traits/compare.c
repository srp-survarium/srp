int __cdecl stlp_std::char_traits<char>::compare(const char *__s1, const char *__s2, int __n)
{
  return memcmp(__s1, __s2, __n);
}
