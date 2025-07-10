vostok::render::streaming_ready_texture *__usercall stlp_std::priv::__copy<vostok::render::streaming_ready_texture *,vostok::render::streaming_ready_texture *,int>@<eax>(
        vostok::render::streaming_ready_texture *__last@<eax>,
        vostok::render::streaming_ready_texture *__result@<ecx>,
        vostok::render::streaming_ready_texture *__first)
{
  const vostok::render::streaming_ready_texture *v3; // ebx
  vostok::render::streaming_ready_texture *v5; // ecx
  int i; // esi

  v3 = __first;
  v5 = (vostok::render::streaming_ready_texture *)((char *)__last - (char *)__first);
  for ( i = __last - __first; i > 0; ++__result )
  {
    vostok::render::streaming_ready_texture::operator=(v5, v3);
    --i;
    ++v3;
  }
  return __result;
}
