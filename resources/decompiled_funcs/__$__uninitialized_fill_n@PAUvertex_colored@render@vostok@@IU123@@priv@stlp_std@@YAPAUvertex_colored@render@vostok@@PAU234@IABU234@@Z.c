vostok::render::vertex_colored *__usercall stlp_std::priv::__uninitialized_fill_n<vostok::render::vertex_colored *,unsigned int,vostok::render::vertex_colored>@<eax>(
        vostok::render::vertex_colored *__first@<edx>,
        unsigned int __n@<eax>,
        const vostok::render::vertex_colored *__x@<esi>)
{
  vostok::render::vertex_colored *result; // eax
  int i; // ecx

  result = &__first[__n];
  for ( i = result - __first; i > 0; ++__first )
  {
    if ( __first )
      *__first = *__x;
    --i;
  }
  return result;
}
