vostok::render::shader_constant *__usercall stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>@<eax>(
        const vostok::render::shader_constant *__last@<eax>,
        vostok::render::shader_constant *__result@<ecx>,
        vostok::render::shader_constant *__first)
{
  vostok::render::shader_constant *v3; // esi
  int i; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
      *__result = *v3;
    --i;
    ++v3;
  }
  return __result;
}
