vostok::render::requested_streamable_texture *__usercall stlp_std::priv::__ucopy<vostok::render::requested_streamable_texture *,vostok::render::requested_streamable_texture *,int>@<eax>(
        vostok::render::requested_streamable_texture *__first@<ecx>,
        vostok::render::requested_streamable_texture *__last@<eax>,
        vostok::render::requested_streamable_texture *__result)
{
  const vostok::render::requested_streamable_texture *v4; // edi
  int i; // ebx

  v4 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
      vostok::render::requested_streamable_texture::requested_streamable_texture(__result, v4);
    --i;
    ++v4;
  }
  return __result;
}
