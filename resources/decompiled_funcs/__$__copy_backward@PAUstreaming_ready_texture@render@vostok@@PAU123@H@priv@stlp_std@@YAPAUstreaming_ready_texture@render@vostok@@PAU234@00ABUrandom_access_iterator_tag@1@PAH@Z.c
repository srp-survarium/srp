vostok::render::streaming_ready_texture *__usercall stlp_std::priv::__copy_backward<vostok::render::streaming_ready_texture *,vostok::render::streaming_ready_texture *,int>@<eax>(
        vostok::render::streaming_ready_texture *__result@<eax>,
        vostok::render::streaming_ready_texture *__first,
        vostok::render::streaming_ready_texture *__last)
{
  const vostok::render::streaming_ready_texture *v3; // ebx
  vostok::render::streaming_ready_texture *v4; // ecx
  int i; // esi

  v3 = __last;
  v4 = (vostok::render::streaming_ready_texture *)((char *)__last - (char *)__first);
  for ( i = __last - __first; i > 0; --i )
    vostok::render::streaming_ready_texture::operator=(v4, (int)--__result, --v3);
  return __result;
}
