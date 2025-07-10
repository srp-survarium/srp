void **__cdecl stlp_std::priv::__fill_n<void * *,unsigned int,void *>(
        void **__first,
        unsigned int __n,
        void *const *__val)
{
  unsigned int v3; // ecx
  void **result; // eax

  v3 = __n;
  for ( result = __first; v3; ++result )
  {
    *result = *__val;
    --v3;
  }
  return result;
}
