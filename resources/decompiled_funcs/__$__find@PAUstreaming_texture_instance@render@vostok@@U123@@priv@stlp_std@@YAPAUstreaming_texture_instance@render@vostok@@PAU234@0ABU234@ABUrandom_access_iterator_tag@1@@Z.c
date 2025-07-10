vostok::render::streaming_texture_instance *__usercall stlp_std::priv::__find<vostok::render::streaming_texture_instance *,vostok::render::streaming_texture_instance>@<eax>(
        vostok::render::streaming_texture_instance *__first@<ecx>,
        vostok::render::streaming_texture_instance *__last@<edi>,
        const vostok::render::streaming_texture_instance *__val@<esi>)
{
  int v3; // edx
  float texel_factor; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm1_4
  float v7; // xmm1_4
  vostok::render::streaming_texture_instance *result; // eax

  v3 = (__last - __first) >> 2;
  if ( v3 > 0 )
  {
    texel_factor = __val->texel_factor;
    while ( __first->texel_factor != texel_factor || __first->surface_instance != __val->surface_instance )
    {
      v5 = __first[1].texel_factor;
      ++__first;
      if ( v5 == texel_factor && __first->surface_instance == __val->surface_instance )
        break;
      v6 = __first[1].texel_factor;
      ++__first;
      if ( v6 == texel_factor && __first->surface_instance == __val->surface_instance )
        break;
      v7 = __first[1].texel_factor;
      ++__first;
      if ( v7 == texel_factor && __first->surface_instance == __val->surface_instance )
        break;
      --v3;
      ++__first;
      if ( v3 <= 0 )
        goto LABEL_12;
    }
    return __first;
  }
LABEL_12:
  if ( __last - __first != 1 )
  {
    if ( __last - __first != 2 )
    {
      if ( __last - __first != 3 )
        return __last;
      if ( __first->texel_factor == __val->texel_factor && __first->surface_instance == __val->surface_instance )
        return __first;
      ++__first;
    }
    if ( __first->texel_factor != __val->texel_factor || __first->surface_instance != __val->surface_instance )
    {
      ++__first;
      goto LABEL_21;
    }
    return __first;
  }
LABEL_21:
  if ( __first->texel_factor != __val->texel_factor )
    return __last;
  result = __first;
  if ( __first->surface_instance != __val->surface_instance )
    return __last;
  return result;
}
