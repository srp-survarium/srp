void __usercall stlp_std::priv::__fill<vostok::render::batched_vertex_source *,vostok::render::batched_vertex_source,int>(
        vostok::render::batched_vertex_source *__first@<ecx>,
        vostok::render::batched_vertex_source *__last@<eax>,
        const vostok::render::batched_vertex_source *__val@<esi>)
{
  int i; // eax

  for ( i = __last - __first; i > 0; ++__first )
  {
    *__first = *__val;
    --i;
  }
}
