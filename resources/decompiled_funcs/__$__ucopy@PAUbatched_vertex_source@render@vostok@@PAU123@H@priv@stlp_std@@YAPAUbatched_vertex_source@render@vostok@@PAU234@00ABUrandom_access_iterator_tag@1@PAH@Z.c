vostok::render::batched_vertex_source *__usercall stlp_std::priv::__ucopy<vostok::render::batched_vertex_source *,vostok::render::batched_vertex_source *,int>@<eax>(
        vostok::render::batched_vertex_source *__last@<eax>,
        vostok::render::batched_vertex_source *__result@<ecx>,
        vostok::render::batched_vertex_source *__first)
{
  vostok::render::batched_vertex_source *v3; // esi
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
