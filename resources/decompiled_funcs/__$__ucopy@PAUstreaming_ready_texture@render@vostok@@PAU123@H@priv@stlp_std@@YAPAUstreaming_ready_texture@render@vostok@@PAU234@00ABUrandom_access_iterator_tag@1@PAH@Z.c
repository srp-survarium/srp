vostok::render::streaming_ready_texture *__usercall stlp_std::priv::__ucopy<vostok::render::streaming_ready_texture *,vostok::render::streaming_ready_texture *,int>@<eax>(
        vostok::render::streaming_ready_texture *__first@<ecx>,
        vostok::render::streaming_ready_texture *__last@<eax>,
        vostok::render::streaming_ready_texture *__result)
{
  const vostok::render::streaming_ready_texture *v4; // edi
  int i; // ebx

  v4 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
      vostok::render::streaming_ready_texture::streaming_ready_texture(__result, v4);
    --i;
    ++v4;
  }
  return __result;
}
