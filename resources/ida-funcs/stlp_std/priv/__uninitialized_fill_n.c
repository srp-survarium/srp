char *__cdecl stlp_std::priv::__uninitialized_fill_n<char *,unsigned int,char>(char *__first, int __n, char *__x)
{
  char *v3; // edx
  int i; // ecx

  v3 = __first;
  for ( i = __n; i > 0; --i )
    *v3++ = *__x;
  return &__first[__n];
}


void **__cdecl stlp_std::priv::__uninitialized_fill_n<void * *,unsigned int,void *>(
        void **__first,
        unsigned int __n,
        void **__x)
{
  void **v3; // edx
  void **result; // eax
  int i; // ecx

  v3 = __first;
  result = &__first[__n];
  for ( i = (int)(4 * __n) >> 2; i > 0; ++v3 )
  {
    *v3 = *__x;
    --i;
  }
  return result;
}


vostok::variant<32> *__usercall stlp_std::priv::__uninitialized_fill_n<vostok::variant<32> *,unsigned int,vostok::variant<32>>@<eax>(
        vostok::variant<32> *__first@<ecx>,
        unsigned int __n@<eax>,
        const vostok::variant<32> *__x)
{
  vostok::variant<32> *v3; // esi
  vostok::variant<32> *v4; // ebx
  int v5; // ecx
  int i; // edi

  v3 = __first;
  v4 = &__first[__n];
  v5 = 48;
  for ( i = (int)(48 * __n) / 48; i > 0; --i )
  {
    if ( v3 )
      vostok::variant<32>::variant<32>(v3, __x, (vostok::variant<32> *)v5);
    ++v3;
  }
  return v4;
}
