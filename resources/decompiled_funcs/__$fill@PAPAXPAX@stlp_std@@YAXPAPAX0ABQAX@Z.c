void __cdecl stlp_std::fill<void * *,void *>(void **__first, void **__last, void *const *__val)
{
  void **v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  v3 = __first;
  for ( i = __last - __first; i > 0; --i )
    *v3++ = *__val;
}
