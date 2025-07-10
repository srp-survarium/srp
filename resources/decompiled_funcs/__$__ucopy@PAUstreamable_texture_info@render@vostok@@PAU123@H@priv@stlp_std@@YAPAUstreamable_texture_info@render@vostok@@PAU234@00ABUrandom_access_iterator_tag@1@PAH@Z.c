vostok::render::streamable_texture_info *__usercall stlp_std::priv::__ucopy<vostok::render::streamable_texture_info *,vostok::render::streamable_texture_info *,int>@<eax>(
        vostok::render::streamable_texture_info *__last@<eax>,
        vostok::render::streamable_texture_info *__result@<ecx>,
        vostok::render::streamable_texture_info *__first)
{
  const vostok::render::streamable_texture_info *v3; // ebx
  int i; // esi

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
      vostok::render::streamable_texture_info::streamable_texture_info(__result, v3);
    --i;
    ++v3;
  }
  return __result;
}
