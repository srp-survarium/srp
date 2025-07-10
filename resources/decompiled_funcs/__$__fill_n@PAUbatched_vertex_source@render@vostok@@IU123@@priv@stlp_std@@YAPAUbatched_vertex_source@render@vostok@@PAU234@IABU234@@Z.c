vostok::render::batched_vertex_source *__fastcall stlp_std::priv::__fill_n<vostok::render::batched_vertex_source *,unsigned int,vostok::render::batched_vertex_source>(
        const vostok::render::batched_vertex_source *__val,
        unsigned int __n,
        vostok::render::batched_vertex_source *__first)
{
  vostok::render::batched_vertex_source *result; // eax

  for ( result = __first; __n; ++result )
  {
    *result = *__val;
    --__n;
  }
  return result;
}
