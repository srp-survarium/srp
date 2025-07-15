vostok::render::shader_constant *__usercall stlp_std::priv::__unguarded_partition<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>@<eax>(
        vostok::render::shader_constant *__first@<ecx>,
        vostok::render::shader_constant *__last@<eax>,
        vostok::render::shader_constant __pivot,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  vostok::render::shader_constant v7; // [esp+8h] [ebp-18h] BYREF

  while ( 1 )
  {
    if ( __comp(__first, &__pivot) )
      goto LABEL_2;
    do
      --__last;
    while ( __comp(&__pivot, __last) );
    if ( __first >= __last )
      return __first;
    v7 = *__first;
    vostok::render::shader_constant::operator=(__last, __first);
    vostok::render::shader_constant::operator=(&v7, __last);
LABEL_2:
    ++__first;
  }
}
