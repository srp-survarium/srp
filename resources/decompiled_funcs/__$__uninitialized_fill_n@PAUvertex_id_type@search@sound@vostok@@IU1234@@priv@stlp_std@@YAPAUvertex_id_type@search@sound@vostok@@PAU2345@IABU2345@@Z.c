vostok::sound::search::vertex_id_type *__cdecl stlp_std::priv::__uninitialized_fill_n<vostok::sound::search::vertex_id_type *,unsigned int,vostok::sound::search::vertex_id_type>(
        vostok::sound::search::vertex_id_type *__first,
        unsigned int __n,
        const vostok::sound::search::vertex_id_type *__x)
{
  int i; // [esp+Ch] [ebp-10h]
  vostok::sound::search::vertex_id_type *v5; // [esp+10h] [ebp-Ch]

  v5 = __first;
  for ( i = (int)(12 * __n) / 12; i > 0; --i )
  {
    if ( v5 )
      *v5 = *__x;
    ++v5;
  }
  return &__first[__n];
}
