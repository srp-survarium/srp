void __usercall stlp_std::priv::__ufill<vostok::render::batched_vertex_source *,vostok::render::batched_vertex_source,int>(
        vostok::render::batched_vertex_source *__first@<edi>,
        vostok::render::batched_vertex_source *__last@<eax>,
        const vostok::render::batched_vertex_source *__x@<esi>)
{
  int v3; // eax
  vostok::math::color *p_normal; // ecx

  v3 = __last - __first;
  if ( v3 > 0 )
  {
    p_normal = &__first->normal;
    do
    {
      if ( p_normal != (vostok::math::color *)12 )
        *(vostok::render::batched_vertex_source *)&p_normal[-3].r = *__x;
      --v3;
      p_normal += 9;
    }
    while ( v3 > 0 );
  }
}
