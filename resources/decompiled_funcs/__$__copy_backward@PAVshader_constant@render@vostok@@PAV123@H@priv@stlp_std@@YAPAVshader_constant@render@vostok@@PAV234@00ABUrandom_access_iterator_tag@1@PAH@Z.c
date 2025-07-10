vostok::render::shader_constant *__usercall stlp_std::priv::__copy_backward<vostok::render::shader_constant *,vostok::render::shader_constant *,int>@<eax>(
        vostok::render::shader_constant *__last@<ecx>,
        vostok::render::shader_constant *__result@<eax>,
        vostok::render::shader_constant *__first)
{
  int i; // eax

  for ( i = __last - __first; i > 0; --i )
  {
    --__last;
    if ( --__result )
      *__result = *__last;
  }
  return __result;
}
