void **__cdecl stlp_std::priv::__uninitialized_fill_n<void * *,unsigned int,void *>(
        void **__first,
        unsigned int __n,
        void *const *__x)
{
  int i; // [esp+4h] [ebp-10h]
  void **v5; // [esp+8h] [ebp-Ch]

  v5 = __first;
  for ( i = (int)(4 * __n) >> 2; i > 0; --i )
  {
    survarium::generate_shaders_world::is_loading();
    survarium::generate_shaders_world::is_loading();
    *v5++ = *__x;
  }
  return &__first[__n];
}
